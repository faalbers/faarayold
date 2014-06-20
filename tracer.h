#ifndef FAARAY_TRACER_H
#define FAARAY_TRACER_H
//==============================================================================
#include <memory>
#include "faaray_global.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

/*!
 * \brief The Tracer base class
 */
class FAARAYSHARED_EXPORT Tracer
{
public:
    Tracer();

    virtual void traceRay(TraceThread &ttRef) const = 0;
};
typedef std::shared_ptr<Tracer> TracerSPtr;
typedef std::shared_ptr<const Tracer> ConstTracerSPtr;
}
#endif // FAARAY_TRACER_H
