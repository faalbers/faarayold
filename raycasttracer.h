#ifndef FAARAY_RAYCASTTRACER_H
#define FAARAY_RAYCASTTRACER_H
//==============================================================================
#include <memory>
#include "faaray_global.h"
#include "tracer.h"
//==============================================================================
namespace FaaRay {

class TraceThread;

class FAARAYSHARED_EXPORT RayCastTracer : public Tracer
{
public:
    RayCastTracer();

    virtual void traceRay(TraceThread &ttRef) const;
};
typedef std::shared_ptr<RayCastTracer>  RayCastTracerSPtr;
RayCastTracerSPtr FAARAYSHARED_EXPORT MakeRayCastTracerSPtr();
}
#endif // FAARAY_RAYCASTTRACER_H
