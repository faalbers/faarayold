#ifndef FAARAY_LIGHT_H
#define FAARAY_LIGHT_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/gfa.h"
#include "gfa/point3d.h"
#include "gfa/rgbcolor.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class TraceThread;

class FAARAYSHARED_EXPORT Light
{
public:
    Light();

    void setCenter(
        const GFA::Scalar &x,
        const GFA::Scalar &y,
        const GFA::Scalar &z);
    void setLs(const GFA::Scalar &ls);

    void getDirection(TraceThread &ttRef) const;

    virtual void L(TraceThread &ttRef) const = 0;

    const bool & castsShadows() const;

protected:
    GFA::Point3D    center_;        // center point of object
    GFA::Scalar     ls_;     // light strength
    GFA::RGBColor   color_;  // light color
    bool            shadows_;
};
typedef std::shared_ptr<Light> LightSPtr;
typedef std::shared_ptr<const Light> ConstLightSPtr;
}
#endif // FAARAY_LIGHT_H
