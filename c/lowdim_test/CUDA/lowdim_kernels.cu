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

void ops_init_backend() {}

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(OPS_instance::getOPSInstance());
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}


//user kernel files
#include "set_val_cuda_kernel.cu"
#include "calc_cuda_kernel.cu"