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
void FaaRay::MatteMaterial::shade(TraceThread &ttRef) const
{
    // Ambient BRDF reflectance mult Ambient Light
    ambientBrdfSPtr_->rho(ttRef);
    diffuseBrdfSPtr_->f(ttRef);
    ttRef.ambientLightSPtr->L(ttRef);
    ttRef.srColor = ttRef.srRhoColor * ttRef.srAmbientL;

    // Add receiving lights.
    //ttRef.sceneSPtr->applyLights(ttRef);
    GFA::Scalar ndotwi;
    std::vector<std::shared_ptr<Light>>::iterator it;
    std::vector<std::shared_ptr<Light>> lightsSPtrs = ttRef.sceneSPtr->getLightsSPtrs();
    for (it = lightsSPtrs.begin() ; it < lightsSPtrs.end(); it++) {
        (*it)->getDirection(ttRef);
        ndotwi = ttRef.lDirection * ttRef.srNormal;
        // check if hitpoint receives light
        if (ndotwi > 0.0) {
            // check if ray casts shadows
            if ((*it)->castsShadows()) {
                ttRef.sRayOrigin = ttRef.srHitPoint;
                ttRef.sRayDirection = ttRef.lDirection;
            } else {
                (*it)->L(ttRef);
                ttRef.srColor += ttRef.srFColor * ttRef.srLightL * ndotwi;
            }
        }
    }
    /*
    int numLights = ttRef.sceneSPtr->lightSPtrs_.size();
    for (GFA::Index j = 0; j < numLights; j++) {
        std::cout << "Handling Light #" << j << std::endl;
    }
    */
    /*
    GFA::Scalar ndotwi;
    for (GFA::Index j = 0; j < lightSPtrs_.size(); j++) {
        lightSPtrs_[j]->getDirection(ttRef);
        ndotwi = ttRef.lDirection * ttRef.srNormal;
        if (ndotwi > 0.0) {
            if (lightSPtrs_[j]->castsShadows())
                ttRef.sRayOrigin = srHitPoint;
                ttRef.sRayDirection = ttRef.lDirection;
                shadowHitObjects(ttRef);

            if ( !ttRef.sRayInShadow ) {
                lightSPtrs_[j]->L(ttRef);
                ttRef.srColor += ttRef.srFColor * ttRef.srLightL * ndotwi;
            }
        }
    }
    */

}
