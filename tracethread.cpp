#include "tracethread.h"
#include "viewplane.h"
//==============================================================================
FaaRay::TraceThread::TraceThread()
{
}
//==============================================================================
void FaaRay::TraceThread::render()
{
    color.r = 0.5;
    color.g = 0.5;
    color.b = 0.5;
    viewPlaneSPtr->setPixel(x, y, color);
}
//==============================================================================
void FaaRay::TraceThread::initRandom(const uint32_t &s)
{
    seedValue_ = s;
    rng_.seed(seedValue_);
}
