//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_accelerate_kernel;
int xdim1_accelerate_kernel;
int xdim2_accelerate_kernel;
int xdim3_accelerate_kernel;
int xdim4_accelerate_kernel;
int xdim5_accelerate_kernel;
int xdim6_accelerate_kernel;
int xdim7_accelerate_kernel;
int xdim8_accelerate_kernel;
int xdim9_accelerate_kernel;
int xdim10_accelerate_kernel;

//user function
inline 
void accelerate_kernel(const ptr_double density0,
  const ptr_double volume,
  ptr_double stepbymass,
  const ptr_double xvel0,
  ptr_double xvel1,
  const ptr_double xarea,
  const ptr_double pressure,
  const ptr_double yvel0,
  ptr_double yvel1,
  const ptr_double yarea,
  const ptr_double viscosity) {

  double nodal_mass;

  nodal_mass = ( OPS_ACC(density0, -1,-1) * OPS_ACC(volume, -1,-1)
    + OPS_ACC(density0, 0,-1) * OPS_ACC(volume, 0,-1)
    + OPS_ACC(density0, 0,0) * OPS_ACC(volume, 0,0)
    + OPS_ACC(density0, -1,0) * OPS_ACC(volume, -1,0) ) * 0.25;

  OPS_ACC(stepbymass, 0,0) = 0.5*dt/ nodal_mass;



  OPS_ACC(xvel1, 0,0) = OPS_ACC(xvel0, 0,0) - OPS_ACC(stepbymass, 0,0) *
            ( OPS_ACC(xarea, 0,0)  * ( OPS_ACC(pressure, 0,0) - OPS_ACC(pressure, -1,0) ) +
              OPS_ACC(xarea, 0,-1) * ( OPS_ACC(pressure, 0,-1) - OPS_ACC(pressure, -1,-1) ) );



  OPS_ACC(yvel1, 0,0) = OPS_ACC(yvel0, 0,0) - OPS_ACC(stepbymass, 0,0) *
            ( OPS_ACC(yarea, 0,0)  * ( OPS_ACC(pressure, 0,0) - OPS_ACC(pressure, 0,-1) ) +
              OPS_ACC(yarea, -1,0) * ( OPS_ACC(pressure, -1,0) - OPS_ACC(pressure, -1,-1) ) );



  OPS_ACC(xvel1, 0,0) = OPS_ACC(xvel1, 0,0) - OPS_ACC(stepbymass, 0,0) *
            ( OPS_ACC(xarea, 0,0) * ( OPS_ACC(viscosity, 0,0) - OPS_ACC(viscosity, -1,0) ) +
              OPS_ACC(xarea, 0,-1) * ( OPS_ACC(viscosity, 0,-1) - OPS_ACC(viscosity, -1,-1) ) );



  OPS_ACC(yvel1, 0,0) = OPS_ACC(yvel1, 0,0) - OPS_ACC(stepbymass, 0,0) *
            ( OPS_ACC(yarea, 0,0) * ( OPS_ACC(viscosity, 0,0) - OPS_ACC(viscosity, 0,-1) ) +
              OPS_ACC(yarea, -1,0) * ( OPS_ACC(viscosity, -1,0) - OPS_ACC(viscosity, -1,-1) ) );

}


void accelerate_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_accelerate_kernel*1*1, xdim0_accelerate_kernel};
      const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_accelerate_kernel*1*1, xdim1_accelerate_kernel};
      ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_accelerate_kernel*1*1, xdim2_accelerate_kernel};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_accelerate_kernel*1*1, xdim3_accelerate_kernel};
      ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_accelerate_kernel*1*1, xdim4_accelerate_kernel};
      const ptr_double ptr5 = {  p_a5 + n_x*1*1 + n_y*xdim5_accelerate_kernel*1*1, xdim5_accelerate_kernel};
      const ptr_double ptr6 = {  p_a6 + n_x*1*1 + n_y*xdim6_accelerate_kernel*1*1, xdim6_accelerate_kernel};
      const ptr_double ptr7 = {  p_a7 + n_x*1*1 + n_y*xdim7_accelerate_kernel*1*1, xdim7_accelerate_kernel};
      ptr_double ptr8 = {  p_a8 + n_x*1*1 + n_y*xdim8_accelerate_kernel*1*1, xdim8_accelerate_kernel};
      const ptr_double ptr9 = {  p_a9 + n_x*1*1 + n_y*xdim9_accelerate_kernel*1*1, xdim9_accelerate_kernel};
      const ptr_double ptr10 = {  p_a10 + n_x*1*1 + n_y*xdim10_accelerate_kernel*1*1, xdim10_accelerate_kernel};
      accelerate_kernel( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
          ptr5,ptr6,
          ptr7,ptr8,
          ptr9,ptr10 );

    }
  }
}