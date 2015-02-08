#ifndef __OPENCYLINDER__
#define __OPENCYLINDER__

#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Ray.h"
#include "Utilities/ShadeRec.h"

class OpenCylinder : public GeometricObject
{
public:
    OpenCylinder(void);      // default constructor
    OpenCylinder(const double bottom, const double top, const double radius);
    ~OpenCylinder(void);     // destructor

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadowHit(const Ray& ray, double& tmin) const;

private:
    double  y0;         // bottom y value
    double  y1;         // top y value
    double  radius;     // sphere radius
    double  invRadius;  // one over the radius
};

#endif

