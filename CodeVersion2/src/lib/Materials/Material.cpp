#include "Materials/Material.h"
#include "Utilities/Constants.h"

Material::Material(void)
{}

Material::~Material(void)
{}

RGBColor Material::getLe(ShadeRec& sr) const
{
    return black;
}

RGBColor Material::areaLightShade(ShadeRec& sr)
{
    return black;
}


