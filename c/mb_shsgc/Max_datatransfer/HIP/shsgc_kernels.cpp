//
// auto-generated by ops.py//

//header
#include <hip/hip_runtime.h>
#define OPS_API 2
#define OPS_1D
#include "ops_lib_core.h"

#include "ops_hip_rt_support.h"
#include "ops_hip_reduction.h"


#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
// global constants
#define nxp nxp_OPSCONSTANT
__constant__ int nxp;
#define nyp nyp_OPSCONSTANT
__constant__ int nyp;
#define xhalo xhalo_OPSCONSTANT
__constant__ int xhalo;
#define xmin xmin_OPSCONSTANT
__constant__ double xmin;
#define xmax xmax_OPSCONSTANT
__constant__ double xmax;
#define dx dx_OPSCONSTANT
__constant__ double dx;
#define pl pl_OPSCONSTANT
__constant__ double pl;
#define pr pr_OPSCONSTANT
__constant__ double pr;
#define rhol rhol_OPSCONSTANT
__constant__ double rhol;
#define rhor rhor_OPSCONSTANT
__constant__ double rhor;
#define ul2 ul2_OPSCONSTANT
__constant__ double ul2;
#define ur ur_OPSCONSTANT
__constant__ double ur;
#define gam gam_OPSCONSTANT
__constant__ double gam;
#define gam1 gam1_OPSCONSTANT
__constant__ double gam1;
#define eps eps_OPSCONSTANT
__constant__ double eps;
#define lambda lambda_OPSCONSTANT
__constant__ double lambda;
#define dt dt_OPSCONSTANT
__constant__ double dt;
#define del2 del2_OPSCONSTANT
__constant__ double del2;
#define akap2 akap2_OPSCONSTANT
__constant__ double akap2;
#define tvdsmu tvdsmu_OPSCONSTANT
__constant__ double tvdsmu;
#define con con_OPSCONSTANT
__constant__ double con;
#define Mach Mach_OPSCONSTANT
__constant__ double Mach;
#define xt xt_OPSCONSTANT
__constant__ double xt;
#define scale scale_OPSCONSTANT
__constant__ int scale;

void ops_init_backend() {}

//Dummy kernel to make sure constants are not optimized out
__global__ void ops_internal_this_is_stupid() {
((int*)&nxp)[0]=0;
((int*)&nyp)[0]=0;
((int*)&xhalo)[0]=0;
((int*)&xmin)[0]=0;
((int*)&xmax)[0]=0;
((int*)&dx)[0]=0;
((int*)&pl)[0]=0;
((int*)&pr)[0]=0;
((int*)&rhol)[0]=0;
((int*)&rhor)[0]=0;
((int*)&ul2)[0]=0;
((int*)&ur)[0]=0;
((int*)&gam)[0]=0;
((int*)&gam1)[0]=0;
((int*)&eps)[0]=0;
((int*)&lambda)[0]=0;
((int*)&dt)[0]=0;
((int*)&del2)[0]=0;
((int*)&akap2)[0]=0;
((int*)&tvdsmu)[0]=0;
((int*)&con)[0]=0;
((int*)&Mach)[0]=0;
((int*)&xt)[0]=0;
((int*)&scale)[0]=0;
}

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(OPS_instance::getOPSInstance());
  if (!strcmp(name,"nxp")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(nxp_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"nyp")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(nyp_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"xhalo")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(xhalo_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"xmin")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(xmin_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"xmax")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(xmax_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"dx")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(dx_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"pl")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(pl_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"pr")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(pr_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rhol")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rhol_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rhor")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rhor_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"ul2")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(ul2_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"ur")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(ur_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"gam")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(gam_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"gam1")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(gam1_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"eps")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(eps_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"lambda")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(lambda_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"dt")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(dt_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"del2")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(del2_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"akap2")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(akap2_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"tvdsmu")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(tvdsmu_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"con")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(con_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"Mach")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(Mach_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"xt")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(xt_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"scale")) {
    hipSafeCall(OPS_instance::getOPSInstance()->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(scale_OPSCONSTANT), dat, dim*size));
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}


//user kernel files
#include "gridgen_kernel_hip_kernel.cpp"
#include "init_kernel_hip_kernel.cpp"
#include "save_kernel_hip_kernel.cpp"
#include "calvar_kernel_hip_kernel.cpp"
#include "xder1_kernel_hip_kernel.cpp"
#include "residue_eval_hip_kernel.cpp"
#include "updateRK3_kernel_hip_kernel.cpp"
#include "Riemann_kernel_hip_kernel.cpp"
#include "limiter_kernel_hip_kernel.cpp"
#include "tvd_kernel_hip_kernel.cpp"
#include "vars_kernel_hip_kernel.cpp"
#include "calupwindeff_kernel_hip_kernel.cpp"
#include "fact_kernel_hip_kernel.cpp"
#include "update_kernel_hip_kernel.cpp"
#include "checkop_kernel_hip_kernel.cpp"
