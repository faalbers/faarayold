#ifndef FAARAY_TRACETHREAD_H
#define FAARAY_TRACETHREAD_H
//==============================================================================
#include "faaray_global.h"
#include "faaray.h"
#include "gfa/gfa.h"
#include "gfa/rgbcolor.h"
#include "gfa/point3d.h"
#include "gfa/vector3d.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class ViewPlane;
class Scene;

class TraceThread
{
public:
    TraceThread();

    void render();

    void        initRandom(const uint32_t &s);

    GFA::Scalar     x;
    GFA::Scalar     y;
    GFA::RGBColor   color;
    uint32_t        seedVal;

    // shared between threads, objects need to be const
    std::shared_ptr<const ViewPlane>    viewPlaneSPtr;
    std::shared_ptr<const Scene>        sceneSPtr;

    // viewplane data
    GFA::Size       width;
    GFA::Size       height;

    // ray data
    GFA::Point3D    rayOrigin;
    GFA::Vector3D   rayDirection;

private:
    uint32_t    seedValue_;
    MyRNG       rng_;
    std::uniform_real_distribution<GFA::Scalar> distribution;

};
}
#endif // FAARAY_TRACETHREAD_H
