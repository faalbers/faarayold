#ifndef __PLASTICMATERIAL__
#define __PLASTICMATERIAL__

#include "Materials/Material.h"
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "BRDFs/BRDF.h"

class PlasticMaterial : public Material
{
public:
    PlasticMaterial(void);          // default constructor
    virtual ~PlasticMaterial(void); // destructor

    void setAmbientBrdf(BRDF* brdf);
    void setDiffuseBrdf(BRDF* brdf);
    void setSpecularBrdf(BRDF* brdf);

    virtual RGBColor shade(ShadeRec& sr);
    virtual RGBColor areaLightShade(ShadeRec& sr);

private:
    BRDF*   ambientBrdf;
    BRDF*   diffuseBrdf;
    BRDF*   specularBrdf;
};

#endif

