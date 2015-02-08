#ifndef __SAMPLER__
#define __SAMPLER__

#include <vector>
#include "Utilities/Point2D.h"
#include "Utilities/Point3D.h"
#include "Utilities/ShadeRec.h"

using namespace std;

class Sampler
{
public:
    Sampler(void);       // default constructor
    Sampler(const int& _numSamples);       // constructor
    virtual ~Sampler(void);      // destructor
    
    virtual void generateSamples(void) = 0;

    void setNumSamples(const int& _numSamples) { numSamples = _numSamples; }
    int getNumSamples(void) const { return numSamples; }
    unsigned long getCount(void) const { return count; }
    void setupShuffledIndices(void);
    void shuffleSamples(void);
	void mapSamplesToHemisphere(const double p);
    
    Point2D sampleUnitSquare(ShadeRec& s) const;
	Point3D	sampleHemisphere(ShadeRec& s) const;
    
protected:
    int             numSamples;
    int             numSets;
    vector<int>     shuffledIndices;
    vector<Point2D> samples;
	vector<Point3D> hemisphereSamples;
    unsigned long   count;
    int             jump;
};

#endif

