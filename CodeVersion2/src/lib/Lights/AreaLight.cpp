#include "Lights/AreaLight.h"
#include "Scene/World.h"

AreaLight::AreaLight(void)
    : Light(),
    objectPtr(NULL),
    materialPtr(NULL),
    ls(1.0),
    color(1.0),
    location(0,0,0)
{}

AreaLight::~AreaLight(void)
{}

const char   Light::ltype[] = "AreaLight";

Vector3D AreaLight::getDirection(ShadeRec& sr)
{
	return ((location - sr.hitPoint).hat());
}

RGBColor AreaLight::L(ShadeRec& s)
{
	return (color * ls);
}

void AreaLight::setLocation(const double x, const double y, const double z)
{
    location.x = x;
    location.y = y;
    location.z = z;
}

void AreaLight::setColor(const double r, const double g, const double b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

bool AreaLight::inShadow(const Ray& ray, const ShadeRec& sr) const
{
    double t;
    int numObjects = sr.world.objects.size();
    double d = location.distance(ray.origin);

    for (int j = 0; j < numObjects; j++)
        if (sr.world.objects[j]->shadowHit(ray, t) && t < d)
            return true;
    
    return false;
}

