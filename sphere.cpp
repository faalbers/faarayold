#include "sphere.h"
//==============================================================================
FaaRay::Sphere::Sphere()
{
}
//==============================================================================
void FaaRay::Sphere::setRadius(const GFA::Scalar &radius)
{
    radius_ = radius;
    radiusQuad_ = radius_*radius_;
}
