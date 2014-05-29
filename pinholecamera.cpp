#include "pinholecamera.h"
#include "tracethread.h"
#include "sampler.h"
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
    GFA::Size numSamples = 0;
    std::cout << ttRef.samplerSPtr << std::endl;
    return;
    numSamples = ttRef.samplerSPtr->numSamples();
    std::cout << numSamples << std::endl;

    GFA::Scalar xStart = ttRef.x - ttRef.halfWidth;
    GFA::Scalar yStart = ttRef.y - ttRef.halfHeight;
    return;
    for (GFA::Index j = 0; j < numSamples; j++) {
        //ttRef.sampleIndex = j;
        //ttRef.samplerSPtr->setSampleUnitSquare(ttRef);
        //ttRef.samplePoint.x = (xStart + ttRef.sampleUnitSquare.x) * ttRef.pixelSize;
        //ttRef.samplePoint.y = (yStart + ttRef.sampleUnitSquare.y) * ttRef.pixelSize;
        //setRayDirection(ttRef);
    }

}
//==============================================================================
void FaaRay::PinholeCamera::setRayDirection(TraceThread &ttRef) const
{
    /*
    ttRef.rayDirection =
        u_*ttRef.samplePoint.x +
        v_*ttRef.samplePoint.y -
        w_*viewPlaneDistance_;
    */
    // Optimized way of running above formula
    ttRef.rayDirection.x =
        u_.x*ttRef.samplePoint.x + v_.x*ttRef.samplePoint.y
        - w_.x*viewPlaneDistance_;
    ttRef.rayDirection.y =
        u_.y*ttRef.samplePoint.x + v_.y*ttRef.samplePoint.y
        - w_.y*viewPlaneDistance_;
    ttRef.rayDirection.z =
        u_.z*ttRef.samplePoint.x + v_.z*ttRef.samplePoint.y
        - w_.z*viewPlaneDistance_;

    ttRef.rayDirection.normalize();
}
//==============================================================================
