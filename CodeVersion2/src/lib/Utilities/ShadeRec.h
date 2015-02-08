#ifndef __SHADEREC__
#define __SHADEREC__

#include "Normal.h"
#include "Point3D.h"
#include "RGBColor.h"
#include "Ray.h"

class World;
class Material;

class ShadeRec
{
public:
    ShadeRec(const World& _world);   // constructor
    ShadeRec(const ShadeRec& sr);       // copy constructor
    ~ShadeRec(void);                    // destructor

    Point3D     localHitPoint;  // for attaching textures to objects
    Point3D     hitPoint;       // world coordinate hit point
    Normal      normal;         // normal at hit point
    
    bool        hitAnObject;    // did the ray hit an object
    RGBColor    color;          // only used in chapter 3
    Material*   materialPtr;    // nearest object's material
    Ray         ray;            // for specular highlights
    Ray*        vpRay;          // view plane ray
    int         depth;          // recursion depth
    Vector3D    dir;            // for area lights
    double      t;              // ray parameter    

    void copyData(const ShadeRec& rhs);
    RGBColor colorXNormal(void) const;
    RGBColor colorYNormal(void) const;
    RGBColor colorZNormal(void) const;
    RGBColor colorXYZNormal(void) const;
    const World&  world;
};

#endif

