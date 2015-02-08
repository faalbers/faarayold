#ifndef __MATHS__
#define __MATHS__

#include <math.h>
#include "Constants.h"

using namespace std;

int     randInt(int l, int h);   
float   randFloat(int l, float h);

// inlined functions

inline int      randInt(void)  { return(rand()); }
inline float    randFloat(void) { return((float)randInt() * invRANDMAX); }

#endif

