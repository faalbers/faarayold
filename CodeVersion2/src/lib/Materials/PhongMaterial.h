#ifndef __PHONGMATERIAL__
#define __PHONGMATERIAL__

#include "Materials/Material.h"
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "BRDFs/LambertianBRDF.h"
#include "BRDFs/GlossySpecularBRDF.h"

class PhongMaterial : public Material
{
public:
    PhongMaterial(void);      // default constructor
    virtual ~PhongMaterial(void);     // destructor

    void setKa(const double k);
    void setKd(const double k);
    void setCd(const double c);
    void setCd(const double r, const double g, const double b);
    void setKs(const double k);
    void setExp(const double exp);

    virtual RGBColor shade(ShadeRec& sr);
    virtual RGBColor areaLightShade(ShadeRec& sr);

private:
    LambertianBRDF*     ambientBrdf;
    LambertianBRDF*     diffuseBrdf;
    GlossySpecularBRDF* specularBrdf;
};

#endif

