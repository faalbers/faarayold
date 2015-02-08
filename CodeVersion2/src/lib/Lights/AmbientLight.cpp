#include "Lights/AmbientLight.h"
#include "Utilities/Constants.h"

AmbientLight::AmbientLight(void)
    : Light(),
    ls(0.3),
    color(white)
{}

AmbientLight::~AmbientLight(void)
{}

Vector3D AmbientLight::getDirection(ShadeRec& sr)
{
	return Vector3D(0,0,0);
}

RGBColor AmbientLight::L(ShadeRec& sr)
{
	return (color * ls);
}


