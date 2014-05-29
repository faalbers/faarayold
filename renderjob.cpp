#include "renderjob.h"
#include "tracethread.h"
#include "viewplane.h"
#include "scene.h"
#include <iostream>
//==============================================================================
FaaRay::RenderJob::RenderJob() :
    viewPlaneSPtr_(new ViewPlane),
    sceneSPtr_(new Scene),
    multiThread_(false)
{
}
//==============================================================================
FaaRay::SceneSPtr FaaRay::RenderJob::getSceneSPtr() const
{
    return sceneSPtr_;
}
//==============================================================================
void FaaRay::RenderJob::setViewPlaneSPtr(ViewPlaneSPtr viewPlaneSPtr)
{
    viewPlaneSPtr_.reset();
    viewPlaneSPtr_ = viewPlaneSPtr;
}
//==============================================================================
void  FaaRay::RenderJob::render() const
{
    if (multiThread_)
        renderMultiThread_();
    else
        renderOneThread_();
}
//=============================================================================
void FaaRay::RenderJob::renderOneThread_() const
{
    // setup render pixel trace that will be refferenced through the whole
    // thread
    TraceThread tt;
    setupTraceThread_(tt);

    // Init random seed
    tt.initRandom(0);

    // Go through all pixels that neeed to be traced
    std::size_t max = tt.width * tt.height;
    for ( std::size_t i = 0; i < max; i++ ) {
        tt.x = i % tt.width;
        tt.y = i / tt.width;
        tt.render();
    }
}
//=============================================================================
void FaaRay::RenderJob::renderMultiThread_() const
{
}
//==============================================================================
void FaaRay::RenderJob::setMultiThread()
{
    multiThread_ = true;
}
//=============================================================================
void FaaRay::RenderJob::setupTraceThread_(TraceThread &ttRef) const
{
    //NOTE: Should be shared pointers ?
    ttRef.viewPlaneSPtr = viewPlaneSPtr_;
    ttRef.sceneSPtr = sceneSPtr_;
    ttRef.samplerSPtr = ttRef.viewPlaneSPtr->getConstSamplerSPtr();

    // Optimization variables
    ttRef.width = ttRef.viewPlaneSPtr->width();
    ttRef.height = ttRef.viewPlaneSPtr->height();
    ttRef.halfWidth = ttRef.width * 0.5;
    ttRef.halfHeight = ttRef.height * 0.5;
}
