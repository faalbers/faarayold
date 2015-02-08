#include "Cameras/Camera.h"
#include "Scene/World.h"

Camera::Camera()
    : exposureTime(1.0)
{
    up.y = 1;
}

Camera::~Camera() 
{}

void Camera::setEye(const double x, const double y, const double z)
{
    eye.x = x;
    eye.y = y;
    eye.z = z;
}

void Camera::setEye(const Point3D pos)
{
    eye.x = pos.x;
    eye.y = pos.y;
    eye.z = pos.z;
}

void Camera::setLookAt(const double x, const double y, const double z)
{
    lookAt.x = x;
    lookAt.y = y;
    lookAt.z = z;
}

void Camera::setLookAt(const Point3D pos)
{
    lookAt.x = pos.x;
    lookAt.y = pos.y;
    lookAt.z = pos.z;
}

void Camera::computeUVW(void)
{
    // take care of up and down singularities
    if ( eye.x == lookAt.x && eye.z == lookAt.z ) {
        if ( eye.y > lookAt.y ) {
            u = Vector3D(0, 0, 1);
            v = Vector3D(1, 0, 0);
            w = Vector3D(0, 1, 0);
            return;
        } else if ( eye.y < lookAt.y ) {
            u = Vector3D(1, 0, 0);
            v = Vector3D(0, 0, 1);
            w = Vector3D(0, -1, 0);
            return;
        }
    }

    w = eye - lookAt;
    w.normalize();
    u = up ^ w;
    u.normalize();
    v = w ^ u;
}


