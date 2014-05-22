#include "viewplane.h"
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
void FaaRay::ViewPlane::setPixel(
    const GFA::Index &x, const GFA::Index &y,
    const GFA::RGBColor &col) const
{
    frameBufferPtr_->setPixel(x, y, col);
    setGUIPixel_(x, y, col);
}
//==============================================================================
void FaaRay::ViewPlane::setGUIPixel_(const GFA::Index &, const GFA::Index &,
        const GFA::RGBColor &) const
{
}
