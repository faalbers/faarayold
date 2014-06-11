#include "raycasttracer.h"
#include "tracethread.h"
#include "scene.h"
#include "material.h"
//==============================================================================
FaaRay::RayCastTracer::RayCastTracer()
{
}
//==============================================================================
void FaaRay::RayCastTracer::traceRay(TraceThread &ttRef) const
{
    ttRef.sceneSPtr->hitObjects(ttRef);
    if(ttRef.srHitAnObject) {
        ttRef.srMaterialSPtr->shade(ttRef);
        //ttRef.srColor.r = 1.0; ttRef.srColor.g = 1.0; ttRef.srColor.b = 1.0;
        //ttRef.srColor.a = 1.0;
    } else {
        ttRef.srColor.r = 0.0; ttRef.srColor.g = 0.0; ttRef.srColor.b = 0.0;
        ttRef.srColor.a = 0.0;
    }
}
//==============================================================================
FaaRay::RayCastTracerSPtr FaaRay::MakeRayCastTracerSPtr()
{
    return std::make_shared<RayCastTracer>();
}
