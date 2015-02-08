#include "Tracers/RayCastTracer.h"
#include "Utilities/Constants.h"


RayCastTracer::RayCastTracer()
    : Tracer()
{
}

RayCastTracer::RayCastTracer(const World * _worldPtr)
    : Tracer(_worldPtr)
{
}

RayCastTracer::~RayCastTracer() 
{}

RGBColor RayCastTracer::traceRay(Ray& ray) const
{
    ShadeRec    sr(worldPtr->hitObjects(ray));
    
    if(sr.hitAnObject) {
        sr.vpRay = &ray;   // for specular reflection
        return sr.materialPtr->shade(sr);
    } else {
        return worldPtr->backgroundColor;
    }
}

