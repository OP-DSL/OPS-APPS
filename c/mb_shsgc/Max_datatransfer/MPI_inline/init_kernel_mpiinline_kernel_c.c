//
// auto-generated by ops.py
//

int xdim0_init_kernel;
int xdim1_init_kernel;
int xdim2_init_kernel;
int xdim3_init_kernel;
int xdim4_init_kernel;
int xdim5_init_kernel;
int xdim6_init_kernel;
int xdim7_init_kernel;


//user function



void init_kernel_c_wrapper(
  double * restrict x_p,
  double * restrict rho_new_p,
  double * restrict rhou_new_p,
  double * restrict rhoE_new_p,
  double * restrict rhoin_p,
  double * restrict rho_old_p,
  double * restrict rhou_old_p,
  double * restrict rhoE_old_p,
  int x_size) {
  #pragma omp parallel for
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double x = { x_p + n_x*1};
    ptr_double rho_new = { rho_new_p + n_x*1};
    ptr_double rhou_new = { rhou_new_p + n_x*1};
    ptr_double rhoE_new = { rhoE_new_p + n_x*1};
    ptr_double rhoin = { rhoin_p + n_x*1};
    ptr_double rho_old = { rho_old_p + n_x*1};
    ptr_double rhou_old = { rhou_old_p + n_x*1};
    ptr_double rhoE_old = { rhoE_old_p + n_x*1};
    
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
}
