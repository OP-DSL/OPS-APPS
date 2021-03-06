//
// auto-generated by ops.py
//

int xdim0_Riemann_kernel;
int xdim1_Riemann_kernel;
int xdim2_Riemann_kernel;
int xdim3_Riemann_kernel;
int xdim4_Riemann_kernel;
int xdim5_Riemann_kernel;


//user function



void Riemann_kernel_c_wrapper(
  double * restrict rho_new_p,
  double * restrict rhou_new_p,
  double * restrict rhoE_new_p,
  double * restrict alam_p,
  double * restrict r_p,
  double * restrict al_p,
  int x_size) {
  #pragma omp parallel for
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double rho_new = { rho_new_p + n_x*1};
    const ptr_double rhou_new = { rhou_new_p + n_x*1};
    const ptr_double rhoE_new = { rhoE_new_p + n_x*1};
    #ifdef OPS_SOA
    ptrm_double alam = { alam_p + n_x*1, xdim3_Riemann_kernel};
    #else
    ptrm_double alam = { alam_p + n_x*1, 3};
    #endif
    #ifdef OPS_SOA
    ptrm_double r = { r_p + n_x*1, xdim4_Riemann_kernel};
    #else
    ptrm_double r = { r_p + n_x*1, 9};
    #endif
    #ifdef OPS_SOA
    ptrm_double al = { al_p + n_x*1, xdim5_Riemann_kernel};
    #else
    ptrm_double al = { al_p + n_x*1, 3};
    #endif
    

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
}
