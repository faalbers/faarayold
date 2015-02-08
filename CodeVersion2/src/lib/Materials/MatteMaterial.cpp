#include "Materials/MatteMaterial.h"
#include "Scene/World.h"

MatteMaterial::MatteMaterial(void)
    : Material(),
    ambientBrdf(new LambertianBRDF),
    diffuseBrdf(new LambertianBRDF)
{}

MatteMaterial::~MatteMaterial(void)
{}

void MatteMaterial::setKa(const double k)
{
    ambientBrdf->setKd(k);
}

void MatteMaterial::setKd(const double k)
{
    diffuseBrdf->setKd(k);
}

void MatteMaterial::setCd(const double c)
{
    ambientBrdf->setCd(c);
    diffuseBrdf->setCd(c);
}

void MatteMaterial::setCd(const double r, const double g, const double b)
{
    ambientBrdf->setCd(r, g, b);
    diffuseBrdf->setCd(r, g, b);
}


RGBColor MatteMaterial::shade(ShadeRec& sr)
{
    Vector3D    wo = -sr.ray.direction;
    // Ambient BRDF reflectance mult Ambient Light 
    RGBColor L = ambientBrdf->rho(sr, wo) * sr.world.ambientPtr->L(sr);

    int numLights = sr.world.lights.size();
    for (int j = 0; j < numLights; j++) {
        Vector3D wi = sr.world.lights[j]->getDirection(sr);
        double ndotwi = wi * sr.normal;
        
        if (ndotwi > 0.0) {
            bool inShadow = false;
            
            if ( sr.world.lights[j]->castsShadows() ) {
                Ray shadowRay(sr.hitPoint, wi);
                inShadow = sr.world.lights[j]->inShadow(shadowRay, sr);
            }
            if (!inShadow) 
                L += diffuseBrdf->f(sr, wi, wo) * sr.world.lights[j]->L(sr) * ndotwi;
        }
    }
    
    return L;
}

RGBColor MatteMaterial::areaLightShade(ShadeRec& sr)
{
    Vector3D    wo = -sr.ray.direction;
    // Ambient BRDF reflectance mult Ambient Light 
    RGBColor L = ambientBrdf->rho(sr, wo) * sr.world.ambientPtr->L(sr);

    int numLights = sr.world.lights.size();
    for (int j = 0; j < numLights; j++) {
        Vector3D wi = sr.world.lights[j]->getDirection(sr);
        double ndotwi = wi * sr.normal;
        
        if (ndotwi > 0.0) {
            bool inShadow = false;
            
            if ( sr.world.lights[j]->castsShadows() ) {
                Ray shadowRay(sr.hitPoint, wi);
                inShadow = sr.world.lights[j]->inShadow(shadowRay, sr);
            }
            if (!inShadow) 
                L += diffuseBrdf->f(sr, wi, wo)
                    * sr.world.lights[j]->L(sr)
                    * sr.world.lights[j]->G(sr)
                    * ndotwi / sr.world.lights[j]->pdf(sr) ;
        }
    }
    
    return L;
}

