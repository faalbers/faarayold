#include "sampler.h"
//==============================================================================
FaaRay::Sampler::Sampler() :
    numSamples_(1)
{
}
//==============================================================================
const GFA::Size & FaaRay::Sampler::numSamples() const
{
    return numSamples_;
}
