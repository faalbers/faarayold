#ifndef __MATTEMATERIAL__
#define __MATTEMATERIAL__

#include "Materials/Material.h"
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "BRDFs/LambertianBRDF.h"

class MatteMaterial : public Material
{
public:
    MatteMaterial(void);      // default constructor
    virtual ~MatteMaterial(void);     // destructor

    void setKa(const double k);
    void setKd(const double k);
    void setCd(const double c);
    void setCd(const double r, const double g, const double b);
    virtual RGBColor shade(ShadeRec& sr);
    virtual RGBColor areaLightShade(ShadeRec& sr);

private:
    LambertianBRDF* ambientBrdf;
    LambertianBRDF* diffuseBrdf;
};

#endif

