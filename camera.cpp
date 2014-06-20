#include "camera.h"
#include <iostream>
//==============================================================================
/*!
 * Constructor that sets up vector with Y Up and compute UVW.
 */
FaaRay::Camera::Camera()
{
    up_.y = 1.0; // set up vector
    computeUVW_();
}
//==============================================================================
/*!
 * Set position of camera's eye and re-compute UVW.
 *
 * \param eye New eye position for camera
 */
void FaaRay::Camera::setEye(const GFA::Point3D &eye)
{
    eye_ = eye;
    computeUVW_();
}
//==============================================================================
/*!
 * Set position for camera to look at and re-compute UVW.
 *
 * \param lookAt New position for camera to look at
 */
void FaaRay::Camera::setLookAt(const GFA::Point3D &lookAt)
{
    lookAt_ = lookAt;
    computeUVW_();
}
//==============================================================================
void FaaRay::Camera::computeUVW_()
{
    // take care of up and down singularities
    if ( eye_.x == lookAt_.x && eye_.z == lookAt_.z ) {
        if ( eye_.y > lookAt_.y ) {
            u_.x = 0.0; u_.y = 0.0; u_.z = 1.0;
            v_.x = 1.0; v_.y = 0.0; v_.z = 0.0;
            w_.x = 0.0; w_.y = 1.0; w_.z = 0.0;
            return;
        } else if ( eye_.y < lookAt_.y ) {
            u_.x = 1.0; u_.y = 0.0; u_.z = 0.0;
            v_.x = 0.0; v_.y = 0.0; v_.z = 1.0;
            w_.x = 0.0; w_.y = -1.0; w_.z = 0.0;
            return;
        }
    }

    w_ = eye_ - lookAt_;
    w_.normalize();
    u_ = up_ ^ w_;
    u_.normalize();
    v_ = w_ ^ u_;
}
