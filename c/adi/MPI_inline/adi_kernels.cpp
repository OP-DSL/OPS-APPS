//
// auto-generated by ops.py
//

#include "./MPI_inline/adi_common.h"


void ops_init_backend() {}

void ops_decl_const_char2(int dim, char const *type,
int size, char *dat, char const *name){
  if (!strcmp(name,"nx")) {
    nx = *(int*)dat;
  }
  else
  if (!strcmp(name,"ny")) {
    ny = *(int*)dat;
  }
  else
  if (!strcmp(name,"nz")) {
    nz = *(int*)dat;
  }
  else
  if (!strcmp(name,"lambda")) {
    lambda = *(double*)dat;
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}

//user kernel files
#include "init_kernel_mpiinline_kernel.cpp"
#include "preproc_kernel_mpiinline_kernel.cpp"