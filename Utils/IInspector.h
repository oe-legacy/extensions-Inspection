// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_I_INSPECTOR_H_
#define _OE_I_INSPECTOR_H_

#include <list>
#include <map>
#include <string>
#include <functional>


namespace OpenEngine {
namespace Utils {
    namespace Inspection {
    using namespace std;

class IValue {
public:
    virtual ~IValue() {};
    std::string name;
};

class ActionValue : public IValue {
public:
    virtual void Call() =0;
};

template <class C>
class ActionValueCall : public ActionValue {
public:
    C& instance;
    void (C::*callFunc)();

    ActionValueCall(C& instance,
                void (C::*cFunc)())
        : instance(instance)
        , callFunc(cFunc) {}
    void Call() {
        (instance.*callFunc)();
    }
};

template <class T>
class RValue : public IValue {
public:
    virtual T Get() =0;
};

template <class C, class T>
class RValueCall : public RValue<T> {
public:
    C& instance;
    T (C::*getFunc)();
    RValueCall(C& instance,
               T (C::*gFun)())
        : instance(instance)
        , getFunc(gFun) 
    {}
    T Get() { return (instance.*getFunc)(); }
};

enum Property {
    MIN,
    MAX,
    STEP
};

template <class T>
class RWValue : public IValue {
public:
    map<Property,T> properties;
    bool isColor;
    RWValue() : isColor(false) {}
    virtual T Get() =0;
    virtual void Set(T) =0;
};    

template <class C, class T> 
class RWValueCall : public RWValue<T> {
public:

    C& instance;
    T (C::*getFunc)();
    void (C::*setFunc)(T);

    RWValueCall(C& instance, 
                T (C::*gFun)(),
                void (C::*sFun)(T))
        : instance(instance), 
          getFunc(gFun),
          setFunc(sFun)
    {}
    T Get() { return (instance.*getFunc)();  }
        
    void Set(T v) {  (instance.*setFunc)(v); }
};

template <class C, class T>
class RWValueToggle : public RWValue<bool> {
public:
    C& instance;
    bool (C::*isEnabled)(T) const;
    void (C::*enable)(T);
    void (C::*disable)(T);
    T v;

    RWValueToggle(C& instance,
                  bool (C::*isE)(T) const,
                  void (C::*eF)(T),
                  void (C::*dF)(T),
                  T v)
        : instance(instance),
          isEnabled(isE),
          enable(eF),
          disable(dF),
          v(v) {}

    bool Get() {return (instance.*isEnabled)(v);}
    void Set(bool e) { e ? (instance.*enable)(v) : (instance.*disable)(v); }

};

#define INSPECT_VALUE(_class, _type, _field, _name)                     \
    do {                                                                \
        RWValueCall<_class, _type> *v                                   \
            = new RWValueCall<_class, _type>(*this,                     \
                                             &_class::Get##_field,      \
                                             &_class::Set##_field);     \
        v->name = _name;                                                \
    values.push_back(v);                                                \
    } while (0)


// /**
//  * Short description.
//  *
//  * @class IInspector IInspector.h ons/Inspection/Utils/IInspector.h
//  */
// class IInspector {
// private:

// public:
//     virtual std::list<IValue> Values() = 0;
// };

typedef list<IValue*> ValueList;
 
}

} // NS Utils
} // NS OpenEngine

#endif // _OE_I_INSPECTOR_H_
