#include "camera.h"
#include <iostream>
//==============================================================================
FaaRay::Camera::Camera()
{
}
//==============================================================================
void FaaRay::Camera::setEye(const GFA::Point3D &eye)
{
    eye_ = eye;
}
//==============================================================================
void FaaRay::Camera::setLookAt(const GFA::Point3D &lookAt)
{
    lookAt_ = lookAt;
}
