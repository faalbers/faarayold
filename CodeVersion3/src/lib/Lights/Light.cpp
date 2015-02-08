#include "Light.h"
#include "FaaRay/TraceThread.h"
//==============================================================================
FaaRay::Light::Light()
    :   shadows_(true)
{
}
//==============================================================================
FaaRay::Light::~Light()
{
}
//==============================================================================
const bool & FaaRay::Light::castsShadows() const
{
    return shadows_;
}
//==============================================================================
void FaaRay::Light::castShadows(const bool &shadows)
{
    shadows_ = shadows;
}


