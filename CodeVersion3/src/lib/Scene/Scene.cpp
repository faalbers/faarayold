//==============================================================================
#include "Scene.h"
#include "GFA/GFA.h"
#include <memory>
#include "FaaRay/Camera.h"
#include "FaaRay/Tracer.h"
#include "FaaRay/Light.h"
#include "FaaRay/TraceThread.h"
#include "FaaRay/GeometricObject.h"
#include "FaaRay/Sphere.h"
#include "FaaRay/Material.h"
//==============================================================================
FaaRay::Scene::Scene(void)
{
}
//==============================================================================
FaaRay::Scene::~Scene(void)
{
}
//==============================================================================
void FaaRay::Scene::setCamera(FaaRay::CameraSPtr cameraSPtr)
{
    cameraSPtr_ = cameraSPtr;
    cameraSPtr_->computeUVW();
}
//==============================================================================
void FaaRay::Scene::setTracer(FaaRay::TracerSPtr tracerSPtr)
{
    tracerSPtr_ = tracerSPtr;
}
//==============================================================================
void FaaRay::Scene::setAmbientLight(FaaRay::LightSPtr ambientLightSPtr)
{
    ambientLightSPtr_ = ambientLightSPtr;
}
//==============================================================================
void FaaRay::Scene::addLight(LightSPtr lightSPtr)
{                                       
    lightSPtrs_.push_back(lightSPtr);
}
//==============================================================================
void FaaRay::Scene::addObject(GeometricObjectSPtr objectSPtr)
{                                       
    objectSPtrs_.push_back(objectSPtr);
}
//==============================================================================
FaaRay::CameraSPtr FaaRay::Scene::getCameraSPtr() const
{
    return cameraSPtr_;
}
//==============================================================================
const FaaRay::Tracer * FaaRay::Scene::getTracerPtr() const
{
    return tracerSPtr_.get();
}
//==============================================================================
FaaRay::TracerSPtr FaaRay::Scene::getTracerSPtr() const
{
    return tracerSPtr_;
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
void FaaRay::Scene::hitObjects(TraceThread &ttRef) const
{
    GFA::Scalar t;
    GFA::Scalar tmin = GFA::HUGE_SCALAR;
    GFA::Index  closestHit = 0;

    // Find closest hit
    ttRef.srHitAnObject = false;
    for (GFA::Index j = 0; j < objectSPtrs_.size(); j++) {
        if (objectSPtrs_[j]->hit(ttRef, t) && (t < tmin)) {
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
//==============================================================================
void FaaRay::Scene::shadowHitObjects(TraceThread &ttRef) const
{
    GFA::Scalar t;

    for (GFA::Index j = 0; j < objectSPtrs_.size(); j++) {
        if ( objectSPtrs_[j]->shadowHit(ttRef, t) ) {
            ttRef.sRayInShadow = true;
            return;
        }
    }
    ttRef.sRayInShadow = false;
}
//==============================================================================
void FaaRay::Scene::applyLights(TraceThread &ttRef) const
{
    GFA::Scalar ndotwi;
    for (GFA::Index j = 0; j < lightSPtrs_.size(); j++) {
        lightSPtrs_[j]->getDirection(ttRef);
        ndotwi = ttRef.lDirection * ttRef.srNormal;
        if (ndotwi > 0.0) {
            if (lightSPtrs_[j]->castsShadows())
                ttRef.sRayOrigin = srHitPoint;
                ttRef.sRayDirection = ttRef.lDirection;
                shadowHitObjects(ttRef);

            if ( !ttRef.sRayInShadow ) {
                lightSPtrs_[j]->L(ttRef);
                ttRef.srColor += ttRef.srFColor * ttRef.srLightL * ndotwi;
            }
        }
    }
}
/*
            bool inShadow = false;
            
            if ( sr.world.lights[j]->castsShadows() ) {
                Ray shadowRay(sr.hitPoint, wi);
                inShadow = sr.world.lights[j]->inShadow(shadowRay, sr);
            }
            if (!inShadow) 
                L += diffuseBrdf->f(sr, wi, wo) * sr.world.lights[j]->L(sr) * ndotwi;
*/
//==============================================================================
/*
    for (GFA::Index j = 0; j < numLights; j++) {
        Vector3D wi = sr.world.lights[j]->getDirection(sr);
        double ndotwi = wi * sr.normal;
        
        if (ndotwi > 0.0) {
            bool inShadow = false;
            
            if ( sr.world.lights[j]->castsShadows() ) {
                Ray shadowRay(sr.hitPoint, wi);
                inShadow = sr.world.lights[j]->inShadow(shadowRay, sr);
            }
            if (!inShadow) 
                L += diffuseBrdf->f(sr, wi, wo) * sr.world.lights[j]->L(sr) * ndotwi;
        }
    }
*/
