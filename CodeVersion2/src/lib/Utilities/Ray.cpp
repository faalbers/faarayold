#include "Ray.h"

Ray::Ray(void)
    : origin(0.0, 0.0, 0.0), 
      direction(0.0, 0.0, 1.0)
{
}

Ray::Ray (const Ray& ray)
	: 	origin(ray.origin), 
		direction(ray.direction) 
{
}

Ray::Ray(const Point3D& _origin, const Vector3D& _direction)
    : origin(_origin),
      direction(_direction)
{
}

Ray::~Ray(void)
{
}

Ray& Ray::operator= (const Ray& rhs) {
	
	if (this == &rhs)
		return (*this);
		
	origin = rhs.origin; 
	direction = rhs.direction; 

	return (*this);	
}

ostream& operator<< (ostream& os, const Ray& rhs)
{
    os << "class Ray: " << endl;
    os << rhs.origin << endl;
    os << rhs.direction << endl;
    return os;
}
