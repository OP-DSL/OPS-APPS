//
// auto-generated by ops.py
//

#include "./MPI_inline/mgrid_common.h"


void ops_init_backend() {}

void ops_decl_const_char2(int dim, char const *type,
int size, char *dat, char const *name){
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}

//user kernel files
#include "mgrid_populate_kernel_1_mpiinline_kernel.cpp"
#include "mgrid_prolong_kernel_mpiinline_kernel.cpp"
#include "prolong_check_mpiinline_kernel.cpp"
#include "mgrid_populate_kernel_3_mpiinline_kernel.cpp"
#include "mgrid_restrict_kernel_mpiinline_kernel.cpp"
#include "restrict_check_mpiinline_kernel.cpp"