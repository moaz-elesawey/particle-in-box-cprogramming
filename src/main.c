#include <stdio.h>
#include <stdlib.h>

#include "Parameters.h"
#include "Initializer.h"
#include "Solver.h"
#include "Writer.h"



int main(int argc, char **argv) {


    // hold box axes x, y, and z
    double *xs = (double*) calloc(N, sizeof(double));
    double *ys = (double*) calloc(N, sizeof(double));
    double *zs = (double*) calloc(N, sizeof(double));

    // hold the timesteps of the simulation
    double *ts = (double*) calloc(NT, sizeof(double));

    // hold the grid of x and y to solve fror
    double *xx = (double*) calloc(N*N, sizeof(double));
    double *yy = (double*) calloc(N*N, sizeof(double));

    // hold the wave function and the density
    double *psi = (double*) calloc(NT*N*N, sizeof(double));
    double *den = (double*) calloc(NT*N*N, sizeof(double));


    // Initialize the variables
    Init(xs, ys, xx, yy, ts, psi, den);

    // Solve the Porblem and Store res in psi and den
    Solve(xx, yy, ts, psi, den);

	// Write to H5 File
	WriteH5(xx, yy, ts, psi, den);

    // free up the heap memory
    free(xs);
    free(ys);
    free(zs);
    free(ts);

	free(xx);
	free(yy);

	free(psi);
	free(den);

    return EXIT_SUCCESS;
}

