#include "mattematerial.h"
#include "tracethread.h"
#include "lambertianbrdf.h"
#include "light.h"
#include "scene.h"
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
void FaaRay::MatteMaterial::shadeOpt(TraceThread &ttRef) const
{
    // Ambient BRDF reflectance mult Ambient Light
    ambientBrdfSPtr_->rho(ttRef);
    diffuseBrdfSPtr_->f(ttRef);
    ttRef.ambientLightSPtr->L(ttRef);
    ttRef.srColor = ttRef.srRhoColor * ttRef.srAmbientL;

    // Add receiving lights.
    ttRef.sceneSPtr->lightsShade(ttRef);
}
//==============================================================================
void FaaRay::MatteMaterial::shade(TraceThread &ttRef) const
{
    // Ambient BRDF reflectance mult Ambient Light
    ambientBrdfSPtr_->rho(ttRef);
    diffuseBrdfSPtr_->f(ttRef);
    ttRef.sceneSPtr->getConstAmbientLightSPtr()->L(ttRef);
    ttRef.srColor = ttRef.srRhoColor * ttRef.srAmbientL;

    // Add receiving lights.
    ttRef.sceneSPtr->lightsShade(ttRef);
}
//==============================================================================
void FaaRay::MatteMaterial::shadeLight(TraceThread &ttRef) const
{
    // Additiveliy shade current light handled by the trace
    GFA::Scalar ndotwi;
    ttRef.srLightSPtr->getDirection(ttRef);
    ndotwi = ttRef.lDirection * ttRef.srNormal;
    // check if hitpoint receives light
    if (ndotwi > 0.0) {
        // check if ray casts shadows
        if (ttRef.srLightSPtr->castsShadows()) {
            ttRef.rayOrigin = ttRef.srHitPoint;
            ttRef.rayDirection = ttRef.lDirection;
            ttRef.sceneSPtr->objectsHit(ttRef, false);
            if (!ttRef.hitAnObject) {
                ttRef.srLightSPtr->L(ttRef);
                ttRef.srColor += ttRef.srFColor * ttRef.srLightL * ndotwi;
            }
        } else {
            ttRef.srLightSPtr->L(ttRef);
            ttRef.srColor += ttRef.srFColor * ttRef.srLightL * ndotwi;
        }
    }
}
