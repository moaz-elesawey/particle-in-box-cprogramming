#ifndef WRITER_H_INCLUDED
#define WRITER_H_INCLUDED

#include "Parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <netcdf.h>


void Write(double **xx, double **yy, double *ts, double ***psi, double ***den);

void WriteSample(char *filename, double ***den);

void NCErrorHandler(int val);

#endif //WRITER_H_INCLUDED
