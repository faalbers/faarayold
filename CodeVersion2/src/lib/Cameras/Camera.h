#ifndef __CAMERA__
#define __CAMERA__

#include "Utilities/Point3D.h"
#include "Utilities/Vector3D.h"

class World;

class Camera
{
public:
    Camera(void);      // default constructor
    virtual ~Camera(void);     // destructor

    void setEye(const double x, const double y, const double z);
    void setEye(const Point3D pos);
    void setLookAt(const double x, const double y, const double z);
    void setLookAt(const Point3D pos);
   
    void            computeUVW(void);
    virtual void    renderScene(const World * const world) = 0;
    virtual void    renderSceneTBB(const World * const world) = 0;

protected:
    Point3D     eye;
    Point3D     lookAt;
    Vector3D    up;
    Vector3D    u, v, w;
    float       exposureTime;
};

#endif

