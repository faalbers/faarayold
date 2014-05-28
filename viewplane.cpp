#include "viewplane.h"
#include "sampler.h"
//==============================================================================
FaaRay::ViewPlane::ViewPlane()
{
}
//==============================================================================
FaaRay::ViewPlane::ViewPlane(const GFA::Size width, const GFA::Size height) :
    frameBufferPtr_(new GFA::RGBColorBuffer(width, height))
{
}
//==============================================================================
const GFA::Size & FaaRay::ViewPlane::width() const
{
    return frameBufferPtr_->width();
}
//==============================================================================
const GFA::Size & FaaRay::ViewPlane::height() const
{
    return frameBufferPtr_->height();
}
//==============================================================================
const GFA::Size & FaaRay::ViewPlane::numSamples() const
{
    return samplerSPtr_->numSamples();
}
//==============================================================================
void FaaRay::ViewPlane::setNumSamples(const GFA::Size &numSamples)
{
    if (samplerSPtr_->numSamples() == numSamples) return;

    // no need to reset prior samplerSPtr, this happens automatically
    //if (numSamples > 1) samplerSPtr_ = MakeMultiJitteredSamplerSPtr(numSamples);
    //else samplerSPtr_ = MakeRegularSamplerSPtr(numSamples);
}
//==============================================================================
void FaaRay::ViewPlane::setPixel(
    const GFA::Index &x, const GFA::Index &y,
    const GFA::RGBColor &col) const
{
    frameBufferPtr_->setPixel(x, y, col);
}
