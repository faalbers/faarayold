#ifndef SPHERE_H
#define SPHERE_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/point3d.h"
#include "geometricobject.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class TraceThread;

class Sphere : public GeometricObject
{
public:
    Sphere();

    void setRadius(const GFA::Scalar &radius);

    //raytrace methods
    virtual void hit(TraceThread &ttRef, GFA::Scalar &tmin) const;

private:
    GFA::Scalar     radius_;        // sphere radius
    GFA::Scalar     radiusQuad_;    // quadratic sphere radius
};
typedef std::shared_ptr<Sphere> SphereSPtr;
}
#endif // SPHERE_H
