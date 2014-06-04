#include "raycasttracer.h"
#include "tracethread.h"
//==============================================================================
FaaRay::RayCastTracer::RayCastTracer()
{
}
//==============================================================================
void FaaRay::RayCastTracer::traceRay(TraceThread &ttRef) const
{
}
//==============================================================================
FaaRay::RayCastTracerSPtr FaaRay::MakeRayCastTracerSPtr()
{
    return std::make_shared<RayCastTracer>();
}
