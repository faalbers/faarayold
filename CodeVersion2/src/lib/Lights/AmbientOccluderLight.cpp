#include "Lights/AmbientOccluderLight.h"
#include "Utilities/Point3D.h"
#include "Scene/World.h"
#include "Utilities/Ray.h"

AmbientOccluderLight::AmbientOccluderLight(void)
    : Light(),
    ls(1.0),
    color(1.0),
    samplerPtr(NULL),
    minAmount(0.0)
{}

AmbientOccluderLight::~AmbientOccluderLight(void)
{}

void AmbientOccluderLight::setSampler(Sampler* _samplerPtr)
{
    if (samplerPtr != NULL) {
        delete samplerPtr;
        samplerPtr = NULL;
    }

    samplerPtr = _samplerPtr;

    samplerPtr->mapSamplesToHemisphere(1);
}

Vector3D AmbientOccluderLight::getDirection(ShadeRec& sr)
{
    // Moved u v w here for multi threading
    Vector3D u, v, w;

    w = sr.normal;
    // jitter up vector in case normal is vertical
    v = w ^ Vector3D(0.0072, 1.0, 0.0034);
    v.normalize();
    u = v ^ w;
    
    Point3D sp = samplerPtr->sampleHemisphere(sr);
	return (u*sp.x + v*sp.y + w*sp.z);
}

RGBColor AmbientOccluderLight::L(ShadeRec& sr)
{
    Ray shadowRay;
    shadowRay.origin = sr.hitPoint;
    shadowRay.direction = getDirection(sr);
    
    if (inShadow(shadowRay, sr))
        return (minAmount * color * ls);
    else
        return (color * ls);
}

bool AmbientOccluderLight::inShadow(const Ray& ray, const ShadeRec& sr) const
{
    double t;
    int numObjects = sr.world.objects.size();

    for (int j = 0; j < numObjects; j++)
        if (sr.world.objects[j]->shadowHit(ray, t))
            return true;
    
    return false;
}

