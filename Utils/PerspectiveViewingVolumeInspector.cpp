#include "PerspectiveViewingVolumeInspector.h"
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Utils {
namespace Inspection {

using namespace Display;

ValueList Inspect(PerspectiveViewingVolume *vol) {
    ValueList values;

    /* Near */ {
        RWValueCall<PerspectiveViewingVolume, float > *v
            = new RWValueCall<PerspectiveViewingVolume, float >
            (*vol,
             &PerspectiveViewingVolume::GetNear,
             &PerspectiveViewingVolume::SetNear);
        v->name = "near";
        v->properties[MIN] = 0.0;
        values.push_back(v);
    }
    /* Far */ {
        RWValueCall<PerspectiveViewingVolume, float > *v
            = new RWValueCall<PerspectiveViewingVolume, float >
            (*vol,
             &PerspectiveViewingVolume::GetFar,
             &PerspectiveViewingVolume::SetFar);
        v->name = "far";
        v->properties[MIN] = 0.0;
        values.push_back(v);
    }
    /* FOV */ {
        RWValueCall<PerspectiveViewingVolume, float > *v
            = new RWValueCall<PerspectiveViewingVolume, float >
            (*vol,
             &PerspectiveViewingVolume::GetFOV,
             &PerspectiveViewingVolume::SetFOV);
        v->name = "FOV";
        v->properties[MIN] = 0.0;
        v->properties[STEP] = 0.01;
        values.push_back(v);
    }
    /* Aspect */ {
        RWValueCall<PerspectiveViewingVolume, float > *v
            = new RWValueCall<PerspectiveViewingVolume, float >
            (*vol,
             &PerspectiveViewingVolume::GetAspect,
             &PerspectiveViewingVolume::SetAspect);
        v->name = "aspect";
        v->properties[MIN] = 0.0;
        v->properties[STEP] = 0.01;
        values.push_back(v);
    }


    return values;    
}

}
}
}
