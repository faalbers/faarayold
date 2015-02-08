#include "Scene/World.h"
#include "Utilities/Point3D.h"
#include "Cameras/PinholeCamera.h"
#include "Tracers/RayCastTracer.h"
#include "Tracers/AreaLightingTracer.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Ray.h"
#include "Utilities/Normal.h"
#include "Lights/AmbientLight.h"
#include "Lights/AmbientOccluderLight.h"
#include "Samplers/MultiJitteredSampler.h"
#include "Lights/PointLight.h"
#include "Materials/PhongMaterial.h"
#include "Materials/MatteMaterial.h"
#include "Materials/EmissiveMaterial.h"
#include "GeometricObjects/Sphere.h"
#include "GeometricObjects/Plane.h"
#include "GeometricObjects/Rectangle.h"
#include "GeometricObjects/Disc.h"
#include "GeometricObjects/OpenCylinder.h"
#include "GUI/TraceThread.h"

World::World()
    :   viewPlane(new ViewPlane()),
        cameraPtr(NULL),
        tracerPtr(NULL),
        ambientPtr(NULL),
        multiCPUs(true)
{
    buildScene();
}

World::~World() 
{
    delete viewPlane;
}

void World::setPinholeCamera(
    const Point3D &eye,
    const Point3D &lookAt,
    const double  &viewPlaneDistance,
    const double  &zoom)
{
    if (cameraPtr) {
        delete cameraPtr;
        cameraPtr = NULL;
    }
    
    PinholeCamera* pinholePtr = new PinholeCamera;
    pinholePtr->setEye(eye);
    pinholePtr->setLookAt(lookAt);
    pinholePtr->setViewPlaneDistance(viewPlaneDistance);
    pinholePtr->setZoom(zoom);
    pinholePtr->computeUVW();
    cameraPtr = pinholePtr;
}

void World::setRayCastTracer()
{
    if (tracerPtr) {
        delete tracerPtr;
        tracerPtr = NULL;
    }
    tracerPtr = new RayCastTracer(this);
}

void World::setAreaLightingTracer()
{
    if (tracerPtr) {
        delete tracerPtr;
        tracerPtr = NULL;
    }
    tracerPtr = new AreaLightingTracer(this);
}

void World::setAmbientLight(const double &scaleRadiance)
{
    if (ambientPtr) {
        delete ambientPtr;
        ambientPtr = NULL;
    }
    AmbientLight* tempPtr = new AmbientLight;
    tempPtr->scaleRadiance(scaleRadiance);
    ambientPtr = tempPtr;
}

void World::setAmbientOccluderLight(const double &scaleRadiance)
{
    if (ambientPtr) {
        delete ambientPtr;
        ambientPtr = NULL;
    }
    AmbientOccluderLight* tempPtr = new AmbientOccluderLight;
    MultiJitteredSampler* samplerPtr = new MultiJitteredSampler(viewPlane->numSamples);
    tempPtr->setSampler(samplerPtr);    // sampler pointer needs to be set or we get a seg fault
    tempPtr->setMinAmount(0.0);
    tempPtr->scaleRadiance(scaleRadiance);
    ambientPtr = tempPtr;
}

void World::render() const
{
    if (!cameraPtr) {
        cout << "ERROR: Camera not set !" << endl;
        return;
    }
    
    cout << "Settings:" << endl;
    cout <<  "tracerPtr = " << tracerPtr->type() << endl;
    cout <<  "ambientPtr = " << ambientPtr->type() << endl;

    if (multiCPUs)
        cameraPtr->renderSceneTBB(this);
    else
        cameraPtr->renderScene(this);
    
}

void World::drawPixel(const Ray &ray, const RGBColor &color) const
{
    traceThreadPtr->imagePtr->setPixel(ray.col, viewPlane->vres-ray.row-1, color.getQRgb() );
}

void World::lineUpdate() const
{
    traceThreadPtr->updateImage();
}

ShadeRec  World::hitObjects(const Ray& ray) const
{
    ShadeRec    sr(*this);
    double      t;
    Normal      normal;
    Point3D     localHitPoint;
    double      tmin        = kHugeValue;
    int         numObjects  = objects.size();
    
    for (int j = 0; j < numObjects; j++) {
        if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
            sr.hitAnObject  = true;
            tmin            = t;
            sr.materialPtr = objects[j]->getMaterial();
            sr.hitPoint = ray.origin + ray.direction * t;
            normal = sr.normal;
            localHitPoint = sr.localHitPoint;
        }
    }
    
    if (sr.hitAnObject) {
        sr.t = tmin;
        sr.normal = normal;
        sr.localHitPoint = localHitPoint;
    }
        
    return sr;
}

void World::buildScene(void)
{
    PointLight* pointLightPtr;
    pointLightPtr = new PointLight;
    pointLightPtr->setLocation(10,5, 4);
    pointLightPtr->scaleRadiance(1.2);
    pointLightPtr->castShadows(true);
    addLight(pointLightPtr);

    PhongMaterial* phongMaterialAPtr = new PhongMaterial;
    phongMaterialAPtr->setCd(1,1,0);
    phongMaterialAPtr->setKs(0.5);       // specular coefficient
    phongMaterialAPtr->setExp(50.0);     // specular exponent

    PhongMaterial* phongMaterialBPtr = new PhongMaterial;
    phongMaterialBPtr->setCd(1,1,1);
    phongMaterialBPtr->setKs(0.5);       // specular coefficient
    phongMaterialBPtr->setExp(50.0);     // specular exponent

    EmissiveMaterial* emissiveMaterialAPtr = new EmissiveMaterial;
    emissiveMaterialAPtr->setCe(white);
    emissiveMaterialAPtr->setLs(1.0);

    MatteMaterial* matteMaterialAPtr = new MatteMaterial;
    matteMaterialAPtr->setCd(1,1,0);
    
    Sphere* spherePtr;
    spherePtr = new Sphere;
    spherePtr->setCenter(2.2, 0.0, 0.0);
    spherePtr->setRadius(1.0);
    spherePtr->setMaterial(matteMaterialAPtr);
    addObject(spherePtr);
    spherePtr = new Sphere;
    spherePtr->setCenter(-2.2, 0.0, 0.0);
    spherePtr->setRadius(1.0);
    spherePtr->setMaterial(phongMaterialAPtr);
    addObject(spherePtr);
    spherePtr = new Sphere;
    spherePtr->setCenter(0.0, 0.0, 2.2);
    spherePtr->setRadius(1.0);
    spherePtr->setMaterial(phongMaterialAPtr);
    addObject(spherePtr);
    spherePtr = new Sphere;
    spherePtr->setCenter(0.0, 0.0, -2.2);
    spherePtr->setRadius(1.0);
    spherePtr->setMaterial(emissiveMaterialAPtr);
    addObject(spherePtr);

    OpenCylinder* cylinderPtr = new OpenCylinder(-1.0, 2.0, 0.0);
    cylinderPtr->setMaterial(phongMaterialAPtr);
    addObject(cylinderPtr);
    
    Plane* planePtr = new Plane(Point3D(0.0, -1.0, 0.0), Normal(0.0, 1.0, 0.0));
    planePtr->setMaterial(phongMaterialBPtr);
    addObject(planePtr);
    
    Disc* discPtr = new Disc(Point3D(1.5, 1.4, 0.5), Normal(0.0, 1.0, 0.0), 1.0);
    discPtr->setMaterial(matteMaterialAPtr);
    addObject(discPtr);

    Rectangle* rectanglePtr = new Rectangle(Point3D(0.0, 1.5, 0.0), Vector3D(2.0, 0.0, 0.0), Vector3D(1.0, 0.0, -1.0));
    rectanglePtr->setMaterial(matteMaterialAPtr);
    addObject(rectanglePtr);
}

void World::addObject(GeometricObject* objectPtr)
{                                       
    objects.push_back(objectPtr);
}

void World::addLight(Light* lightPtr)
{                                       
    lights.push_back(lightPtr);
}

void World::hello() const
{
    cout << "Hello World!" << endl;
}
