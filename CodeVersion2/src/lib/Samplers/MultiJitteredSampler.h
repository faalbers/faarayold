#ifndef __MULTIJITTEREDSAMPLER__
#define __MULTIJITTEREDSAMPLER__

#include "Samplers/Sampler.h"

class MultiJitteredSampler : public Sampler
{
public:
    MultiJitteredSampler(void);       // default constructor
    MultiJitteredSampler(const int& _numSamples);       // constructor
    virtual ~MultiJitteredSampler(void);      // destructor
    
    virtual void generateSamples(void);

};

#endif

