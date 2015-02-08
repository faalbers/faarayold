#ifndef __DIRECTIONALLIGHT__
#define __DIRECTIONALLIGHT__

#include "Lights/Light.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/RGBColor.h"
#include "Utilities/Vector3D.h"
#include "Utilities/Ray.h"

class DirectionalLight : public Light
{
public:
    DirectionalLight(void);      // default constructor
    virtual ~DirectionalLight(void);     // destructor

    virtual Vector3D getDirection(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool inShadow(const Ray& ray, const ShadeRec& sr) const;

    void scaleRadiance(const double b) { ls = b; }
    void setLocation(const double x, const double y, const double z);
    void setDirection(const double x, const double y, const double z);
    void setColor(const double r, const double g, const double b);

private:
    double      ls;
    RGBColor    color;
    Vector3D    location;
    Vector3D    direction;
};

#endif

