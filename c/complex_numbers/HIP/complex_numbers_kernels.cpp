//
// auto-generated by ops.py//

//header
#include <hip/hip_runtime.h>
#define OPS_API 2
#define OPS_1D
#include "ops_lib_core.h"

#include "ops_hip_rt_support.h"
#include "ops_hip_reduction.h"


#define OPS_FUN_PREFIX __device__ __host__
#include "user_types.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
// global constants
#define c0 c0_OPSCONSTANT
__constant__ double c0;
#define rc0 rc0_OPSCONSTANT
__constant__ double rc0;
#define rc1 rc1_OPSCONSTANT
__constant__ double rc1;
#define rc2 rc2_OPSCONSTANT
__constant__ double rc2;
#define rc3 rc3_OPSCONSTANT
__constant__ double rc3;
#define nx0 nx0_OPSCONSTANT
__constant__ int nx0;
#define deltai0 deltai0_OPSCONSTANT
__constant__ double deltai0;
#define deltat deltat_OPSCONSTANT
__constant__ double deltat;

void ops_init_backend() {}

//Dummy kernel to make sure constants are not optimized out
__global__ void ops_internal_this_is_stupid() {
((int*)&c0)[0]=0;
((int*)&rc0)[0]=0;
((int*)&rc1)[0]=0;
((int*)&rc2)[0]=0;
((int*)&rc3)[0]=0;
((int*)&nx0)[0]=0;
((int*)&deltai0)[0]=0;
((int*)&deltat)[0]=0;
}

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(OPS_instance::getOPSInstance());
  if (!strcmp(name,"c0")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(c0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc0")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc1")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc1_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc2")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc2_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc3")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc3_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"nx0")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(nx0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"deltai0")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(deltai0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"deltat")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(deltat_OPSCONSTANT), dat, dim*size));
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}


//user kernel files
#include "complex_numbers_block0_5_kernel_hip_kernel.cpp"
#include "complex_numbers_block0_4_kernel_hip_kernel.cpp"
#include "complex_numbers_block0_0_kernel_hip_kernel.cpp"
#include "complex_numbers_block0_1_kernel_hip_kernel.cpp"
#include "complex_numbers_block0_2_kernel_hip_kernel.cpp"
#include "complex_numbers_block0_3_kernel_hip_kernel.cpp"
#include "complex_numbers_block0_cn_kernel_hip_kernel.cpp"
