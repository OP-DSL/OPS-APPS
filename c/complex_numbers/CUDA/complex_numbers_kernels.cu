//
// auto-generated by ops.py//

//header
#include <cuda.h>
#define OPS_API 2
#define OPS_1D
#include "ops_lib_core.h"

#include "ops_cuda_rt_support.h"
#include "ops_cuda_reduction.h"

#include <cuComplex.h>

#define OPS_FUN_PREFIX __device__ __host__
#include "user_types.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
// global constants
__constant__ double c0;
__constant__ double rc0;
__constant__ double rc1;
__constant__ double rc2;
__constant__ double rc3;
__constant__ int nx0;
__constant__ double deltai0;
__constant__ double deltat;

void ops_init_backend() {}

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(OPS_instance::getOPSInstance());
  if (!strcmp(name,"c0")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(c0, dat, dim*size));
  }
  else
  if (!strcmp(name,"rc0")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(rc0, dat, dim*size));
  }
  else
  if (!strcmp(name,"rc1")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(rc1, dat, dim*size));
  }
  else
  if (!strcmp(name,"rc2")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(rc2, dat, dim*size));
  }
  else
  if (!strcmp(name,"rc3")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(rc3, dat, dim*size));
  }
  else
  if (!strcmp(name,"nx0")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(nx0, dat, dim*size));
  }
  else
  if (!strcmp(name,"deltai0")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(deltai0, dat, dim*size));
  }
  else
  if (!strcmp(name,"deltat")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(deltat, dat, dim*size));
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}


//user kernel files
#include "complex_numbers_block0_5_kernel_cuda_kernel.cu"
#include "complex_numbers_block0_4_kernel_cuda_kernel.cu"
#include "complex_numbers_block0_0_kernel_cuda_kernel.cu"
#include "complex_numbers_block0_1_kernel_cuda_kernel.cu"
#include "complex_numbers_block0_2_kernel_cuda_kernel.cu"
#include "complex_numbers_block0_3_kernel_cuda_kernel.cu"
#include "complex_numbers_block0_cn_kernel_cuda_kernel.cu"
