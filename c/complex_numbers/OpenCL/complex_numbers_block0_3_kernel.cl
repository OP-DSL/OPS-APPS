//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
#define OPS_1D
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

void complex_numbers_block0_3_kernel(const ptr_double wk1,
  ptr_double phi_old,
  const ACC<double> &rkold, const double deltat)
{
OPS_ACCS(phi_old, 0) = deltat*rkold[0]*OPS_ACCS(wk1, 0) + OPS_ACCS(phi_old, 0);
}


__kernel void ops_complex_numbers_block0_3_kernel(
__global const double* restrict arg0,
__global double* restrict arg1,
const double arg2,
const double deltat,
const int base0,
const int base1,
const int size0 ){


  int idx_x = get_global_id(0);

  if (idx_x < size0) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1] };
    ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1] };
    complex_numbers_block0_3_kernel(ptr0,
                                    ptr1,
                                    &arg2,
                                    deltat);
  }

}
