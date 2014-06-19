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
class Tracer;
class TraceThread;

class FAARAYSHARED_EXPORT Scene
{
public:
    Scene();

    // Setup methods
    void setCamera(std::shared_ptr<Camera> cameraSPtr);
    void setTracer(std::shared_ptr<Tracer> tracerSPtr);
    void setAmbientLight(std::shared_ptr<Light> ambientLightSPtr);

    // add methods
    void addObject(std::shared_ptr<GeometricObject> objectSPtr);
    void addLight(std::shared_ptr<Light> lightSPtr);

    // Retrieving methods
    const Camera * getConstCameraPtr() const;
    const Tracer * getConstTracerPtr() const;
    const Light * getConstAmbientLightPtr() const;
    std::vector<std::shared_ptr<Light>> getLightsSPtrs() const;

    // ray trace methods
    void objectsHit(TraceThread &ttRef, bool closest) const;
    void lightsShade(TraceThread &ttRef) const;

private:
    std::shared_ptr<Camera>                         cameraSPtr_;
    std::shared_ptr<Tracer>                         tracerSPtr_;
    std::shared_ptr<Light>                          ambientLightSPtr_;
    std::vector<std::shared_ptr<GeometricObject>>   objectSPtrs_;
    std::vector<std::shared_ptr<Light>>             lightSPtrs_;
};
typedef std::shared_ptr<Scene> SceneSPtr;
}
//==============================================================================
#endif // FAARAY_SCENE_H
