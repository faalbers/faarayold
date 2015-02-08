#include "Vector3D.h"
#include "Normal.h"
#include "Point3D.h"
#include "Maths.h"

Vector3D::Vector3D()
    :x(0), y(0), z(0)
{
}

Vector3D::Vector3D(const double _x, const double _y, const double _z)
    :x(_x), y(_y), z(_z)
{
}

Vector3D::Vector3D(const Vector3D& v)
    :x(v.x), y(v.y), z(v.z)
{
}

Vector3D::Vector3D(const Normal& n)
    :x(n.x), y(n.y), z(n.z)
{
}

Vector3D::~Vector3D() 
{}

Vector3D Vector3D::operator- (void) const
{
	return (Vector3D(-x, -y, -z));    
}

Vector3D Vector3D::operator+ (const Vector3D& rhs) const
{
    return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3D Vector3D::operator- (const Vector3D& rhs) const
{
    return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3D Vector3D::operator- (const Point3D& rhs) const
{
    return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

void Vector3D::normalize(void)
{
    double dom = 1.0 / sqrt(x*x + y*y + z*z);
    x *= dom;
    y *= dom;
    z *= dom;
}

// dot multiply
double Vector3D::operator* (const Normal& rhs) const
{
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

double Vector3D::operator* (const Vector3D& rhs) const
{
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

// cross multiply
Vector3D Vector3D::operator^ (const Vector3D& rhs) const
{
    return Vector3D(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

Vector3D Vector3D::operator^ (const Normal& rhs) const
{
    return Vector3D(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

Vector3D Vector3D::operator* (const double& rhs) const
{
    return Vector3D(x * rhs, y * rhs, z * rhs);
}

Vector3D Vector3D::operator/ (const double& rhs) const
{
    return Vector3D(x / rhs, y / rhs, z / rhs);
}

ostream& operator<< (ostream& os, const Vector3D& rhs)
{
    os << "Vector3D(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";

    return os;
}

Vector3D& Vector3D::hat(void)
{	
	double len = length();
	x /= len; y /= len; z /= len;
	return (*this);
} 

double Vector3D::length(void) const
{
    return sqrt(x * x + y * y + z * z);
}


