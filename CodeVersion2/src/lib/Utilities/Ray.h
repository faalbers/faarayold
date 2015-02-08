#ifndef __RAY__
#define __RAY__

#include "Point3D.h"
#include "Vector3D.h"
#include "Normal.h"
#include "Constants.h"

class Ray
{
public:
    Ray(void);              // default constructor
	Ray(const Ray& ray);    // copy constructor
    Ray(const Point3D& _origin, const Vector3D& _direction); // constructor
    ~Ray(void);             // destructor

    Point3D     origin;  // origin
    Vector3D    direction;  // direction
    
    int         row;        // view plane pixel row
    int         col;        // view plane pixel column
    int         index;      // view plane pixel index
    int         numSamples; // filter sample count
    int         sample;     // filter sample index
    int         sampleJump; // filter sample index

    Ray& operator= (const Ray& rhs);    // assignement operator

};

ostream& operator<< (ostream& os, const Ray& rhs);

#endif

