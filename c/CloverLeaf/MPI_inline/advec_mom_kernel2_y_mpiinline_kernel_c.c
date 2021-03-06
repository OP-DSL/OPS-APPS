//
// auto-generated by ops.py
//

int xdim0_advec_mom_kernel2_y;
int xdim1_advec_mom_kernel2_y;
int xdim2_advec_mom_kernel2_y;
int xdim3_advec_mom_kernel2_y;


//user function



void advec_mom_kernel2_y_c_wrapper(
  double * restrict vel1_p,
  double * restrict node_mass_post_p,
  double * restrict node_mass_pre_p,
  double * restrict mom_flux_p,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double vel1 = { vel1_p + n_x*1 + n_y * xdim0_advec_mom_kernel2_y*1, xdim0_advec_mom_kernel2_y};
      const ptr_double node_mass_post = { node_mass_post_p + n_x*1 + n_y * xdim1_advec_mom_kernel2_y*1, xdim1_advec_mom_kernel2_y};
      const ptr_double node_mass_pre = { node_mass_pre_p + n_x*1 + n_y * xdim2_advec_mom_kernel2_y*1, xdim2_advec_mom_kernel2_y};
      const ptr_double mom_flux = { mom_flux_p + n_x*1 + n_y * xdim3_advec_mom_kernel2_y*1, xdim3_advec_mom_kernel2_y};
      

  OPS_ACC(vel1, 0,0) = ( OPS_ACC(vel1, 0,0) * OPS_ACC(node_mass_pre, 0,0)  +
    OPS_ACC(mom_flux, 0,-1) - OPS_ACC(mom_flux, 0,0) ) / OPS_ACC(node_mass_post, 0,0);

    }
  }
}
