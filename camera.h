#ifndef FAARAY_CAMERA_H
#define FAARAY_CAMERA_H
//==============================================================================
#include "faaray_global.h"
#include <memory>
#include "gfa/point3d.h"
#include "gfa/vector3d.h"
//==============================================================================
namespace FaaRay {

class TraceThread;

class FAARAYSHARED_EXPORT Camera
{
public:
    Camera();

    void setEye(const GFA::Point3D &eye);
    void setLookAt(const GFA::Point3D &lookAt);

    virtual void    render(TraceThread &rp) const = 0;

protected:
    GFA::Point3D  eye_;
    GFA::Point3D  lookAt_;
    GFA::Vector3D u_, v_, w_;
};
typedef std::shared_ptr<Camera> CameraSPtr;
}
#endif // FAARAY_CAMERA_H
