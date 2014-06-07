#include "testscenes.h"
#include "light.h"
#include "pointlight.h"
#include "sphere.h"
#include "mattematerial.h"
//==============================================================================
FaaRay::TestScenes::TestScenes(std::shared_ptr<Scene> sceneSPtr)
{
    sceneSPtr_.reset();
    sceneSPtr_ = sceneSPtr;
}
//==============================================================================
void FaaRay::TestScenes::addSetA() const
{
    // Create materials to be used
    FaaRay::MatteMaterialSPtr matteMaterialASPtr(new FaaRay::MatteMaterial);
    matteMaterialASPtr->setCd(1.0, 1.0, 0.0);

    // Add set models

    // Add sphere annd attach material
    SphereSPtr sphereSPtr(new Sphere);
    sphereSPtr->setCenter(0, 0, 0);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialASPtr);
    sceneSPtr_->addObject(sphereSPtr);

    //Add Lights
    PointLightSPtr pointLightASPtr(new PointLight);
    pointLightASPtr->setCenter(15, 15, 15);
    sceneSPtr_->addLight(pointLightASPtr);
}
