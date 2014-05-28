#ifndef FAARAY_SCENE_H
#define FAARAY_SCENE_H
//==============================================================================
#include "faaray_global.h"
#include <vector>
#include <memory>
//==============================================================================
namespace FaaRay {

class Camera;
class GeometricObject;
class Light;

class Scene
{
public:
    Scene();

    // Setup methods
    void setCamera(std::shared_ptr<Camera> cameraSPtr);

    // add methods
    void addObject(std::shared_ptr<GeometricObject> objectSPtr);
    void addLight(std::shared_ptr<Light> lightSPtr);

    // Retrieving methods
    std::shared_ptr<Camera> getCameraSPtr() const;

private:
    std::shared_ptr<Camera>                         cameraSPtr_;
    std::vector<std::shared_ptr<GeometricObject>>   objectSPtrs_;
    std::vector<std::shared_ptr<Light>>             lightSPtrs_;
};
typedef std::shared_ptr<Scene> SceneSPtr;
}
//==============================================================================
#endif // FAARAY_SCENE_H
