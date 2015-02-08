#ifndef __RGBCOLOR__
#define __RGBCOLOR__

#include <iostream>
#include <stdio.h>
#include <QtGui/QColor>

using namespace std;

class RGBColor
{
public:
    RGBColor(void);                                     // default constructor
    RGBColor(const RGBColor& _color);                           // copy constructor
    RGBColor(const double& _r, const double& _g, const double& _b);// constructor
    RGBColor(const double& grey);                                // constructor
    ~RGBColor(void);                                            // destructor

    float r, g, b;

    RGBColor powc(double invGamma) const;
    QRgb getQRgb() const;

    RGBColor operator+ (const RGBColor& rhs) const;
    RGBColor operator- (const RGBColor& rhs) const;
    
    RGBColor operator* (const double& rhs) const;
    RGBColor operator* (const RGBColor& rhs) const;
    RGBColor operator/ (const double& rhs) const;
   
    RGBColor& operator= (const RGBColor& rhs);
    RGBColor& operator+= (const RGBColor& rhs);
    RGBColor& operator/= (const RGBColor& rhs);
    RGBColor& operator*= (const double& rhs);
    RGBColor& operator*= (const RGBColor& rhs);
    
};

ostream& operator<< (ostream& os, const RGBColor& rhs);

#endif

