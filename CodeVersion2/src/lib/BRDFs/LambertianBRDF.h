#ifndef __LAMBERTIAN_BRDF__
#define __LAMBERTIAN_BRDF__

#include "BRDFs/BRDF.h"

#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Vector3D.h"
#include "Samplers/Sampler.h"

class LambertianBRDF: public BRDF
{
public:
    LambertianBRDF(void);           // default constructor
    virtual ~LambertianBRDF(void);  // destructor
    
    // BRDF
    virtual RGBColor f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const;
    virtual RGBColor sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;
    // Bihemispherical reflectance.
    virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

    void setKd(const double k) { kd = k; }
    void setCd(const RGBColor& c) { cd = c; }
    void setCd(const double r, const double g, const double b);

private:
    double kd;      // Diffuse Reflection Coefficient
    RGBColor cd;    // Diffuse Color
};

#endif

