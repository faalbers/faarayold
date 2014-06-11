#include "ambientlight.h"
#include "tracethread.h"
//==============================================================================
FaaRay::AmbientLight::AmbientLight()
{
}
//==============================================================================
void  FaaRay::AmbientLight::L(TraceThread &ttRef) const
{
    ttRef.srAmbientL = color_ * ls_;
}
//==============================================================================
FaaRay::AmbientLightSPtr FaaRay::MakeAmbientLightSPtr()
{
    return std::make_shared<AmbientLight>();
}
