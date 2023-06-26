#include "Writer.h"
#include "hdf5.h"


void WriteH5(double *xx, double *yy, double *ts, double *psi, double *den) {
	
	char *filename = "result.h5";

    hid_t file, den_ds, psi_ds, xx_ds, yy_ds;
	hid_t dataspace_3d, dataspace_2d;

    herr_t status;

	int rank_3d = 3, rank_2d = 2;

	hsize_t dim_3d[3] = {NT, N, N};
	hsize_t dim_2d[2] = {N, N};

	double * data = (double *) calloc(N*N*NT, sizeof(double));

    file = H5Fcreate(filename, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

    dataspace_3d = H5Screate_simple(rank_3d, dim_3d, NULL);
    dataspace_2d = H5Screate_simple(rank_2d, dim_2d, NULL);


    den_ds = H5Dcreate(file, "density", H5T_NATIVE_DOUBLE, dataspace_3d, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    status = H5Dwrite(den_ds, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, &(den[0]));

    psi_ds = H5Dcreate(file, "wavefunction", H5T_NATIVE_DOUBLE, dataspace_3d, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    status = H5Dwrite(psi_ds, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, &(psi[0]));

    xx_ds = H5Dcreate(file, "xx", H5T_NATIVE_DOUBLE, dataspace_2d, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    status = H5Dwrite(xx_ds, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, &(xx[0]));

    yy_ds = H5Dcreate(file, "yy", H5T_NATIVE_DOUBLE, dataspace_2d, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    status = H5Dwrite(yy_ds, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, &(yy[0]));

	free(data);

    H5Sclose(dataspace_3d);
    H5Sclose(dataspace_2d);
    H5Dclose(psi_ds);
    H5Dclose(den_ds);
    H5Dclose(xx_ds);
    H5Dclose(yy_ds);
    H5Fclose(file);
	
	printf("Done Writing Data to result.h5 with status %d\n", status);

	return ;
}

