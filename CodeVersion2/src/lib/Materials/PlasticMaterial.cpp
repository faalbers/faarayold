#include "Materials/PlasticMaterial.h"
#include "Scene/World.h"

PlasticMaterial::PlasticMaterial(void)
    : Material(),
    ambientBrdf(NULL),
    diffuseBrdf(NULL),
    specularBrdf(NULL)
{}

PlasticMaterial::~PlasticMaterial(void)
{}

RGBColor PlasticMaterial::shade(ShadeRec& sr)
{
    Vector3D    wo = -sr.ray.direction;
    // Ambient BRDF reflectance mult Ambient Light 
    RGBColor L = ambientBrdf->rho(sr, wo) * sr.world.ambientPtr->L(sr);

    int numLights = sr.world.lights.size();
    for (int j = 0; j < numLights; j++) {
        Vector3D wi = sr.world.lights[j]->getDirection(sr);
        double ndotwi = wi * sr.normal;
        
        if (ndotwi > 0.0) {
            L += (diffuseBrdf->f(sr, wi, wo) + specularBrdf->f(sr, wi, wo)) *
                    sr.world.lights[j]->L(sr) * ndotwi;
        }
    }
    
    return L;
}

RGBColor PlasticMaterial::areaLightShade(ShadeRec& sr)
{
    Vector3D    wo = -sr.ray.direction;
    // Ambient BRDF reflectance mult Ambient Light 
    RGBColor L = ambientBrdf->rho(sr, wo) * sr.world.ambientPtr->L(sr);

    int numLights = sr.world.lights.size();
    for (int j = 0; j < numLights; j++) {
        Vector3D wi = sr.world.lights[j]->getDirection(sr);
        double ndotwi = wi * sr.normal;
        
        if (ndotwi > 0.0) {
            L += (diffuseBrdf->f(sr, wi, wo) + specularBrdf->f(sr, wi, wo)) *
                    sr.world.lights[j]->L(sr) * ndotwi;
        }
    }
    
    return L;
}

