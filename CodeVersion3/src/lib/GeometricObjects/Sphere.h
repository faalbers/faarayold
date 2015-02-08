#ifndef __FAARAY_SPHERE_H__
#define __FAARAY_SPHERE_H__
//==============================================================================
#include <memory>
#include "FaaRay/FaaRay.h"
#include "GeometricObject.h"
#include "GFA/GFA.h"
#include "GFA/Point3D.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

class FAARAY_DLL_PUBLIC Sphere : public GeometricObject
{
public:
    Sphere();
    ~Sphere(void);     // destructor

    void setCenter(
        const GFA::Scalar &x,
        const GFA::Scalar &y,
        const GFA::Scalar &z);
    void setRadius(const GFA::Scalar &radius);

    virtual bool hit(TraceThread &ttRef, GFA::Scalar &tmin) const;
    virtual bool shadowHit(TraceThread &ttRef, GFA::Scalar &tmin) const;

private:
    GFA::Point3D    center_;    // center point of the sphere
    GFA::Scalar     radius_;     // sphere radius
    GFA::Scalar     radiusQuad_; // quadratic sphere radius
};

typedef std::shared_ptr<Sphere> SphereSPtr;
SphereSPtr FAARAY_DLL_PUBLIC MakeSphereSPtr();

}
//==============================================================================
#endif
//==============================================================================

