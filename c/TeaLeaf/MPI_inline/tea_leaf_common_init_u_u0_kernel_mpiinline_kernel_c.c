//
// auto-generated by ops.py
//

int xdim0_tea_leaf_common_init_u_u0_kernel;
int xdim1_tea_leaf_common_init_u_u0_kernel;
int xdim2_tea_leaf_common_init_u_u0_kernel;
int xdim3_tea_leaf_common_init_u_u0_kernel;


//user function



void tea_leaf_common_init_u_u0_kernel_c_wrapper(
  double * restrict u_p,
  double * restrict u0_p,
  double * restrict energy_p,
  double * restrict density_p,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double u = { u_p + n_x*1 + n_y * xdim0_tea_leaf_common_init_u_u0_kernel*1, xdim0_tea_leaf_common_init_u_u0_kernel};
      ptr_double u0 = { u0_p + n_x*1 + n_y * xdim1_tea_leaf_common_init_u_u0_kernel*1, xdim1_tea_leaf_common_init_u_u0_kernel};
      const ptr_double energy = { energy_p + n_x*1 + n_y * xdim2_tea_leaf_common_init_u_u0_kernel*1, xdim2_tea_leaf_common_init_u_u0_kernel};
      const ptr_double density = { density_p + n_x*1 + n_y * xdim3_tea_leaf_common_init_u_u0_kernel*1, xdim3_tea_leaf_common_init_u_u0_kernel};
      
	OPS_ACC(u, 0,0)=OPS_ACC(energy, 0,0)*OPS_ACC(density, 0,0);
	OPS_ACC(u0, 0,0)=OPS_ACC(energy, 0,0)*OPS_ACC(density, 0,0);

    }
  }
}