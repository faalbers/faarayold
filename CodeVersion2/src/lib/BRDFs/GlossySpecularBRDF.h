#ifndef __GLOSSYSPECULAR_BRDF__
#define __GLOSSYSPECULAR_BRDF__

#include "BRDFs/BRDF.h"

#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Vector3D.h"
#include "Samplers/Sampler.h"

class GlossySpecularBRDF: public BRDF
{
public:
    GlossySpecularBRDF(void);           // default constructor
    virtual ~GlossySpecularBRDF(void);  // destructor

    // BRDF
    virtual RGBColor f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const;
    virtual RGBColor sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;
    // Bihemispherical reflectance.
    virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

    void setKs(const double k) { ks = k; }
    void setCs(const RGBColor& c) { cs = c; }
    void setCs(const double r, const double g, const double b);
    void setExp(const double _exp) { exp = _exp; }

private:
    double      ks;     // Specular Reflection Coefficient
    RGBColor    cs;     // Specular Color
    double      exp;    // Phong exponent
};

#endif

