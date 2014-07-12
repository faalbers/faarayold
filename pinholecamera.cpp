#include "pinholecamera.h"
#include "tracethread.h"
#include "sampler.h"
#include "tracer.h"
#include "viewplane.h"
#include "scene.h"
//==============================================================================
/*!
 * Constructor that sets the up vector with Y Up and compute UVW.
 */
FaaRay::PinholeCamera::PinholeCamera() :
    Camera()
{
}
//==============================================================================
/*!
 * Set distance between camera's eye and the viewplane.
 *
 * \param viewPlaneDistance Distance between camera's eye and the viewplane
 */
void FaaRay::PinholeCamera::setViewPlaneDistance(
    const GFA::Scalar &viewPlaneDistance)
{
    viewPlaneDistance_ = viewPlaneDistance;
}
//==============================================================================
/*!
 * Set Zoom for the camera. Not used yet.
 *
 * \param zoom Zoom value
 */
void FaaRay::PinholeCamera::setZoom(const GFA::Scalar &zoom)
{
    zoom_ = zoom;
}
//==============================================================================
/*!
 * Trace a ray for each sample on the viewplane's pixel. All info will be
 * gathered from and written to the TraceThread.
 *
 * \param ttRef Referenced TraceThread
 */
void FaaRay::PinholeCamera::render(TraceThread &ttRef) const
{
    //! Get tracer and sampler info from the TraceThread
    const Sampler   *samplerPtr = ttRef.viewPlanePtr->getConstSamplerPtr();
    const Tracer    *tracerPtr = ttRef.scenePtr->getConstTracerPtr();
    GFA::Size numSamples = samplerPtr->numSamples();

    //! Initialize color to black
    ttRef.color.r = 0.0; ttRef.color.g = 0.0; ttRef.color.b = 0.0;
    ttRef.color.a = 0.0;
    ttRef.rayOrigin = eye_;

    //! Distribute rays for each sample based on the sampler
    GFA::Scalar xStart = ttRef.x - ttRef.viewPlanePtr->width() * 0.5;
    GFA::Scalar yStart = ttRef.y - ttRef.viewPlanePtr->height() * 0.5;
    for (GFA::Index j = 0; j < numSamples; j++) {
        ttRef.sampleIndex = j;

        //! Find a position in the pixel's Unit Square
        samplerPtr->setSampleUnitSquare(ttRef);
        ttRef.samplePoint.x = (xStart + ttRef.sampleUnitSquare.x)
                * ttRef.viewPlanePtr->pixelSize();
        ttRef.samplePoint.y = (yStart + ttRef.sampleUnitSquare.y)
                * ttRef.viewPlanePtr->pixelSize();

        //! Calculate ray direction from camera eye to viewplane pixel position.
        setRayDirection(ttRef);

        //! Trace the ray
        tracerPtr->traceRay(ttRef);

        //! Add color from ray trace to pixel color
        ttRef.color += ttRef.srColor;
    }

    //! Average added pixel colors with amount of samples and wite into the
    //! TraceThread.
    ttRef.color /= numSamples;
}
//==============================================================================
/*!
 * Set the ray direction between the camera's eye and position on the viewplane
 * The current viewplane information is gathered from the TraceThread object.
 * Results are witten into the TraceThread object.
 *
 * \param ttRef Referenced TraceThread
 */
void FaaRay::PinholeCamera::setRayDirection(TraceThread &ttRef) const
{
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
/*!
 * Function to create a new PinholeCamera and return it's address pointer as
 * a shared pointer.
 *
 * \return PinholeCameraSPtr , a shared pointer of a PinholeCamera object.
 */
FaaRay::PinholeCameraSPtr FaaRay::MakePinholeCameraSPtr()
{
    return std::make_shared<PinholeCamera>();
}
