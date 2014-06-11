#ifndef FAARAY_LAMBERTIANBRDF_H
#define FAARAY_LAMBERTIANBRDF_H
//==============================================================================
#include "brdf.h"
#include "gfa/gfa.h"
#include "gfa/rgbcolor.h"
//==============================================================================
namespace FaaRay {

class TraceThread;

class LambertianBRDF : public BRDF
{
public:
    LambertianBRDF();

    void setCd(
        const GFA::Scalar &r,
        const GFA::Scalar &g,
        const GFA::Scalar &b);

    virtual void rho(TraceThread &ttRef) const;
    virtual void f(TraceThread &ttRef) const;

private:
    GFA::RGBColor   cd_;    // diffuse color
    GFA::Scalar     kd_;    // Diffuse Reflection Coefficient
};
}
#endif // FAARAY_LAMBERTIANBRDF_H
