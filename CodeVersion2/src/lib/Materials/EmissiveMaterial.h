#ifndef __EMISSIVEMATERIAL__
#define __EMISSIVEMATERIAL__

#include "Materials/Material.h"
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"

class EmissiveMaterial : public Material
{
public:
    EmissiveMaterial(void);      // default constructor
    virtual ~EmissiveMaterial(void);     // destructor

    void setCe(const RGBColor _ce) { ce = _ce; }
    void setLs(const double _ls) { ls = _ls; }


    virtual RGBColor getLe(ShadeRec& sr) const;
    virtual RGBColor shade(ShadeRec& sr);
    virtual RGBColor areaLightShade(ShadeRec& sr);
 
private:
    RGBColor    ce; // color
    double      ls; // radiance scaling factor
};

#endif

