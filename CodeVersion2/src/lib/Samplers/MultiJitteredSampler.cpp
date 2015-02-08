#include "Samplers/MultiJitteredSampler.h"
#include "Utilities/Maths.h"

MultiJitteredSampler::MultiJitteredSampler(void)
    :   Sampler()
{
    generateSamples();
}

MultiJitteredSampler::MultiJitteredSampler(const int& _numSamples)
    :   Sampler(_numSamples)
{
    generateSamples();
}

MultiJitteredSampler::~MultiJitteredSampler(void)
{
}
   
void MultiJitteredSampler::generateSamples(void)
{
    int n = (int) sqrt((float) numSamples);

    for (int p = 0; p < numSets; p++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                Point2D sp((k + randFloat()) / n, (j + randFloat()) / n);
                samples.push_back(sp);
            }
        }
    }
}

