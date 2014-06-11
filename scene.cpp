#include "scene.h"
#include "camera.h"
#include "geometricobject.h"
#include "light.h"
#include "tracer.h"
#include "tracethread.h"
//==============================================================================
FaaRay::Scene::Scene()
{
}
//==============================================================================
void FaaRay::Scene::setCamera(CameraSPtr cameraSPtr)
{
    cameraSPtr_ = cameraSPtr;
    //cameraSPtr_->computeUVW();
}
//==============================================================================
void FaaRay::Scene::setTracer(TracerSPtr tracerSPtr)
{
    tracerSPtr_ = tracerSPtr;
}
//==============================================================================
void FaaRay::Scene::setAmbientLight(LightSPtr ambientLightSPtr)
{
    ambientLightSPtr_ = ambientLightSPtr;
}
//==============================================================================
void FaaRay::Scene::addObject(GeometricObjectSPtr objectSPtr)
{
    objectSPtrs_.push_back(objectSPtr);
}
//==============================================================================
void FaaRay::Scene::addLight(LightSPtr lightSPtr)
{
    lightSPtrs_.push_back(lightSPtr);
}
//==============================================================================
FaaRay::CameraSPtr FaaRay::Scene::getCameraSPtr() const
{
    return cameraSPtr_;
}
//==============================================================================
FaaRay::ConstTracerSPtr FaaRay::Scene::getConstTracerSPtr() const
{
    return tracerSPtr_;
}
//==============================================================================
FaaRay::ConstLightSPtr FaaRay::Scene::getConstAmbientLightSPtr() const
{
    return ambientLightSPtr_;
}
//==============================================================================
std::vector<std::shared_ptr<FaaRay::Light>> FaaRay::Scene::getLightsSPtrs() const
{
    return lightSPtrs_;
}
//==============================================================================
void FaaRay::Scene::hitObjects(TraceThread &ttRef) const
{
    GFA::Scalar t;
    GFA::Scalar tmin = GFA::HUGE_SCALAR;
    GFA::Index  closestHit = 0;

    // Find closest hit
    ttRef.srHitAnObject = false;
    for (GFA::Index j = 0; j < objectSPtrs_.size(); j++) {
        objectSPtrs_[j]->hit(ttRef, t);
        if (ttRef.srHitAnObject && (t < tmin)) {
            ttRef.srHitAnObject = true;
            tmin = t;
            closestHit = j;
        }
    }

    if (ttRef.srHitAnObject) {
        // no need to delete prior srMaterialSPtr, this happens automatically
        ttRef.srMaterialSPtr = objectSPtrs_[closestHit]->getMaterialSPtr();
        ttRef.srHitPoint = ttRef.rayOrigin + ttRef.rayDirection * t;
    }
}
