#include "Solver.h"


void Solve(double *xx, double *yy, double *ts, double *psi, double *den) {

    printf("\nStarted Calculations...\n");

    for(int i=0; i<NT; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){

                psi[i*NT*N + j*N + k] = pow(sin(nx * xx[j*N + k] * PI / a), 2) +
                               pow(sin(ny * yy[j*N + k] * PI / b), 2) +
                               sin(nx * xx[j*NT + k] * PI / a) *
                               sin(ny * yy[j*NT + k] * PI / b) *
                               cos(ts[i]);

                den[i*NT*N + j*N + k] = pow(psi[i*NT*N + j*N + k], 2);

            }
        }
        if((int) i % 20 == 0)
            printf("Calculation Done for Timestep t = [%3d/%3d]\n", i, NT);
    }

    return ;
}

