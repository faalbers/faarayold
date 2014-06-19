#include "scene.h"
#include "camera.h"
#include "geometricobject.h"
#include "light.h"
#include "tracer.h"
#include "tracethread.h"
#include "material.h"
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
const FaaRay::Camera * FaaRay::Scene::getConstCameraPtr() const
{
    return cameraSPtr_.get();
}
//==============================================================================
const FaaRay::Tracer * FaaRay::Scene::getConstTracerPtr() const
{
    return tracerSPtr_.get();
}
//==============================================================================
const FaaRay::Light * FaaRay::Scene::getConstAmbientLightPtr() const
{
    return ambientLightSPtr_.get();
}
//==============================================================================
std::vector<std::shared_ptr<FaaRay::Light>> FaaRay::Scene::getLightsSPtrs() const
{
    return lightSPtrs_;
}
//==============================================================================
void FaaRay::Scene::objectsHit(TraceThread &ttRef, bool closest) const
{
    GFA::Scalar tmin = GFA::HUGE_SCALAR;
    GFA::Index  closestHit = 0;

    // Find closest hit
    ttRef.hitAnObject = false;
    for (GFA::Index j = 0; j < objectSPtrs_.size(); j++) {
        if (objectSPtrs_[j]->hit(ttRef) && (ttRef.hitDistance < tmin)) {
            ttRef.hitAnObject = true;
            tmin = ttRef.hitDistance;
            // optimize if closest objects is not needed
            if (!closest) return;
            closestHit = j;
        }
    }

    if (ttRef.hitAnObject) {
        ttRef.hitObjectPtr = objectSPtrs_[closestHit].get();
        ttRef.hitDistance = tmin;
    }
}
//==============================================================================
void FaaRay::Scene::lightsShade(TraceThread &ttRef) const
{
    std::vector<std::shared_ptr<Light>>::const_iterator it;
    for (it = lightSPtrs_.begin() ; it < lightSPtrs_.end(); it++) {
        ttRef.srLightPtr = (*it).get();
        ttRef.hitObjectPtr->getConstMaterialPtr()->shadeLight(ttRef);
    }
}
