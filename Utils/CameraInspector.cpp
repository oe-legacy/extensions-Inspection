#include "CameraInspector.h"
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Utils {
namespace Inspection {

using namespace Display;

ValueList Inspect(Camera *cam) {
    ValueList values;

    /* Position */ {
        RWValueCall<Camera, Vector<3,float> > *v
            = new RWValueCall<Camera, Vector<3,float> >(*cam,
                                                        &Camera::GetPosition,
                                                        &Camera::SetPosition);
        v->name = "position";
        values.push_back(v);
    }
    /* Direction */ {
        RWValueCall<Camera, Quaternion<float> > *v
            = new RWValueCall<Camera, Quaternion<float> >(*cam,
                                                        &Camera::GetDirection,
                                                        &Camera::SetDirection);
        v->name = "direction";
        values.push_back(v);
    }

    return values;    
}

}
}
}
