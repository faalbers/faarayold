#include "scene.h"
#include "camera.h"
#include "geometricobject.h"
#include "light.h"
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
