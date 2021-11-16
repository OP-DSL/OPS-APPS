//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_preproc_kernel;
int ydim0_preproc_kernel;
int xdim1_preproc_kernel;
int ydim1_preproc_kernel;
int xdim2_preproc_kernel;
int ydim2_preproc_kernel;
int xdim3_preproc_kernel;
int ydim3_preproc_kernel;
int xdim4_preproc_kernel;
int ydim4_preproc_kernel;
int xdim5_preproc_kernel;
int ydim5_preproc_kernel;
int xdim6_preproc_kernel;
int ydim6_preproc_kernel;
int xdim7_preproc_kernel;
int ydim7_preproc_kernel;
int xdim8_preproc_kernel;
int ydim8_preproc_kernel;
int xdim9_preproc_kernel;
int ydim9_preproc_kernel;
int xdim10_preproc_kernel;
int ydim10_preproc_kernel;

//user function
inline 
void preproc_kernel(const ptr_double u,
  ptr_double du,
  ptr_double ax,
  ptr_double bx,
  ptr_double cx,
  ptr_double ay,
  ptr_double by,
  ptr_double cy,
  ptr_double az,
  ptr_double bz,
  ptr_double cz,
  int *idx){

  double a, b, c, d;

  if(idx[0]==0 || idx[0]==nx-1 || idx[1]==0 || idx[1]==ny-1 || idx[2]==0 || idx[2]==nz-1) {
    d = 0.0f;
    a = 0.0f;
    b = 1.0f;
    c = 0.0f;
  } else {
    d = lambda*( OPS_ACC(u, -1,0,0) + OPS_ACC(u, 1,0,0)
               + OPS_ACC(u, 0,-1,0) + OPS_ACC(u, 0,1,0)
               + OPS_ACC(u, 0,0,-1) + OPS_ACC(u, 0,0,1)
               - 6.0f*OPS_ACC(u, 0,0,0));
    a = -0.5f * lambda;
    b =  1.0f + lambda;
    c = -0.5f * lambda;

  }

  OPS_ACC(du, 0,0,0) = d;
  OPS_ACC(ax, 0,0,0) = a;
  OPS_ACC(bx, 0,0,0) = b;
  OPS_ACC(cx, 0,0,0) = c;
  OPS_ACC(ay, 0,0,0) = a;
  OPS_ACC(by, 0,0,0) = b;
  OPS_ACC(cy, 0,0,0) = c;
  OPS_ACC(az, 0,0,0) = a;
  OPS_ACC(bz, 0,0,0) = b;
  OPS_ACC(cz, 0,0,0) = c;
}


void preproc_kernel_c_wrapper(
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
  int *p_a11,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10)
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
        const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_preproc_kernel*1*1 + n_z*xdim0_preproc_kernel*ydim0_preproc_kernel*1*1, xdim0_preproc_kernel, ydim0_preproc_kernel};
        ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_preproc_kernel*1*1 + n_z*xdim1_preproc_kernel*ydim1_preproc_kernel*1*1, xdim1_preproc_kernel, ydim1_preproc_kernel};
        ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_preproc_kernel*1*1 + n_z*xdim2_preproc_kernel*ydim2_preproc_kernel*1*1, xdim2_preproc_kernel, ydim2_preproc_kernel};
        ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_preproc_kernel*1*1 + n_z*xdim3_preproc_kernel*ydim3_preproc_kernel*1*1, xdim3_preproc_kernel, ydim3_preproc_kernel};
        ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_preproc_kernel*1*1 + n_z*xdim4_preproc_kernel*ydim4_preproc_kernel*1*1, xdim4_preproc_kernel, ydim4_preproc_kernel};
        ptr_double ptr5 = {  p_a5 + n_x*1*1 + n_y*xdim5_preproc_kernel*1*1 + n_z*xdim5_preproc_kernel*ydim5_preproc_kernel*1*1, xdim5_preproc_kernel, ydim5_preproc_kernel};
        ptr_double ptr6 = {  p_a6 + n_x*1*1 + n_y*xdim6_preproc_kernel*1*1 + n_z*xdim6_preproc_kernel*ydim6_preproc_kernel*1*1, xdim6_preproc_kernel, ydim6_preproc_kernel};
        ptr_double ptr7 = {  p_a7 + n_x*1*1 + n_y*xdim7_preproc_kernel*1*1 + n_z*xdim7_preproc_kernel*ydim7_preproc_kernel*1*1, xdim7_preproc_kernel, ydim7_preproc_kernel};
        ptr_double ptr8 = {  p_a8 + n_x*1*1 + n_y*xdim8_preproc_kernel*1*1 + n_z*xdim8_preproc_kernel*ydim8_preproc_kernel*1*1, xdim8_preproc_kernel, ydim8_preproc_kernel};
        ptr_double ptr9 = {  p_a9 + n_x*1*1 + n_y*xdim9_preproc_kernel*1*1 + n_z*xdim9_preproc_kernel*ydim9_preproc_kernel*1*1, xdim9_preproc_kernel, ydim9_preproc_kernel};
        ptr_double ptr10 = {  p_a10 + n_x*1*1 + n_y*xdim10_preproc_kernel*1*1 + n_z*xdim10_preproc_kernel*ydim10_preproc_kernel*1*1, xdim10_preproc_kernel, ydim10_preproc_kernel};
        preproc_kernel( ptr0,
          ptr1,
          ptr2,
          ptr3,
          ptr4,
          ptr5,
          ptr6,
          ptr7,
          ptr8,
          ptr9,
          ptr10,
          arg_idx );

      }
    }
  }
}