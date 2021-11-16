//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

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

void checkop_kernel(const ptr_double rho_new,
  const ptr_double x,
  const ptr_double rhoin,
  double *pre,
  double *post,
  int *num, const double rhol)
{
  double diff;
  diff = (OPS_ACCS(rho_new, 0) - OPS_ACCS(rhoin, 0));
  if(fabs(diff)<0.01 && OPS_ACCS(x, 0) > -4.1){
    *post = *post + diff*diff;
    *num = *num + 1;

  }
  else
    *pre = *pre + (OPS_ACCS(rho_new, 0) - rhol)* (OPS_ACCS(rho_new, 0) - rhol);
}


__kernel void ops_checkop_kernel(
__global const double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global double* restrict arg3,
__local double* scratch3,
int r_bytes3,
__global double* restrict arg4,
__local double* scratch4,
int r_bytes4,
__global int* restrict arg5,
__local int* scratch5,
int r_bytes5,
const double rhol,
const int base0,
const int base1,
const int base2,
const int size0 ){

  arg3 += r_bytes3;
  double arg3_l[1];
  arg4 += r_bytes4;
  double arg4_l[1];
  arg5 += r_bytes5;
  int arg5_l[1];
  for (int d=0; d<1; d++) arg3_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg4_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg5_l[d] = ZERO_int;

  int idx_x = get_global_id(0);

  if (idx_x < size0) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1] };
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1] };
    const ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1] };
    checkop_kernel(ptr0,
                   ptr1,
                   ptr2,
                   arg3_l,
                   arg4_l,
                   arg5_l,
                   rhol);
  }
  int group_index = get_group_id(0) + get_group_id(1)*get_num_groups(0)+ get_group_id(2)*get_num_groups(0)*get_num_groups(1);
  for (int d=0; d<1; d++)
    reduce_double(arg3_l[d], scratch3, &arg3[group_index*1+d], OPS_INC);
  for (int d=0; d<1; d++)
    reduce_double(arg4_l[d], scratch4, &arg4[group_index*1+d], OPS_INC);
  for (int d=0; d<1; d++)
    reduce_int(arg5_l[d], scratch5, &arg5[group_index*1+d], OPS_INC);

}