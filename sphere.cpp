#include "sphere.h"
#include "tracethread.h"
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
//==============================================================================
bool FaaRay::Sphere::hit(TraceThread &ttRef) const
{
    // page 57
    GFA::Vector3D temp = ttRef.rayOrigin - center_;
    GFA::Scalar b = 2.0 * (temp * ttRef.rayDirection);
    GFA::Scalar c = (temp * temp) - radiusQuad_;
    GFA::Scalar disc = (b * b) - (4 * c);

    if (disc < 0.0) {
        return false;
    } else {
        GFA::Scalar t;
        GFA::Scalar e = sqrt(disc);
        t = (-b - e) / 2.0; // smaller root
        if (t <= GFA::EPSILON)
            t = (-b + e) / 2.0; // larger root
        if (t <= GFA::EPSILON)
            return false;

        ttRef.hitDistance = t;
        ttRef.hitNormal = (temp + ttRef.rayDirection * t) / radius_;
    }

    return true;
}
//==============================================================================
FaaRay::SphereSPtr FaaRay::MakeSphereSPtr()
{
    return std::make_shared<Sphere>();
}
