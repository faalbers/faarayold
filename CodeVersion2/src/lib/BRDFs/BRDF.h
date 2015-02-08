#ifndef __BRDF__
#define __BRDF__

#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Vector3D.h"
#include "Samplers/Sampler.h"

class BRDF {
public:
    // BRDF
    virtual RGBColor f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const = 0;
    virtual RGBColor sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const = 0;
    // Bihemispherical reflectance.
    virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const = 0;

protected:
    Sampler *sampler_ptr;
};

#endif

