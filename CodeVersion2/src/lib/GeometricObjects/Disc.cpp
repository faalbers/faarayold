#include "Disc.h"
#include "Utilities/Constants.h"

Disc::Disc(void)
    :   GeometricObject()
{
    type = 1;
}

Disc::Disc(const Point3D& _point, const Normal& _normal, const double& _radius)
    :   GeometricObject(),
        point(_point),
        normal(_normal),
        radius(_radius)
{
    type = 1;
}

Disc::~Disc(void)
{
}

void Disc::setPoint(const double& x, const double& y, const double& z)
{
    point.x = x;
    point.y = y;
    point.z = z;
}

void Disc::setNormal(const double& x, const double& y, const double& z)
{
    normal.x = x;
    normal.y = y;
    normal.z = z;
}

bool Disc::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
    double t = (point - ray.origin) * normal / (ray.direction * normal);

	if (t <= kEpsilon)
		return (false);

    Point3D localHitPoint = ray.origin + ray.direction * t;
    if ( (localHitPoint - point).length() > radius )
        return (false);

    tmin = t;
    sr.localHitPoint    = localHitPoint;
    sr.normal           = normal;
    sr.color            = color;

    return (true);
}

bool Disc::shadowHit(const Ray& ray, double& tmin) const
{
    double t = (point - ray.origin) * normal / (ray.direction * normal);

	if (t <= kEpsilon)
		return (false);

    Point3D localHitPoint = ray.origin + ray.direction * t;
    if ( (localHitPoint - point).length() > radius )
        return (false);

    return (true);
}


