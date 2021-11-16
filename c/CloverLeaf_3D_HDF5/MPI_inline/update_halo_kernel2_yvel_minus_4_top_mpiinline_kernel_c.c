//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel2_yvel_minus_4_top;
int ydim0_update_halo_kernel2_yvel_minus_4_top;
int xdim1_update_halo_kernel2_yvel_minus_4_top;
int ydim1_update_halo_kernel2_yvel_minus_4_top;


//user function



void update_halo_kernel2_yvel_minus_4_top_c_wrapper(
  double * restrict yvel0_p,
  double * restrict yvel1_p,
  const int * restrict fields,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        ptr_double yvel0 = { yvel0_p + n_x*1 + n_y * xdim0_update_halo_kernel2_yvel_minus_4_top*1 + n_z * xdim0_update_halo_kernel2_yvel_minus_4_top * ydim0_update_halo_kernel2_yvel_minus_4_top*1, xdim0_update_halo_kernel2_yvel_minus_4_top, ydim0_update_halo_kernel2_yvel_minus_4_top};
        ptr_double yvel1 = { yvel1_p + n_x*1 + n_y * xdim1_update_halo_kernel2_yvel_minus_4_top*1 + n_z * xdim1_update_halo_kernel2_yvel_minus_4_top * ydim1_update_halo_kernel2_yvel_minus_4_top*1, xdim1_update_halo_kernel2_yvel_minus_4_top, ydim1_update_halo_kernel2_yvel_minus_4_top};
        
  if(fields[FIELD_YVEL0] == 1) OPS_ACC(yvel0, 0,0,0) = -OPS_ACC(yvel0, 0,-4,0);
  if(fields[FIELD_YVEL1] == 1) OPS_ACC(yvel1, 0,0,0) = -OPS_ACC(yvel1, 0,-4,0);

      }
    }
  }
}