//==============================================================================
#ifndef __FAARAY_VIEWPLANE_H__
#define __FAARAY_VIEWPLANE_H__
//==============================================================================
#include <memory>
#include "FaaRay/FaaRay.h"
#include "GFA/GFA.h"
#include "GFA/RGBColor.h"
#include "GFA/RGBColorBuffer.h"
//==============================================================================
namespace FaaRay
{

class Sampler;

class FAARAY_DLL_PUBLIC ViewPlane
{
    public:
        ViewPlane();
        ViewPlane(const GFA::Size width, const GFA::Size height);
        virtual ~ViewPlane(void);
    
        const GFA::Size   & width() const;
        const GFA::Size   & height() const;
        const GFA::Scalar & pixelSize() const;
        const GFA::Size   & numSamples() const;
        
        void setPixel(const GFA::Index &x, const GFA::Index &y,
            const GFA::RGBColor &col) const; 
    
        void setNumSamples(const GFA::Size &numSamples);
        const Sampler * getSamplerPtr() const;
        std::shared_ptr<Sampler> getSamplerSPtr() const;
        std::shared_ptr<const Sampler> getConstSamplerSPtr() const;
       
    protected:
        GFA::RGBColorBuffer         *frameBufferPtr_;
        GFA::Scalar                 pixelSize_;
        std::shared_ptr<Sampler>    samplerSPtr_;
    
        virtual void setGUIPixel_(const GFA::Index &x, const GFA::Index &y,
            const GFA::RGBColor &col) const; 
};

typedef std::shared_ptr<ViewPlane> ViewPlaneSPtr;
typedef std::shared_ptr<const ViewPlane> ConstViewPlaneSPtr;

}
//==============================================================================
#endif
//==============================================================================

