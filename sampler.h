#ifndef SAMPLER_H
#define SAMPLER_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/gfa.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class Sampler
{
public:
    Sampler();

    const GFA::Size & numSamples() const;

protected:
    GFA::Size                   numSamples_;        // sample count in set
};
typedef std::shared_ptr<Sampler>  SamplerSPtr;
}
#endif // SAMPLER_H
