#ifndef __FAARAY_SAMPLER_H__
#define __FAARAY_SAMPLER_H__
//==============================================================================
#include <memory>
#include <vector>
#include "GFA/GFA.h"
#include "FaaRay/FaaRay.h"
#include "GFA/Point2D.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

class Sampler
{
    public:
        Sampler();
        Sampler(const GFA::Size &numSamplesRef);
        virtual ~Sampler();
        
        const GFA::Size & numSamples() const;
        
        virtual void generateSamples() = 0;
        void setupShuffledIndices();
    
        void setSampleUnitSquare(TraceThread &ttRef) const;
        
    protected:
        GFA::Size                   numOneDimSamples_;  // one dim of samples
        GFA::Size                   numSamples_;        // sample count in set
        GFA::Size                   numSets_;           // sample sets count
        std::vector<GFA::Point2D>   samples_;
        std::vector<GFA::Index>     shuffledIndices_;
        MyRNG       rng_;
        std::uniform_real_distribution<GFA::Scalar> distribution;  
        GFA::Scalar rand_();
};

typedef std::shared_ptr<Sampler>  SamplerSPtr;
typedef std::shared_ptr<const Sampler>  ConstSamplerSPtr;

}
//==============================================================================
#endif
//==============================================================================

