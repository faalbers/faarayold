#include "GeometricObjects/OpenCylinder.h"
#include "Utilities/Maths.h"

OpenCylinder::OpenCylinder(void)
    :   GeometricObject(),
        y0(-1.0),
        y1(1.0),
        radius(1.0),
        invRadius(1.0)
{
    type = 2;
}

OpenCylinder::OpenCylinder(const double bottom, const double top, const double r)
    :   GeometricObject(),
        y0(bottom),
        y1(top),
        radius(1.0),
        invRadius(1.0/radius)
{
}

OpenCylinder::~OpenCylinder(void)
{
}

bool OpenCylinder::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
	double t;
	double ox = ray.origin.x;
	double oy = ray.origin.y;
	double oz = ray.origin.z;
	double dx = ray.direction.x;
	double dy = ray.direction.y;
	double dz = ray.direction.z;
	
	double a = dx * dx + dz * dz;  	
	double b = 2.0 * (ox * dx + oz * dz);					
	double c = ox * ox + oz * oz - radius * radius;
	double disc = b * b - 4.0 * a * c ;

			
	if (disc < 0.0)
		return(false);
	else {	
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;    // smaller root
		
		if (t > kEpsilon) {
			double yhit = oy + t * dy;
			
			if (yhit > y0 && yhit < y1) {
				tmin = t;
				sr.normal = Normal((ox + t * dx) * invRadius, 0.0, (oz + t * dz) * invRadius);
				
				// test for hitting from inside
			
				if (-ray.direction * sr.normal < 0.0)
					sr.normal = sr.normal * (-1.0);
					
				sr.localHitPoint = ray.origin + ray.direction * tmin;
				
				return (true);
			}
		} 
		
		t = (-b + e) / denom;    // larger root
		
		if (t > kEpsilon) {
			double yhit = oy + t * dy;
			
			if (yhit > y0 && yhit < y1) {
				tmin = t;
				sr.normal = Normal((ox + t * dx) * invRadius, 0.0, (oz + t * dz) * invRadius);
				
				// test for hitting inside surface
			
				if (-ray.direction * sr.normal < 0.0)
					sr.normal = sr.normal * (-1.0);
					
				sr.localHitPoint = ray.origin + ray.direction * tmin;
	
				return (true);
			}
		} 
	}
	
	return (false);			
}

bool OpenCylinder::shadowHit(const Ray& ray, double& tmin) const
{
	double t;
	double ox = ray.origin.x;
	double oy = ray.origin.y;
	double oz = ray.origin.z;
	double dx = ray.direction.x;
	double dy = ray.direction.y;
	double dz = ray.direction.z;
	
	double a = dx * dx + dz * dz;  	
	double b = 2.0 * (ox * dx + oz * dz);					
	double c = ox * ox + oz * oz - radius * radius;
	double disc = b * b - 4.0 * a * c ;

			
	if (disc < 0.0)
		return(false);
	else {	
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;    // smaller root
		
		if (t > kEpsilon) {
			double yhit = oy + t * dy;
			
			if (yhit > y0 && yhit < y1) {
				tmin = t;
				return (true);
			}
		} 
		
		t = (-b + e) / denom;    // larger root
		
		if (t > kEpsilon) {
			double yhit = oy + t * dy;
			
			if (yhit > y0 && yhit < y1) {
				tmin = t;
				return (true);
			}
		} 
	}
	
	return (false);			
}

