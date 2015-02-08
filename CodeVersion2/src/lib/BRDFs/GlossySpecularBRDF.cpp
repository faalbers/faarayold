#include "BRDFs/GlossySpecularBRDF.h"
#include "Utilities/Maths.h"

GlossySpecularBRDF::GlossySpecularBRDF(void)
    :BRDF(),
    ks(1.0),
    cs(white),
    exp(50)
{
}

GlossySpecularBRDF::~GlossySpecularBRDF(void)
{
}

RGBColor GlossySpecularBRDF::f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const
{
    RGBColor L;
    double ndotwi = sr.normal * wi;
    Vector3D r(sr.normal * 2.0 * ndotwi - wi);
    double rdotwo = r * wo;
    
    if (rdotwo > 0.0 ) {
        L = ks * pow(rdotwo, exp);
    }
    
    return L;
}

RGBColor GlossySpecularBRDF::sample_f(const ShadeRec& /*sr*/, Vector3D& /*wi*/, const Vector3D& /*wo*/) const
{
    return black;
}

RGBColor GlossySpecularBRDF::rho(const ShadeRec& /*sr*/, const Vector3D& /*wo*/) const
{
    return black;
}

void GlossySpecularBRDF::setCs(const double r, const double g, const double b)
{
    cs.r = r;
    cs.g = g;
    cs.b = b;
}

