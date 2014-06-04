#include "tracethread.h"
#include "viewplane.h"
#include "scene.h"
#include "sampler.h"
#include "camera.h"
#include "tracer.h"
//==============================================================================
FaaRay::TraceThread::TraceThread()
{
}
//==============================================================================
void FaaRay::TraceThread::render()
{
    CameraSPtr cameraSPtr = sceneSPtr->getCameraSPtr();

    //NOTE: Handle this better
    if (cameraSPtr == 0) {
        std::cout << "Scene has no camera" << std::endl;
        return;
    }

    cameraSPtr->render(*this);
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
