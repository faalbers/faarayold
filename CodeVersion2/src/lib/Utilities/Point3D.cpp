#include "Point3D.h"
#include "Maths.h"

Point3D::Point3D()
    :x(0.0), y(0.0), z(0.0)
{
}

Point3D::Point3D(const double _x, const double _y, const double _z)
    :x(_x), y(_y), z(_z)
{
}

Point3D::Point3D(const Point3D& p)
    :x(p.x), y(p.y), z(p.z)
{
}

Point3D::~Point3D() 
{}

Point3D Point3D::operator+ (const Vector3D& rhs) const
{
    return Point3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3D Point3D::operator- (const Point3D& rhs) const
{
    return Vector3D(x-rhs.x, y-rhs.y, z-rhs.z); 
}

ostream& operator<< (ostream& os, const Point3D& rhs)
{
    os << "Point3D(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}

double Point3D::distance(const Point3D& to) const
{
	return (sqrt(		(x - to.x) * (x - to.x) 
					+ 	(y - to.y) * (y - to.y)
					+	(z - to.z) * (z - to.z) ));
}
