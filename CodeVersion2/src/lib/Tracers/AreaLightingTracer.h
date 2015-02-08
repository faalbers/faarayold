#ifndef __AREALIGHTINGTRACER__
#define __AREALIGHTINGTRACER__

#include "Tracers/Tracer.h"
#include "Scene/World.h"
#include "Utilities/RGBColor.h"
#include "Utilities/Ray.h"

class AreaLightingTracer : public Tracer
{
public:
    AreaLightingTracer(void);       // default constructor
    AreaLightingTracer(const World* _worldPtr);   // constructor
    virtual ~AreaLightingTracer(void);      // destructor
    
    virtual const char* type(void) const { return "AreaLightingTracer"; }
    virtual RGBColor traceRay(Ray &ray) const;
  
};

#endif

