#include "tracethread.h"
//==============================================================================
FaaRay::TraceThread::TraceThread()
{
}
//==============================================================================
void FaaRay::TraceThread::initRandom(const uint32_t &s)
{
    seedValue_ = s;
    rng_.seed(seedValue_);
}
