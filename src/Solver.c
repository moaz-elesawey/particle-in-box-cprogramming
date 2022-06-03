#include "Solver.h"


void Solve(double **xx, double **yy, double *ts, double ***psi, double ***den) {

    printf("\nStarted Calculations...\n");

    for(int i=0; i<NT; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){

                psi[i][j][k] = pow(sin(nx * xx[j][k] * PI / a), 2) +
                               pow(sin(ny * yy[j][k] * PI / b), 2) +
                               sin(nx * xx[j][k] * PI / a) *
                               sin(ny * yy[j][k] * PI / b) *
                               cos(ts[i]);

                den[i][j][k] = pow(psi[i][j][k], 2);

            }
        }
        if((int) i % 20 == 0)
            printf("Calculation Done for Timestep t = %-5d of %5d\n", i, NT);
    }

    return ;
}

