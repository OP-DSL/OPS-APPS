//
// auto-generated by ops.py
//

int xdim0_xder1_kernel;
int xdim1_xder1_kernel;


//user function



void xder1_kernel_c_wrapper(
  double * restrict inp_p,
  double * restrict out_p,
  int x_size) {
  #pragma omp parallel for
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double inp = { inp_p + n_x*1};
    ptr_double out = { out_p + n_x*1};
    
  double dix = 1/(12.00*dx);
  OPS_ACC(out, 0) = (OPS_ACC(inp, -2) - OPS_ACC(inp, 2)  + 8.0 *(
  OPS_ACC(inp, 1) - OPS_ACC(inp, -1) )) * dix;

  }
}
