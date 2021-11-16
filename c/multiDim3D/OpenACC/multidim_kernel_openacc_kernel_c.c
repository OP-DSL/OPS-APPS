//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_multidim_kernel;
int ydim0_multidim_kernel;
int zdim0_multidim_kernel;

//user function
inline 
void multidim_kernel(ptrm_double val,
  int *idx){
  OPS_ACC(val, 0,0,0,0) = (double)(idx[0]);
  OPS_ACC(val, 1,0,0,0) = (double)(idx[1]);
  OPS_ACC(val, 2,0,0,0) = (double)(idx[2]);



}


void multidim_kernel_c_wrapper(
  double *p_a0,
  int *p_a1,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0)
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
        int arg_idx[] = {arg_idx0+n_x, arg_idx1+n_y, arg_idx2+n_z};
        #ifdef OPS_SOA
        ptrm_double ptr0 = {  p_a0 + n_x*1 + n_y*xdim0_multidim_kernel*1 + n_z*xdim0_multidim_kernel*ydim0_multidim_kernel*1, xdim0_multidim_kernel, ydim0_multidim_kernel, zdim0_multidim_kernel};
        #else
        ptrm_double ptr0 = {  p_a0 + n_x*1 + n_y*xdim0_multidim_kernel*1 + n_z*xdim0_multidim_kernel*ydim0_multidim_kernel*1, xdim0_multidim_kernel, ydim0_multidim_kernel, 3};
        #endif
        multidim_kernel( ptr0,
          arg_idx );

      }
    }
  }
}