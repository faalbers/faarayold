#ifndef __SPHERE__
#define __SPHERE__

#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Point3D.h"
#include "Utilities/Ray.h"
#include "Utilities/ShadeRec.h"

class Sphere : public GeometricObject
{
public:
    Sphere(void);      // default constructor
    ~Sphere(void);     // destructor
    Sphere(const Point3D& _center, const double& _radius);   // constructor

    void setCenter(const double& x, const double& y, const double& z);
    void setCenter(const Point3D& p);
    void setRadius(const double& _radius) { radius = _radius; }

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadowHit(const Ray& ray, double& tmin) const;

private:
    Point3D center; // center point of the sphere
    double  radius; // sphere radius
};

#endif

