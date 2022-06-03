#include "Writer.h"


void Write(double **xx, double **yy, double *ts, double ***psi, double ***den) {
   
    printf("\nDone All Calculations. Writing to [%s]...\n", fname);

    int nc_id;

    int ns_id, nt_id;
    int a_id, b_id;

    /* int linedim_id[1]; */
    /* int griddim_id[2]; */
    /* int boxdim_id[3]; */

    /* int xxvar_id, yyvar_id, psivar_id, denvar_id; */

    /* int tsvar_id; */

    // create the nc file.
    NCErrorHandler( nc_create("result.nc", NC_NETCDF4, &nc_id) );

    NCErrorHandler( nc_def_dim(nc_id, "N",  N , &ns_id) );
    NCErrorHandler( nc_def_dim(nc_id, "NT", NT , &nt_id) );

    NCErrorHandler( nc_def_dim(nc_id, "a", a , &a_id) );
    NCErrorHandler( nc_def_dim(nc_id, "b", b , &b_id) );

    /* linedim_id[0] = nt_id; */

    /* griddim_id[0] = ns_id; */
    /* griddim_id[1] = ns_id; */

    /* boxdim_id[0] = nt_id; */
    /* boxdim_id[1] = ns_id; */
    /* boxdim_id[2] = ns_id; */

    // creating the variables
    /* NCErrorHandler( nc_def_var(nc_id, "xx" , NC_DOUBLE, 2, griddim_id, &xxvar_id) ); */
    /* NCErrorHandler( nc_def_var(nc_id, "yy" , NC_DOUBLE, 2, griddim_id, &yyvar_id) ); */

    /* NCErrorHandler( nc_def_var(nc_id, "t"  , NC_DOUBLE, 1, linedim_id, &tsvar_id) ); */

    /* NCErrorHandler( nc_def_var(nc_id, "psi", NC_DOUBLE, 3, boxdim_id, &psivar_id) ); */
    /* NCErrorHandler( nc_def_var(nc_id, "den", NC_DOUBLE, 3, boxdim_id, &denvar_id) ); */

    NCErrorHandler( nc_enddef(nc_id) );

    /* // placing the variables */
    /* NCErrorHandler( nc_put_var_double(nc_id, xxvar_id , &xx[0][0]) ); */
    /* NCErrorHandler( nc_put_var_double(nc_id, yyvar_id , &yy[0][0]) ); */

    /* NCErrorHandler( nc_put_var_double(nc_id, tsvar_id , &ts[0]) ); */
    
    /* NCErrorHandler( nc_put_var_double(nc_id, psivar_id, &psi[0][0][0]) ); */
    /* NCErrorHandler( nc_put_var_double(nc_id, denvar_id, &den[0][0][0]) ); */


    // close the  nc file.
    NCErrorHandler( nc_close(nc_id) );

    return ;
}


void NCErrorHandler(int val) {
    
    /* Error Handler to chech plancing variables has done successfully or not
     * @param val int : error code 
     */
   
    if (val) {
        printf("Error: %s\n", nc_strerror(val));
        exit(2);
    }
}


void WriteSample(char *filename, double ***den) {

    printf("\nWriting Data to [%s]...\n", filename);

    FILE *fptr;
    fptr = fopen(filename, "w");

    if(fptr != NULL) {
        for(int n=0; n<NT; n++){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    fprintf(fptr, "%.5f ", den[n][i][j]);
                }
                fprintf(fptr, "\n");
            }
            fprintf(fptr, "\n");
        }
    }

    fclose(fptr);

    return ;
}
