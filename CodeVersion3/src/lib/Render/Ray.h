#ifndef __FAARAY_RAY_H__
#define __FAARAY_RAY_H__
//==============================================================================
#include "GFA/Point3D.h"
#include "GFA/Vector3D.h"
//==============================================================================
namespace FaaRay
{

class Ray
{
    public:
        Ray();
        Ray(const Ray &rayRef);
        Ray(const GFA::Point3D &originRef, const GFA::Vector3D &directionRef);
        
        void setOrigin(const GFA::Point3D &originRef);
    
    private:
        GFA::Point3D     origin_;
        GFA::Vector3D    direction_;
};
}
//==============================================================================
#endif

