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

void ideal_gas_kernel(const ptr_double density,
  const ptr_double energy,
  ptr_double pressure,
  ptr_double soundspeed) {

  double sound_speed_squared, v, pressurebyenergy, pressurebyvolume;

  v = 1.0 / OPS_ACCS(density, 0,0,0);
  OPS_ACCS(pressure, 0,0,0) = (1.4 - 1.0) * OPS_ACCS(density, 0,0,0) * OPS_ACCS(energy, 0,0,0);

  pressurebyenergy = (1.4 - 1.0) * OPS_ACCS(density, 0,0,0);
  pressurebyvolume = -1.0*OPS_ACCS(density, 0,0,0) * OPS_ACCS(pressure, 0,0,0);
  sound_speed_squared = v*v*(OPS_ACCS(pressure, 0,0,0) * pressurebyenergy-pressurebyvolume);
  OPS_ACCS(soundspeed, 0,0,0) = sqrt(sound_speed_squared);
}


__kernel void ops_ideal_gas_kernel(
__global const double* restrict arg0,
__global const double* restrict arg1,
__global double* restrict arg2,
__global double* restrict arg3,
const int base0,
const int base1,
const int base2,
const int base3,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_ideal_gas_kernel + idx_z * 1*1 * xdim0_ideal_gas_kernel * ydim0_ideal_gas_kernel], xdim0_ideal_gas_kernel, ydim0_ideal_gas_kernel};
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_ideal_gas_kernel + idx_z * 1*1 * xdim1_ideal_gas_kernel * ydim1_ideal_gas_kernel], xdim1_ideal_gas_kernel, ydim1_ideal_gas_kernel};
    ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_ideal_gas_kernel + idx_z * 1*1 * xdim2_ideal_gas_kernel * ydim2_ideal_gas_kernel], xdim2_ideal_gas_kernel, ydim2_ideal_gas_kernel};
    ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_ideal_gas_kernel + idx_z * 1*1 * xdim3_ideal_gas_kernel * ydim3_ideal_gas_kernel], xdim3_ideal_gas_kernel, ydim3_ideal_gas_kernel};
    ideal_gas_kernel(ptr0,
                     ptr1,
                     ptr2,
                     ptr3);
  }

}
