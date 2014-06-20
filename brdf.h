#ifndef FAARAY_BRDF_H
#define FAARAY_BRDF_H
//==============================================================================
namespace FaaRay {

class TraceThread;

/*!
 * \brief The BRDF base class
 */
class BRDF
{
public:
    BRDF();

    virtual void rho(TraceThread &ttRef) const = 0;
    virtual void f(TraceThread &ttRef) const = 0;
};
}
#endif // FAARAY_BRDF_H
