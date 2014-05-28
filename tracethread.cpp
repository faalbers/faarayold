#include "tracethread.h"
#include "viewplane.h"
#include "scene.h"
#include "camera.h"
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
