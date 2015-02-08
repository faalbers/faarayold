#ifndef __FAARAY_POINTLIGHT_H__
#define __FAARAY_POINTLIGHT_H__
//==============================================================================
#include "Light.h"
#include <memory>
#include "FaaRay/FaaRay.h"
#include "GFA/GFA.h"
#include "GFA/RGBColor.h"
#include "GFA/Point3D.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

class FAARAY_DLL_PUBLIC PointLight : public Light
{
public:
    PointLight();
    virtual ~PointLight();

    void setCenter(
        const GFA::Scalar &x,
        const GFA::Scalar &y,
        const GFA::Scalar &z);

    virtual void getDirection(TraceThread &ttRef) const;
    virtual void L(TraceThread &ttRef) const;
    virtual void inShadow(TraceThread &ttRef) const;    

private:
    GFA::Point3D    center_; // center point of the point light
    GFA::Scalar     ls_;     // light strength
    GFA::RGBColor   color_;  // light color
};

typedef std::shared_ptr<PointLight>  PointLightSPtr;
PointLightSPtr FAARAY_DLL_PUBLIC MakePointLightSPtr();

}
//==============================================================================
#endif

