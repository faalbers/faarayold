#include "pinholecamera.h"
#include "tracethread.h"
//==============================================================================
FaaRay::PinholeCamera::PinholeCamera()
{
}
//==============================================================================
void FaaRay::PinholeCamera::setViewPlaneDistance(
    const GFA::Scalar &viewPlaneDistance)
{
    viewPlaneDistance_ = viewPlaneDistance;
}
//==============================================================================
void FaaRay::PinholeCamera::setZoom(const GFA::Scalar &zoom)
{
    zoom_ = zoom;
}
//==============================================================================
void FaaRay::PinholeCamera::render(TraceThread &ttRef) const
{
    // best optimization for more samples
    ttRef.color.r = 0.0; ttRef.color.g = 0.0; ttRef.color.b = 0.0;
    ttRef.color.a = 0.0;
    ttRef.rayOrigin = eye_;
    //GFA::Size numSamples = ttRef.samplerSPtr->numSamples();

}
