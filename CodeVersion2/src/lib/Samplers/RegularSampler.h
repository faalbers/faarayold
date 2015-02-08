#ifndef __REGULARSAMPLER__
#define __REGULARSAMPLER__

#include "Samplers/Sampler.h"

class RegularSampler : public Sampler
{
public:
    RegularSampler(void);       // default constructor
    RegularSampler(const int& _numSamples);       // constructor
    virtual ~RegularSampler(void);      // destructor
    
    virtual void generateSamples(void);
};

#endif

