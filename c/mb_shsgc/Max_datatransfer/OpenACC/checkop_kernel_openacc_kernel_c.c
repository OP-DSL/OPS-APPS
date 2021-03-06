//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_checkop_kernel;
int xdim1_checkop_kernel;
int xdim2_checkop_kernel;

//user function
inline 
void checkop_kernel(const ptr_double rho_new,
  const ptr_double x,
  const ptr_double rhoin,
  double *pre,
  double *post,
  int *num) {
  double diff;
  diff = (OPS_ACC(rho_new, 0) - OPS_ACC(rhoin, 0));
  if(fabs(diff)<0.01 && OPS_ACC(x, 0) > -4.1){
    *post = *post + diff*diff;
    *num = *num + 1;

  }
  else
    *pre = *pre + (OPS_ACC(rho_new, 0) - rhol)* (OPS_ACC(rho_new, 0) - rhol);
}


void checkop_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  int *p_a5,
  int x_size) {
  double p_a3_0 = p_a3[0];
  double p_a4_0 = p_a4[0];
  int p_a5_0 = p_a5[0];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2) reduction(+:p_a3_0) reduction(+:p_a4_0) reduction(+:p_a5_0)
  #pragma acc loop reduction(+:p_a3_0) reduction(+:p_a4_0) reduction(+:p_a5_0)
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    const ptr_double ptr1 = {  p_a1 + n_x*1*1 };
    const ptr_double ptr2 = {  p_a2 + n_x*1*1 };
    checkop_kernel( ptr0,
          ptr1,ptr2,
           &p_a3_0, &p_a4_0,
           &p_a5_0 );

  }
  p_a3[0] = p_a3_0;
  p_a4[0] = p_a4_0;
  p_a5[0] = p_a5_0;
}
