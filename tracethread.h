#ifndef FAARAY_TRACETHREAD_H
#define FAARAY_TRACETHREAD_H
//==============================================================================
#include "faaray_global.h"
#include "faaray.h"
#include "gfa/gfa.h"
#include "gfa/rgbcolor.h"
#include "gfa/point2d.h"
#include "gfa/point3d.h"
#include "gfa/vector3d.h"
#include "gfa/normal.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class ViewPlane;
class Scene;
class Sampler;
class Tracer;
class Material;
class GeometricObject;
class Light;

class TraceThread
{
public:
    TraceThread();

    void render();
    GFA::Scalar rand();

    void        initRandom(const uint32_t &s);

    GFA::Scalar     x;
    GFA::Scalar     y;
    GFA::RGBColor   color;
    uint32_t        seedVal;

    // shared between threads, objects need to be const
    const ViewPlane                     *viewPlanePtr;
    const Scene                         *scenePtr;

    // viewplane data
    // might later be a Sample object
    GFA::Size       width;
    GFA::Size       height;

    // sample data
    GFA::Index      sampleIndex;
    GFA::Index      sampleSetIndex;
    GFA::Point2D    sampleUnitSquare;
    GFA::Point2D    samplePoint;

    // ray data
    // might later be a Ray object
    GFA::Point3D            rayOrigin;
    GFA::Vector3D           rayDirection;
    bool                    hitAnObject;
    const GeometricObject   *hitObjectPtr;  // gets changed per hit point
    GFA::Scalar             hitDistance;
    GFA::Normal             hitNormal;

    // ShadeRec (surface) data
    // might later be a ShadeRec object
    GFA::Point3D            srHitPoint;
    GFA::Normal             srNormal;
    GFA::RGBColor           srColor;
    GFA::RGBColor           srRhoColor;     // diffuse calculated color
    GFA::RGBColor           srFColor;
    GFA::RGBColor           srLightL;
    GFA::RGBColor           srAmbientL;
    const Material          *srMaterialPtr; // gets changed per hit point
    const GeometricObject   *srObjectPtr;   // gets changed per hit point
    const Light             *srLightPtr;    // gets changed per hit point

    // light data
    GFA::Vector3D   lDirection;

private:
    uint32_t    seedValue_;
    MyRNG       rng_;
    std::uniform_real_distribution<GFA::Scalar> distribution;

};
}
#endif // FAARAY_TRACETHREAD_H
