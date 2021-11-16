//
// auto-generated by ops.py
//

int xdim0_mgrid_prolong_kernel;
int xdim1_mgrid_prolong_kernel;


//user function



void mgrid_prolong_kernel_c_wrapper(
  double * restrict coarse_p,
  double * restrict fine_p,
  int * restrict idx,
  const int * restrict global_idx,
  const int * restrict stride_0,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      int idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      const ptr_double coarse = { coarse_p + (n_x+global_idx[0]%stride_0[0])/stride_0[0]*1 + (n_y+global_idx[1]%stride_0[1])/stride_0[1] * xdim0_mgrid_prolong_kernel*1, xdim0_mgrid_prolong_kernel};
      ptr_double fine = { fine_p + n_x*1 + n_y * xdim1_mgrid_prolong_kernel*1, xdim1_mgrid_prolong_kernel};
      
  OPS_ACC(fine, 0,0) = OPS_ACC(coarse, 0,0);

    }
  }
}