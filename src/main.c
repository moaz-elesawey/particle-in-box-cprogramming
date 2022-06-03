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
    double **xx = (double**) calloc(N*N, sizeof(double));
    double **yy = (double**) calloc(N*N, sizeof(double));

    // hold the wave function and the density
    double ***psi = (double***) calloc(NT*N*N, sizeof(double));
    double ***den = (double***) calloc(NT*N*N, sizeof(double));

    // creates the grids arrays
    for(int i=0; i<N; i++) {
        xx[i] = (double*) calloc(N, sizeof(double));
        yy[i] = (double*) calloc(N, sizeof(double));
    }

    // creates the wavefunction array
    for(int i=0; i<NT; i++) {
        psi[i] = (double**) calloc(N*N, sizeof(double));
        den[i] = (double**) calloc(N*N, sizeof(double));
        for(int j=0; j<N; j++){
            psi[i][j] = (double*) calloc(N, sizeof(double));
            den[i][j] = (double*) calloc(N, sizeof(double));
        }
    }


    // Initialize the variables
    Init(xs, ys, xx, yy, ts, psi, den);

    // Solve the Porblem and Store res in psi and den
    Solve(xx, yy, ts, psi, den);

    // Write out the results to NetCDF file
    Write(xx, yy, ts, psi, den);

    WriteSample("density.txt", den);
    WriteSample("wavefunction.txt", psi);

    // free up the heap memory
    free(xs);
    free(ys);
    free(zs);
    free(ts);

    for(int i=0; i<N; i++){
        free(xx[i]);
        free(yy[i]);
    }

    for(int i=0; i<NT; i++){
        for(int j=0; j<N; j++){
            free(psi[i][j]);
            free(den[i][j]);
        }
    }

    return EXIT_SUCCESS;
}

