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
#include <string>
#include <functional>


namespace OpenEngine {
namespace Utils {

    using namespace std;

class IValue {
public:
    virtual ~IValue() {};
    std::string name;
};

    // template <class T>
    // class ICallback {
    // // C& instance;
    // // void (C::*setFunc)(T);
    // // T (C::*getFunc)();
    // public:
    //     // , T (C::*gPtr)(), void (C::*sPtr)(T)
    //     //,
    //     //setFunc(sPtr),
    //     //getFunc(gPtr)
    //     T Get() {};
    // };

    // template <class C, class T>
    // class Callback : public ICallback<T> {

    // };

template <class T>
class RWValue : public IValue {
public:
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

} // NS Utils
} // NS OpenEngine

#endif // _OE_I_INSPECTOR_H_
