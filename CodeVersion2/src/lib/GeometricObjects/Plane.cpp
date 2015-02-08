#include "GeometricObjects/Plane.h"
#include "Utilities/Constants.h"

Plane::Plane(void)
    :   GeometricObject()
{
    type = 1;
}

Plane::Plane(const Point3D& _point, const Normal& _normal)
    :   GeometricObject(),
        point(_point),
        normal(_normal)
{
    type = 1;
}

Plane::~Plane(void)
{
}

void Plane::setPoint(const double& x, const double& y, const double& z)
{
    point.x = x;
    point.y = y;
    point.z = z;
}

void Plane::setNormal(const double& x, const double& y, const double& z)
{
    normal.x = x;
    normal.y = y;
    normal.z = z;
}

bool Plane::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
    // page 54
    double t = (point - ray.origin) * normal / (ray.direction * normal);

    if (t > kEpsilon) {
        tmin = t;
        sr.normal           = normal;
        sr.localHitPoint    = ray.origin + ray.direction * t;
        sr.color            = color;
        return (true);
    }
    
    return (false);
}

bool Plane::shadowHit(const Ray& ray, double& tmin) const
{
    // page 54
    double t = (point - ray.origin) * normal / (ray.direction * normal);

    if (t > kEpsilon) {
        tmin = t;
        return (true);
    }
    
    return (false);
}


