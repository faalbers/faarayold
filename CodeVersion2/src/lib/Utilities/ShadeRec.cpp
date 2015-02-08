#include "Utilities/ShadeRec.h"
#include "Scene/World.h"
#include "Materials/Material.h"

ShadeRec::ShadeRec(const World& _world)
    :   hitAnObject(false),
        world(_world),
        hitPoint(),localHitPoint(), normal(),
        ray(), depth(0), dir(),
        vpRay(NULL),
        materialPtr(NULL),
        t(0.0)
{
}

// Copy constructor
ShadeRec::ShadeRec(const ShadeRec& sr)
    :   hitAnObject(sr.hitAnObject),
        world(sr.world),
        hitPoint(sr.hitPoint),localHitPoint(sr.localHitPoint), normal(sr.normal),
        ray(sr.ray), depth(sr.depth), dir(sr.dir),
        materialPtr(sr.materialPtr)
{
}

ShadeRec::~ShadeRec(void)
{
}

void ShadeRec::copyData (const ShadeRec& shadeRec)
{
    normal          = shadeRec.normal;
    localHitPoint   = shadeRec.localHitPoint;
    color           = shadeRec.color;
}

RGBColor ShadeRec::colorXNormal(void) const
{
    return color * (normal.x < 0 ? 0.0 : normal.x);
}

RGBColor ShadeRec::colorYNormal(void) const
{
    return color * (normal.y < 0 ? 0.0 : normal.y);
}

RGBColor ShadeRec::colorZNormal(void) const
{
    return color * (normal.z < 0 ? 0.0 : normal.z);
}

RGBColor ShadeRec::colorXYZNormal(void) const
{
    return colorXNormal() * colorYNormal() * colorZNormal() * 3;
}
