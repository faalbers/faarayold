#ifndef __MATERIAL__
#define __MATERIAL__

#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"

class Material {
public:
    Material(void);      // default constructor
    virtual ~Material(void);     // destructor

    virtual RGBColor shade(ShadeRec& sr) = 0;
    virtual RGBColor getLe(ShadeRec& sr) const;
    virtual RGBColor areaLightShade(ShadeRec& sr) = 0;

};

#endif

