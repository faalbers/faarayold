#ifndef __POINT2D__
#define __POINT2D__

class Point2D
{
public:
    Point2D();                          // default constructor
    Point2D(const double _x, const double _y);  // constructor
    Point2D(const Point2D& p);                  // constructor
    ~Point2D(void);                             // destructor

    double x, y;

};

#endif

