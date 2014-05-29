#ifndef FAARAY_PINHOLECAMERA_H
#define FAARAY_PINHOLECAMERA_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/gfa.h"
#include "camera.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class TraceThread;

class FAARAYSHARED_EXPORT PinholeCamera : public Camera
{
public:
    PinholeCamera();

    void setViewPlaneDistance(const GFA::Scalar &viewPlaneDistance);
    void setZoom(const GFA::Scalar &zoom);
    void setRayDirection(TraceThread &ttRef) const;

    virtual void render(TraceThread &ttRef) const;

private:
    GFA::Scalar viewPlaneDistance_;
    GFA::Scalar zoom_;
};
typedef std::shared_ptr<PinholeCamera> PinholeCameraSPtr;
}
#endif // FAARAY_PINHOLECAMERA_H
