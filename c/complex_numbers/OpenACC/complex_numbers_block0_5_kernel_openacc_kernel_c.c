//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_complex_numbers_block0_5_kernel;

//user function
inline 
void complex_numbers_block0_5_kernel(ptr_double phi,
  const int *idx)
{
OPS_ACC(phi, 0) = sin(2*deltai0*idx[0]*M_PI);
}


void complex_numbers_block0_5_kernel_c_wrapper(
  double *p_a0,
  int *p_a1,
  int arg_idx0,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    int arg_idx[] = {arg_idx0+n_x};
    ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    complex_numbers_block0_5_kernel( ptr0,
          arg_idx );

  }
}
