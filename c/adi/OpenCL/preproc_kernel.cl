//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_3D
#define OPS_API 2
#define OPS_NO_GLOBALS
#include "ops_macros.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5

//user function

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
  int *idx, const int nx, const int ny, const int nz, const double lambda)
{

  double a, b, c, d;

  if(idx[0]==0 || idx[0]==nx-1 || idx[1]==0 || idx[1]==ny-1 || idx[2]==0 || idx[2]==nz-1) {
    d = 0.0f;
    a = 0.0f;
    b = 1.0f;
    c = 0.0f;
  } else {
    d = lambda*( OPS_ACCS(u, -1,0,0) + OPS_ACCS(u, 1,0,0)
               + OPS_ACCS(u, 0,-1,0) + OPS_ACCS(u, 0,1,0)
               + OPS_ACCS(u, 0,0,-1) + OPS_ACCS(u, 0,0,1)
               - 6.0f*OPS_ACCS(u, 0,0,0));
    a = -0.5f * lambda;
    b =  1.0f + lambda;
    c = -0.5f * lambda;

  }

  OPS_ACCS(du, 0,0,0) = d;
  OPS_ACCS(ax, 0,0,0) = a;
  OPS_ACCS(bx, 0,0,0) = b;
  OPS_ACCS(cx, 0,0,0) = c;
  OPS_ACCS(ay, 0,0,0) = a;
  OPS_ACCS(by, 0,0,0) = b;
  OPS_ACCS(cy, 0,0,0) = c;
  OPS_ACCS(az, 0,0,0) = a;
  OPS_ACCS(bz, 0,0,0) = b;
  OPS_ACCS(cz, 0,0,0) = c;
}


__kernel void ops_preproc_kernel(
__global const double* restrict arg0,
__global double* restrict arg1,
__global double* restrict arg2,
__global double* restrict arg3,
__global double* restrict arg4,
__global double* restrict arg5,
__global double* restrict arg6,
__global double* restrict arg7,
__global double* restrict arg8,
__global double* restrict arg9,
__global double* restrict arg10,
const int nx,
const int ny,
const int nz,
const double lambda,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int base6,
const int base7,
const int base8,
const int base9,
const int base10,
int arg_idx0, int arg_idx1, int arg_idx2,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  int arg_idx[3];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg_idx[2] = arg_idx2+idx_z;
  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_preproc_kernel + idx_z * 1*1 * xdim0_preproc_kernel * ydim0_preproc_kernel], xdim0_preproc_kernel, ydim0_preproc_kernel};
    ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_preproc_kernel + idx_z * 1*1 * xdim1_preproc_kernel * ydim1_preproc_kernel], xdim1_preproc_kernel, ydim1_preproc_kernel};
    ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_preproc_kernel + idx_z * 1*1 * xdim2_preproc_kernel * ydim2_preproc_kernel], xdim2_preproc_kernel, ydim2_preproc_kernel};
    ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_preproc_kernel + idx_z * 1*1 * xdim3_preproc_kernel * ydim3_preproc_kernel], xdim3_preproc_kernel, ydim3_preproc_kernel};
    ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_preproc_kernel + idx_z * 1*1 * xdim4_preproc_kernel * ydim4_preproc_kernel], xdim4_preproc_kernel, ydim4_preproc_kernel};
    ptr_double ptr5 = { &arg5[base5 + idx_x * 1*1 + idx_y * 1*1 * xdim5_preproc_kernel + idx_z * 1*1 * xdim5_preproc_kernel * ydim5_preproc_kernel], xdim5_preproc_kernel, ydim5_preproc_kernel};
    ptr_double ptr6 = { &arg6[base6 + idx_x * 1*1 + idx_y * 1*1 * xdim6_preproc_kernel + idx_z * 1*1 * xdim6_preproc_kernel * ydim6_preproc_kernel], xdim6_preproc_kernel, ydim6_preproc_kernel};
    ptr_double ptr7 = { &arg7[base7 + idx_x * 1*1 + idx_y * 1*1 * xdim7_preproc_kernel + idx_z * 1*1 * xdim7_preproc_kernel * ydim7_preproc_kernel], xdim7_preproc_kernel, ydim7_preproc_kernel};
    ptr_double ptr8 = { &arg8[base8 + idx_x * 1*1 + idx_y * 1*1 * xdim8_preproc_kernel + idx_z * 1*1 * xdim8_preproc_kernel * ydim8_preproc_kernel], xdim8_preproc_kernel, ydim8_preproc_kernel};
    ptr_double ptr9 = { &arg9[base9 + idx_x * 1*1 + idx_y * 1*1 * xdim9_preproc_kernel + idx_z * 1*1 * xdim9_preproc_kernel * ydim9_preproc_kernel], xdim9_preproc_kernel, ydim9_preproc_kernel};
    ptr_double ptr10 = { &arg10[base10 + idx_x * 1*1 + idx_y * 1*1 * xdim10_preproc_kernel + idx_z * 1*1 * xdim10_preproc_kernel * ydim10_preproc_kernel], xdim10_preproc_kernel, ydim10_preproc_kernel};
    preproc_kernel(ptr0,
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
                   arg_idx,
                   nx,
                   ny,
                   nz,
                   lambda);
  }

}
