#ifndef __DISC
#define __DISC

#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Point3D.h"
#include "Utilities/Normal.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Ray.h"

class Disc : public GeometricObject
{
public:
    Disc(void);      // default constructor
    Disc(const Point3D& _point, const Normal& _normal, const double& _radius);   // constructor
    ~Disc(void);     // destructor

    void setPoint(const double& x, const double& y, const double& z);
    void setNormal(const double& x, const double& y, const double& z);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadowHit(const Ray& ray, double& tmin) const;

private:
    Point3D point;  // point through which disc passes
    Normal  normal; // disc normal
    double  radius; // disc radius
};

#endif

