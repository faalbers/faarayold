#ifndef __PIXEL__
#define __PIXEL__

#include "RGBColor.h"

class Pixel
{
public:
    Pixel();                    // default constructor
    Pixel(const int _x, const int _y, const RGBColor& _color);  // constructor
    Pixel(const Pixel& p);              // constructor
    ~Pixel(void);                       // destructor

    int         x, y;
    RGBColor    color;
};

#endif

