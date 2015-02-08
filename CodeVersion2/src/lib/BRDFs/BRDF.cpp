#include "BRDFs/BRDF.h"
#include "Utilities/Constants.h"

RGBColor BRDF::f(const ShadeRec& /*sr*/, const Vector3D& /*wi*/, const Vector3D& /*wo*/) const
{
	return (black);
}

RGBColor BRDF::sample_f(const ShadeRec& /*sr*/, Vector3D& /*wi*/, const Vector3D& /*wo*/) const
{
	return (black);
}

RGBColor BRDF::rho(const ShadeRec& /*sr*/, const Vector3D& /*wo*/) const
{
	return (black);
}

