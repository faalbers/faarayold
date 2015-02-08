#ifndef __PINHOLECAMERA__
#define __PINHOLECAMERA__

#include "Cameras/Camera.h"
#include "Utilities/Vector3D.h"
#include "Utilities/Point2D.h"
#include "Scene/World.h"

class PinholeCamera : public Camera
{
public:
    PinholeCamera(void);      // default constructor
    virtual ~PinholeCamera(void);     // destructor

    void setViewPlaneDistance(const double _viewPlaneDistance)
    {   viewPlaneDistance = _viewPlaneDistance; }
    void setZoom(const double _zoom) {   zoom = _zoom; }
    
    Vector3D        rayDirection(const Point2D& point) const;
    virtual void    renderScene(const World * const worldPtr);
    virtual void    renderSceneTBB(const World * const worldPtr);

private:
    double  viewPlaneDistance;
    double  zoom;
};

#endif

