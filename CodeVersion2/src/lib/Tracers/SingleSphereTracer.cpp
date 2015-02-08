#include "Tracers/SingleSphereTracer.h"
#include "Utilities/Constants.h"

SingleSphereTracer::SingleSphereTracer()
    : Tracer()
{
}

SingleSphereTracer::SingleSphereTracer(World* _worldPtr)
    : Tracer(_worldPtr)
{
}

SingleSphereTracer::~SingleSphereTracer() 
{}

RGBColor SingleSphereTracer::traceRay(const Ray& ray) const
{
    ShadeRec    sr(*worldPtr);
    double      t;
    
    if (worldPtr->sphere.hit(ray, t, sr))
        return(red);
    else
        return(worldPtr->backgroundColor);
}

