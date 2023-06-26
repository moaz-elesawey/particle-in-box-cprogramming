#ifndef PARAMETERS_H_INCLUDED
#define PARAMETERS_H_INCLUDED

#include <math.h>

#define N 150

#define nx 1
#define ny 2
#define nz 3

#define NT 150

#define a 2.0
#define b 2.0
#define c 2.0

#define dx a / (float) N
#define dy b / (float) N
#define dz c / (float) N

#define dt 9.0 / (float) NT

#define h 1.0
#define m 1.0

#define PI 3.1415926

#define G sqrt(8)/(a*b*c)

#define fname "result.nc"

#endif //PARAMETERS_H_INLCUDED

