#ifndef __FAARAY_RAYCASTTRACER_H__
#define __FAARAY_RAYCASTTRACER_H__
//==============================================================================
#include <memory>
#include "FaaRay/FaaRay.h"
#include "Tracer.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

class FAARAY_DLL_PUBLIC RayCastTracer : public Tracer
{
    public:
        virtual ~RayCastTracer(void);

        virtual void traceRay(TraceThread &ttRef) const;
};
                                  
typedef std::shared_ptr<RayCastTracer>  RayCastTracerSPtr;
RayCastTracerSPtr FAARAY_DLL_PUBLIC MakeRayCastTracerSPtr();

}
//==============================================================================
#endif
//==============================================================================

