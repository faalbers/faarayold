#include "Cameras/PinholeCamera.h"
#include <QtCore/QTime>
#include "Utilities/Constants.h"
#include "Scene/ViewPlane.h"
#include "Utilities/Ray.h"
#include "Scene/World.h"
#include "Utilities/Maths.h"
#include "Utilities/ShadeRec.h"
#include <time.h>
#include <vector>
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"

using namespace std;
using namespace tbb;

// Rendering the pixel using tbb
class PixelTBB
{
public:
    PixelTBB(
        PinholeCamera *_pinholeCameraPtr,
        ViewPlane *_viewPlanePtr,
        Point3D _eye,
        const World * const _worldPtr);

    PinholeCamera       *pinholeCameraPtr;
    ViewPlane           *viewPlanePtr;
    const World * const worldPtr;
    Point3D         eye;
    
    void operator() ( const blocked_range<size_t> &r) const;
    void serial(int range) const;
    
    void pixelTBBProc (Ray& ray) const;
};

PixelTBB::PixelTBB(
    PinholeCamera *_pinholeCameraPtr,
    ViewPlane *_viewPlanePtr,
    Point3D _eye,
    const World * const _worldPtr)
    :   pinholeCameraPtr(_pinholeCameraPtr),
        viewPlanePtr(_viewPlanePtr),
        eye(_eye),
        worldPtr(_worldPtr)
{
}

void PixelTBB::operator() ( const blocked_range<size_t> &r) const
{
    Ray ray;
    ray.origin = eye;
    
    //size_t startID = r.begin();
    //srand(startID*time(NULL));
    for ( size_t i = r.begin(); i != r.end(); ++i ) {
        ray.row = (int) ((float) i / viewPlanePtr->hres);
        ray.col = i % viewPlanePtr->hres;
        ray.index = i;
        ray.numSamples = viewPlanePtr->numSamples;
        pixelTBBProc(ray);
    }
}

void PixelTBB::serial (int range) const
{
    Ray ray;
    ray.origin = eye;

    for ( size_t i = 0; i < range; ++i ) {
        ray.row = (int) ((float) i / viewPlanePtr->hres);
        ray.col = i % viewPlanePtr->hres;
        ray.index = i;
        ray.numSamples = viewPlanePtr->numSamples;
        pixelTBBProc(ray);
        if (ray.col == 0)
            worldPtr->lineUpdate();
    }
}

void PixelTBB::pixelTBBProc (Ray& ray) const
{
    RGBColor        L;
    int             depth = 0;
    Point2D         sp, pp;
    ShadeRec        vpSr(*worldPtr);
    vpSr.vpRay = &ray;
   
    L = black;
    for (int j = 0; j < ray.numSamples; j++) {
        ray.sample = j;
        sp = viewPlanePtr->samplerPtr->sampleUnitSquare(vpSr);
        pp = Point2D(0.5,0.5);
        pp.x = viewPlanePtr->pixelSize * (ray.col - 0.5 * viewPlanePtr->hres + sp.x);
        pp.y = viewPlanePtr->pixelSize * (ray.row - 0.5 * viewPlanePtr->vres + sp.y);
        ray.direction = pinholeCameraPtr->rayDirection(pp);
        L += worldPtr->tracerPtr->traceRay(ray);
        //L += worldPtr->tracerPtr->traceRayMoire(ray, 0.00001);
    }
    L /= viewPlanePtr->numSamples;
    //L *= exposureTime;
    
    worldPtr->drawPixel(ray, L);
}

// Actual PinholeCamera class
PinholeCamera::PinholeCamera(void)
    :   Camera(),
        viewPlaneDistance(100),
        zoom(1.0)
{
}

PinholeCamera::~PinholeCamera(void)
{
}

Vector3D PinholeCamera::rayDirection(const Point2D& samplePoint) const
{
    Vector3D direction = u*samplePoint.x + v*samplePoint.y - w*viewPlaneDistance;
    direction.normalize();
    return direction;
}

void PinholeCamera::renderScene(const World * const worldPtr)
{   
    ViewPlane   viewPlane(worldPtr->viewPlane);

    viewPlane.pixelSize /= zoom;
    QTime timer;

    cout << "Start Pinhole render" << endl;
    timer.start();

    int range = viewPlane.vres*viewPlane.hres;
    cout << "range = " << range << endl;

    PixelTBB pixelTBB( this, &viewPlane, eye, worldPtr);
    pixelTBB.serial(range);
    
    printf("Render SEC: %f\n", (double) timer.elapsed()/1000.0);
    
    //worldPtr->displayColors(myColors);

    //printf("FPS: %f\n", 1000.0 / timer.elapsed());
    printf("Render+DrawSEC: %f\n", (double) timer.elapsed()/1000.0);
}

void PinholeCamera::renderSceneTBB(const World * const worldPtr)
{        
    ViewPlane   viewPlane(worldPtr->viewPlane);

    viewPlane.pixelSize /= zoom;
    QTime timer;

    cout << "Start Pinhole render" << endl;
    timer.start();

    int range = viewPlane.vres*viewPlane.hres;
    cout << "range = " << range << endl;

    parallel_for(blocked_range<size_t>(0, range), PixelTBB( this, &viewPlane, eye, worldPtr) );
    
    printf("Render SEC: %f\n", (double) timer.elapsed()/1000.0);
    
    //worldPtr->displayColors(myColors);

    //printf("FPS: %f\n", 1000.0 / timer.elapsed());
    printf("Render+Draw SEC: %f\n", (double) timer.elapsed()/1000.0);
}


