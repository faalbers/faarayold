#include "Point2D.h"

Point2D::Point2D()
    :x(0.0), y(0.0)
{
}

Point2D::Point2D(const double _x, const double _y)
    :x(_x), y(_y)
{
}

Point2D::Point2D(const Point2D& p)
    :x(p.x), y(p.y)
{
}

Point2D::~Point2D() 
{}


