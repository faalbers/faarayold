#include "scene.h"
#include "camera.h"
#include "geometricobject.h"
#include "light.h"
#include "tracer.h"
//==============================================================================
FaaRay::Scene::Scene()
{
}
//==============================================================================
void FaaRay::Scene::setCamera(FaaRay::CameraSPtr cameraSPtr)
{
    cameraSPtr_ = cameraSPtr;
    //cameraSPtr_->computeUVW();
}
//==============================================================================
void FaaRay::Scene::setTracer(FaaRay::TracerSPtr tracerSPtr)
{
    tracerSPtr_ = tracerSPtr;
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
