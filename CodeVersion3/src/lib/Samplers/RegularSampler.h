#ifndef __FAARAY_REGULARSAMPLER_H__
#define __FAARAY_REGULARSAMPLER_H__
//==============================================================================
#include <memory>
#include "Sampler.h"
#include "GFA/GFA.h"
//==============================================================================
namespace FaaRay
{
class RegularSampler : public Sampler
{
    public:
        RegularSampler();
        RegularSampler(const GFA::Size &numSamplesRef);
        virtual ~RegularSampler();

        virtual void generateSamples();

};

typedef std::shared_ptr<RegularSampler>  RegularSamplerSPtr;
RegularSamplerSPtr MakeRegularSamplerSPtr();
RegularSamplerSPtr MakeRegularSamplerSPtr(const GFA::Size &numSamplesRef);

}
//==============================================================================
#endif
//==============================================================================
