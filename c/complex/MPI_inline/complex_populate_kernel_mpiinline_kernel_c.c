//
// auto-generated by ops.py
//

int xdim0_complex_populate_kernel;


//user function



void complex_populate_kernel_c_wrapper(
  complexd * restrict val_p,
  complexd * restrict red_g,
  int * restrict idx,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  complexd red_0 = red_g[0];
  #pragma omp parallel for reduction(+:red_0)
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      complexd red[1];
      red[0] = 0;
      int idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      ptr_complexd val = { val_p + n_x*1 + n_y * xdim0_complex_populate_kernel*1, xdim0_complex_populate_kernel};
      
  OPS_ACC(val, 0,0).real((double)idx[0]);
  OPS_ACC(val, 0,0).imag((double)idx[1]);
  *red += OPS_ACC(val, 0,0);

      red_0 +=red[0];
    }
  }
  red_g[0] = red_0;
}
