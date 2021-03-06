//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_multidim_reduce_kernel;
int ydim0_multidim_reduce_kernel;
int zdim0_multidim_reduce_kernel;

//user function
inline 
void multidim_reduce_kernel(const ptrm_double val,
  double *redu_dat1) {

  redu_dat1[0] = redu_dat1[0] + OPS_ACC(val, 0,0,0,0);
  redu_dat1[1] = redu_dat1[1] + OPS_ACC(val, 1,0,0,0);
  redu_dat1[2] = redu_dat1[2] + OPS_ACC(val, 2,0,0,0);
}


void multidim_reduce_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size, int y_size, int z_size) {
  double p_a1_0 = p_a1[0];
  double p_a1_1 = p_a1[1];
  double p_a1_2 = p_a1[2];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0) reduction(+:p_a1_0) reduction(+:p_a1_1) reduction(+:p_a1_2)
  #pragma acc loop reduction(+:p_a1_0) reduction(+:p_a1_1) reduction(+:p_a1_2)
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop reduction(+:p_a1_0) reduction(+:p_a1_1) reduction(+:p_a1_2)
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop reduction(+:p_a1_0) reduction(+:p_a1_1) reduction(+:p_a1_2)
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        double p_a1_local[3];
        p_a1_local[0] = ZERO_double;
        p_a1_local[1] = ZERO_double;
        p_a1_local[2] = ZERO_double;
        #ifdef OPS_SOA
        const ptrm_double ptr0 = {  p_a0 + n_x*1 + n_y*xdim0_multidim_reduce_kernel*1 + n_z*xdim0_multidim_reduce_kernel*ydim0_multidim_reduce_kernel*1, xdim0_multidim_reduce_kernel, ydim0_multidim_reduce_kernel, zdim0_multidim_reduce_kernel};
        #else
        const ptrm_double ptr0 = {  p_a0 + n_x*1 + n_y*xdim0_multidim_reduce_kernel*1 + n_z*xdim0_multidim_reduce_kernel*ydim0_multidim_reduce_kernel*1, xdim0_multidim_reduce_kernel, ydim0_multidim_reduce_kernel, 3};
        #endif
        multidim_reduce_kernel( ptr0,
           p_a1_local );

        p_a1_0 +=p_a1_local[0];
        p_a1_1 +=p_a1_local[1];
        p_a1_2 +=p_a1_local[2];
      }
    }
  }
  p_a1[0] = p_a1_0;
  p_a1[1] = p_a1_1;
  p_a1[2] = p_a1_2;
}
