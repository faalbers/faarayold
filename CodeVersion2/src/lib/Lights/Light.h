#ifndef __LIGHT__
#define __LIGHT__

#include "Utilities/ShadeRec.h"
#include <string>

using namespace std;

class Light {
public:
    Light(void);      // default constructor
    virtual ~Light(void);     // destructor

    virtual const char* type(void) const = 0;
    virtual Vector3D getDirection(ShadeRec& sr) = 0;
    virtual RGBColor L(ShadeRec& sr) = 0;
    virtual bool inShadow(const Ray& ray, const ShadeRec& sr) const;
    virtual double G(ShadeRec& sr) const;
    virtual double pdf(ShadeRec& sr) const;

    bool castsShadows(void) const;
    bool castShadows(bool _shadows) { shadows = _shadows; }

protected:
    bool                shadows;
};

#endif

