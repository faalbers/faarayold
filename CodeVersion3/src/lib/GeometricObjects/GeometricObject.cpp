#include "GeometricObject.h"
#include "FaaRay/TraceThread.h"
#include "FaaRay/Material.h"
//==============================================================================
FaaRay::GeometricObject::GeometricObject(void)
{
}
//==============================================================================
FaaRay::GeometricObject::~GeometricObject(void)
{
}
//==============================================================================
void FaaRay::GeometricObject::setMaterialSPtr(ConstMaterialSPtr materialSPtr)
{
    materialSPtr_ = materialSPtr;
}
//==============================================================================
FaaRay::ConstMaterialSPtr FaaRay::GeometricObject::getMaterialSPtr() const
{
    return materialSPtr_;
}

