//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_xder1_kernel;
int xdim1_xder1_kernel;

//user function
inline 
void xder1_kernel(const ptr_double inp,
  ptr_double out) {
  double dix = 1/(12.00*dx);
  OPS_ACC(out, 0) = (OPS_ACC(inp, -2) - OPS_ACC(inp, 2)  + 8.0 *(
  OPS_ACC(inp, 1) - OPS_ACC(inp, -1) )) * dix;
}


void xder1_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    ptr_double ptr1 = {  p_a1 + n_x*1*1 };
    xder1_kernel( ptr0,
          ptr1 );

  }
}
