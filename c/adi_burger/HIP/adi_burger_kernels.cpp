//
// auto-generated by ops.py//

//header
#include <hip/hip_runtime.h>
#define OPS_API 2
#define OPS_2D
#include "ops_lib_core.h"

#include "ops_hip_rt_support.h"
#include "ops_hip_reduction.h"


#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
// global constants
#define nx nx_OPSCONSTANT
__constant__ int nx;
#define ny ny_OPSCONSTANT
__constant__ int ny;
#define Re Re_OPSCONSTANT
__constant__ double Re;
#define h h_OPSCONSTANT
__constant__ double h;
#define r1 r1_OPSCONSTANT
__constant__ double r1;
#define r2 r2_OPSCONSTANT
__constant__ double r2;

void ops_init_backend() {}

//Dummy kernel to make sure constants are not optimized out
__global__ void ops_internal_this_is_stupid() {
((int*)&nx)[0]=0;
((int*)&ny)[0]=0;
((int*)&Re)[0]=0;
((int*)&h)[0]=0;
((int*)&r1)[0]=0;
((int*)&r2)[0]=0;
}

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(OPS_instance::getOPSInstance());
  if (!strcmp(name,"nx")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(nx_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"ny")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(ny_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"Re")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(Re_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"h")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(h_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"r1")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(r1_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"r2")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(r2_OPSCONSTANT), dat, dim*size));
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}


//user kernel files
#include "initKernel_hip_kernel.cpp"
#include "preprocessX_hip_kernel.cpp"
#include "preprocessY_hip_kernel.cpp"
