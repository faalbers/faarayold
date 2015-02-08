#ifndef __FAARAY_CAMERA_H__
#define __FAARAY_CAMERA_H__
//==============================================================================
#include <memory>
#include "FaaRay/FaaRay.h"
#include "GFA/Point3D.h"
#include "GFA/Vector3D.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

class FAARAY_DLL_PUBLIC Camera
{
public:
    Camera();
    virtual ~Camera();                           

    void setEye(const GFA::Point3D &eye);
    const GFA::Point3D & getEye() const;
    void setLookAt(const GFA::Point3D &lookAt);
   
    void            computeUVW();

    virtual void    render(TraceThread &rp) const = 0;

protected:
    GFA::Point3D  eye_;
    GFA::Point3D  lookAt_;
    GFA::Vector3D up_;
    GFA::Vector3D u_, v_, w_;
};

typedef std::shared_ptr<Camera> CameraSPtr;

}
//==============================================================================
#endif

