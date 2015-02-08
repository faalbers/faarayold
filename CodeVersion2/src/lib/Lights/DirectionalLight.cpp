#include "Lights/DirectionalLight.h"
#include "Scene/World.h"

DirectionalLight::DirectionalLight(void)
    : Light(),
    ls(1.0),
    color(1.0),
    location(0,0,0),
    direction(0,0,1)
{}

DirectionalLight::~DirectionalLight(void)
{}

Vector3D DirectionalLight::getDirection(ShadeRec& sr)
{
	return direction;
}

RGBColor DirectionalLight::L(ShadeRec& sr)
{
	return (color * ls);
}

void DirectionalLight::setLocation(const double x, const double y, const double z)
{
    location.x = x;
    location.y = y;
    location.z = z;
}

void DirectionalLight::setDirection(const double x, const double y, const double z)
{
    direction.x = x;
    direction.y = y;
    direction.z = z;
    direction.hat();
}

void DirectionalLight::setColor(const double r, const double g, const double b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

bool DirectionalLight::inShadow(const Ray& ray, const ShadeRec& sr) const
{
    double t;
    int numObjects = sr.world.objects.size();

    for (int j = 0; j < numObjects; j++)
        if (sr.world.objects[j]->shadowHit(ray, t))
            return true;
    
    return false;
}

