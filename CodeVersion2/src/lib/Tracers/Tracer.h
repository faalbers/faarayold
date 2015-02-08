#ifndef __TRACER__
#define __TRACER__

#include "Utilities/RGBColor.h"
#include "Utilities/Ray.h"

class World; // can't #include "World" here because World contains a Trace pointer

class Tracer
{
public:
    Tracer();       // default constructor
    Tracer(const World * _worldPtr);   // constructor
    virtual ~Tracer(void);      // destructor
    
    virtual const char* type(void) const = 0;
    virtual RGBColor traceRay(Ray& ray) const = 0;


    RGBColor traceRayMoire(const Ray& ray, const double& mult) const;
    
protected:
    const World *  worldPtr;
};

#endif

