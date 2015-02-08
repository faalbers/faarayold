#include "Samplers/Sampler.h"
#include "Utilities/Maths.h"
#include <algorithm>   // for random_shuffle in Sampler::setup_shuffled_indices
#include <iostream>

using namespace std;

Sampler::Sampler()
    :   numSamples(1),
        numSets(83), // some kind of magical number
        count(0),
        jump(0)
{
	samples.reserve(numSamples * numSets);
	setupShuffledIndices();
}

Sampler::Sampler(const int& _numSamples)
    :   numSamples(_numSamples),
        numSets(83), // some kind of magical number
        count(0),
        jump(0)
{
	samples.reserve(numSamples * numSets);
	setupShuffledIndices();
}

Sampler::~Sampler() 
{
}

// sets up randomly shuffled indices for the samples array
void Sampler::setupShuffledIndices(void)
{
	shuffledIndices.reserve(numSamples * numSets);
	vector<int> indices;
	
	for (int j = 0; j < numSamples; j++)
		indices.push_back(j);
	
	for (int p = 0; p < numSets; p++) { 
		random_shuffle(indices.begin(), indices.end());	
		
		for (int j = 0; j < numSamples; j++)
			shuffledIndices.push_back(indices[j]);
	}	
}

void Sampler::shuffleSamples(void)
{
}

// Maps the 2D sample points to 3D points on a unit hemisphere with a cosine power
// density distribution in the polar angle

void Sampler::mapSamplesToHemisphere(const double exp)
{
	int size = samples.size();

	hemisphereSamples.reserve(numSamples * numSets);
		
	for (int j = 0; j < size; j++) {
		double cosPhi = cos(2.0 * PI * samples[j].x);
		double sinPhi = sin(2.0 * PI * samples[j].x);
		double cosTheta = pow((1.0 - samples[j].y), 1.0 / (exp + 1.0));
		double sinTheta = sqrt (1.0 - cosTheta * cosTheta);
        //double cosTheta = cos(0.5 * PI * samples[j].y);
        //double sinTheta = sin(0.5 * PI * samples[j].y);
		double pu = sinTheta * cosPhi;
		double pv = sinTheta * sinPhi;
		double pw = cosTheta;
		hemisphereSamples.push_back(Point3D(pu, pv, pw));
	}
}

Point2D Sampler::sampleUnitSquare(ShadeRec& sr) const
{   
    if (sr.vpRay->numSamples != numSamples)
        return Point2D(0.5, 0.5);
    
    if (sr.vpRay->sample == 0)                    // start of a new pixel, see pages 101 and 102
		sr.vpRay->sampleJump = (randInt() % numSets) * numSamples; // random index jump in numSets jumps
 
	return (samples[sr.vpRay->sampleJump + shuffledIndices[sr.vpRay->sampleJump + sr.vpRay->sample]]);
}

Point3D Sampler::sampleHemisphere(ShadeRec& sr) const
{
    if (sr.vpRay->numSamples != numSamples)
        return Point3D(0.5, 0.5, 0.5);
    
    if (sr.vpRay->sample == 0)                    // start of a new pixel, see pages 101 and 102
		sr.vpRay->sampleJump = (randInt() % numSets) * numSamples; // random index jump in numSets jumps
 
	return (hemisphereSamples[sr.vpRay->sampleJump + shuffledIndices[sr.vpRay->sampleJump + sr.vpRay->sample]]);
}

