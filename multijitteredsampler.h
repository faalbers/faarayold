#ifndef FAARAY_MULTIJITTEREDSAMPLER_H
#define FAARAY_MULTIJITTEREDSAMPLER_H
//==============================================================================
#include "faaray_global.h"
#include <memory>
#include "sampler.h"
#include "gfa/gfa.h"
//==============================================================================
namespace FaaRay {

class MultiJitteredSampler : public Sampler
{
public:
    MultiJitteredSampler();
    MultiJitteredSampler(const GFA::Size &numSamplesRef);

    virtual void generateSamples();
};
typedef std::shared_ptr<MultiJitteredSampler>  MultiJitteredSamplerSPtr;
MultiJitteredSamplerSPtr MakeMultiJitteredSamplerSPtr();
MultiJitteredSamplerSPtr MakeMultiJitteredSamplerSPtr(const GFA::Size &numSamplesRef);
}
#endif // FAARAY_MULTIJITTEREDSAMPLER_H
