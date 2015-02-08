#include "Samplers/RegularSampler.h"
#include "Utilities/Maths.h"

RegularSampler::RegularSampler(void)
    :   Sampler()
{
    generateSamples();
}

RegularSampler::RegularSampler(const int& _numSamples)
    :   Sampler(_numSamples)
{
    generateSamples();
}

RegularSampler::~RegularSampler(void)
{
}
   
void RegularSampler::generateSamples(void)
{
    int n = (int) sqrt((float) numSamples);

    for (int p = 0; p < numSets; p++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                Point2D sp((k + 0.5) / n, (j + 0.5) / n);
                samples.push_back(sp);
            }
        }
    }
}

