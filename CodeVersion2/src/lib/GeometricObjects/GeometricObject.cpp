#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Constants.h"

GeometricObject::GeometricObject(void)
    :   type(0),
        materialPtr(NULL),
        color(black)
{
}

GeometricObject::~GeometricObject(void)
{
}

void GeometricObject::setColor(const float& r, const float& g, const float& b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

Material* GeometricObject::getMaterial(void) const
{
	return (materialPtr);
}

void GeometricObject::setMaterial(Material* _materialPtr)
{
    if (materialPtr) {
        delete materialPtr;
        materialPtr = NULL;
    }
	materialPtr = _materialPtr;
}

