//
// auto-generated by ops.py
//

#include "./MPI_inline/adi_burger_3D_common.h"


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
  if (!strcmp(name,"Re")) {
    Re = *(double*)dat;
  }
  else
  if (!strcmp(name,"h")) {
    h = *(double*)dat;
  }
  else
  if (!strcmp(name,"r1")) {
    r1 = *(double*)dat;
  }
  else
  if (!strcmp(name,"r2")) {
    r2 = *(double*)dat;
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}

//user kernel files
#include "initKernel_mpiinline_kernel.cpp"
#include "CopyUVW_mpiinline_kernel.cpp"
#include "preprocessX_mpiinline_kernel.cpp"
#include "preprocessY_mpiinline_kernel.cpp"
#include "preprocessZ_mpiinline_kernel.cpp"
