//
// auto-generated by ops.py
//
__constant__ int dims_field_summary_kernel [12][2];
static int dims_field_summary_kernel_h [12][2] = {{0}};

//user function
__device__

void field_summary_kernel_gpu(const ACC<double> &volume,
  const ACC<double> &density0,
  const ACC<double> &energy0,
  const ACC<double> &pressure,
  const ACC<double> &xvel0,
  const ACC<double> &yvel0,
  const ACC<double> &zvel0,
  double *vol,
  double *mass,
  double *ie,
  double *ke,
  double *press) {

  double vsqrd, cell_vol, cell_mass;

  vsqrd = 0.0;
  vsqrd+=0.125*( xvel0(0,0,0) * xvel0(0,0,0) +
                 yvel0(0,0,0) * yvel0(0,0,0) +
                 zvel0(0,0,0) * zvel0(0,0,0));
  vsqrd+=0.125*( xvel0(1,0,0) * xvel0(1,0,0) +
                 yvel0(1,0,0) * yvel0(1,0,0) +
                 zvel0(1,0,0) * zvel0(1,0,0));
  vsqrd+=0.125*( xvel0(0,1,0) * xvel0(0,1,0) +
                 yvel0(0,1,0) * yvel0(0,1,0) +
                 zvel0(0,1,0) * zvel0(0,1,0));
  vsqrd+=0.125*( xvel0(1,1,0) * xvel0(1,1,0) +
                 yvel0(1,1,0) * yvel0(1,1,0) +
                 zvel0(1,1,0) * zvel0(1,1,0));
  vsqrd+=0.125*( xvel0(0,0,1) * xvel0(0,0,1) +
                 yvel0(0,0,1) * yvel0(0,0,1) +
                 zvel0(0,0,1) * zvel0(0,0,1));
  vsqrd+=0.125*( xvel0(1,0,1) * xvel0(1,0,1) +
                 yvel0(1,0,1) * yvel0(1,0,1) +
                 zvel0(1,0,1) * zvel0(1,0,1));
  vsqrd+=0.125*( xvel0(0,1,1) * xvel0(0,1,1) +
                 yvel0(0,1,1) * yvel0(0,1,1) +
                 zvel0(0,1,1) * zvel0(0,1,1));
  vsqrd+=0.125*( xvel0(1,1,1) * xvel0(1,1,1) +
                 yvel0(1,1,1) * yvel0(1,1,1) +
                 zvel0(1,1,1) * zvel0(1,1,1));

  cell_vol = volume(0,0,0);
  cell_mass = cell_vol * density0(0,0,0);
  *vol = *vol + cell_vol;
  *mass = *mass + cell_mass;
  *ie = *ie + cell_mass * energy0(0,0,0);
  *ke = *ke + cell_mass * 0.5 * vsqrd;
  *press = *press + cell_vol * pressure(0,0,0);

}



__global__ void ops_field_summary_kernel(
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
  if (size0==-1) dims_field_summary_kernel[0][0]=0;

  double arg7_l[1];
  double arg8_l[1];
  double arg9_l[1];
  double arg10_l[1];
  double arg11_l[1];
  for (int d=0; d<1; d++) arg7_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg8_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg9_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg10_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg11_l[d] = ZERO_double;

  int idx_z =hipBlockDim_z* hipBlockIdx_z + hipThreadIdx_z;
  int idx_y = hipBlockDim_y *  hipBlockIdx_y + hipThreadIdx_y;
  int idx_x = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_field_summary_kernel[0][0] + idx_z * 1*1 * dims_field_summary_kernel[0][0] * dims_field_summary_kernel[0][1];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_field_summary_kernel[1][0] + idx_z * 1*1 * dims_field_summary_kernel[1][0] * dims_field_summary_kernel[1][1];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_field_summary_kernel[2][0] + idx_z * 1*1 * dims_field_summary_kernel[2][0] * dims_field_summary_kernel[2][1];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_field_summary_kernel[3][0] + idx_z * 1*1 * dims_field_summary_kernel[3][0] * dims_field_summary_kernel[3][1];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_field_summary_kernel[4][0] + idx_z * 1*1 * dims_field_summary_kernel[4][0] * dims_field_summary_kernel[4][1];
  arg5 += idx_x * 1*1 + idx_y * 1*1 * dims_field_summary_kernel[5][0] + idx_z * 1*1 * dims_field_summary_kernel[5][0] * dims_field_summary_kernel[5][1];
  arg6 += idx_x * 1*1 + idx_y * 1*1 * dims_field_summary_kernel[6][0] + idx_z * 1*1 * dims_field_summary_kernel[6][0] * dims_field_summary_kernel[6][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ACC<double> argp0(dims_field_summary_kernel[0][0], dims_field_summary_kernel[0][1], arg0);
    const ACC<double> argp1(dims_field_summary_kernel[1][0], dims_field_summary_kernel[1][1], arg1);
    const ACC<double> argp2(dims_field_summary_kernel[2][0], dims_field_summary_kernel[2][1], arg2);
    const ACC<double> argp3(dims_field_summary_kernel[3][0], dims_field_summary_kernel[3][1], arg3);
    const ACC<double> argp4(dims_field_summary_kernel[4][0], dims_field_summary_kernel[4][1], arg4);
    const ACC<double> argp5(dims_field_summary_kernel[5][0], dims_field_summary_kernel[5][1], arg5);
    const ACC<double> argp6(dims_field_summary_kernel[6][0], dims_field_summary_kernel[6][1], arg6);
    field_summary_kernel_gpu(argp0, argp1, argp2, argp3,
                   argp4, argp5, argp6, arg7_l, arg8_l,
                   arg9_l, arg10_l, arg11_l);
  }
  for (int d=0; d<1; d++)
    ops_reduction_hip<OPS_INC>(&arg7[d+(hipBlockIdx_x + hipBlockIdx_y*hipGridDim_x + hipBlockIdx_z*hipGridDim_x*hipGridDim_y)*1],arg7_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_hip<OPS_INC>(&arg8[d+(hipBlockIdx_x + hipBlockIdx_y*hipGridDim_x + hipBlockIdx_z*hipGridDim_x*hipGridDim_y)*1],arg8_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_hip<OPS_INC>(&arg9[d+(hipBlockIdx_x + hipBlockIdx_y*hipGridDim_x + hipBlockIdx_z*hipGridDim_x*hipGridDim_y)*1],arg9_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_hip<OPS_INC>(&arg10[d+(hipBlockIdx_x + hipBlockIdx_y*hipGridDim_x + hipBlockIdx_z*hipGridDim_x*hipGridDim_y)*1],arg10_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_hip<OPS_INC>(&arg11[d+(hipBlockIdx_x + hipBlockIdx_y*hipGridDim_x + hipBlockIdx_z*hipGridDim_x*hipGridDim_y)*1],arg11_l[d]);

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_field_summary_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8,
 ops_arg arg9, ops_arg arg10, ops_arg arg11) {
#else
void ops_par_loop_field_summary_kernel_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,12,range,95)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,95,"field_summary_kernel");
    block->instance->OPS_kernels[95].count++;
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

  if (xdim0 != dims_field_summary_kernel_h[0][0] || ydim0 != dims_field_summary_kernel_h[0][1] || xdim1 != dims_field_summary_kernel_h[1][0] || ydim1 != dims_field_summary_kernel_h[1][1] || xdim2 != dims_field_summary_kernel_h[2][0] || ydim2 != dims_field_summary_kernel_h[2][1] || xdim3 != dims_field_summary_kernel_h[3][0] || ydim3 != dims_field_summary_kernel_h[3][1] || xdim4 != dims_field_summary_kernel_h[4][0] || ydim4 != dims_field_summary_kernel_h[4][1] || xdim5 != dims_field_summary_kernel_h[5][0] || ydim5 != dims_field_summary_kernel_h[5][1] || xdim6 != dims_field_summary_kernel_h[6][0] || ydim6 != dims_field_summary_kernel_h[6][1]) {
    dims_field_summary_kernel_h[0][0] = xdim0;
    dims_field_summary_kernel_h[0][1] = ydim0;
    dims_field_summary_kernel_h[1][0] = xdim1;
    dims_field_summary_kernel_h[1][1] = ydim1;
    dims_field_summary_kernel_h[2][0] = xdim2;
    dims_field_summary_kernel_h[2][1] = ydim2;
    dims_field_summary_kernel_h[3][0] = xdim3;
    dims_field_summary_kernel_h[3][1] = ydim3;
    dims_field_summary_kernel_h[4][0] = xdim4;
    dims_field_summary_kernel_h[4][1] = ydim4;
    dims_field_summary_kernel_h[5][0] = xdim5;
    dims_field_summary_kernel_h[5][1] = ydim5;
    dims_field_summary_kernel_h[6][0] = xdim6;
    dims_field_summary_kernel_h[6][1] = ydim6;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol(HIP_SYMBOL(dims_field_summary_kernel), dims_field_summary_kernel_h, sizeof(dims_field_summary_kernel)));
  }


  #if defined(OPS_LAZY) && !defined(OPS_MPI)
  ops_block block = desc->block;
  #endif
  #ifdef OPS_MPI
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data + ((ops_reduction)args[7].data)->size * block->index);
  #else
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data);
  #endif
  #ifdef OPS_MPI
  double *arg8h = (double *)(((ops_reduction)args[8].data)->data + ((ops_reduction)args[8].data)->size * block->index);
  #else
  double *arg8h = (double *)(((ops_reduction)args[8].data)->data);
  #endif
  #ifdef OPS_MPI
  double *arg9h = (double *)(((ops_reduction)args[9].data)->data + ((ops_reduction)args[9].data)->size * block->index);
  #else
  double *arg9h = (double *)(((ops_reduction)args[9].data)->data);
  #endif
  #ifdef OPS_MPI
  double *arg10h = (double *)(((ops_reduction)args[10].data)->data + ((ops_reduction)args[10].data)->size * block->index);
  #else
  double *arg10h = (double *)(((ops_reduction)args[10].data)->data);
  #endif
  #ifdef OPS_MPI
  double *arg11h = (double *)(((ops_reduction)args[11].data)->data + ((ops_reduction)args[11].data)->size * block->index);
  #else
  double *arg11h = (double *)(((ops_reduction)args[11].data)->data);
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, (z_size-1)/block->instance->OPS_block_size_z +1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);

  int nblocks = ((x_size-1)/block->instance->OPS_block_size_x+ 1)*((y_size-1)/block->instance->OPS_block_size_y + 1)*((z_size-1)/block->instance->OPS_block_size_z +1);
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  size_t reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);

  reallocReductArrays(block->instance,reduct_bytes);
  reduct_bytes = 0;

  arg7.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg7.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg7.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg8.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg8.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg8.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg9.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg9.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg9.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg10.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg10.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg10.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg11.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg11.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg11.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));


  mvReductArraysToDevice(block->instance,reduct_bytes);
  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  long long int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  long long int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  long long int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  long long int dat5 = (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  long long int dat6 = (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);

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


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 12);
  ops_halo_exchanges(args,12,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[95].mpi_time += t2-t1;
  }

  size_t nshared = 0;
  int nthread = block->instance->OPS_block_size_x*block->instance->OPS_block_size_y*block->instance->OPS_block_size_z;

  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    hipLaunchKernelGGL(ops_field_summary_kernel,grid ,tblock ,nshared ,0 , (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],
         (double *)p_a[6], (double *)arg7.data_d,
         (double *)arg8.data_d, (double *)arg9.data_d,
         (double *)arg10.data_d, (double *)arg11.data_d,x_size, y_size, z_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  mvReductArraysToHost(block->instance,reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg7h[d] = arg7h[d] + ((double *)arg7.data)[d+b*1];
    }
  }
  arg7.data = (char *)arg7h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg8h[d] = arg8h[d] + ((double *)arg8.data)[d+b*1];
    }
  }
  arg8.data = (char *)arg8h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg9h[d] = arg9h[d] + ((double *)arg9.data)[d+b*1];
    }
  }
  arg9.data = (char *)arg9h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg10h[d] = arg10h[d] + ((double *)arg10.data)[d+b*1];
    }
  }
  arg10.data = (char *)arg10h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg11h[d] = arg11h[d] + ((double *)arg11.data)[d+b*1];
    }
  }
  arg11.data = (char *)arg11h;

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[95].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 12);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[95].mpi_time += t2-t1;
    block->instance->OPS_kernels[95].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[95].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[95].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[95].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[95].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[95].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[95].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_field_summary_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 95;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 95;
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
  desc->args[8] = arg8;
  desc->args[9] = arg9;
  desc->args[10] = arg10;
  desc->args[11] = arg11;
  desc->function = ops_par_loop_field_summary_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,95,"field_summary_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
