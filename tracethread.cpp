#include "tracethread.h"
#include "viewplane.h"
#include "scene.h"
#include "sampler.h"
#include "camera.h"
#include "tracer.h"
#include "material.h"
#include "geometricobject.h"
#include "light.h"
//==============================================================================
FaaRay::TraceThread::TraceThread() :
    viewPlanePtr(0),
    scenePtr(0),
    hitObjectPtr(0),
    srMaterialPtr(0), // gets changed per hit point
    srObjectPtr(0),   // gets changed per hit point
    srLightPtr(0)     // gets changed per hit point
{
}
//==============================================================================
void FaaRay::TraceThread::render()
{
    const Camera *cameraPtr = scenePtr->getConstCameraPtr();

    //NOTE: Handle this better
    if (cameraPtr == 0) {
        std::cout << "Scene has no camera" << std::endl;
        return;
    }

    cameraPtr->render(*this);
    viewPlanePtr->setPixel(x, y, color);
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
