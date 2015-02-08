#include "Lights/Light.h"
#include "Utilities/Vector3D.h"

Light::Light(void)
    :   shadows(true)
{}

Light::~Light(void)
{}

Vector3D Light::getDirection(ShadeRec& sr)
{
	return Vector3D(0,0,0);
}

RGBColor Light::L(ShadeRec& sr)
{
	return (black);
}

bool Light::inShadow(const Ray& ray, const ShadeRec& sr) const
{
    return false;
}

double Light::G(ShadeRec& sr) const
{
    return 1.0;
}

double Light::pdf(ShadeRec& sr) const
{
    return 1.0;
}

bool Light::castsShadows(void) const
{
    return shadows;
}

