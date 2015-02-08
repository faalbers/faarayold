#ifndef __FAARAY_GEOMETRICOBJECT_H__
#define __FAARAY_GEOMETRICOBJECT_H__
//==============================================================================
#include <memory>
#include "GFA/GFA.h"
#include "FaaRay/FaaRay.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;
class Material;

class FAARAY_DLL_PUBLIC GeometricObject
{
public:
    GeometricObject();      // default constructor
    ~GeometricObject();     // destructor
    
    virtual bool hit(TraceThread &ttRef, GFA::Scalar &tmin) const = 0;
    virtual bool shadowHit(TraceThread &ttRef, GFA::Scalar &tmin) const = 0;

    void setMaterialSPtr(std::shared_ptr<const Material> materialSPtr);
    std::shared_ptr<const Material> getMaterialSPtr() const;
    
protected:
    std::shared_ptr<const Material>  materialSPtr_;
};

typedef std::shared_ptr<GeometricObject> GeometricObjectSPtr;

}
//==============================================================================
#endif
//==============================================================================

