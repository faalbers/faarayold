#include "pinholecamera.h"
#include "tracethread.h"
#include "sampler.h"
#include "tracer.h"
#include "viewplane.h"
#include "scene.h"
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
    // Get tracer and sampler info
    const Sampler   *samplerPtr = ttRef.viewPlanePtr->getConstSamplerPtr();
    const Tracer    *tracerPtr = ttRef.scenePtr->getConstTracerPtr();
    GFA::Size numSamples = samplerPtr->numSamples();

    // Initialize color
    ttRef.color.r = 0.0; ttRef.color.g = 0.0; ttRef.color.b = 0.0;
    ttRef.color.a = 0.0;
    ttRef.rayOrigin = eye_;

    // distribute rays for each sample based on the sampler
    GFA::Scalar xStart = ttRef.x - ttRef.viewPlanePtr->width() * 0.5;
    GFA::Scalar yStart = ttRef.y - ttRef.viewPlanePtr->height() * 0.5;
    for (GFA::Index j = 0; j < numSamples; j++) {
        ttRef.sampleIndex = j;
        samplerPtr->setSampleUnitSquare(ttRef);
        ttRef.samplePoint.x = (xStart + ttRef.sampleUnitSquare.x)
                * ttRef.viewPlanePtr->pixelSize();
        ttRef.samplePoint.y = (yStart + ttRef.sampleUnitSquare.y)
                * ttRef.viewPlanePtr->pixelSize();
        setRayDirection(ttRef);
        tracerPtr->traceRay(ttRef);
        ttRef.color += ttRef.srColor;
    }
    ttRef.color /= numSamples;
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
FaaRay::PinholeCameraSPtr FaaRay::MakePinholeCameraSPtr()
{
    return std::make_shared<PinholeCamera>();
}
