#ifndef SAMPLER_H
#define SAMPLER_H
//==============================================================================
#include "faaray_global.h"
#include "gfa/gfa.h"
#include "gfa/point2d.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class TraceThread;

class Sampler
{
public:
    Sampler();
    Sampler(const GFA::Size &numSamplesRef);

    const GFA::Size & numSamples() const;

    void setSampleUnitSquare(TraceThread &ttRef) const;

protected:
    GFA::Size                   numOneDimSamples_;  // one dim of samples
    GFA::Size                   numSamples_;        // sample count in set
    GFA::Size                   numSets_;           // sample sets count
    std::vector<GFA::Point2D>   samples_;
    std::vector<GFA::Index>     shuffledIndices_;
};
typedef std::shared_ptr<Sampler>  SamplerSPtr;
typedef std::shared_ptr<const Sampler>  ConstSamplerSPtr;
}
#endif // SAMPLER_H
