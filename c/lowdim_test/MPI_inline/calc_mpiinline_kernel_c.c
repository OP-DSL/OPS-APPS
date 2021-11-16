//
// auto-generated by ops.py
//

int xdim0_calc;
int ydim0_calc;
int xdim1_calc;
int ydim1_calc;
int xdim2_calc;
int ydim2_calc;
int xdim3_calc;
int ydim3_calc;
int xdim4_calc;
int ydim4_calc;
int xdim5_calc;
int ydim5_calc;
int xdim6_calc;
int ydim6_calc;


//user function



void calc_c_wrapper(
  double * restrict dat3D_p,
  double * restrict dat2D_xy_p,
  double * restrict dat2D_yz_p,
  double * restrict dat2D_xz_p,
  double * restrict dat1D_x_p,
  double * restrict dat1D_y_p,
  double * restrict dat1D_z_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        ptr_double dat3D = { dat3D_p + n_x*1 + n_y * xdim0_calc*1 + n_z * xdim0_calc * ydim0_calc*1, xdim0_calc, ydim0_calc};
        const ptr_double dat2D_xy = { dat2D_xy_p + n_x*1 + n_y * xdim1_calc*1 + n_z * xdim1_calc * ydim1_calc*0, xdim1_calc, ydim1_calc};
        const ptr_double dat2D_yz = { dat2D_yz_p + n_x*0 + n_y * xdim2_calc*1 + n_z * xdim2_calc * ydim2_calc*1, xdim2_calc, ydim2_calc};
        const ptr_double dat2D_xz = { dat2D_xz_p + n_x*1 + n_y * xdim3_calc*0 + n_z * xdim3_calc * ydim3_calc*1, xdim3_calc, ydim3_calc};
        const ptr_double dat1D_x = { dat1D_x_p + n_x*1 + n_y * xdim4_calc*0 + n_z * xdim4_calc * ydim4_calc*0, xdim4_calc, ydim4_calc};
        const ptr_double dat1D_y = { dat1D_y_p + n_x*0 + n_y * xdim5_calc*1 + n_z * xdim5_calc * ydim5_calc*0, xdim5_calc, ydim5_calc};
        const ptr_double dat1D_z = { dat1D_z_p + n_x*0 + n_y * xdim6_calc*0 + n_z * xdim6_calc * ydim6_calc*1, xdim6_calc, ydim6_calc};
        
  OPS_ACC(dat3D, 0,0,0) = OPS_ACC(dat2D_xy, 0,0,0) +
                           OPS_ACC(dat2D_yz, 0,0,0) +
                           OPS_ACC(dat2D_xz, 0,0,0) +
                           OPS_ACC(dat1D_x, 0,0,0) +
                           OPS_ACC(dat1D_y, 0,0,0) +
                           OPS_ACC(dat1D_z, 0,0,0);

      }
    }
  }
}
