#ifndef FAARAY_GEOMETRICOBJECT_H
#define FAARAY_GEOMETRICOBJECT_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/gfa.h"
#include "gfa/point3d.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class TraceThread;

class GeometricObject
{
public:
    GeometricObject();

    void setCenter(
        const GFA::Scalar &x,
        const GFA::Scalar &y,
        const GFA::Scalar &z);

    //raytrace methods
    virtual void hit(TraceThread &ttRef, GFA::Scalar &tmin) const = 0;

protected:
    GFA::Point3D    center_;        // center point of object

};
typedef std::shared_ptr<GeometricObject> GeometricObjectSPtr;
}
#endif // FAARAY_GEOMETRICOBJECT_H
