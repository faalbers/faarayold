#include "GeometricObjects/Rectangle.h"
#include "Utilities/Constants.h"

Rectangle::Rectangle(void)
    :   GeometricObject(),
        corner(-1, 0, -1), 
        sideA(0, 0, 2), sideB(2, 0, 0),
        sideALength(2), sideBLength(2),
		normal(0, 1, 0)
{
    type = 1;
}

Rectangle::Rectangle(const Point3D& _corner, const Vector3D& _sideA, const Vector3D& _sideB)
    :   GeometricObject(),
        corner(_corner), 
        sideA(_sideA), sideB(_sideB)
{
    type = 1;
    normal = sideA ^ sideB;
    sideALength = sideA.length()*sideA.length();
    sideBLength = sideB.length()*sideB.length();
	normal.normalize();
}

Rectangle::~Rectangle(void)
{
}

void Rectangle::setCorner(const double& x, const double& y, const double& z)
{
    corner.x = x;
    corner.y = y;
    corner.z = z;
}

void Rectangle::setNormal(const double& x, const double& y, const double& z)
{
    normal.x = x;
    normal.y = y;
    normal.z = z;
}

bool Rectangle::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
    double t = (corner - ray.origin) * normal / (ray.direction * normal);

	if (t <= kEpsilon)
		return (false);

    Point3D localHitPoint = ray.origin + ray.direction * t;

    Vector3D fromCornerV = localHitPoint - corner;
	
	double ddota = fromCornerV * sideA;
	
	if (ddota < 0.0 || ddota > sideALength)
		return (false);
		
	double ddotb = fromCornerV * sideB;
	
	if (ddotb < 0.0 || ddotb > sideBLength)
		return (false);

    tmin = t;
    sr.localHitPoint    = localHitPoint;
    sr.normal           = normal;
    sr.color            = color;

    return (true);
}

bool Rectangle::shadowHit(const Ray& ray, double& tmin) const
{
    double t = (corner - ray.origin) * normal / (ray.direction * normal);

	if (t <= kEpsilon)
		return (false);

    Point3D localHitPoint = ray.origin + ray.direction * t;

    Vector3D fromCornerV = localHitPoint - corner;
	
	double ddota = fromCornerV * sideA;
	
	if (ddota < 0.0 || ddota > sideALength)
		return (false);
		
	double ddotb = fromCornerV * sideB;
	
	if (ddotb < 0.0 || ddotb > sideBLength)
		return (false);

    return (true);
}


