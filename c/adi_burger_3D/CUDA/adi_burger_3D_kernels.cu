//
// auto-generated by ops.py//

//header
#include <cuda.h>
#define OPS_API 2
#define OPS_3D
#include "ops_lib_core.h"

#include "ops_cuda_rt_support.h"
#include "ops_cuda_reduction.h"

#include <cuComplex.h>

#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
// global constants
__constant__ int nx;
__constant__ int ny;
__constant__ int nz;
__constant__ double Re;
__constant__ double h;
__constant__ double r1;
__constant__ double r2;

void ops_init_backend() {}

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(OPS_instance::getOPSInstance());
  if (!strcmp(name,"nx")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(nx, dat, dim*size));
  }
  else
  if (!strcmp(name,"ny")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(ny, dat, dim*size));
  }
  else
  if (!strcmp(name,"nz")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(nz, dat, dim*size));
  }
  else
  if (!strcmp(name,"Re")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(Re, dat, dim*size));
  }
  else
  if (!strcmp(name,"h")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(h, dat, dim*size));
  }
  else
  if (!strcmp(name,"r1")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(r1, dat, dim*size));
  }
  else
  if (!strcmp(name,"r2")) {
    cutilSafeCall(OPS_instance::getOPSInstance()->ostream(),cudaMemcpyToSymbol(r2, dat, dim*size));
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}


//user kernel files
#include "initKernel_cuda_kernel.cu"
#include "CopyUVW_cuda_kernel.cu"
#include "preprocessX_cuda_kernel.cu"
#include "preprocessY_cuda_kernel.cu"
#include "preprocessZ_cuda_kernel.cu"
