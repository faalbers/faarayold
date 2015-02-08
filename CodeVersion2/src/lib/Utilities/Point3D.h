#ifndef __POINT3D__
#define __POINT3D__

#include "Vector3D.h"
#include "Constants.h"

class Point3D
{
public:
    Point3D();                                          // default constructor
    Point3D(const double _x, const double _y, const double _z); // constructor
    Point3D(const Point3D& p);                                  // constructor
    ~Point3D(void);                                             // destructor

    double x, y, z;

    Point3D operator+ (const Vector3D& rhs) const;

    Vector3D operator- (const Point3D& rhs) const;

    double distance(const Point3D& to) const;
};

ostream& operator<< (ostream& os, const Point3D& rhs);

#endif

