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

/*!
 * \brief The PinholeCamera class
 *
 * Class for a Pinhole type Camera object. The rays will penetrate from the
 * viewplane's pixel positions into the camera's eye position.
 */
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
/*!
 * PinholeCamera Shared Pointer
 */
typedef std::shared_ptr<PinholeCamera>  PinholeCameraSPtr;

/*!
 * PinholeCamera Pointer
 */
typedef PinholeCamera                   *PinholeCameraPtr;

PinholeCameraSPtr FAARAYSHARED_EXPORT MakePinholeCameraSPtr();
}
#endif // FAARAY_PINHOLECAMERA_H
