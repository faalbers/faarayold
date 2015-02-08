#include "Normal.h"
#include "Maths.h"

Normal::Normal()
    :x(0.0), y(0.0), z(0.0)
{
}

Normal::Normal(const double _x, const double _y, const double _z)
    :x(_x), y(_y), z(_z)
{
}

Normal::Normal(const Normal& n)
    :x(n.x), y(n.y), z(n.z)
{
}

Normal::~Normal() 
{}

Normal Normal::operator+ (const Normal& rhs) const
{
    return Normal(x + rhs.x, y + rhs.y, z + rhs.z);
}

Normal Normal::operator- (const Normal& rhs) const
{
    return Normal(x - rhs.x, y - rhs.y, z - rhs.z);
}

Normal Normal::operator+ (const Vector3D& rhs) const
{
    return Normal(x + rhs.x, y + rhs.y, z + rhs.z);
}

Normal Normal::operator- (const Vector3D& rhs) const
{
    return Normal(x - rhs.x, y - rhs.y, z - rhs.z);
}

double Normal::operator* (const Vector3D& rhs) const
{
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

// cross multiply
Normal Normal::operator^ (const Vector3D& rhs) const
{
    return Normal(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

Normal Normal::operator^ (const Normal& rhs) const
{
    return Normal(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

Normal Normal::operator* (const double& rhs) const
{
    return Normal(x * rhs, y * rhs, z * rhs);
}

Normal Normal::operator/ (const double& rhs) const
{
    return Normal(x / rhs, y / rhs, z / rhs);
}

Normal& Normal::operator= (const Vector3D& rhs)
{
	if (this == (Normal*) &rhs)
		return (*this);

	x = rhs.x; y = rhs.y; z = rhs.z;

	return (*this);
}

Normal& Normal::normalize(void)
{	
	double len = length();
	x /= len; y /= len; z /= len;
	return (*this);
} 

double Normal::length(void) const
{
    return sqrt(x * x + y * y + z * z);
}

