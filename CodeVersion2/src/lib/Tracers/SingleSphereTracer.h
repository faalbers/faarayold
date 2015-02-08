#ifndef __SINGLESPHERETRACER__
#define __SINGLESPHERETRACER__

#include "Tracers/Tracer.h"
#include "Scene/World.h"
#include "Utilities/RGBColor.h"
#include "Utilities/Ray.h"

class SingleSphereTracer : public Tracer
{
public:
    SingleSphereTracer(void);       // default constructor
    SingleSphereTracer(World* _worldPtr);   // constructor
    virtual ~SingleSphereTracer(void);      // destructor
    
    virtual const char* type(void) const { return "SingleSphereTracer"; }
    virtual RGBColor traceRay(const Ray& ray) const;
    
};

#endif

