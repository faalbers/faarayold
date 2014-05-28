#ifndef FAARAY_LIGHT_H
#define FAARAY_LIGHT_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/gfa.h"
#include "gfa/point3d.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class Light
{
public:
    Light();

    void setCenter(
        const GFA::Scalar &x,
        const GFA::Scalar &y,
        const GFA::Scalar &z);

protected:
    GFA::Point3D    center_;        // center point of object
};
typedef std::shared_ptr<Light> LightSPtr;
}
#endif // FAARAY_LIGHT_H
