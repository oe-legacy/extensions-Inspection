#include "TransformationNodeInspector.h"

#include <list>

namespace OpenEngine {
namespace Utils {

using namespace Scene;

ValueList Inspect(TransformationNode* node) {
    ValueList values;
    // position
    RWValueCall<TransformationNode,Vector<3,float> > *v 
        = new RWValueCall<TransformationNode,Vector<3,float> >(*node,
                                                               &TransformationNode::GetPosition,
                                                               &TransformationNode::SetPosition);
   
    v->name = "position";
    values.push_back(v);

    // rotation
    RWValueCall<TransformationNode, Quaternion<float> > *r
        = new RWValueCall<TransformationNode, Quaternion<float> >(*node,
                                                                  &TransformationNode::GetRotation,
                                                                  &TransformationNode::SetRotation);

    r->name = "rotation";
    values.push_back(r);

    /* Scale */ { 
        RWValueCall<TransformationNode,Vector<3,float> > *v 
            = new RWValueCall<TransformationNode,Vector<3,float> >(*node,
                                                                   &TransformationNode::GetScale,
                                                                   &TransformationNode::SetScale);
        
        v->name = "scale";
        values.push_back(v);
    }

    return values;
}

}
}
