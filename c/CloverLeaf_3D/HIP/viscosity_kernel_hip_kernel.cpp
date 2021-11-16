//
// auto-generated by ops.py
//
__constant__ int dims_viscosity_kernel [12][2];
static int dims_viscosity_kernel_h [12][2] = {{0}};

//user function
__device__

void viscosity_kernel_gpu(const ACC<double> &xvel0,
  const ACC<double> &yvel0,
  const ACC<double> &celldx,
  const ACC<double> &celldy,
  const ACC<double> &pressure,
  const ACC<double> &density0,
  ACC<double> &viscosity,
  const ACC<double> &zvel0,
  const ACC<double> &celldz,
  const ACC<double> &xarea,
  const ACC<double> &yarea,
  const ACC<double> &zarea) {

  double grad2,
         pgradx,pgrady,pgradz,
         pgradx2,pgrady2,pgradz2,
         grad,
         ygrad, xgrad, zgrad,
         div,
         limiter,
         pgrad;

  double ugradx1=xvel0(0,0,0)+xvel0(0,1,0)+xvel0(0,0,1)+xvel0(0,1,1);
  double ugradx2=xvel0(1,0,0)+xvel0(1,1,0)+xvel0(1,0,1)+xvel0(1,1,1);
  double ugrady1=xvel0(0,0,0)+xvel0(1,0,0)+xvel0(0,0,1)+xvel0(1,0,1);
  double ugrady2=xvel0(0,1,0)+xvel0(1,1,0)+xvel0(0,1,1)+xvel0(1,1,1);
  double ugradz1=xvel0(0,0,0)+xvel0(1,0,0)+xvel0(0,1,0)+xvel0(1,1,0);
  double ugradz2=xvel0(0,0,1)+xvel0(1,0,1)+xvel0(0,1,1)+xvel0(1,1,1);

  double vgradx1=yvel0(0,0,0)+yvel0(0,1,0)+yvel0(0,0,1)+yvel0(0,1,1);
  double vgradx2=yvel0(1,0,0)+yvel0(1,1,0)+yvel0(1,0,1)+yvel0(1,1,1);
  double vgrady1=yvel0(0,0,0)+yvel0(1,0,0)+yvel0(0,0,1)+yvel0(1,0,1);
  double vgrady2=yvel0(0,1,0)+yvel0(1,1,0)+yvel0(0,1,1)+yvel0(1,1,1);
  double vgradz1=yvel0(0,0,0)+yvel0(1,0,0)+yvel0(0,1,0)+yvel0(1,1,0);
  double vgradz2=yvel0(0,0,1)+yvel0(1,0,1)+yvel0(0,1,1)+yvel0(1,1,1);

  double wgradx1=zvel0(0,0,0)+zvel0(0,1,0)+zvel0(0,0,1)+zvel0(0,1,1);
  double wgradx2=zvel0(1,0,0)+zvel0(1,1,0)+zvel0(1,0,1)+zvel0(1,1,1);
  double wgrady1=zvel0(0,0,0)+zvel0(1,0,0)+zvel0(0,0,1)+zvel0(1,0,1);
  double wgrady2=zvel0(0,1,0)+zvel0(1,1,0)+zvel0(0,1,1)+zvel0(1,1,1);
  double wgradz1=zvel0(0,0,0)+zvel0(1,0,0)+zvel0(0,1,0)+zvel0(1,1,0);
  double wgradz2=zvel0(0,0,1)+zvel0(1,0,1)+zvel0(0,1,1)+zvel0(1,1,1);

  div = xarea(0,0,0)*(ugradx2-ugradx1) + yarea(0,0,0)*(vgrady2-vgrady1) + zarea(0,0,0)*(wgradz2-wgradz1);

  double xx = 0.25*(ugradx2-ugradx1)/(celldx(0,0,0));
  double yy = 0.25*(vgrady2-vgrady1)/(celldy(0,0,0));
  double zz = 0.25*(wgradz2-wgradz1)/(celldz(0,0,0));
  double xy = 0.25*(ugrady2-ugrady1)/(celldy(0,0,0))+0.25*(vgradx2-vgradx1)/(celldx(0,0,0));
  double xz = 0.25*(ugradz2-ugradz1)/(celldz(0,0,0))+0.25*(wgradx2-wgradx1)/(celldx(0,0,0));
  double yz = 0.25*(vgradz2-vgradz1)/(celldz(0,0,0))+0.25*(wgrady2-wgrady1)/(celldy(0,0,0));


  pgradx = (pressure(1,0,0) - pressure(-1,0,0))/(celldx(0,0,0)+ celldx(1,0,0));
  pgrady = (pressure(0,1,0) - pressure(0,-1,0))/(celldy(0,0,0)+ celldy(0,1,0));
  pgradz = (pressure(0,0,1) - pressure(0,0,-1))/(celldz(0,0,0)+ celldz(0,0,1));

  pgradx2 = pgradx * pgradx;
  pgrady2 = pgrady * pgrady;
  pgradz2 = pgradz * pgradz;
  limiter = (xx*pgradx2+yy*pgrady2+zz*pgradz2
          +  xy*pgradx*pgrady+xz*pgradx*pgradz+yz*pgrady*pgradz)
                / MAX(pgradx2+pgrady2+pgradz2,1.0e-16);

  if( (limiter > 0.0) || (div >= 0.0)) {
        viscosity(0,0,0) = 0.0;
  }
  else {
    pgradx = SIGN( MAX(1.0e-16, fabs(pgradx)), pgradx);
    pgrady = SIGN( MAX(1.0e-16, fabs(pgrady)), pgrady);
    pgradz = SIGN( MAX(1.0e-16, fabs(pgradz)), pgradz);
    pgrad = sqrt(pgradx*pgradx + pgrady*pgrady + pgradz*pgradz);
    xgrad = fabs(celldx(0,0,0) * pgrad/pgradx);
    ygrad = fabs(celldy(0,0,0) * pgrad/pgrady);
    zgrad = fabs(celldz(0,0,0) * pgrad/pgradz);
    grad  = MIN(xgrad,MIN(ygrad,zgrad));
    grad2 = grad*grad;

    viscosity(0,0,0) = 2.0 * (density0(0,0,0)) * grad2 * limiter * limiter;
  }
}



__global__ void ops_viscosity_kernel(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
double* __restrict arg6,
double* __restrict arg7,
double* __restrict arg8,
double* __restrict arg9,
double* __restrict arg10,
double* __restrict arg11,
int size0,
int size1,
int size2 ){

  //Make sure constants are not optimized out
  if (size0==-1) dims_viscosity_kernel[0][0]=0;


  int idx_z =hipBlockDim_z* hipBlockIdx_z + hipThreadIdx_z;
  int idx_y = hipBlockDim_y *  hipBlockIdx_y + hipThreadIdx_y;
  int idx_x = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[0][0] + idx_z * 1*1 * dims_viscosity_kernel[0][0] * dims_viscosity_kernel[0][1];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[1][0] + idx_z * 1*1 * dims_viscosity_kernel[1][0] * dims_viscosity_kernel[1][1];
  arg2 += idx_x * 1*1 + idx_y * 0*1 * dims_viscosity_kernel[2][0] + idx_z * 0*1 * dims_viscosity_kernel[2][0] * dims_viscosity_kernel[2][1];
  arg3 += idx_x * 0*1 + idx_y * 1*1 * dims_viscosity_kernel[3][0] + idx_z * 0*1 * dims_viscosity_kernel[3][0] * dims_viscosity_kernel[3][1];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[4][0] + idx_z * 1*1 * dims_viscosity_kernel[4][0] * dims_viscosity_kernel[4][1];
  arg5 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[5][0] + idx_z * 1*1 * dims_viscosity_kernel[5][0] * dims_viscosity_kernel[5][1];
  arg6 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[6][0] + idx_z * 1*1 * dims_viscosity_kernel[6][0] * dims_viscosity_kernel[6][1];
  arg7 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[7][0] + idx_z * 1*1 * dims_viscosity_kernel[7][0] * dims_viscosity_kernel[7][1];
  arg8 += idx_x * 0*1 + idx_y * 0*1 * dims_viscosity_kernel[8][0] + idx_z * 1*1 * dims_viscosity_kernel[8][0] * dims_viscosity_kernel[8][1];
  arg9 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[9][0] + idx_z * 1*1 * dims_viscosity_kernel[9][0] * dims_viscosity_kernel[9][1];
  arg10 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[10][0] + idx_z * 1*1 * dims_viscosity_kernel[10][0] * dims_viscosity_kernel[10][1];
  arg11 += idx_x * 1*1 + idx_y * 1*1 * dims_viscosity_kernel[11][0] + idx_z * 1*1 * dims_viscosity_kernel[11][0] * dims_viscosity_kernel[11][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ACC<double> argp0(dims_viscosity_kernel[0][0], dims_viscosity_kernel[0][1], arg0);
    const ACC<double> argp1(dims_viscosity_kernel[1][0], dims_viscosity_kernel[1][1], arg1);
    const ACC<double> argp2(dims_viscosity_kernel[2][0], dims_viscosity_kernel[2][1], arg2);
    const ACC<double> argp3(dims_viscosity_kernel[3][0], dims_viscosity_kernel[3][1], arg3);
    const ACC<double> argp4(dims_viscosity_kernel[4][0], dims_viscosity_kernel[4][1], arg4);
    const ACC<double> argp5(dims_viscosity_kernel[5][0], dims_viscosity_kernel[5][1], arg5);
    ACC<double> argp6(dims_viscosity_kernel[6][0], dims_viscosity_kernel[6][1], arg6);
    const ACC<double> argp7(dims_viscosity_kernel[7][0], dims_viscosity_kernel[7][1], arg7);
    const ACC<double> argp8(dims_viscosity_kernel[8][0], dims_viscosity_kernel[8][1], arg8);
    const ACC<double> argp9(dims_viscosity_kernel[9][0], dims_viscosity_kernel[9][1], arg9);
    const ACC<double> argp10(dims_viscosity_kernel[10][0], dims_viscosity_kernel[10][1], arg10);
    const ACC<double> argp11(dims_viscosity_kernel[11][0], dims_viscosity_kernel[11][1], arg11);
    viscosity_kernel_gpu(argp0, argp1, argp2, argp3,
                   argp4, argp5, argp6, argp7, argp8,
                   argp9, argp10, argp11);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_viscosity_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8,
 ops_arg arg9, ops_arg arg10, ops_arg arg11) {
#else
void ops_par_loop_viscosity_kernel_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  ops_arg arg8 = desc->args[8];
  ops_arg arg9 = desc->args[9];
  ops_arg arg10 = desc->args[10];
  ops_arg arg11 = desc->args[11];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[12] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,12,range,97)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,97,"viscosity_kernel");
    block->instance->OPS_kernels[97].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  #ifdef OPS_MPI
  int arg_idx[3];
  #endif
  #ifdef OPS_MPI
  if (compute_ranges(args, 12,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];
  int xdim7 = args[7].dat->size[0];
  int ydim7 = args[7].dat->size[1];
  int xdim8 = args[8].dat->size[0];
  int ydim8 = args[8].dat->size[1];
  int xdim9 = args[9].dat->size[0];
  int ydim9 = args[9].dat->size[1];
  int xdim10 = args[10].dat->size[0];
  int ydim10 = args[10].dat->size[1];
  int xdim11 = args[11].dat->size[0];
  int ydim11 = args[11].dat->size[1];

  if (xdim0 != dims_viscosity_kernel_h[0][0] || ydim0 != dims_viscosity_kernel_h[0][1] || xdim1 != dims_viscosity_kernel_h[1][0] || ydim1 != dims_viscosity_kernel_h[1][1] || xdim2 != dims_viscosity_kernel_h[2][0] || ydim2 != dims_viscosity_kernel_h[2][1] || xdim3 != dims_viscosity_kernel_h[3][0] || ydim3 != dims_viscosity_kernel_h[3][1] || xdim4 != dims_viscosity_kernel_h[4][0] || ydim4 != dims_viscosity_kernel_h[4][1] || xdim5 != dims_viscosity_kernel_h[5][0] || ydim5 != dims_viscosity_kernel_h[5][1] || xdim6 != dims_viscosity_kernel_h[6][0] || ydim6 != dims_viscosity_kernel_h[6][1] || xdim7 != dims_viscosity_kernel_h[7][0] || ydim7 != dims_viscosity_kernel_h[7][1] || xdim8 != dims_viscosity_kernel_h[8][0] || ydim8 != dims_viscosity_kernel_h[8][1] || xdim9 != dims_viscosity_kernel_h[9][0] || ydim9 != dims_viscosity_kernel_h[9][1] || xdim10 != dims_viscosity_kernel_h[10][0] || ydim10 != dims_viscosity_kernel_h[10][1] || xdim11 != dims_viscosity_kernel_h[11][0] || ydim11 != dims_viscosity_kernel_h[11][1]) {
    dims_viscosity_kernel_h[0][0] = xdim0;
    dims_viscosity_kernel_h[0][1] = ydim0;
    dims_viscosity_kernel_h[1][0] = xdim1;
    dims_viscosity_kernel_h[1][1] = ydim1;
    dims_viscosity_kernel_h[2][0] = xdim2;
    dims_viscosity_kernel_h[2][1] = ydim2;
    dims_viscosity_kernel_h[3][0] = xdim3;
    dims_viscosity_kernel_h[3][1] = ydim3;
    dims_viscosity_kernel_h[4][0] = xdim4;
    dims_viscosity_kernel_h[4][1] = ydim4;
    dims_viscosity_kernel_h[5][0] = xdim5;
    dims_viscosity_kernel_h[5][1] = ydim5;
    dims_viscosity_kernel_h[6][0] = xdim6;
    dims_viscosity_kernel_h[6][1] = ydim6;
    dims_viscosity_kernel_h[7][0] = xdim7;
    dims_viscosity_kernel_h[7][1] = ydim7;
    dims_viscosity_kernel_h[8][0] = xdim8;
    dims_viscosity_kernel_h[8][1] = ydim8;
    dims_viscosity_kernel_h[9][0] = xdim9;
    dims_viscosity_kernel_h[9][1] = ydim9;
    dims_viscosity_kernel_h[10][0] = xdim10;
    dims_viscosity_kernel_h[10][1] = ydim10;
    dims_viscosity_kernel_h[11][0] = xdim11;
    dims_viscosity_kernel_h[11][1] = ydim11;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol(HIP_SYMBOL(dims_viscosity_kernel), dims_viscosity_kernel_h, sizeof(dims_viscosity_kernel)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, (z_size-1)/block->instance->OPS_block_size_z +1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  long long int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  long long int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  long long int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  long long int dat5 = (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  long long int dat6 = (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);
  long long int dat7 = (block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size);
  long long int dat8 = (block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size);
  long long int dat9 = (block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size);
  long long int dat10 = (block->instance->OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size);
  long long int dat11 = (block->instance->OPS_soa ? args[11].dat->type_size : args[11].dat->elem_size);

  char *p_a[12];

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2]);
  p_a[0] = (char *)args[0].data_d + base0;

  long long int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  long long int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2]);
  p_a[2] = (char *)args[2].data_d + base2;

  long long int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    (start[2] * args[3].stencil->stride[2]);
  p_a[3] = (char *)args[3].data_d + base3;

  long long int base4 = args[4].dat->base_offset + 
           dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    (start[2] * args[4].stencil->stride[2]);
  p_a[4] = (char *)args[4].data_d + base4;

  long long int base5 = args[5].dat->base_offset + 
           dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    (start[2] * args[5].stencil->stride[2]);
  p_a[5] = (char *)args[5].data_d + base5;

  long long int base6 = args[6].dat->base_offset + 
           dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    (start[2] * args[6].stencil->stride[2]);
  p_a[6] = (char *)args[6].data_d + base6;

  long long int base7 = args[7].dat->base_offset + 
           dat7 * 1 * (start[0] * args[7].stencil->stride[0]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    (start[1] * args[7].stencil->stride[1]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    args[7].dat->size[1] *
    (start[2] * args[7].stencil->stride[2]);
  p_a[7] = (char *)args[7].data_d + base7;

  long long int base8 = args[8].dat->base_offset + 
           dat8 * 1 * (start[0] * args[8].stencil->stride[0]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    (start[1] * args[8].stencil->stride[1]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    args[8].dat->size[1] *
    (start[2] * args[8].stencil->stride[2]);
  p_a[8] = (char *)args[8].data_d + base8;

  long long int base9 = args[9].dat->base_offset + 
           dat9 * 1 * (start[0] * args[9].stencil->stride[0]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    (start[1] * args[9].stencil->stride[1]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    args[9].dat->size[1] *
    (start[2] * args[9].stencil->stride[2]);
  p_a[9] = (char *)args[9].data_d + base9;

  long long int base10 = args[10].dat->base_offset + 
           dat10 * 1 * (start[0] * args[10].stencil->stride[0]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    (start[1] * args[10].stencil->stride[1]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    args[10].dat->size[1] *
    (start[2] * args[10].stencil->stride[2]);
  p_a[10] = (char *)args[10].data_d + base10;

  long long int base11 = args[11].dat->base_offset + 
           dat11 * 1 * (start[0] * args[11].stencil->stride[0]);
  base11 = base11+ dat11 *
    args[11].dat->size[0] *
    (start[1] * args[11].stencil->stride[1]);
  base11 = base11+ dat11 *
    args[11].dat->size[0] *
    args[11].dat->size[1] *
    (start[2] * args[11].stencil->stride[2]);
  p_a[11] = (char *)args[11].data_d + base11;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 12);
  ops_halo_exchanges(args,12,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[97].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    hipLaunchKernelGGL(ops_viscosity_kernel,grid ,tblock ,0 ,0 , (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],
         (double *)p_a[6], (double *)p_a[7],
         (double *)p_a[8], (double *)p_a[9],
         (double *)p_a[10], (double *)p_a[11],x_size, y_size, z_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[97].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 12);
  ops_set_halo_dirtybit3(&args[6],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[97].mpi_time += t2-t1;
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg9);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg10);
    block->instance->OPS_kernels[97].transfer += ops_compute_transfer(dim, start, end, &arg11);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_viscosity_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 97;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 97;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 12;
  desc->args = (ops_arg*)malloc(12*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg7.dat->index;
  desc->args[8] = arg8;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg8.dat->index;
  desc->args[9] = arg9;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg9.dat->index;
  desc->args[10] = arg10;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg10.dat->index;
  desc->args[11] = arg11;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg11.dat->index;
  desc->function = ops_par_loop_viscosity_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,97,"viscosity_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
