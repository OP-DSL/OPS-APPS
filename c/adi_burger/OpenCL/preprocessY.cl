//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_2D
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

void preprocessY(const ptr_double u,
  const ptr_double v,
  const double *time,
  ptr_double a,
  ptr_double b,
  ptr_double c,
  ptr_double du,
  ptr_double dv,
  ACC<double> resU,
  ACC<double> resV,
  int *idx, const int nx, const int ny, const double Re, const double h, const double r1, const double r2)
{
    OPS_ACCS(resU, 0, 0) = 0;
    OPS_ACCS(resV, 0, 0) = 0;
    if (idx[0] == 0 || idx[0] == nx - 1 || idx[1] == 0 || idx[1] == ny - 1) {
        OPS_ACCS(a, 0, 0) = 0;
        OPS_ACCS(b, 0, 0) = 1;
        OPS_ACCS(c, 0, 0) = 0;
        OPS_ACCS(du, 0, 0) =
            0.75 -
            1 / (4 * (1 + exp((-4 * idx[0] * h + 4 * idx[1] * h - (*time)) *
                              Re / 32)));
        OPS_ACCS(dv, 0, 0) =
            0.75 +
            1 / (4 * (1 + exp((-4 * idx[0] * h + 4 * idx[1] * h - (*time)) *
                              Re / 32)));
    } else {
        OPS_ACCS(a, 0, 0) = -r1 * OPS_ACCS(v, 0, 0) - r2;
        OPS_ACCS(b, 0, 0) = 1 + 2 * r2;
        OPS_ACCS(c, 0, 0) = -r1 * OPS_ACCS(v, 0, 0) + r2;
        OPS_ACCS(du, 0, 0) = (r1 * OPS_ACCS(u, 0, 0) + r2) * OPS_ACCS(u, -1, 0) + (1 - 2 * r2) * OPS_ACCS(u, 0, 0) +
                   (-r1 * OPS_ACCS(u, 0, 0) + r2) * OPS_ACCS(u, 1, 0);
        OPS_ACCS(dv, 0, 0) = (r1 * OPS_ACCS(u, 0, 0) + r2) * OPS_ACCS(v, -1, 0) + (1 - 2 * r2) * OPS_ACCS(v, 0, 0) +
                   (-r1 * OPS_ACCS(u, 0, 0) + r2) * OPS_ACCS(v, 1, 0);
    }
}


__kernel void ops_preprocessY(
__global const double* restrict arg0,
__global const double* restrict arg1,
const double arg2,
__global double* restrict arg3,
__global double* restrict arg4,
__global double* restrict arg5,
__global double* restrict arg6,
__global double* restrict arg7,
__global double* restrict arg8,
__global double* restrict arg9,
const int nx,
const int ny,
const double Re,
const double h,
const double r1,
const double r2,
const int base0,
const int base1,
const int base3,
const int base4,
const int base5,
const int base6,
const int base7,
const int base8,
const int base9,
int arg_idx0, int arg_idx1,
const int size0,
const int size1 ){


  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  int arg_idx[2];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  if (idx_x < size0 && idx_y < size1) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_preprocessY], xdim0_preprocessY};
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_preprocessY], xdim1_preprocessY};
    ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_preprocessY], xdim3_preprocessY};
    ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_preprocessY], xdim4_preprocessY};
    ptr_double ptr5 = { &arg5[base5 + idx_x * 1*1 + idx_y * 1*1 * xdim5_preprocessY], xdim5_preprocessY};
    ptr_double ptr6 = { &arg6[base6 + idx_x * 1*1 + idx_y * 1*1 * xdim6_preprocessY], xdim6_preprocessY};
    ptr_double ptr7 = { &arg7[base7 + idx_x * 1*1 + idx_y * 1*1 * xdim7_preprocessY], xdim7_preprocessY};
    ptr_double ptr8 = { &arg8[base8 + idx_x * 1*1 + idx_y * 1*1 * xdim8_preprocessY], xdim8_preprocessY};
    ptr_double ptr9 = { &arg9[base9 + idx_x * 1*1 + idx_y * 1*1 * xdim9_preprocessY], xdim9_preprocessY};
    preprocessY(ptr0,
                     ptr1,
                     &arg2,
                     ptr3,
                     ptr4,
                     ptr5,
                     ptr6,
                     ptr7,
                     ptr8,
                     ptr9,
                     arg_idx,
                     nx,
                     ny,
                     Re,
                     h,
                     r1,
                     r2);
  }

}
