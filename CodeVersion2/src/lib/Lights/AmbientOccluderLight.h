#ifndef __AMBIENTOCCLUDERLIGHT__
#define __AMBIENTOCCLUDERLIGHT__

#include "Lights/Light.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/RGBColor.h"
#include "Samplers/Sampler.h"
#include "Utilities/Ray.h"

class AmbientOccluderLight : public Light
{
public:
    AmbientOccluderLight(void);      // default constructor
    virtual ~AmbientOccluderLight(void);     // destructor

    void setSampler(Sampler* _samplerPtr);
    
    virtual const char* type(void) const { return "AmbientOccluderLight"; }
    virtual Vector3D getDirection(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool inShadow(const Ray& ray, const ShadeRec& sr) const;

    void scaleRadiance(const double b) { ls = b; }
    void setMinAmount(const double m) { minAmount = m; }
    
private:
    double      ls;      // light strength
    RGBColor    color; // light color
    Sampler*    samplerPtr;
    RGBColor    minAmount;
};

#endif

