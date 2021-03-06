//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_zerores_kernel;
int xdim1_zerores_kernel;
int xdim2_zerores_kernel;

//user function
inline 
void zerores_kernel(ptr_double rho_res,
  ptr_double rhou_res,
  ptr_double rhoE_res) {
      OPS_ACC(rho_res, 0) = 0.0;
      OPS_ACC(rhou_res, 0) = 0.0;
      OPS_ACC(rhoE_res, 0) = 0.0;
}


void zerores_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    ptr_double ptr1 = {  p_a1 + n_x*1*1 };
    ptr_double ptr2 = {  p_a2 + n_x*1*1 };
    zerores_kernel( ptr0,
          ptr1,ptr2 );

  }
}
