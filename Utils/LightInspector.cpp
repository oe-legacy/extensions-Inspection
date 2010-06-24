#include "LightInspector.h"
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Utils {
namespace Inspection {

using namespace Geometry;

ValueList Inspect(Light *l) {
    ValueList values;

    /* Ambient */ {
        RWValueCall<Light, Vector<4,float> > *v
            = new RWValueCall<Light, Vector<4,float> >
            (*l,
             &Light::GetAmbient,
             &Light::SetAmbient);
        v->name = "ambient";
        v->isColor = true;
        values.push_back(v);
    }
    /* Diffuse */ {
        RWValueCall<Light, Vector<4,float> > *v
            = new RWValueCall<Light, Vector<4,float> >
            (*l,
             &Light::GetDiffuse,
             &Light::SetDiffuse);
        v->name = "diffuse";
        v->isColor = true;
        values.push_back(v);
    }
    /* Specular */ {
        RWValueCall<Light, Vector<4,float> > *v
            = new RWValueCall<Light, Vector<4,float> >
            (*l,
             &Light::GetSpecular,
             &Light::SetSpecular);
        v->name = "specular";
        v->isColor = true;
        values.push_back(v);
    }

    return values;    
}

}
}
}
