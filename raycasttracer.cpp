#include "raycasttracer.h"
#include "tracethread.h"
#include "scene.h"
#include "geometricobject.h"
#include "material.h"
//==============================================================================
FaaRay::RayCastTracer::RayCastTracer()
{
}
//==============================================================================
void FaaRay::RayCastTracer::traceRayOpt(TraceThread &ttRef) const
{
    ttRef.sceneSPtr->objectsHit(ttRef, true);
    if(ttRef.hitAnObject) {
        ttRef.srMaterialSPtr = ttRef.hitObjectSPtr->getConstMaterialSPtr();
        ttRef.srHitPoint = ttRef.rayOrigin + ttRef.rayDirection * ttRef.hitDistance;
        ttRef.srNormal = ttRef.hitNormal;

        ttRef.srMaterialSPtr->shadeOpt(ttRef);
    } else {
        ttRef.srColor.r = 0.0; ttRef.srColor.g = 0.0; ttRef.srColor.b = 0.0;
        ttRef.srColor.a = 0.0;
    }
}
//==============================================================================
void FaaRay::RayCastTracer::traceRay(TraceThread &ttRef) const
{
    ttRef.sceneSPtr->objectsHit(ttRef, true);
    if(ttRef.hitAnObject) {
        ttRef.srHitPoint = ttRef.rayOrigin + ttRef.rayDirection * ttRef.hitDistance;
        ttRef.srNormal = ttRef.hitNormal;

        ttRef.hitObjectSPtr->getConstMaterialSPtr()->shade(ttRef);
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
