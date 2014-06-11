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
    std::shared_ptr<const ViewPlane>    viewPlaneSPtr;
    std::shared_ptr<const Scene>        sceneSPtr;
    std::shared_ptr<const Sampler>      samplerSPtr;
    std::shared_ptr<const Tracer>       tracerSPtr;
    std::shared_ptr<const Light>        ambientLightSPtr;

    // viewplane data
    GFA::Size       width;
    GFA::Size       height;
    GFA::Scalar     halfWidth;
    GFA::Scalar     halfHeight;
    GFA::Scalar     pixelSize;

    // sample data
    GFA::Index      sampleIndex;
    GFA::Index      sampleSetIndex;
    GFA::Point2D    sampleUnitSquare;
    GFA::Point2D    samplePoint;

    // ray data
    GFA::Point3D    rayOrigin;
    GFA::Vector3D   rayDirection;

    // shadow ray data
    GFA::Point3D    sRayOrigin;
    GFA::Vector3D   sRayDirection;

    // ShadeRec (surface) data
    bool                            srHitAnObject;
    GFA::Point3D                    srHitPoint;
    GFA::Normal                     srNormal;
    GFA::RGBColor                   srColor;
    GFA::RGBColor                   srRhoColor; // diffuse calculated color
    GFA::RGBColor                   srFColor;
    GFA::RGBColor                   srLightL;
    GFA::RGBColor                   srAmbientL;
    std::shared_ptr<const Material> srMaterialSPtr; // gets changed per hit point

    // light data
    GFA::Vector3D   lDirection;

private:
    uint32_t    seedValue_;
    MyRNG       rng_;
    std::uniform_real_distribution<GFA::Scalar> distribution;

};
}
#endif // FAARAY_TRACETHREAD_H
