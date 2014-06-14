#ifndef FAARAY_SPHERE_H
#define FAARAY_SPHERE_H
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
    virtual bool hit(TraceThread &ttRef) const;

private:
    GFA::Scalar     radius_;        // sphere radius
    GFA::Scalar     radiusQuad_;    // quadratic sphere radius
};
typedef std::shared_ptr<Sphere> SphereSPtr;
SphereSPtr MakeSphereSPtr();
}
#endif // FAARAY_SPHERE_H
