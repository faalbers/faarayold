#include "geometricobject.h"
#include "material.h"
//==============================================================================
FaaRay::GeometricObject::GeometricObject()
{
}
//==============================================================================
void FaaRay::GeometricObject::setCenter(
    const GFA::Scalar &x,
    const GFA::Scalar &y,
    const GFA::Scalar &z)
{
    center_.x = x;
    center_.y = y;
    center_.z = z;
}
//==============================================================================
void FaaRay::GeometricObject::setMaterialSPtr(ConstMaterialSPtr materialSPtr)
{
    materialSPtr_ = materialSPtr;
}
//==============================================================================
const GFA::Point3D & FaaRay::GeometricObject::getCenter() const
{
    return center_;
}
//==============================================================================
const FaaRay::Material * FaaRay::GeometricObject::getConstMaterialPtr() const
{
    return materialSPtr_.get();
}
