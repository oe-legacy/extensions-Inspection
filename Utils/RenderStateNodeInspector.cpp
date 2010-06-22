#include "RenderStateNodeInspector.h"


namespace OpenEngine {
namespace Utils {
namespace Inspection {

using namespace Scene;



ValueList Inspect(RenderStateNode* node) {
    ValueList values;
    
    list<pair<string,RenderStateNode::RenderStateOption> > options;
    options.push_back(make_pair("texture",RenderStateNode::TEXTURE));
    options.push_back(make_pair("shader",RenderStateNode::SHADER));
    options.push_back(make_pair("backface",RenderStateNode::BACKFACE));
    options.push_back(make_pair("lighting",RenderStateNode::LIGHTING));
    options.push_back(make_pair("depthtest",RenderStateNode::DEPTH_TEST));
    options.push_back(make_pair("wireframe",RenderStateNode::WIREFRAME));
    options.push_back(make_pair("softnorm",RenderStateNode::SOFT_NORMAL));
    options.push_back(make_pair("hardnorm",RenderStateNode::HARD_NORMAL));
    options.push_back(make_pair("binormal",RenderStateNode::BINORMAL));
    options.push_back(make_pair("tangent",RenderStateNode::TANGENT));
    options.push_back(make_pair("colormaterial",RenderStateNode::COLOR_MATERIAL));


    for (list<pair<string,RenderStateNode::RenderStateOption> >::iterator itr = options.begin();
         itr != options.end();
         itr++) {
        string name = itr->first;
        RenderStateNode::RenderStateOption option = itr->second;        
        RWValueToggle<RenderStateNode,RenderStateNode::RenderStateOption > *v 
            = new RWValueToggle<RenderStateNode,RenderStateNode::RenderStateOption >
            (*node,
             &RenderStateNode::IsOptionEnabled,
             &RenderStateNode::EnableOption,
             &RenderStateNode::DisableOption,
             option);
        
        v->name = name;
        values.push_back(v);
    }

    return values;
}

}
}
}
