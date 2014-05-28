//==============================================================================
#ifndef FAARAY_VIEWPLANE_H
#define FAARAY_VIEWPLANE_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/gfa.h"
#include "gfa/rgbcolor.h"
#include "gfa/rgbcolorbuffer.h"
#include <memory>
//==============================================================================
namespace FaaRay {
class FAARAYSHARED_EXPORT ViewPlane
{
public:
    ViewPlane();
    ViewPlane(const GFA::Size width, const GFA::Size height);

    const GFA::Size   & width() const;
    const GFA::Size   & height() const;

    virtual void setPixel(const GFA::Index &x, const GFA::Index &y,
        const GFA::RGBColor &col) const;

protected:
    GFA::RGBColorBuffer         *frameBufferPtr_;
};

typedef std::shared_ptr<ViewPlane> ViewPlaneSPtr;
typedef std::shared_ptr<const ViewPlane> ConstViewPlaneSPtr;

}
//==============================================================================
#endif // FAARAY_VIEWPLANE_H
