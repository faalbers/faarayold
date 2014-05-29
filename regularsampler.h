#ifndef FAARAY_REGULARSAMPLER_H
#define FAARAY_REGULARSAMPLER_H
//==============================================================================
#include "faaray_global.h"
#include <memory>
#include "sampler.h"
//==============================================================================
namespace FaaRay {

class RegularSampler : public Sampler
{
public:
    RegularSampler();
    RegularSampler(const GFA::Size &numSamplesRef);
};
typedef std::shared_ptr<RegularSampler>  RegularSamplerSPtr;
RegularSamplerSPtr MakeRegularSamplerSPtr();
RegularSamplerSPtr MakeRegularSamplerSPtr(const GFA::Size &numSamplesRef);
}
#endif // FAARAY_REGULARSAMPLER_H
