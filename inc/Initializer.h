#ifndef INITIALIZER_H_INCLUDED
#define INITIALIZER_H_INCLUDED

#include "Parameters.h"

#include <stdio.h>

void Init(double *xs, double *ys, double **xx, double **yy, double *ts,
          double ***psi, double ***den);

void LineSpace(double *xs, int size, double inc);
void MeshGrid(double *xs, double *ys, double **xx, double **yy);

void PrintMat1D(double *x);
void PrintMat2D(double **xx);
void PrintMat3D(double ***den, int n_samples);


#endif //INITIALIZER_H_INCLUDED
