//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_init_kernel;
int xdim1_init_kernel;
int xdim2_init_kernel;
int xdim3_init_kernel;
int xdim4_init_kernel;
int xdim5_init_kernel;
int xdim6_init_kernel;
int xdim7_init_kernel;

//user function
inline 
void init_kernel(const ptr_double x,
  ptr_double rho_new,
  ptr_double rhou_new,
  ptr_double rhoE_new,
  ptr_double  rhoin,
  ptr_double rho_old,
  ptr_double rhou_old,
  ptr_double rhoE_old) {
  if (OPS_ACC(x, 0) >= -4.0){
    OPS_ACC(rho_new, 0) = 1.0 + eps * sin(lambda *OPS_ACC(x, 0));
    OPS_ACC(rhou_new, 0) = ur * OPS_ACC(rho_new, 0);
    OPS_ACC(rhoE_new, 0) = (pr / gam1) + 0.5 * pow(OPS_ACC(rhou_new, 0),2)/OPS_ACC(rho_new, 0);
  }
  else {
    OPS_ACC(rho_new, 0) = rhol;
    OPS_ACC(rhou_new, 0) = ul2 * OPS_ACC(rho_new, 0);
    OPS_ACC(rhoE_new, 0) = (pl / gam1) + 0.5 * pow(OPS_ACC(rhou_new, 0),2)/OPS_ACC(rho_new, 0);
  }
  OPS_ACC(rho_old, 0)  = OPS_ACC(rho_new, 0);
  OPS_ACC(rhou_old, 0) = OPS_ACC(rhou_new, 0);
  OPS_ACC(rhoE_old, 0) = OPS_ACC(rhoE_new, 0);

  OPS_ACC(rhoin, 0) = OPS_ACC(rho_new, 0);

}


void init_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    ptr_double ptr1 = {  p_a1 + n_x*1*1 };
    ptr_double ptr2 = {  p_a2 + n_x*1*1 };
    ptr_double ptr3 = {  p_a3 + n_x*1*1 };
    ptr_double ptr4 = {  p_a4 + n_x*1*1 };
    ptr_double ptr5 = {  p_a5 + n_x*1*1 };
    ptr_double ptr6 = {  p_a6 + n_x*1*1 };
    ptr_double ptr7 = {  p_a7 + n_x*1*1 };
    init_kernel( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
          ptr5,ptr6,
          ptr7 );

  }
}
