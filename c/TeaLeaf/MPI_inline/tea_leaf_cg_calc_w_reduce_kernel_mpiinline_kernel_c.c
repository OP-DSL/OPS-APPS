//
// auto-generated by ops.py
//

int xdim0_tea_leaf_cg_calc_w_reduce_kernel;
int xdim1_tea_leaf_cg_calc_w_reduce_kernel;
int xdim2_tea_leaf_cg_calc_w_reduce_kernel;
int xdim3_tea_leaf_cg_calc_w_reduce_kernel;


//user function



void tea_leaf_cg_calc_w_reduce_kernel_c_wrapper(
  double * restrict w_p,
  double * restrict Kx_p,
  double * restrict Ky_p,
  double * restrict p_p,
  const double * restrict rx,
  const double * restrict ry,
  double * restrict pw_g,
  int x_size, int y_size) {
  double pw_0 = pw_g[0];
  #pragma omp parallel for reduction(+:pw_0)
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      double pw[1];
      pw[0] = 0;
      ptr_double w = { w_p + n_x*1 + n_y * xdim0_tea_leaf_cg_calc_w_reduce_kernel*1, xdim0_tea_leaf_cg_calc_w_reduce_kernel};
      const ptr_double Kx = { Kx_p + n_x*1 + n_y * xdim1_tea_leaf_cg_calc_w_reduce_kernel*1, xdim1_tea_leaf_cg_calc_w_reduce_kernel};
      const ptr_double Ky = { Ky_p + n_x*1 + n_y * xdim2_tea_leaf_cg_calc_w_reduce_kernel*1, xdim2_tea_leaf_cg_calc_w_reduce_kernel};
      const ptr_double p = { p_p + n_x*1 + n_y * xdim3_tea_leaf_cg_calc_w_reduce_kernel*1, xdim3_tea_leaf_cg_calc_w_reduce_kernel};
      
  OPS_ACC(w, 0,0) = (1.0
                + (*ry)*(OPS_ACC(Ky, 0,1) + OPS_ACC(Ky, 0,0))
                + (*rx)*(OPS_ACC(Kx, 1,0) + OPS_ACC(Kx, 0,0)))*OPS_ACC(p, 0,0)
                - (*ry)*(OPS_ACC(Ky, 0,1)*OPS_ACC(p, 0,1) + OPS_ACC(Ky, 0,0)*OPS_ACC(p, 0,-1))
                - (*rx)*(OPS_ACC(Kx, 1,0)*OPS_ACC(p, 1,0) + OPS_ACC(Kx, 0,0)*OPS_ACC(p, -1,0));
  *pw = *pw + OPS_ACC(w, 0,0)*OPS_ACC(p, 0,0);

      pw_0 +=pw[0];
    }
  }
  pw_g[0] = pw_0;
}