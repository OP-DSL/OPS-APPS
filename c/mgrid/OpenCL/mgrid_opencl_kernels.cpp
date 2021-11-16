//
// auto-generated by ops.py//

//header
#define OPS_API 2
#define OPS_2D
#include "stdlib.h"
#include "stdio.h"
#include "ops_lib_core.h"
#include "ops_opencl_rt_support.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
//global constants


void ops_init_backend() {}

//this needs to be a platform specific copy symbol to device function
void ops_decl_const_char(int dim, char const * type, int typeSize, char * dat, char const * name ) {
  OPS_instance *instance = OPS_instance::getOPSInstance();
  ops_execute(instance);
  cl_int ret = 0;
  if (instance->opencl_instance->OPS_opencl_core.constant == NULL) {
    instance->opencl_instance->OPS_opencl_core.constant = (cl_mem*) malloc((0)*sizeof(cl_mem));
    for ( int i=0; i<0; i++ ){
      instance->opencl_instance->OPS_opencl_core.constant[i] = NULL;
    }
  }
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}



  void buildOpenCLKernels(OPS_instance *instance) {
    static bool isbuilt = false;

    if(!isbuilt) {
      //clSafeCall( clUnloadCompiler() );

      instance->opencl_instance->OPS_opencl_core.n_kernels = 8;
      instance->opencl_instance->OPS_opencl_core.kernel = (cl_kernel*) malloc(8*sizeof(cl_kernel));
    }
    isbuilt = true;
  }
  
//user kernel files
#include "restrict_check_opencl_kernel.cpp"
#include "mgrid_restrict_kernel_opencl_kernel.cpp"
#include "mgrid_populate_kernel_1_opencl_kernel.cpp"
#include "mgrid_populate_kernel_3_opencl_kernel.cpp"
#include "mgrid_prolong_kernel_opencl_kernel.cpp"
#include "prolong_check_opencl_kernel.cpp"
