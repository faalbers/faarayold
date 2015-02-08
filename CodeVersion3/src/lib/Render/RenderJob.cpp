#include "RenderJob.h"
#include <stdlib.h>
#include <time.h>
#include "GFA/RGBColor.h"
#include "FaaRay/ViewPlane.h"
#include "FaaRay/Scene.h"
#include "TraceThread.h"
//==============================================================================
FaaRay::RenderJob::RenderJob()
    :   viewPlaneSPtr_(new ViewPlane),
        sceneSPtr_(new Scene),
        multiThread_(false)
{
}
//==============================================================================
FaaRay::RenderJob::~RenderJob()
{
}
//==============================================================================
FaaRay::SceneSPtr FaaRay::RenderJob::getSceneSPtr() const
{
    return sceneSPtr_;
}
//==============================================================================
FaaRay::ViewPlaneSPtr FaaRay::RenderJob::getViewPlaneSPtr() const
{
    return viewPlaneSPtr_;
}
//==============================================================================
void FaaRay::RenderJob::setViewPlaneSPtr(ViewPlaneSPtr viewPlaneSPtr)
{
    viewPlaneSPtr_.reset();
    viewPlaneSPtr_ = viewPlaneSPtr;
}
//==============================================================================  
void FaaRay::RenderJob::setMultiThread()
{
    multiThread_ = true;
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
void FaaRay::RenderJob::setupTraceThread_(TraceThread &ttRef) const
{
    //NOTE: Should be shared pointers ?
    ttRef.viewPlaneSPtr = viewPlaneSPtr_;
    ttRef.sceneSPtr = sceneSPtr_;
    ttRef.samplerSPtr = ttRef.viewPlaneSPtr->getConstSamplerSPtr();
    ttRef.tracerSPtr = ttRef.sceneSPtr->getConstTracerSPtr();
    ttRef.ambientLightSPtr = ttRef.sceneSPtr->getConstAmbientLightSPtr();
    
    // All following could be added to a TraceThread init method
    
    // Optimization variables
    ttRef.width = ttRef.viewPlaneSPtr->width();
    ttRef.height = ttRef.viewPlaneSPtr->height();
    ttRef.halfWidth = ttRef.width * 0.5;
    ttRef.halfHeight = ttRef.height * 0.5;
    ttRef.pixelSize = ttRef.viewPlaneSPtr->pixelSize();
}
//=============================================================================
void FaaRay::RenderJob::renderOneThread_() const
{
    //NOTE: Needs warning
    if (viewPlaneSPtr_ == 0 || sceneSPtr_ == 0) return;
    
    // setup render pixel that will be refferenced through the whole thread
    TraceThread tt;
    setupTraceThread_(tt);

    // Init random seed
    tt.initRandom(0);

    std::size_t max = tt.width * tt.height;
    for ( std::size_t i = 0; i < max; i++ ) {
        tt.x = i % tt.width;
        tt.y = i / tt.width;
        tt.render();
    }
}
//==============================================================================
void FaaRay::RenderJob::renderMultiThread_() const
{
    //NOTE: Needs warning
    if (viewPlaneSPtr_ == 0 || sceneSPtr_ == 0) return;
    
    tbb::parallel_for(
        tbb::blocked_range<size_t>(
            0, viewPlaneSPtr_->width()*viewPlaneSPtr_->height()),
        *this);
}
//=============================================================================
void FaaRay::RenderJob::operator() ( const tbb::blocked_range<std::size_t> &r) const
{
    // setup render thread that will be refferenced through the whole thread
    TraceThread tt;
    setupTraceThread_(tt);

    // Init random seed
    tt.initRandom(r.begin());

    for ( std::size_t i = r.begin(); i != r.end(); ++i ) {
        tt.x = i % tt.width;
        tt.y = i / tt.width;
        tt.render();
    }
}
//=============================================================================

