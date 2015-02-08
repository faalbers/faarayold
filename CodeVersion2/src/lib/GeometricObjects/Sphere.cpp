#include "GeometricObjects/Sphere.h"
#include "Utilities/Maths.h"

Sphere::Sphere(void)
    :   GeometricObject(),
        radius(1)
{
    type = 2;
}

Sphere::Sphere(const Point3D& _center, const double& _radius)
    :   GeometricObject(),
        center(_center),
        radius(_radius)
{
}

Sphere::~Sphere(void)
{
    type = 2;
}

void Sphere::setCenter(const double& x, const double& y, const double& z)
{
    center.x = x;
    center.y = y;
    center.z = z;
}

void Sphere::setCenter(const Point3D& p)
{
    center.x = p.x;
    center.y = p.y;
    center.z = p.z;
}

bool Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
    // page 57
    double t;
    Vector3D temp = ray.origin - center;
    double a = ray.direction * ray.direction;
    double b = 2.0 * (temp * ray.direction);
    double c = (temp * temp) - (radius * radius);
    double disc = (b * b) - (4 * a * c);
    
    if (disc < 0.0)
        return (false);
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom; // smaller root

        if (t > kEpsilon) {
            tmin = t;
            sr.normal       = (temp + ray.direction * t) / radius;
            sr.localHitPoint = ray.origin + ray.direction * t;
            sr.color = color;
            return (true);
        }

        t = (-b + e) / denom; // larger root

        if (t > kEpsilon) {
            tmin = t;
            sr.normal       = (temp + ray.direction * t) / radius;
            sr.localHitPoint = ray.origin + ray.direction * t;
            sr.color = color;
            return (true);
        }
    }
    
    return (false);
}

bool Sphere::shadowHit(const Ray& ray, double& tmin) const
{
    double t;
    Vector3D temp = ray.origin - center;
    double a = ray.direction * ray.direction;
    double b = 2.0 * (temp * ray.direction);
    double c = (temp * temp) - (radius * radius);
    double disc = (b * b) - (4 * a * c);
    
    if (disc < 0.0)
        return (false);
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom; // smaller root

        if (t > kEpsilon) {
            tmin = t;
            return (true);
        }

        t = (-b + e) / denom; // larger root

        if (t > kEpsilon) {
            tmin = t;
            return (true);
        }
    }
    
    return (false);
}

