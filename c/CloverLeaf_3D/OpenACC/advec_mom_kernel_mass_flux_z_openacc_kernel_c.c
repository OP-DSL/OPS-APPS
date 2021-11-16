//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_advec_mom_kernel_mass_flux_z;
int ydim0_advec_mom_kernel_mass_flux_z;
int xdim1_advec_mom_kernel_mass_flux_z;
int ydim1_advec_mom_kernel_mass_flux_z;

//user function

inline void advec_mom_kernel_mass_flux_z(ptr_double node_flux,
  const ptr_double mass_flux_z) {


  OPS_ACC(node_flux, 0,0,0) = 0.125 * ( OPS_ACC(mass_flux_z, -1,0,0) + OPS_ACC(mass_flux_z, 0,0,0) +
                                         OPS_ACC(mass_flux_z, -1,0,1) + OPS_ACC(mass_flux_z, 0,0,1) +
                                         OPS_ACC(mass_flux_z, -1,-1,0) + OPS_ACC(mass_flux_z, 0,-1,0) +
                                         OPS_ACC(mass_flux_z, -1,-1,1) + OPS_ACC(mass_flux_z, 0,-1,1) );
}


void advec_mom_kernel_mass_flux_z_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_advec_mom_kernel_mass_flux_z*1*1 + n_z*xdim0_advec_mom_kernel_mass_flux_z*ydim0_advec_mom_kernel_mass_flux_z*1*1, xdim0_advec_mom_kernel_mass_flux_z, ydim0_advec_mom_kernel_mass_flux_z};
        const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_advec_mom_kernel_mass_flux_z*1*1 + n_z*xdim1_advec_mom_kernel_mass_flux_z*ydim1_advec_mom_kernel_mass_flux_z*1*1, xdim1_advec_mom_kernel_mass_flux_z, ydim1_advec_mom_kernel_mass_flux_z};
        advec_mom_kernel_mass_flux_z( ptr0,
          ptr1 );

      }
    }
  }
}