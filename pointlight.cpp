#include "pointlight.h"
#include "tracethread.h"
//==============================================================================
FaaRay::PointLight::PointLight()
{
}
//==============================================================================
void  FaaRay::PointLight::L(TraceThread &ttRef) const
{
    ttRef.srLightL = color_ * ls_;
}
