//
// auto-generated by ops.py//

//header
#include <hip/hip_runtime.h>
#define OPS_API 2
#define OPS_3D
#include "ops_lib_core.h"

#include "ops_hip_rt_support.h"
#include "ops_hip_reduction.h"


#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
// global constants

void ops_init_backend() {}

//Dummy kernel to make sure constants are not optimized out
__global__ void ops_internal_this_is_stupid() {
}

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(OPS_instance::getOPSInstance());
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}


//user kernel files
#include "write_kernel_hip_kernel.cpp"
