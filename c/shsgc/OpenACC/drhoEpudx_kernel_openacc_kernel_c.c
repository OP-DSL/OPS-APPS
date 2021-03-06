//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_drhoEpudx_kernel;
int xdim1_drhoEpudx_kernel;
int xdim2_drhoEpudx_kernel;
int xdim3_drhoEpudx_kernel;

//user function
inline 
void drhoEpudx_kernel(const ptr_double rhou_new,
  const ptr_double  rho_new,
  const ptr_double  rhoE_new,
  ptr_double rhoE_res) {

			double fni = OPS_ACC(rhou_new, 0) * OPS_ACC(rhou_new, 0) / OPS_ACC(rho_new, 0) ;
			double p = gam1 * (OPS_ACC(rhoE_new, 0) - 0.5 * fni);
			fni = (OPS_ACC(rhoE_new, 0) + p) * OPS_ACC(rhou_new, 0) / OPS_ACC(rho_new, 0) ;

			double fnim1 = OPS_ACC(rhou_new, -1) * OPS_ACC(rhou_new, -1) / OPS_ACC(rho_new, -1);
			p = gam1 * (OPS_ACC(rhoE_new, -1) - 0.5 * fnim1);
			fnim1 = (OPS_ACC(rhoE_new, -1) + p) * OPS_ACC(rhou_new, -1) / OPS_ACC(rho_new, -1);

			double fnim2 = OPS_ACC(rhou_new, -2) * OPS_ACC(rhou_new, -2) / OPS_ACC(rho_new, -2);
			p = gam1 * (OPS_ACC(rhoE_new, -2) - 0.5 * fnim2);
			fnim2 = (OPS_ACC(rhoE_new, -2) + p ) * OPS_ACC(rhou_new, -2) / OPS_ACC(rho_new, -2);

			double fnip1 = OPS_ACC(rhou_new, 1) * OPS_ACC(rhou_new, 1) / OPS_ACC(rho_new, 1);
			p = gam1 * (OPS_ACC(rhoE_new, 1) - 0.5 * fnip1);
			fnip1 = (OPS_ACC(rhoE_new, 1) + p) * OPS_ACC(rhou_new, 1) / OPS_ACC(rho_new, 1);

			double fnip2 = OPS_ACC(rhou_new, 2) * OPS_ACC(rhou_new, 2) / OPS_ACC(rho_new, 2);
			p = gam1 * (OPS_ACC(rhoE_new, 2) - 0.5 * fnip2);
			fnip2 = (OPS_ACC(rhoE_new, 2) + p) * OPS_ACC(rhou_new, 2) / OPS_ACC(rho_new, 2);

			double deriv = (fnim2 - fnip2 + 8.0* (fnip1 - fnim1))/(12.00*dx);
			OPS_ACC(rhoE_res, 0) = deriv;
}


void drhoEpudx_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    const ptr_double ptr1 = {  p_a1 + n_x*1*1 };
    const ptr_double ptr2 = {  p_a2 + n_x*1*1 };
    ptr_double ptr3 = {  p_a3 + n_x*1*1 };
    drhoEpudx_kernel( ptr0,
          ptr1,ptr2,
          ptr3 );

  }
}
