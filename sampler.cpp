#include "sampler.h"
#include "tracethread.h"
//==============================================================================
FaaRay::Sampler::Sampler() :
    numOneDimSamples_(1),
    numSamples_(1),
    numSets_(83) // some kind of magical number
{
}
//==============================================================================
// The numSamples will be changed to lowes nomber that has a int square root
// ex: 10 will be changed to 9 because lowest square root is 3
FaaRay::Sampler::Sampler(const GFA::Size &numSamplesRef) :
    numOneDimSamples_((GFA::Size) sqrt((float) numSamplesRef)),
    numSamples_(numOneDimSamples_ * numOneDimSamples_),
    numSets_(83) // some kind of magical number
{
}
//==============================================================================
const GFA::Size & FaaRay::Sampler::numSamples() const
{
    return numSamples_;
}
//==============================================================================
// This method is called from multiple threads at the same time
// Do NOT use this class's random method, only the given random method in the
// render thread. TraceThread will be updated.
void FaaRay::Sampler::setSampleUnitSquare(TraceThread &ttRef) const
{
    GFA::Index newIndex;

    if (ttRef.sampleIndex == 0)
        ttRef.sampleSetIndex = (GFA::Index) (numSets_ * ttRef.rand()) * numSamples_;

    newIndex = ttRef.sampleSetIndex + ttRef.sampleIndex;
    newIndex = ttRef.sampleSetIndex + shuffledIndices_[newIndex];

    //NOTE: further optimize samples vector search up ?
    ttRef.sampleUnitSquare.x = samples_[newIndex].x;
    ttRef.sampleUnitSquare.y = samples_[newIndex].y;
}
