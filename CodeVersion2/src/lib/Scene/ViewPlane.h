#ifndef __VIEWPLANE__
#define __VIEWPLANE__

#include "Samplers/Sampler.h"
#include "Utilities/Point2D.h"

class ViewPlane
{
public:
    ViewPlane();      // default constructor
    ViewPlane(ViewPlane * const viewPlane);
    ~ViewPlane();     // destructor

    void setGamma(const float& _gamma);
    float getInvGamma() const { return invGamma; }
    
    void setSampler(Sampler * const _samplerPtr);
    void setNumSamples(const int _numSamples);
    const Sampler * getSampler() const { return samplerPtr; }
    
    int         hres;
    int         vres;
    float       pixelSize;
    int         numSamples;
    bool        showOutOfGamut;

    const Sampler   *samplerPtr;
    
private:
    float           gamma;
    float           invGamma;
};

#endif

