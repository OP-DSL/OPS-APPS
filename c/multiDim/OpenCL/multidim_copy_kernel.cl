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

void multidim_copy_kernel(const ptrm_double src,
  ptrm_double dest){
  OPS_ACCM(dest, 0,0,0) = OPS_ACCM(src, 0,0,0);
  OPS_ACCM(dest, 1,0,0) = OPS_ACCM(src, 1,0,0);
}


__kernel void ops_multidim_copy_kernel(
__global const double* restrict arg0,
__global double* restrict arg1,
const int base0,
const int base1,
const int size0,
const int size1 ){


  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1) {
    #ifdef OPS_SOA
    const ptrm_double ptr0 = { &arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_multidim_copy_kernel], xdim0_multidim_copy_kernel, ydim0_multidim_copy_kernel};
    #else
    const ptrm_double ptr0 = { &arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_multidim_copy_kernel], xdim0_multidim_copy_kernel, 2};
    #endif
    #ifdef OPS_SOA
    ptrm_double ptr1 = { &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_multidim_copy_kernel], xdim1_multidim_copy_kernel, ydim1_multidim_copy_kernel};
    #else
    ptrm_double ptr1 = { &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_multidim_copy_kernel], xdim1_multidim_copy_kernel, 2};
    #endif
    multidim_copy_kernel(ptr0,
                         ptr1);
  }

}
