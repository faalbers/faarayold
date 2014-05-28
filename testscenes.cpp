#include "testscenes.h"
#include "light.h"
#include "pointlight.h"
#include "sphere.h"
//==============================================================================
FaaRay::TestScenes::TestScenes(std::shared_ptr<Scene> sceneSPtr)
{
    sceneSPtr_.reset();
    sceneSPtr_ = sceneSPtr;
}
//==============================================================================
void FaaRay::TestScenes::addSetA() const
{
    // Add set models

    // Add sphere
    SphereSPtr sphereSPtr(new Sphere);
    sphereSPtr->setCenter(0, 0, 0);
    sphereSPtr->setRadius(5);
    sceneSPtr_->addObject(sphereSPtr);

    //Add Lights
    PointLightSPtr pointLightASPtr(new PointLight);
    pointLightASPtr->setCenter(15, 15, 15);
    sceneSPtr_->addLight(pointLightASPtr);
}
