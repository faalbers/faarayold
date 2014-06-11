#include "mattematerial.h"
#include "tracethread.h"
#include "lambertianbrdf.h"
#include "light.h"
//==============================================================================
FaaRay::MatteMaterial::MatteMaterial() :
    ambientBrdfSPtr_(new LambertianBRDF),
    diffuseBrdfSPtr_(new LambertianBRDF)
{
}
//==============================================================================
void FaaRay::MatteMaterial::setCd(
            const GFA::Scalar &r,
            const GFA::Scalar &g,
            const GFA::Scalar &b) const
{
    ambientBrdfSPtr_->setCd(r, g, b);
    diffuseBrdfSPtr_->setCd(r, g, b);
}
//==============================================================================
void FaaRay::MatteMaterial::shade(TraceThread &ttRef) const
{
    // Ambient BRDF reflectance mult Ambient Light
    ambientBrdfSPtr_->rho(ttRef);
    diffuseBrdfSPtr_->f(ttRef);
    ttRef.ambientLightSPtr->L(ttRef);
    ttRef.srColor = ttRef.srRhoColor * ttRef.srAmbientL;
}
