#include "Materials/EmissiveMaterial.h"
#include "Scene/World.h"
#include "Utilities/Constants.h"
#include "Utilities/Vector3D.h"

EmissiveMaterial::EmissiveMaterial(void)
    : Material(),
      ls(1.0),
      ce(white)
{}

EmissiveMaterial::~EmissiveMaterial(void)
{}

RGBColor EmissiveMaterial::getLe(ShadeRec& sr) const
{
    return black;
}

RGBColor EmissiveMaterial::shade(ShadeRec& sr)
{
    // As long as surface normal is seen by ray
    if (((sr.normal * -1) * sr.vpRay->direction) > 0.0)
        return (ce * ls);
    else
        return black;
}

RGBColor EmissiveMaterial::areaLightShade(ShadeRec& sr)
{
    // As long as surface normal is seen by ray
    if (((sr.normal * -1) * sr.vpRay->direction) > 0.0)
        return (ce * ls);
    else
        return black;
}


