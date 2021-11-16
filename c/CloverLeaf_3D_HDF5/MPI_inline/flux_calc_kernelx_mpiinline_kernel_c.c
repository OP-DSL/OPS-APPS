//
// auto-generated by ops.py
//

int xdim0_flux_calc_kernelx;
int ydim0_flux_calc_kernelx;
int xdim1_flux_calc_kernelx;
int ydim1_flux_calc_kernelx;
int xdim2_flux_calc_kernelx;
int ydim2_flux_calc_kernelx;
int xdim3_flux_calc_kernelx;
int ydim3_flux_calc_kernelx;


//user function



void flux_calc_kernelx_c_wrapper(
  double * restrict vol_flux_x_p,
  double * restrict xarea_p,
  double * restrict xvel0_p,
  double * restrict xvel1_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        ptr_double vol_flux_x = { vol_flux_x_p + n_x*1 + n_y * xdim0_flux_calc_kernelx*1 + n_z * xdim0_flux_calc_kernelx * ydim0_flux_calc_kernelx*1, xdim0_flux_calc_kernelx, ydim0_flux_calc_kernelx};
        const ptr_double xarea = { xarea_p + n_x*1 + n_y * xdim1_flux_calc_kernelx*1 + n_z * xdim1_flux_calc_kernelx * ydim1_flux_calc_kernelx*1, xdim1_flux_calc_kernelx, ydim1_flux_calc_kernelx};
        const ptr_double xvel0 = { xvel0_p + n_x*1 + n_y * xdim2_flux_calc_kernelx*1 + n_z * xdim2_flux_calc_kernelx * ydim2_flux_calc_kernelx*1, xdim2_flux_calc_kernelx, ydim2_flux_calc_kernelx};
        const ptr_double xvel1 = { xvel1_p + n_x*1 + n_y * xdim3_flux_calc_kernelx*1 + n_z * xdim3_flux_calc_kernelx * ydim3_flux_calc_kernelx*1, xdim3_flux_calc_kernelx, ydim3_flux_calc_kernelx};
        

  OPS_ACC(vol_flux_x, 0,0,0) = 0.125 * dt * (OPS_ACC(xarea, 0,0,0)) *
  ( OPS_ACC(xvel0, 0,0,0) + OPS_ACC(xvel0, 0,1,0) + OPS_ACC(xvel0, 0,0,1) + OPS_ACC(xvel0, 0,1,1) +
    OPS_ACC(xvel1, 0,0,0) + OPS_ACC(xvel1, 0,1,0) + OPS_ACC(xvel1, 0,0,1) + OPS_ACC(xvel1, 0,1,1));

      }
    }
  }
}