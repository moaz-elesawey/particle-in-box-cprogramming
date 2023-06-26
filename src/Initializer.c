#include "Initializer.h"


void Init(double *xs, double *ys, double *xx, double *yy, double *ts,
          double *psi, double *den) {

    printf("\nInitializing Variables...\n");

    LineSpace(ts, NT, dt);
    LineSpace(xs, N , dx);
    LineSpace(ys, N , dy);

    MeshGrid(xs, ys, xx, yy);

    return ;
}


void LineSpace(double *xs, int size, double inc){
    
    /* create a linspace array from an incremental value inc */

    for(int i=0; i<size; i++) {
        xs[i] = (double)(inc * i);
    }

    return ;
}


void MeshGrid(double *xs, double *ys, double *xx, double *yy){
    /* create a meshgrid from linear arrays */


    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            xx[j*N + i] = xs[i];
            yy[i*N + j] = ys[i];
        }
    }

    return ;
}


/* void PrintMat1D(double *x) { */
/*     printf("===============================\n"); */
    
/*     for(int i=0; i<NT; i++) */
/*         printf("%.2f ", x[i]); */

/*     printf("\n===============================\n"); */

/*     return ; */

/* } */


/* void PrintMat2D(double **xx) { */

/*     printf("===============================\n"); */
/*     for(int i=0; i<N; i++) { */
/*         for(int j=0; j<N; j++) { */
/*             printf("%.2f ", xx[i][j]); */
/*         } */
/*         printf("\n"); */
/*     } */
/*     printf("===============================\n"); */

/*     return ; */
/* } */


/* void PrintMat3D(double ***den, int n_samples) { */

/*     for (int n=0; n<n_samples; n++){ */
/*         printf("===============================\n"); */
/*         for(int i=0; i<N; i++) { */
/*             for(int j=0; j<N; j++) { */
/*                 printf("%.2f ", den[n][i][j]); */
/*             } */
/*             printf("\n"); */
/*         } */
/*         printf("===============================\n"); */
/*     } */

/*     return ; */
/* } */


