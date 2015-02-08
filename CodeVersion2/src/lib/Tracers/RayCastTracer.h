#ifndef __RAYCASTTRACER__
#define __RAYCASTTRACER__

#include "Tracers/Tracer.h"
#include "Scene/World.h"
#include "Utilities/RGBColor.h"
#include "Utilities/Ray.h"

class RayCastTracer : public Tracer
{
public:
    RayCastTracer(void);       // default constructor
    RayCastTracer(const World * _worldPtr);   // constructor
    virtual ~RayCastTracer(void);      // destructor
    
    virtual const char* type(void) const { return "RayCastTracer"; }
    virtual RGBColor traceRay(Ray &ray) const;
  
};

#endif

