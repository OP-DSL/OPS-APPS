//
// auto-generated by ops.py
//

int xdim0_mgrid_populate_kernel_3;


//user function



void mgrid_populate_kernel_3_c_wrapper(
  double * restrict val_p,
  int * restrict idx,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      int idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      ptr_double val = { val_p + n_x*1 + n_y * xdim0_mgrid_populate_kernel_3*1, xdim0_mgrid_populate_kernel_3};
      
  OPS_ACC(val, 0,0) = (double)(idx[0]+24*idx[1]);

    }
  }
}
