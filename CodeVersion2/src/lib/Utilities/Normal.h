#ifndef __NORMAL__
#define __NORMAL__

#include "Vector3D.h"

class Normal
{
public:
    Normal();                                           // default constructor
    Normal(const double _x, const double _y, const double _z);  // constructor
    Normal(const Normal& n);                                    // constructor
    ~Normal(void);                                              // destructor

    double x, y, z;

    Normal operator+ (const Normal& rhs) const;
    Normal operator- (const Normal& rhs) const;
    Normal operator+ (const Vector3D& rhs) const;
    Normal operator- (const Vector3D& rhs) const;

    // dot multiply
    double operator* (const Normal& rhs) const;
    double operator* (const Vector3D& rhs) const;

    // cross multiply
    Normal operator^ (const Normal& rhs) const;
    Normal operator^ (const Vector3D& rhs) const;

    // double multiply
    Normal operator* (const double& rhs) const;
    Normal operator/ (const double& rhs) const;
    
    Normal& operator= (const Vector3D& rhs);
    
    Normal& normalize(void);
    double  length(void) const;
};

#endif

