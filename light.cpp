#include "light.h"
//==============================================================================
FaaRay::Light::Light()
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
