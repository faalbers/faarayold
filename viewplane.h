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

class Sampler;

class FAARAYSHARED_EXPORT ViewPlane
{
public:
    ViewPlane();
    ViewPlane(const GFA::Size width, const GFA::Size height);

    // Retrieval methods
    const GFA::Size   & width() const;
    const GFA::Size   & height() const;
    const GFA::Scalar & pixelSize() const;
    const GFA::Size   & numSamples() const;

    std::shared_ptr<const Sampler> getConstSamplerSPtr() const;

    void setNumSamples(const GFA::Size &numSamples);

    virtual void setPixel(const GFA::Index &x, const GFA::Index &y,
        const GFA::RGBColor &col) const;

protected:
    GFA::RGBColorBuffer         *frameBufferPtr_;
    GFA::Scalar                 pixelSize_;
    std::shared_ptr<Sampler>    samplerSPtr_;
};

typedef std::shared_ptr<ViewPlane> ViewPlaneSPtr;
typedef std::shared_ptr<const ViewPlane> ConstViewPlaneSPtr;

}
//==============================================================================
#endif // FAARAY_VIEWPLANE_H
