#ifndef __MULTIPLEOBJECTSTRACER__
#define __MULTIPLEOBJECTSTRACER__

#include "Tracers/Tracer.h"
#include "Scene/World.h"
#include "Utilities/RGBColor.h"
#include "Utilities/Ray.h"

class MultipleObjectsTracer : public Tracer
{
public:
    MultipleObjectsTracer(void);       // default constructor
    MultipleObjectsTracer(World* _worldPtr);   // constructor
    virtual ~MultipleObjectsTracer(void);      // destructor
    
    virtual const char* type(void) const { return "MultipleObjectsTracer"; }
    virtual RGBColor traceRay(const Ray& ray, const int& depth) const;
   
};

#endif

