//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel1_l2;
int xdim1_update_halo_kernel1_l2;
int xdim2_update_halo_kernel1_l2;
int xdim3_update_halo_kernel1_l2;
int xdim4_update_halo_kernel1_l2;
int xdim5_update_halo_kernel1_l2;


//user function



void update_halo_kernel1_l2_c_wrapper(
  double * restrict density0_p,
  double * restrict energy0_p,
  double * restrict energy1_p,
  double * restrict u_p,
  double * restrict p_p,
  double * restrict sd_p,
  const int * restrict fields,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double density0 = { density0_p + n_x*1 + n_y * xdim0_update_halo_kernel1_l2*1, xdim0_update_halo_kernel1_l2};
      ptr_double energy0 = { energy0_p + n_x*1 + n_y * xdim1_update_halo_kernel1_l2*1, xdim1_update_halo_kernel1_l2};
      ptr_double energy1 = { energy1_p + n_x*1 + n_y * xdim2_update_halo_kernel1_l2*1, xdim2_update_halo_kernel1_l2};
      ptr_double u = { u_p + n_x*1 + n_y * xdim3_update_halo_kernel1_l2*1, xdim3_update_halo_kernel1_l2};
      ptr_double p = { p_p + n_x*1 + n_y * xdim4_update_halo_kernel1_l2*1, xdim4_update_halo_kernel1_l2};
      ptr_double sd = { sd_p + n_x*1 + n_y * xdim5_update_halo_kernel1_l2*1, xdim5_update_halo_kernel1_l2};
      
  if(fields[FIELD_DENSITY] == 1) OPS_ACC(density0, 0,0) = OPS_ACC(density0, 3,0);
  if(fields[FIELD_ENERGY0] == 1) OPS_ACC(energy0, 0,0) = OPS_ACC(energy0, 3,0);
  if(fields[FIELD_ENERGY1] == 1) OPS_ACC(energy1, 0,0) = OPS_ACC(energy1, 3,0);
  if(fields[FIELD_U] == 1) OPS_ACC(u, 0,0) = OPS_ACC(u, 3,0);
  if(fields[FIELD_P] == 1) OPS_ACC(p, 0,0) = OPS_ACC(p, 3,0);
  if(fields[FIELD_SD] == 1) OPS_ACC(sd, 0,0) = OPS_ACC(sd, 3,0);


    }
  }
}