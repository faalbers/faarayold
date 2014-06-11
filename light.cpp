#include "light.h"
#include "tracethread.h"
//==============================================================================
FaaRay::Light::Light() :
    ls_(1.0),
    color_(GFA::RGBColor(1.0, 1.0, 1.0)),
    shadows_(false)
{
}
//==============================================================================
void FaaRay::Light::setCenter(
    const GFA::Scalar &x,
    const GFA::Scalar &y,
    const GFA::Scalar &z)
{
    center_.x = x;
    center_.y = y;
    center_.z = z;
}
//==============================================================================
void FaaRay::Light::setLs(const GFA::Scalar &ls)
{
    ls_ = ls;
}
//==============================================================================
void  FaaRay::Light::getDirection(TraceThread &ttRef) const
{
    ttRef.lDirection = center_ - ttRef.srHitPoint;
    ttRef.lDirection.normalize();
}
//==============================================================================
const bool & FaaRay::Light::castsShadows() const
{
    return shadows_;
}
