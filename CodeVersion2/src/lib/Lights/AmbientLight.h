#ifndef __AMBIENTLIGHT__
#define __AMBIENTLIGHT__

#include "Lights/Light.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/RGBColor.h"

class AmbientLight : public Light
{
public:
    AmbientLight(void);      // default constructor
    virtual ~AmbientLight(void);     // destructor

    virtual const char* type(void) const { return "AmbientLight"; }
    virtual Vector3D getDirection(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);

    void scaleRadiance(const double b) { ls = b; }
    
private:
    double ls;      // light strength
    RGBColor color; // light color
};

#endif

