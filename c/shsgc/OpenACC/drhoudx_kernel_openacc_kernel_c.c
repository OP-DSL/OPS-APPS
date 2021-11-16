//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_drhoudx_kernel;
int xdim1_drhoudx_kernel;

//user function
inline 
void drhoudx_kernel(const ptr_double rhou_new,
  ptr_double rho_res) {

        double fnim1 = OPS_ACC(rhou_new, -1);
        double fnim2 = OPS_ACC(rhou_new, -2);
        double fnip1 = OPS_ACC(rhou_new, 1);
        double fnip2 = OPS_ACC(rhou_new, 2);

        double deriv = (fnim2 - fnip2 + 8.0* (fnip1 - fnim1))/(12.00*dx);
        OPS_ACC(rho_res, 0) = deriv;
}


void drhoudx_kernel_c_wrapper(
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
    drhoudx_kernel( ptr0,
          ptr1 );

  }
}