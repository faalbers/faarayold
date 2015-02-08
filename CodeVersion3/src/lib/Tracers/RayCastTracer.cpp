//==============================================================================
#include "RayCastTracer.h"
#include "FaaRay/TraceThread.h"
#include "FaaRay/Scene.h"
#include "FaaRay/Material.h"
//==============================================================================
FaaRay::RayCastTracer::~RayCastTracer()
{
}
//==============================================================================
void FaaRay::RayCastTracer::traceRay(TraceThread &ttRef) const
{
    ttRef.sceneSPtr->hitObjects(ttRef);
    if(ttRef.srHitAnObject) {
        ttRef.srMaterialSPtr->shade(ttRef);
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
//==============================================================================

