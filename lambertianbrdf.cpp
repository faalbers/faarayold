#include "lambertianbrdf.h"
#include "tracethread.h"
//==============================================================================
FaaRay::LambertianBRDF::LambertianBRDF() :
    kd_(1.0)
{
}
//==============================================================================
void FaaRay::LambertianBRDF::setCd(
    const GFA::Scalar &r,
    const GFA::Scalar &g,
    const GFA::Scalar &b)
{
    cd_.r = r; cd_.g = g; cd_.b = b;
}
//==============================================================================
void FaaRay::LambertianBRDF::rho(TraceThread &ttRef) const
{
    ttRef.srRhoColor = cd_*kd_;

}
//==============================================================================
void FaaRay::LambertianBRDF::f(TraceThread &ttRef) const
{
    ttRef.srFColor = cd_*kd_ * GFA::invPI;
}
