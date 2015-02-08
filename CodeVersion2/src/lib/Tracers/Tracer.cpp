#include "Tracers/Tracer.h"
#include <stdio.h>
#include "Utilities/Maths.h"

Tracer::Tracer()
    : worldPtr(NULL)
{
}

Tracer::Tracer(const World * _worldPointer)
    : worldPtr(_worldPointer)
{
}

Tracer::~Tracer() 
{}

RGBColor Tracer::traceRayMoire(const Ray& ray, const double& mult) const
{
    return RGBColor(0.5 * (1.0 + sin(ray.origin.x * ray.origin.x * ray.origin.y * ray.origin.y * mult)));
}

