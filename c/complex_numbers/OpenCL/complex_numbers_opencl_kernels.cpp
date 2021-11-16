//
// auto-generated by ops.py//

//header
#define OPS_API 2
#define OPS_1D
#include "stdlib.h"
#include "stdio.h"
#include "ops_lib_core.h"
#include "ops_opencl_rt_support.h"
#include "user_types.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
//global constants
extern double c0;
extern double rc0;
extern double rc1;
extern double rc2;
extern double rc3;
extern int nx0;
extern double deltai0;
extern double deltat;


void ops_init_backend() {}

//this needs to be a platform specific copy symbol to device function
void ops_decl_const_char(int dim, char const * type, int typeSize, char * dat, char const * name ) {
  OPS_instance *instance = OPS_instance::getOPSInstance();
  ops_execute(instance);
  cl_int ret = 0;
  if (instance->opencl_instance->OPS_opencl_core.constant == NULL) {
    instance->opencl_instance->OPS_opencl_core.constant = (cl_mem*) malloc((8)*sizeof(cl_mem));
    for ( int i=0; i<8; i++ ){
      instance->opencl_instance->OPS_opencl_core.constant[i] = NULL;
    }
  }
  if (!strcmp(name,"c0")) {
    if (instance->opencl_instance->OPS_opencl_core.constant[0] == NULL) {
      instance->opencl_instance->OPS_opencl_core.constant[0] = clCreateBuffer(instance->opencl_instance->OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(instance->opencl_instance->OPS_opencl_core.command_queue, instance->opencl_instance->OPS_opencl_core.constant[0], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(instance->opencl_instance->OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(instance->opencl_instance->OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc0")) {
    if (instance->opencl_instance->OPS_opencl_core.constant[1] == NULL) {
      instance->opencl_instance->OPS_opencl_core.constant[1] = clCreateBuffer(instance->opencl_instance->OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(instance->opencl_instance->OPS_opencl_core.command_queue, instance->opencl_instance->OPS_opencl_core.constant[1], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(instance->opencl_instance->OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(instance->opencl_instance->OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc1")) {
    if (instance->opencl_instance->OPS_opencl_core.constant[2] == NULL) {
      instance->opencl_instance->OPS_opencl_core.constant[2] = clCreateBuffer(instance->opencl_instance->OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(instance->opencl_instance->OPS_opencl_core.command_queue, instance->opencl_instance->OPS_opencl_core.constant[2], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(instance->opencl_instance->OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(instance->opencl_instance->OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc2")) {
    if (instance->opencl_instance->OPS_opencl_core.constant[3] == NULL) {
      instance->opencl_instance->OPS_opencl_core.constant[3] = clCreateBuffer(instance->opencl_instance->OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(instance->opencl_instance->OPS_opencl_core.command_queue, instance->opencl_instance->OPS_opencl_core.constant[3], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(instance->opencl_instance->OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(instance->opencl_instance->OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc3")) {
    if (instance->opencl_instance->OPS_opencl_core.constant[4] == NULL) {
      instance->opencl_instance->OPS_opencl_core.constant[4] = clCreateBuffer(instance->opencl_instance->OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(instance->opencl_instance->OPS_opencl_core.command_queue, instance->opencl_instance->OPS_opencl_core.constant[4], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(instance->opencl_instance->OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(instance->opencl_instance->OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"nx0")) {
    if (instance->opencl_instance->OPS_opencl_core.constant[5] == NULL) {
      instance->opencl_instance->OPS_opencl_core.constant[5] = clCreateBuffer(instance->opencl_instance->OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(instance->opencl_instance->OPS_opencl_core.command_queue, instance->opencl_instance->OPS_opencl_core.constant[5], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(instance->opencl_instance->OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(instance->opencl_instance->OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"deltai0")) {
    if (instance->opencl_instance->OPS_opencl_core.constant[6] == NULL) {
      instance->opencl_instance->OPS_opencl_core.constant[6] = clCreateBuffer(instance->opencl_instance->OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(instance->opencl_instance->OPS_opencl_core.command_queue, instance->opencl_instance->OPS_opencl_core.constant[6], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(instance->opencl_instance->OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(instance->opencl_instance->OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"deltat")) {
    if (instance->opencl_instance->OPS_opencl_core.constant[7] == NULL) {
      instance->opencl_instance->OPS_opencl_core.constant[7] = clCreateBuffer(instance->opencl_instance->OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(instance->opencl_instance->OPS_opencl_core.command_queue, instance->opencl_instance->OPS_opencl_core.constant[7], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(instance->opencl_instance->OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(instance->opencl_instance->OPS_opencl_core.command_queue) );
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}



  void buildOpenCLKernels(OPS_instance *instance) {
    static bool isbuilt = false;

    if(!isbuilt) {
      //clSafeCall( clUnloadCompiler() );

      instance->opencl_instance->OPS_opencl_core.n_kernels = 7;
      instance->opencl_instance->OPS_opencl_core.kernel = (cl_kernel*) malloc(7*sizeof(cl_kernel));
    }
    isbuilt = true;
  }
  
//user kernel files
#include "complex_numbers_block0_cn_kernel_opencl_kernel.cpp"
#include "complex_numbers_block0_2_kernel_opencl_kernel.cpp"
#include "complex_numbers_block0_5_kernel_opencl_kernel.cpp"
#include "complex_numbers_block0_1_kernel_opencl_kernel.cpp"
#include "complex_numbers_block0_4_kernel_opencl_kernel.cpp"
#include "complex_numbers_block0_3_kernel_opencl_kernel.cpp"
#include "complex_numbers_block0_0_kernel_opencl_kernel.cpp"