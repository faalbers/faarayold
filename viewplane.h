//==============================================================================
#ifndef FAARAY_VIEWPLANE_H
#define FAARAY_VIEWPLANE_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/gfa.h"
#include <memory>
//==============================================================================
namespace FaaRay {
class FAARAYSHARED_EXPORT ViewPlane
{
public:
    ViewPlane();
    ViewPlane(const GFA::Size width, const GFA::Size height);
};

typedef std::shared_ptr<ViewPlane> ViewPlaneSPtr;
typedef std::shared_ptr<const ViewPlane> ConstViewPlaneSPtr;

}
//==============================================================================
#endif // FAARAY_VIEWPLANE_H
