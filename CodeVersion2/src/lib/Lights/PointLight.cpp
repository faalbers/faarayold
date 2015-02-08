#include "Lights/PointLight.h"
#include "Scene/World.h"

PointLight::PointLight(void)
    :   Light(),
        ls(1.0),
        color(1.0),
        location(0,0,0)
{}

PointLight::~PointLight(void)
{}

Vector3D PointLight::getDirection(ShadeRec& sr)
{
	return ((location - sr.hitPoint).hat());
}

RGBColor PointLight::L(ShadeRec& s)
{
	return (color * ls);
}

void PointLight::setLocation(const double x, const double y, const double z)
{
    location.x = x;
    location.y = y;
    location.z = z;
}

void PointLight::setColor(const double r, const double g, const double b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

bool PointLight::inShadow(const Ray& ray, const ShadeRec& sr) const
{
    double t;
    int numObjects = sr.world.objects.size();
    double d = location.distance(ray.origin);

    for (int j = 0; j < numObjects; j++)
        if (sr.world.objects[j]->shadowHit(ray, t) && t < d)
            return true;
    
    return false;
}

