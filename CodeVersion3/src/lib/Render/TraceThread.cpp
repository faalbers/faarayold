#include "TraceThread.h"
#include "FaaRay/ViewPlane.h"
#include "FaaRay/Scene.h"
#include "FaaRay/Sampler.h"
#include "FaaRay/Camera.h"
#include "FaaRay/Tracer.h"
#include "FaaRay/Light.h"
#include "FaaRay/Material.h"
//==============================================================================
FaaRay::TraceThread::TraceThread()
{
}
//==============================================================================
void FaaRay::TraceThread::render()
{
    sceneSPtr->getCameraSPtr()->render(*this);
    viewPlaneSPtr->setPixel(x, y, color);
}
//==============================================================================
void FaaRay::TraceThread::initRandom(const uint32_t &s)
{
    seedValue_ = s;
    rng_.seed(seedValue_);
}
//==============================================================================
GFA::Scalar FaaRay::TraceThread::rand()
{
    return distribution(rng_);
}
//==============================================================================

