//==============================================================================
#ifndef __FAARAY_TRACER_H__
#define __FAARAY_TRACER_H__
//==============================================================================
#include <memory>
#include "FaaRay/FaaRay.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

class FAARAY_DLL_PUBLIC Tracer
{
    public:
        Tracer();
        virtual ~Tracer(void);
        
        virtual void traceRay(TraceThread &ttRef) const = 0;
};
                                  
typedef std::shared_ptr<Tracer> TracerSPtr;
typedef std::shared_ptr<const Tracer> ConstTracerSPtr;

}
//==============================================================================

#endif
//==============================================================================

