#include "PointLight.h"
#include "FaaRay/TraceThread.h"
//==============================================================================
FaaRay::PointLight::PointLight()
    :   ls_(1.0),
        color_(GFA::RGBColor(1.0, 1.0, 1.0))
{
}
//==============================================================================
FaaRay::PointLight::~PointLight()
{
}
//==============================================================================
void FaaRay::PointLight::setCenter(
    const GFA::Scalar &x,
    const GFA::Scalar &y,
    const GFA::Scalar &z)
{
    center_.x = x;
    center_.y = y;
    center_.z = z;
}
//==============================================================================
void  FaaRay::PointLight::getDirection(TraceThread &ttRef) const
{
    ttRef.lDirection = center_ - ttRef.srHitPoint;
    ttRef.lDirection.normalize();
}
//==============================================================================
void  FaaRay::PointLight::inShadow(TraceThread &ttRef) const
{
    if ( castsShadows() ) {
        ttRef.sRayInShadow = false;
    } else
        ttRef.sRayInShadow = false;
}
//==============================================================================
void  FaaRay::PointLight::L(TraceThread &ttRef) const
{
    ttRef.srLightL = color_ * ls_;
}
//==============================================================================
FaaRay::PointLightSPtr FaaRay::MakePointLightSPtr()
{
    return std::make_shared<PointLight>();
}
//==============================================================================
/*
    double t;
    int numObjects = sr.world.objects.size();
    double d = location.distance(ray.origin);

    for (int j = 0; j < numObjects; j++)
        if (sr.world.objects[j]->shadowHit(ray, t) && t < d)
            return true;
    
    return false;
*/
