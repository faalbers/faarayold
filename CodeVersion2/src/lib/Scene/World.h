#ifndef __WORLD__
#define __WORLD__

#include <vector>
#include "Scene/ViewPlane.h"
#include "Utilities/RGBColor.h"
#include "Cameras/Camera.h"
#include "Tracers/Tracer.h"
#include "Utilities/Point3D.h"
#include "GeometricObjects/GeometricObject.h"
#include "Lights/Light.h"
#include <QtGui/QImage>

class TraceThread;

class World
{
public:
    World();
    ~World(void);

    // Constant elements
    ViewPlane * const   viewPlane;
    RGBColor            backgroundColor;

    // Changable elements
    Camera      *cameraPtr;
    Tracer      *tracerPtr;
    Light       *ambientPtr;
    TraceThread *traceThreadPtr; // creation and deletion not handled by World
    bool        multiCPUs;
    
    // Scene elements
    vector<GeometricObject*>    objects;
    vector<Light*>              lights;

    // Setup methods
    void setPinholeCamera(
        const Point3D &eye,
        const Point3D &lookAt,
        const double  &viewPlaneDistance,
        const double  &zoom);
    void setRayCastTracer();
    void setAreaLightingTracer();
    void setAmbientLight(const double &scaleRadiance);
    void setAmbientOccluderLight(const double &scaleRadiance);

    // Scene creation methods
    void buildScene();
    void addObject(GeometricObject *objectPtr);
    void addLight(Light *lightPtr);
    
    // Tracing methods
    void render() const;
    ShadeRec hitObjects(const Ray& ray) const;

    // render image update
    void drawPixel(const Ray &ray, const RGBColor &color) const;
    void lineUpdate() const;

    void hello() const;
};

#endif

