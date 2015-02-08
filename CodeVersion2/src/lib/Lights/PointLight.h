#ifndef __POINTLIGHT__
#define __POINTLIGHT__

#include "Lights/Light.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/RGBColor.h"
#include "Utilities/Point3D.h"

class PointLight : public Light
{
public:
    PointLight(void);      // default constructor
    virtual ~PointLight(void);     // destructor

    virtual const char* type(void) const { return "PointLight"; }
    virtual Vector3D getDirection(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool inShadow(const Ray& ray, const ShadeRec& sr) const;

    void scaleRadiance(const double b) { ls = b; }
    void setLocation(const double x, const double y, const double z);
    void setColor(const double r, const double g, const double b);
    
private:
    double      ls;
    RGBColor    color;
    Point3D     location;
};

#endif

