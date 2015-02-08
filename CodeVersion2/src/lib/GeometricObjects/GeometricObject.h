#ifndef __GEOMETRICOBJECT__
#define __GEOMETRICOBJECT__

#include "Utilities/Ray.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/RGBColor.h"
#include "Materials/Material.h"

class GeometricObject
{
public:
    GeometricObject(void);      // default constructor
    ~GeometricObject(void);     // destructor
    
    int type;

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const = 0;
    virtual bool shadowHit(const Ray& ray, double& tmin) const = 0;

    void setColor(const float& r, const float& g, const float& b);
    RGBColor getColor() const { return color; }

    Material* getMaterial(void) const;
    void setMaterial(Material* _materialPtr);
    
protected:
    mutable Material*   materialPtr;   // mutable allows the const functions Compound::hit, Instance::hit, and RegularGrid::hit to assign to material_ptr
    RGBColor            color;          // only used for barebones
};

#endif

