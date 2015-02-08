#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Point3D.h"
#include "Utilities/Normal.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Ray.h"

class Rectangle : public GeometricObject
{
public:
    Rectangle(void);      // default constructor
    Rectangle(const Point3D& _corner, const Vector3D& __sideA, const Vector3D& __sideB);
    ~Rectangle(void);     // destructor

    void setCorner(const double& x, const double& y, const double& z);
    void setNormal(const double& x, const double& y, const double& z);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadowHit(const Ray& ray, double& tmin) const;

private:
    Point3D     corner; // rectangle corner position
    Normal      normal; // rectangle normal
    Vector3D    sideA;  // side A
    Vector3D    sideB;  // side B
    double      sideALength;  // side A ength
    double      sideBLength;  // side B ength
};

#endif

