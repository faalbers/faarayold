#ifndef __FAARAY_PINHOLECAMERA_H__
#define __FAARAY_PINHOLECAMERA_H__
//==============================================================================
#include <memory>
#include "Camera.h"
#include "FaaRay/FaaRay.h"
#include "GFA/GFA.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

class FAARAY_DLL_PUBLIC PinholeCamera : public Camera
{
public:
    //PinholeCamera();
    virtual ~PinholeCamera();

    void setViewPlaneDistance(const GFA::Scalar &viewPlaneDistance);
    void setZoom(const GFA::Scalar &zoom);
    
    void setRayDirection(TraceThread &ttRef) const;

    virtual void render(TraceThread &ttRef) const;
 
private:
    GFA::Scalar viewPlaneDistance_;
    GFA::Scalar zoom_;
};

typedef std::shared_ptr<PinholeCamera> PinholeCameraSPtr;
PinholeCameraSPtr FAARAY_DLL_PUBLIC MakePinholeCameraSPtr();

}
//==============================================================================
#endif
//==============================================================================
