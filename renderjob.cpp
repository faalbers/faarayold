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
        // temporary decide here for Opt or normal version
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
    std::size_t max = tt.viewPlanePtr->width() * tt.viewPlanePtr->height();
    for ( std::size_t i = 0; i < max; i++ ) {
        tt.x = i % tt.viewPlanePtr->width();
        tt.y = i / tt.viewPlanePtr->width();
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
    ttRef.viewPlanePtr = viewPlaneSPtr_.get();
    ttRef.scenePtr = sceneSPtr_.get();
}
