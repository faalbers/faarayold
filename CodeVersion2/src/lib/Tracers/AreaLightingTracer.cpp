#include "Tracers/AreaLightingTracer.h"
#include "Utilities/Constants.h"


AreaLightingTracer::AreaLightingTracer()
    : Tracer()
{
}

AreaLightingTracer::AreaLightingTracer(const World* _worldPtr)
    : Tracer(_worldPtr)
{
}

AreaLightingTracer::~AreaLightingTracer() 
{}

RGBColor AreaLightingTracer::traceRay(Ray& ray) const
{
    ShadeRec    sr(worldPtr->hitObjects(ray));
    
    if(sr.hitAnObject) {
        sr.vpRay = &ray;   // for specular reflection
        return sr.materialPtr->areaLightShade(sr);
    } else {
        return worldPtr->backgroundColor;
    }
}

