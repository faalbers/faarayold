#include "Ray.h"
//==============================================================================
FaaRay::Ray::Ray()
{
}
//==============================================================================
FaaRay::Ray::Ray(const Ray &rayRef)
    :   origin_(rayRef.origin_),
        direction_(rayRef.direction_)
{
}
//==============================================================================
FaaRay::Ray::Ray(const GFA::Point3D &originRef, const GFA::Vector3D &directionRef)
    :   origin_(originRef),
        direction_(directionRef)
{
}
//==============================================================================
void FaaRay::Ray::setOrigin(const GFA::Point3D &originRef)
{
    origin_ = originRef;
}
//==============================================================================

