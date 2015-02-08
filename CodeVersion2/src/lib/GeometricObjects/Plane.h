#ifndef __PLANE__
#define __PLANE__

#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Point3D.h"
#include "Utilities/Normal.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Ray.h"

class Plane : public GeometricObject
{
public:
    Plane(void);      // default constructor
    Plane(const Point3D& _point, const Normal& _normal);   // constructor
    ~Plane(void);     // destructor

    void setPoint(const double& x, const double& y, const double& z);
    void setNormal(const double& x, const double& y, const double& z);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadowHit(const Ray& ray, double& tmin) const;

private:
    Point3D point;  // point through which plane passes
    Normal  normal; // plane normal
};

#endif

