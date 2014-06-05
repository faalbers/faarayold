#include "viewplane.h"
#include "sampler.h"
#include "regularsampler.h"
//==============================================================================
FaaRay::ViewPlane::ViewPlane() :
    frameBufferPtr_(new GFA::RGBColorBuffer),
    pixelSize_(1.0),
    samplerSPtr_(new RegularSampler)
{
}
//==============================================================================
FaaRay::ViewPlane::ViewPlane(const GFA::Size width, const GFA::Size height) :
    frameBufferPtr_(new GFA::RGBColorBuffer(width, height)),
    pixelSize_(10.0/256.0),
    samplerSPtr_(new RegularSampler(1))
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
const GFA::Scalar & FaaRay::ViewPlane::pixelSize() const
{
    return pixelSize_;
}
//==============================================================================
const GFA::Size & FaaRay::ViewPlane::numSamples() const
{
    return samplerSPtr_->numSamples();
}
//==============================================================================
FaaRay::ConstSamplerSPtr FaaRay::ViewPlane::getConstSamplerSPtr() const
{
    return samplerSPtr_;
}
//==============================================================================
void FaaRay::ViewPlane::setNumSamples(const GFA::Size &numSamples)
{
    if (samplerSPtr_->numSamples() == numSamples) return;

    // no need to reset prior samplerSPtr, this happens automatically
    samplerSPtr_ = MakeRegularSamplerSPtr(numSamples);
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
