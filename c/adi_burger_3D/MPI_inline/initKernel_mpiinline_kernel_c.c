//
// auto-generated by ops.py
//

int xdim0_initKernel;
int ydim0_initKernel;
int xdim1_initKernel;
int ydim1_initKernel;
int xdim2_initKernel;
int ydim2_initKernel;


//user function



void initKernel_c_wrapper(
  double * restrict u_p,
  double * restrict v_p,
  double * restrict w_p,
  int * restrict idx,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        int idx[] = {arg_idx0+n_x, arg_idx1+n_y, arg_idx2+n_z};
        ptr_double u = { u_p + n_x*1 + n_y * xdim0_initKernel*1 + n_z * xdim0_initKernel * ydim0_initKernel*1, xdim0_initKernel, ydim0_initKernel};
        ptr_double v = { v_p + n_x*1 + n_y * xdim1_initKernel*1 + n_z * xdim1_initKernel * ydim1_initKernel*1, xdim1_initKernel, ydim1_initKernel};
        ptr_double w = { w_p + n_x*1 + n_y * xdim2_initKernel*1 + n_z * xdim2_initKernel * ydim2_initKernel*1, xdim2_initKernel, ydim2_initKernel};
        
    const double x{h * idx[0]};
    const double y{h * idx[1]};
    const double z{h * idx[2]};
    OPS_ACC(u, 0, 0, 0) =
        2 * sin(x) * sin(y) * cos(z) / (Re * (cos(x) * sin(y) * cos(z) + 1));
    OPS_ACC(v, 0, 0, 0) =
        -2 * cos(x) * cos(y) * cos(z) / (Re * (cos(x) * sin(y) * cos(z) + 1));
    OPS_ACC(w, 0, 0, 0) =
        2 * cos(x) * sin(y) * sin(z) / (Re * (cos(x) * sin(y) * cos(z) + 1));

      }
    }
  }
}
