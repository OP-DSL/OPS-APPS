//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_initialize_kernel;
int xdim1_initialize_kernel;
int xdim2_initialize_kernel;
int xdim3_initialize_kernel;
int xdim4_initialize_kernel;

//user function
inline 
void initialize_kernel(ptr_double x,
  ptr_double rho_new,
  ptr_double rhou_new,
  ptr_double rhoE_new,
  ptr_double  rhoin,
  int *idx) {
  OPS_ACC(x, 0) = xmin + (idx[0]-2) * dx;
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

	OPS_ACC(rhoin, 0) = gam1 * (OPS_ACC(rhoE_new, 0) - 0.5 * OPS_ACC(rhou_new, 0) * OPS_ACC(rhou_new, 0) / OPS_ACC(rho_new, 0));

}


void initialize_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  int *p_a5,
  int arg_idx0,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    int arg_idx[] = {arg_idx0+n_x};
    ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    ptr_double ptr1 = {  p_a1 + n_x*1*1 };
    ptr_double ptr2 = {  p_a2 + n_x*1*1 };
    ptr_double ptr3 = {  p_a3 + n_x*1*1 };
    ptr_double ptr4 = {  p_a4 + n_x*1*1 };
    initialize_kernel( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
          arg_idx );

  }
}
