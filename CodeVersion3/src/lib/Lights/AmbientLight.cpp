#include "AmbientLight.h"
#include "FaaRay/TraceThread.h"
#include "GFA/Vector3D.h"
//==============================================================================
FaaRay::AmbientLight::AmbientLight()
    :   ls_(1.0),
        color_(GFA::RGBColor(1.0, 1.0, 1.0))
{
}
//==============================================================================
FaaRay::AmbientLight::~AmbientLight()
{
}
//==============================================================================
void FaaRay::AmbientLight::setLs(const GFA::Scalar &ls)
{
    ls_ = ls;
}
//==============================================================================
void  FaaRay::AmbientLight::getDirection(TraceThread &ttRef) const
{
    ttRef.lDirection = GFA::Vector3D(0.0, 0.0, 0.0);
}
//==============================================================================
void  FaaRay::AmbientLight::inShadow(TraceThread &ttRef) const
{
    ttRef.sRayInShadow = false;
}
//==============================================================================
void  FaaRay::AmbientLight::L(TraceThread &ttRef) const
{
    ttRef.srAmbientL = color_ * ls_;
}
//==============================================================================
FaaRay::AmbientLightSPtr FaaRay::MakeAmbientLightSPtr()
{
    return std::make_shared<AmbientLight>();
}
//==============================================================================

