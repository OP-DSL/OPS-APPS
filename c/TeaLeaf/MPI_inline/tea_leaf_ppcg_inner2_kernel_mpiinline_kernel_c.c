//
// auto-generated by ops.py
//

int xdim0_tea_leaf_ppcg_inner2_kernel;
int xdim1_tea_leaf_ppcg_inner2_kernel;
int xdim2_tea_leaf_ppcg_inner2_kernel;


//user function



void tea_leaf_ppcg_inner2_kernel_c_wrapper(
  double * restrict sd_p,
  double * restrict utemp_p,
  double * restrict z_p,
  const double * restrict alpha,
  const double * restrict beta,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double sd = { sd_p + n_x*1 + n_y * xdim0_tea_leaf_ppcg_inner2_kernel*1, xdim0_tea_leaf_ppcg_inner2_kernel};
      ptr_double utemp = { utemp_p + n_x*1 + n_y * xdim1_tea_leaf_ppcg_inner2_kernel*1, xdim1_tea_leaf_ppcg_inner2_kernel};
      const ptr_double z = { z_p + n_x*1 + n_y * xdim2_tea_leaf_ppcg_inner2_kernel*1, xdim2_tea_leaf_ppcg_inner2_kernel};
      
  OPS_ACC(sd, 0,0) = (*alpha) * OPS_ACC(sd, 0,0) + (*beta)*OPS_ACC(z, 0,0);
  OPS_ACC(utemp, 0,0) = OPS_ACC(utemp, 0,0) + OPS_ACC(sd, 0,0);

    }
  }
}