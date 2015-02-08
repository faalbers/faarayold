#ifndef __AREALIGHT__
#define __AREALIGHT__

#include "Lights/Light.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/RGBColor.h"
#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Point3D.h"

class AreaLight : public Light
{
public:
    AreaLight(void);      // default constructor
    virtual ~AreaLight(void);     // destructor

    virtual Vector3D getDirection(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool inShadow(const Ray& ray, const ShadeRec& sr) const;
    virtual double G(ShadeRec& sr) const;
    virtual double pdf(ShadeRec& sr) const;

    void scaleRadiance(const double b) { ls = b; }
    void setLocation(const double x, const double y, const double z);
    void setColor(const double r, const double g, const double b);
    
private:
    GeometricObject*    objectPtr;
    Material*           materialPtr;    // emissive material
    Point3D             samplePoint;    // sample point on the surface
    Normal              lightNormal;    // normal at sample point
    Vector3D            wi;             // unit vector from hit point to sample point

    double ls;
    RGBColor color;
    Point3D location;
};

#endif

