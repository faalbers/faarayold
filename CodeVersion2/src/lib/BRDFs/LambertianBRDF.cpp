#include "BRDFs/LambertianBRDF.h"
#include "Utilities/Constants.h"

LambertianBRDF::LambertianBRDF(void)
    :BRDF(),
    kd(1.0),
    cd(white)
{
}
LambertianBRDF::~LambertianBRDF(void)
{
}

RGBColor LambertianBRDF::f(const ShadeRec& /*sr*/, const Vector3D& /*wi*/, const Vector3D& /*wo*/) const
{
    return (cd * kd * invPI);
}

RGBColor LambertianBRDF::sample_f(const ShadeRec& /*sr*/, Vector3D& /*wi*/, const Vector3D& /*wo*/) const
{
    return cd;
}

RGBColor LambertianBRDF::rho(const ShadeRec& /*sr*/, const Vector3D& /*wo*/) const
{
    return (cd * kd);
}

void LambertianBRDF::setCd(const double r, const double g, const double b)
{
    cd.r = r;
    cd.g = g;
    cd.b = b;
}

