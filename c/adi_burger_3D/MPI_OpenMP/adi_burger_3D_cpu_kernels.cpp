//
// auto-generated by ops.py//

//header
#define OPS_3D
#define OPS_API 2
#include "ops_lib_core.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

// global constants
extern int nx;
extern int ny;
extern int nz;
extern double Re;
extern double h;
extern double r1;
extern double r2;

void ops_init_backend() {}

//user kernel files
#include "initKernel_cpu_kernel.cpp"
#include "CopyUVW_cpu_kernel.cpp"
#include "preprocessX_cpu_kernel.cpp"
#include "preprocessY_cpu_kernel.cpp"
#include "preprocessZ_cpu_kernel.cpp"
