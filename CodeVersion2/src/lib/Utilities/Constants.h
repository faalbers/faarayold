#ifndef __CONSTANTS__
#define __CONSTANTS__

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#include <stdlib.h>			// for RAND_MAX
#include "RGBColor.h"

const double    kEpsilon 	= 0.0001;
const double	kHugeValue	= 1.0E10;

const RGBColor  black   = RGBColor(0.0);
const RGBColor  grey   = RGBColor(0.5);
const RGBColor  white   = RGBColor(1.0);
const RGBColor  red     = RGBColor(1.0, 0.0, 0.0);
const RGBColor  yellow  = RGBColor(1.0, 1.0, 0.0);

const float 	invRANDMAX = 1.0 / (float) RAND_MAX;
const float     PI = 3.14159265359;
const float     invPI = 1.0 / PI;

const string    INDENT  = string("  ");

#endif
