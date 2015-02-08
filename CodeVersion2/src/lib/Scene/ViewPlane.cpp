#include "Scene/ViewPlane.h"
#include "Utilities/Maths.h"
#include "Samplers/MultiJitteredSampler.h"
#include "Samplers/RegularSampler.h"

ViewPlane::ViewPlane()
    :   hres(0),
        vres(0),
        pixelSize(1.0),
        numSamples(1),
        samplerPtr(NULL),
        showOutOfGamut(false),
        gamma(1.0),
        invGamma(1.0)
{
}

ViewPlane::ViewPlane(ViewPlane * const viewPlane)
    :   hres(viewPlane->hres),
        vres(viewPlane->vres),
        pixelSize(viewPlane->pixelSize),
        numSamples(viewPlane->numSamples),
        samplerPtr(viewPlane->samplerPtr),
        showOutOfGamut(viewPlane->showOutOfGamut),
        gamma(viewPlane->gamma),
        invGamma(viewPlane->invGamma)
{
}

ViewPlane::~ViewPlane() 
{
}

void ViewPlane::setGamma(const float& _gamma)
{
    gamma       = _gamma;
    invGamma    = 1.0/gamma;
}

void ViewPlane::setSampler(Sampler* const _samplerPtr)
{
    if (samplerPtr) {
        delete(samplerPtr);
        samplerPtr = NULL;
    }

    samplerPtr = _samplerPtr;
    numSamples = _samplerPtr->getNumSamples();
}

void ViewPlane::setNumSamples(const int _numSamples)
{
    if (samplerPtr) {
        delete(samplerPtr);
        samplerPtr = NULL;
    }
    
    numSamples = _numSamples;
    
    if (numSamples > 1)
        samplerPtr = new MultiJitteredSampler(numSamples);
    else
        samplerPtr = new RegularSampler(numSamples);
}

