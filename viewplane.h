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

/*!
 * \brief The ViewPlane class
 *
 * This creates a 2 dimentional view plane. This plane exists in the 3
 * dimensional scene space and will be used as the flat projection plane for the
 * ray trace render.
 *
 */
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

    const Sampler * getConstSamplerPtr() const;

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
