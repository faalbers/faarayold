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
class Material;

class GeometricObject
{
public:
    GeometricObject();

    // Set methodes
    void setCenter(
        const GFA::Scalar &x,
        const GFA::Scalar &y,
        const GFA::Scalar &z);
    void setMaterialSPtr(std::shared_ptr<const Material> materialSPtr);

    // Get methods
    const GFA::Point3D & getCenter() const;
    std::shared_ptr<const Material> getMaterialSPtr() const;

    //raytrace methods
    virtual bool hit(TraceThread &ttRef) const = 0;

protected:
    GFA::Point3D    center_;        // center point of object
    std::shared_ptr<const Material>  materialSPtr_;

};
typedef std::shared_ptr<GeometricObject> GeometricObjectSPtr;
}
#endif // FAARAY_GEOMETRICOBJECT_H
