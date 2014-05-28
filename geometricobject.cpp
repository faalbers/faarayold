#include "geometricobject.h"
//==============================================================================
FaaRay::GeometricObject::GeometricObject()
{
}
//==============================================================================
void FaaRay::GeometricObject::setCenter(
    const GFA::Scalar &x,
    const GFA::Scalar &y,
    const GFA::Scalar &z)
{
    center_.x = x;
    center_.y = y;
    center_.z = z;
}
