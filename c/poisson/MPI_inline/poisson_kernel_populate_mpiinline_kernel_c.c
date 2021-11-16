//
// auto-generated by ops.py
//

int xdim3_poisson_kernel_populate;
int xdim4_poisson_kernel_populate;
int xdim5_poisson_kernel_populate;


//user function



void poisson_kernel_populate_c_wrapper(
  const int * restrict dispx,
  const int * restrict dispy,
  int * restrict idx,
  double * restrict u_p,
  double * restrict f_p,
  double * restrict ref_p,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      int idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      ptr_double u = { u_p + n_x*1 + n_y * xdim3_poisson_kernel_populate*1, xdim3_poisson_kernel_populate};
      ptr_double f = { f_p + n_x*1 + n_y * xdim4_poisson_kernel_populate*1, xdim4_poisson_kernel_populate};
      ptr_double ref = { ref_p + n_x*1 + n_y * xdim5_poisson_kernel_populate*1, xdim5_poisson_kernel_populate};
      
  double x = dx * (double)(idx[0]+dispx[0]);
  double y = dy * (double)(idx[1]+dispy[0]);

  OPS_ACC(u, 0,0) = myfun(sin(M_PI*x),cos(2.0*M_PI*y))-1.0;
  OPS_ACC(f, 0,0) = -5.0*M_PI*M_PI*sin(M_PI*x)*cos(2.0*M_PI*y);
  OPS_ACC(ref, 0,0) = sin(M_PI*x)*cos(2.0*M_PI*y);


    }
  }
}
