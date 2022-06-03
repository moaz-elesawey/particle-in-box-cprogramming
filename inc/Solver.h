#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

#include "Parameters.h"
#include <stdio.h>
#include <math.h>


void Solve(double **xx, double **yy, double *ts, double ***psi, double ***den);


#endif //SOLVER_H_INCLUDED
