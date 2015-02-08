#include "RGBColor.h"
#include "Maths.h"

RGBColor::RGBColor(void)
    : r(0.0), g(0.0), b(0.0)
{
}

RGBColor::RGBColor(const RGBColor& _color)
    : r(_color.r), g(_color.g), b(_color.b)
{
}

RGBColor::RGBColor(const double& _r, const double& _g, const double& _b)
    : r(_r), g(_g), b(_b)
{
}

RGBColor::RGBColor(const double& grey)
    : r(grey), g(grey), b(grey)
{
}

RGBColor::~RGBColor(void)
{
}

RGBColor RGBColor::operator+ (const RGBColor& rhs) const
{
    return RGBColor(r + rhs.r, g + rhs.g, b + rhs.b);
}

RGBColor RGBColor::operator- (const RGBColor& rhs) const
{
    return RGBColor(r - rhs.r, g - rhs.g, b - rhs.b);
}

RGBColor RGBColor::operator* (const double& rhs) const
{
    return RGBColor(r * rhs, g * rhs, b * rhs);
}

RGBColor RGBColor::operator* (const RGBColor& rhs) const
{
    return RGBColor(r * rhs.r, g * rhs.g, b * rhs.b);
}

RGBColor RGBColor::operator/ (const double& rhs) const
{
    return RGBColor(r / rhs, g / rhs, b / rhs);
}

RGBColor& RGBColor::operator= (const RGBColor& rhs)
{
	if (this == &rhs)
		return (*this);

	r = rhs.r; g = rhs.g; b = rhs.b;

	return (*this);
}

RGBColor& RGBColor::operator+= (const RGBColor& rhs)
{
	r += rhs.r; g += rhs.g; b += rhs.b;

	return (*this);
}

RGBColor& RGBColor::operator/= (const RGBColor& rhs)
{
	r /= rhs.r; g /= rhs.g; b /= rhs.b;

	return (*this);
}

RGBColor& RGBColor::operator*= (const double& rhs)
{
	r *= rhs; g *= rhs; b *= rhs;

	return (*this);
}

RGBColor& RGBColor::operator*= (const RGBColor& rhs)
{
	r *= rhs.r; g *= rhs.g; b *= rhs.b;

	return (*this);
}

RGBColor RGBColor::powc(double invGamma) const {
	return (RGBColor(pow(r, invGamma), pow(g, invGamma), pow(b, invGamma)));
}

ostream& operator<< (ostream& os, const RGBColor& rhs)
{
    os << "RGBColor(" << rhs.r << ", " << rhs.g << ", " << rhs.b << ")";
    return os;
}

QRgb RGBColor::getQRgb() const
{
    QColor color;
    double maxValue = 1.0/max(r, max(g, b));
    
    if (maxValue < 1.0)
        color.setRgbF ( r*maxValue, g*maxValue, b*maxValue, 1.0 );
    else
        color.setRgbF ( r, g, b, 1.0 );

    return color.rgba();
}
