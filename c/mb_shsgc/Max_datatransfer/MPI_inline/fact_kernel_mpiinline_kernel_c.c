//
// auto-generated by ops.py
//

int xdim0_fact_kernel;
int xdim1_fact_kernel;


//user function



void fact_kernel_c_wrapper(
  double * restrict eff_p,
  double * restrict s_p,
  int x_size) {
  #pragma omp parallel for
  for ( int n_x=0; n_x<x_size; n_x++ ){
    #ifdef OPS_SOA
    const ptrm_double eff = { eff_p + n_x*1, xdim0_fact_kernel};
    #else
    const ptrm_double eff = { eff_p + n_x*1, 3};
    #endif
    #ifdef OPS_SOA
    ptrm_double s = { s_p + n_x*1, xdim1_fact_kernel};
    #else
    ptrm_double s = { s_p + n_x*1, 3};
    #endif
    
  double fact;
  for (int m=0; m < 3 ;m++) {
    fact  = 0.50 * dt / dx ;
    OPS_ACC(s, m,0) = -fact * (OPS_ACC(eff, m,0) - OPS_ACC(eff, m,-1));
  }

  }
}