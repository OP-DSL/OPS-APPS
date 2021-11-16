//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_calc_dt_kernel_get;
int xdim1_calc_dt_kernel_get;

//user function
inline 
void calc_dt_kernel_get(const ptr_double cellx,
  const ptr_double celly,
  double* xl_pos,
  double* yl_pos) {
  *xl_pos = OPS_ACC(cellx, 0,0);
  *yl_pos = OPS_ACC(celly, 0,0);
}


void calc_dt_kernel_get_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size) {
  double p_a2_0 = p_a2[0];
  double p_a3_0 = p_a3[0];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1) reduction(+:p_a2_0) reduction(+:p_a3_0)
  #pragma acc loop reduction(+:p_a2_0) reduction(+:p_a3_0)
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop reduction(+:p_a2_0) reduction(+:p_a3_0)
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_calc_dt_kernel_get*0*1, xdim0_calc_dt_kernel_get};
      const ptr_double ptr1 = {  p_a1 + n_x*0*1 + n_y*xdim1_calc_dt_kernel_get*1*1, xdim1_calc_dt_kernel_get};
      calc_dt_kernel_get( ptr0,
          ptr1, &p_a2_0,
           &p_a3_0 );

    }
  }
  p_a2[0] = p_a2_0;
  p_a3[0] = p_a3_0;
}