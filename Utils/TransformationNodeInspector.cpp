#include "TransformationNodeInspector.h"

#include <list>

namespace OpenEngine {
namespace Utils {

    using namespace std;

// TransformationNodeInspector::TransformationNodeInspector(TransformationNode* node) 
//     : node(node) {
//     RWValueCall<TransformationNode,Vector<3,float> > v(*node,
//                                                        &TransformationNode::GetPosition,
//                                                        &TransformationNode::SetPosition);

    
//     v.name = "position";
//     values.push_back(v);

//     // IValue v2;
//     // v2.name = "position";
//     // values.push_back(v2);
// }

// list<IValue> TransformationNodeInspector::Values() {
    
//     return values;
//}

ValueList Inspect(TransformationNode* node) {
    ValueList values;

    RWValueCall<TransformationNode,Vector<3,float> > *v 
        = new RWValueCall<TransformationNode,Vector<3,float> >(*node,
                                                               &TransformationNode::GetPosition,
                                                               &TransformationNode::SetPosition);

    
    v->name = "position";
    values.push_back(v);

    RWValueCall<TransformationNode, Quaternion<float> > *r
        = new RWValueCall<TransformationNode, Quaternion<float> >(*node,
                                                                  &TransformationNode::GetRotation,
                                                                  &TransformationNode::SetRotation);

    r->name = "rotation";
    values.push_back(r);

    return values;
}

}
}
