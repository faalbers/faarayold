#include "Tracers/MultipleObjectsTracer.h"
#include "Utilities/Constants.h"

MultipleObjectsTracer::MultipleObjectsTracer()
    : Tracer()
{
}

MultipleObjectsTracer::MultipleObjectsTracer(World* _worldPtr)
    : Tracer(_worldPtr)
{
}

MultipleObjectsTracer::~MultipleObjectsTracer() 
{}

RGBColor MultipleObjectsTracer::traceRay(const Ray& ray, const int& /*depth*/) const
{
    ShadeRec    sr(worldPtr->hitBareBonesObjects(ray));

    if(sr.hitAnObject) {
        return sr.colorZNormal();
        //return sr.color;
    } else
        return worldPtr->backgroundColor;
}

