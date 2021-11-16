//
// auto-generated by ops.py
//

int xdim0_PdV_kernel_nopredict;
int ydim0_PdV_kernel_nopredict;
int xdim1_PdV_kernel_nopredict;
int ydim1_PdV_kernel_nopredict;
int xdim2_PdV_kernel_nopredict;
int ydim2_PdV_kernel_nopredict;
int xdim3_PdV_kernel_nopredict;
int ydim3_PdV_kernel_nopredict;
int xdim4_PdV_kernel_nopredict;
int ydim4_PdV_kernel_nopredict;
int xdim5_PdV_kernel_nopredict;
int ydim5_PdV_kernel_nopredict;
int xdim6_PdV_kernel_nopredict;
int ydim6_PdV_kernel_nopredict;
int xdim7_PdV_kernel_nopredict;
int ydim7_PdV_kernel_nopredict;
int xdim8_PdV_kernel_nopredict;
int ydim8_PdV_kernel_nopredict;
int xdim9_PdV_kernel_nopredict;
int ydim9_PdV_kernel_nopredict;
int xdim10_PdV_kernel_nopredict;
int ydim10_PdV_kernel_nopredict;
int xdim11_PdV_kernel_nopredict;
int ydim11_PdV_kernel_nopredict;
int xdim12_PdV_kernel_nopredict;
int ydim12_PdV_kernel_nopredict;
int xdim13_PdV_kernel_nopredict;
int ydim13_PdV_kernel_nopredict;
int xdim14_PdV_kernel_nopredict;
int ydim14_PdV_kernel_nopredict;
int xdim15_PdV_kernel_nopredict;
int ydim15_PdV_kernel_nopredict;
int xdim16_PdV_kernel_nopredict;
int ydim16_PdV_kernel_nopredict;


//user function



void PdV_kernel_nopredict_c_wrapper(
  double * restrict xarea_p,
  double * restrict xvel0_p,
  double * restrict xvel1_p,
  double * restrict yarea_p,
  double * restrict yvel0_p,
  double * restrict yvel1_p,
  double * restrict volume_change_p,
  double * restrict volume_p,
  double * restrict pressure_p,
  double * restrict density0_p,
  double * restrict density1_p,
  double * restrict viscosity_p,
  double * restrict energy0_p,
  double * restrict energy1_p,
  double * restrict zarea_p,
  double * restrict zvel0_p,
  double * restrict zvel1_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double xarea = { xarea_p + n_x*1 + n_y * xdim0_PdV_kernel_nopredict*1 + n_z * xdim0_PdV_kernel_nopredict * ydim0_PdV_kernel_nopredict*1, xdim0_PdV_kernel_nopredict, ydim0_PdV_kernel_nopredict};
        const ptr_double xvel0 = { xvel0_p + n_x*1 + n_y * xdim1_PdV_kernel_nopredict*1 + n_z * xdim1_PdV_kernel_nopredict * ydim1_PdV_kernel_nopredict*1, xdim1_PdV_kernel_nopredict, ydim1_PdV_kernel_nopredict};
        const ptr_double xvel1 = { xvel1_p + n_x*1 + n_y * xdim2_PdV_kernel_nopredict*1 + n_z * xdim2_PdV_kernel_nopredict * ydim2_PdV_kernel_nopredict*1, xdim2_PdV_kernel_nopredict, ydim2_PdV_kernel_nopredict};
        const ptr_double yarea = { yarea_p + n_x*1 + n_y * xdim3_PdV_kernel_nopredict*1 + n_z * xdim3_PdV_kernel_nopredict * ydim3_PdV_kernel_nopredict*1, xdim3_PdV_kernel_nopredict, ydim3_PdV_kernel_nopredict};
        const ptr_double yvel0 = { yvel0_p + n_x*1 + n_y * xdim4_PdV_kernel_nopredict*1 + n_z * xdim4_PdV_kernel_nopredict * ydim4_PdV_kernel_nopredict*1, xdim4_PdV_kernel_nopredict, ydim4_PdV_kernel_nopredict};
        const ptr_double yvel1 = { yvel1_p + n_x*1 + n_y * xdim5_PdV_kernel_nopredict*1 + n_z * xdim5_PdV_kernel_nopredict * ydim5_PdV_kernel_nopredict*1, xdim5_PdV_kernel_nopredict, ydim5_PdV_kernel_nopredict};
        ptr_double volume_change = { volume_change_p + n_x*1 + n_y * xdim6_PdV_kernel_nopredict*1 + n_z * xdim6_PdV_kernel_nopredict * ydim6_PdV_kernel_nopredict*1, xdim6_PdV_kernel_nopredict, ydim6_PdV_kernel_nopredict};
        const ptr_double volume = { volume_p + n_x*1 + n_y * xdim7_PdV_kernel_nopredict*1 + n_z * xdim7_PdV_kernel_nopredict * ydim7_PdV_kernel_nopredict*1, xdim7_PdV_kernel_nopredict, ydim7_PdV_kernel_nopredict};
        const ptr_double pressure = { pressure_p + n_x*1 + n_y * xdim8_PdV_kernel_nopredict*1 + n_z * xdim8_PdV_kernel_nopredict * ydim8_PdV_kernel_nopredict*1, xdim8_PdV_kernel_nopredict, ydim8_PdV_kernel_nopredict};
        const ptr_double density0 = { density0_p + n_x*1 + n_y * xdim9_PdV_kernel_nopredict*1 + n_z * xdim9_PdV_kernel_nopredict * ydim9_PdV_kernel_nopredict*1, xdim9_PdV_kernel_nopredict, ydim9_PdV_kernel_nopredict};
        ptr_double density1 = { density1_p + n_x*1 + n_y * xdim10_PdV_kernel_nopredict*1 + n_z * xdim10_PdV_kernel_nopredict * ydim10_PdV_kernel_nopredict*1, xdim10_PdV_kernel_nopredict, ydim10_PdV_kernel_nopredict};
        const ptr_double viscosity = { viscosity_p + n_x*1 + n_y * xdim11_PdV_kernel_nopredict*1 + n_z * xdim11_PdV_kernel_nopredict * ydim11_PdV_kernel_nopredict*1, xdim11_PdV_kernel_nopredict, ydim11_PdV_kernel_nopredict};
        const ptr_double energy0 = { energy0_p + n_x*1 + n_y * xdim12_PdV_kernel_nopredict*1 + n_z * xdim12_PdV_kernel_nopredict * ydim12_PdV_kernel_nopredict*1, xdim12_PdV_kernel_nopredict, ydim12_PdV_kernel_nopredict};
        ptr_double energy1 = { energy1_p + n_x*1 + n_y * xdim13_PdV_kernel_nopredict*1 + n_z * xdim13_PdV_kernel_nopredict * ydim13_PdV_kernel_nopredict*1, xdim13_PdV_kernel_nopredict, ydim13_PdV_kernel_nopredict};
        const ptr_double zarea = { zarea_p + n_x*1 + n_y * xdim14_PdV_kernel_nopredict*1 + n_z * xdim14_PdV_kernel_nopredict * ydim14_PdV_kernel_nopredict*1, xdim14_PdV_kernel_nopredict, ydim14_PdV_kernel_nopredict};
        const ptr_double zvel0 = { zvel0_p + n_x*1 + n_y * xdim15_PdV_kernel_nopredict*1 + n_z * xdim15_PdV_kernel_nopredict * ydim15_PdV_kernel_nopredict*1, xdim15_PdV_kernel_nopredict, ydim15_PdV_kernel_nopredict};
        const ptr_double zvel1 = { zvel1_p + n_x*1 + n_y * xdim16_PdV_kernel_nopredict*1 + n_z * xdim16_PdV_kernel_nopredict * ydim16_PdV_kernel_nopredict*1, xdim16_PdV_kernel_nopredict, ydim16_PdV_kernel_nopredict};
        

  double recip_volume, energy_change;
  double right_flux, left_flux, top_flux, bottom_flux, back_flux, front_flux, total_flux;

  left_flux = ( OPS_ACC(xarea, 0,0,0) * ( OPS_ACC(xvel0, 0,0,0) + OPS_ACC(xvel0, 0,1,0) +
                                           OPS_ACC(xvel0, 0,0,1) + OPS_ACC(xvel0, 0,1,1) +
                                           OPS_ACC(xvel1, 0,0,0) + OPS_ACC(xvel1, 0,1,0) +
                                           OPS_ACC(xvel1, 0,0,1) + OPS_ACC(xvel1, 0,1,1) ) ) * 0.125 * dt;
  right_flux = ( OPS_ACC(xarea, 1,0,0) * ( OPS_ACC(xvel0, 1,0,0) + OPS_ACC(xvel0, 1,1,0) +
                                            OPS_ACC(xvel0, 1,0,1) + OPS_ACC(xvel0, 1,1,1) +
                                            OPS_ACC(xvel1, 1,0,0) + OPS_ACC(xvel1, 1,1,0) +
                                            OPS_ACC(xvel1, 1,0,1) + OPS_ACC(xvel1, 1,1,1) ) ) * 0.125 * dt;

  bottom_flux = ( OPS_ACC(yarea, 0,0,0) * ( OPS_ACC(yvel0, 0,0,0) + OPS_ACC(yvel0, 1,0,0) +
                                             OPS_ACC(yvel0, 0,0,1) + OPS_ACC(yvel0, 1,0,1) +
                                             OPS_ACC(yvel1, 0,0,0) + OPS_ACC(yvel1, 1,0,0) +
                                             OPS_ACC(yvel1, 0,0,1) + OPS_ACC(yvel1, 1,0,1) ) ) * 0.125* dt;
  top_flux = ( OPS_ACC(yarea, 0,1,0) * ( OPS_ACC(yvel0, 0,1,0) + OPS_ACC(yvel0, 1,1,0) +
                                          OPS_ACC(yvel0, 0,1,1) + OPS_ACC(yvel0, 1,1,1) +
                                          OPS_ACC(yvel1, 0,1,0) + OPS_ACC(yvel1, 1,1,0) +
                                          OPS_ACC(yvel1, 0,1,1) + OPS_ACC(yvel1, 1,1,1)) ) * 0.125 * dt;

  back_flux = ( OPS_ACC(zarea, 0,0,0) * ( OPS_ACC(zvel0, 0,0,0) + OPS_ACC(zvel0, 1,0,0) +
                                            OPS_ACC(zvel0, 0,1,0) + OPS_ACC(zvel0, 1,1,0) +
                                            OPS_ACC(zvel1, 0,0,0) + OPS_ACC(zvel1, 1,0,0) +
                                            OPS_ACC(zvel1, 0,1,0) + OPS_ACC(zvel1, 1,1,0) ) ) * 0.125* dt;
  front_flux = ( OPS_ACC(zarea, 0,0,1) * ( OPS_ACC(zvel0, 0,0,1) + OPS_ACC(zvel0, 1,0,1) +
                                             OPS_ACC(zvel0, 0,1,1) + OPS_ACC(zvel0, 1,1,1) +
                                             OPS_ACC(zvel1, 0,0,1) + OPS_ACC(zvel1, 1,0,1) +
                                             OPS_ACC(zvel1, 0,1,1) + OPS_ACC(zvel1, 1,1,1)) ) * 0.125 * dt;

  total_flux = right_flux - left_flux + top_flux - bottom_flux + front_flux - back_flux;

  OPS_ACC(volume_change, 0,0,0) = (OPS_ACC(volume, 0,0,0))/(OPS_ACC(volume, 0,0,0) + total_flux);
  recip_volume = 1.0/OPS_ACC(volume, 0,0,0);
  energy_change = ( OPS_ACC(pressure, 0,0,0)/OPS_ACC(density0, 0,0,0) +
                    OPS_ACC(viscosity, 0,0,0)/OPS_ACC(density0, 0,0,0) ) * total_flux * recip_volume;
  OPS_ACC(energy1, 0,0,0) = OPS_ACC(energy0, 0,0,0) - energy_change;
  OPS_ACC(density1, 0,0,0) = OPS_ACC(density0, 0,0,0) * OPS_ACC(volume_change, 0,0,0);


      }
    }
  }
}