#ifndef __VECTOR3D__
#define __VECTOR3D__

#include "Constants.h"

class Normal;
class Point3D;

class Vector3D
{
public:
    Vector3D(void);                                         // default constructor
    Vector3D(const double _x, const double _y, const double _z);    // constructor
    Vector3D(const Vector3D& v);                                    // constructor
    Vector3D(const Normal& v);                                    // constructor
    ~Vector3D(void);                                                // destructor

    double x, y, z;
    
    void normalize(void);

    Vector3D operator- (void) const;
    
    Vector3D operator+ (const Vector3D& rhs) const;
    Vector3D operator- (const Vector3D& rhs) const;
    Vector3D operator- (const Point3D& rhs) const;

    // dot multiply
    double operator* (const Vector3D& rhs) const;
    double operator* (const Normal& rhs) const;
    
    // cross multiply
    Vector3D operator^ (const Vector3D& rhs) const;
    Vector3D operator^ (const Normal& rhs) const;

    // double multiply
    Vector3D operator* (const double& rhs) const;
    Vector3D operator/ (const double& rhs) const;
    
    // normalize
    Vector3D& hat(void);
    
    double length(void) const;
};

ostream& operator<< (ostream& os, const Vector3D& rhs);

#endif

