#include "regularsampler.h"
//==============================================================================
FaaRay::RegularSampler::RegularSampler()
{
}
//==============================================================================
FaaRay::RegularSampler::RegularSampler(const GFA::Size &numSamplesRef) :
    Sampler(numSamplesRef)
{
}
//==============================================================================
FaaRay::RegularSamplerSPtr FaaRay::MakeRegularSamplerSPtr()
{
    return std::make_shared<RegularSampler>();
}
//==============================================================================
FaaRay::RegularSamplerSPtr FaaRay::MakeRegularSamplerSPtr(
    const GFA::Size &numSamplesRef)
{
    return std::make_shared<RegularSampler>(numSamplesRef);
}
