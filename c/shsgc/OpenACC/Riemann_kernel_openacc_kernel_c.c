//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_Riemann_kernel;
int xdim1_Riemann_kernel;
int xdim2_Riemann_kernel;
int xdim3_Riemann_kernel;
int xdim4_Riemann_kernel;
int xdim5_Riemann_kernel;

//user function
inline 
void Riemann_kernel(const ptr_double  rho_new,
  const ptr_double rhou_new,
  const ptr_double  rhoE_new,
  ptrm_double  alam,
  ptrm_double  r,
  ptrm_double  al) {

  double rl, rr, rho, u, hl, hr, h, Vsq, csq, c;
  double dw1, dw2, dw3, delpc2, rdeluc;

  rl = sqrt(OPS_ACC(rho_new, 0));
  rr = sqrt(OPS_ACC(rho_new, 1));
  rho = rl + rr;
  u = ((OPS_ACC(rhou_new, 0) / rl) + (OPS_ACC(rhou_new, 1) / rr)) / rho ;
  double fni = OPS_ACC(rhou_new, 0) * OPS_ACC(rhou_new, 0) / OPS_ACC(rho_new, 0) ;
  double p = gam1 * (OPS_ACC(rhoE_new, 0) - 0.5 * fni);
  hl = (OPS_ACC(rhoE_new, 0) + p)  / rl ;
  fni = OPS_ACC(rhou_new, 1) * OPS_ACC(rhou_new, 1) / OPS_ACC(rho_new, 1) ;
  p = gam1 * (OPS_ACC(rhoE_new, 1) - 0.5 * fni);
  hr = (OPS_ACC(rhoE_new, 1) + p)  / rr ;
  h = (hl + hr)/rho;
  Vsq = u*u;
  csq = gam1 * (h - 0.5 * Vsq);
  c = sqrt(csq);

  OPS_ACC(alam, 0,0) = u - c;
  OPS_ACC(alam, 1,0) = u;
  OPS_ACC(alam, 2,0) = u + c;

  OPS_ACC(r, 0,0) = 1.0;
  OPS_ACC(r, 1,0) = 1.0;
  OPS_ACC(r, 2,0) = 1.0;

  OPS_ACC(r, 3,0) = u - c;
  OPS_ACC(r, 4,0) = u;
  OPS_ACC(r, 5,0) = u + c;

  OPS_ACC(r, 6,0) = h - u * c;
  OPS_ACC(r, 7,0) = 0.5 * Vsq;
  OPS_ACC(r, 8,0) = h + u * c;

  for (int m=0; m<9; m++)
    OPS_ACC(r, m,0) = OPS_ACC(r, m,0) / csq;

  dw1 = OPS_ACC(rho_new, 1) - OPS_ACC(rho_new, 0);
  dw2 = OPS_ACC(rhou_new, 1) - OPS_ACC(rhou_new, 0);
  dw3 = OPS_ACC(rhoE_new, 1) - OPS_ACC(rhoE_new, 0);

  delpc2 = gam1 * ( dw3 + 0.50 * Vsq * dw1  - u * dw2) / csq;
  rdeluc = ( dw2 - u * dw1) / c ;

  OPS_ACC(al, 0,0) = 0.5 * (delpc2 - rdeluc);
  OPS_ACC(al, 1,0) = dw1 - delpc2 ;
  OPS_ACC(al, 2,0) = 0.5 * ( delpc2 + rdeluc );

  for (int m=0; m<3; m++)
    OPS_ACC(al, m,0) = OPS_ACC(al, m,0) * csq;
}


void Riemann_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    const ptr_double ptr1 = {  p_a1 + n_x*1*1 };
    const ptr_double ptr2 = {  p_a2 + n_x*1*1 };
    #ifdef OPS_SOA
    ptrm_double ptr3 = {  p_a3 + n_x*1*3, xdim3_Riemann_kernel};
    #else
    ptrm_double ptr3 = {  p_a3 + n_x*1*3, 3};
    #endif
    #ifdef OPS_SOA
    ptrm_double ptr4 = {  p_a4 + n_x*1*9, xdim4_Riemann_kernel};
    #else
    ptrm_double ptr4 = {  p_a4 + n_x*1*9, 9};
    #endif
    #ifdef OPS_SOA
    ptrm_double ptr5 = {  p_a5 + n_x*1*3, xdim5_Riemann_kernel};
    #else
    ptrm_double ptr5 = {  p_a5 + n_x*1*3, 3};
    #endif
    Riemann_kernel( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
          ptr5 );

  }
}
