#include "viewplane.h"
#include "sampler.h"
#include "regularsampler.h"
#include "multijitteredsampler.h"
//==============================================================================
/*!
 * Constructor that prepares the view plane based on setting. It will also
 * create a new empty frame buffer, and a regular sampler for ray tracing.
 * Pixel size is set to 1.0 as default.
 */
FaaRay::ViewPlane::ViewPlane() :
    frameBufferPtr_(new GFA::RGBColorBuffer),
    pixelSize_(1.0),
    samplerSPtr_(new RegularSampler)
{
}
//==============================================================================
/*!
 * Constructor that prepares the view plane based on given size. It will also
 * create a frame buffer of that size, and a regular sampler for ray tracing
 * with sample count 1 as default.
 * Pixel size is set to 10.0/256.0 as default.
 */
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
const FaaRay::Sampler * FaaRay::ViewPlane::getConstSamplerPtr() const
{
    return samplerSPtr_.get();
}
//==============================================================================
void FaaRay::ViewPlane::setNumSamples(const GFA::Size &numSamples)
{
    if (samplerSPtr_->numSamples() == numSamples) return;

    // no need to reset prior samplerSPtr, this happens automatically
    //samplerSPtr_ = MakeRegularSamplerSPtr(numSamples);
    if (numSamples > 1) samplerSPtr_ = MakeMultiJitteredSamplerSPtr(numSamples);
    else samplerSPtr_ = MakeRegularSamplerSPtr(numSamples);
}
//==============================================================================
void FaaRay::ViewPlane::setPixel(
    const GFA::Index &x, const GFA::Index &y,
    const GFA::RGBColor &col) const
{
    frameBufferPtr_->setPixel(x, y, col);
}
