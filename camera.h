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

/*!
 * \brief The Camera base class
 *
 * Base class for Camera object
 */
class FAARAYSHARED_EXPORT Camera
{
public:
    Camera();

    void setEye(const GFA::Point3D &eye);
    void setLookAt(const GFA::Point3D &lookAt);

    virtual void    render(TraceThread &rp) const = 0;

protected:
    GFA::Point3D  eye_;     //!< Position of camera eye
    GFA::Point3D  lookAt_;  //!< Position camera is looking at
    GFA::Vector3D up_;      //!< Up Vector of the camera
    GFA::Vector3D u_;       //!< U Vector of camera
    GFA::Vector3D v_;       //!< V Vector of camera
    GFA::Vector3D w_;       //!< W Vector of camera

    void computeUVW_();
};
typedef std::shared_ptr<Camera> CameraSPtr;
}
#endif // FAARAY_CAMERA_H
