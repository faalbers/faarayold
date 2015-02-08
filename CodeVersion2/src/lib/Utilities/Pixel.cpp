#include "Pixel.h"

Pixel::Pixel()
    :x(0), y(0)
{
}

Pixel::Pixel(const int _x, const int _y, const RGBColor& _color)
    :x(_x), y(_y), color(_color)
{
}

Pixel::Pixel(const Pixel& p)
    :x(p.x), y(p.y), color(p.color)
{
}

Pixel::~Pixel() 
{}


