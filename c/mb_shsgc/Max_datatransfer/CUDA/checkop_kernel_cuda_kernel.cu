//
// auto-generated by ops.py
//
__constant__ int dims_checkop_kernel [6][1];
static int dims_checkop_kernel_h [6][1] = {0};

//user function
__device__

void checkop_kernel_gpu(const ACC<double> &rho_new,
  const ACC<double> &x,
  const ACC<double> &rhoin,
  double *pre,
  double *post,
  int *num) {
  double diff;
  diff = (rho_new(0) - rhoin(0));
  if(fabs(diff)<0.01 && x(0) > -4.1){
    *post = *post + diff*diff;
    *num = *num + 1;

  }
  else
    *pre = *pre + (rho_new(0) - rhol)* (rho_new(0) - rhol);
}



__global__ void ops_checkop_kernel(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
int* __restrict arg5,
int size0 ){

  double arg3_l[1];
  double arg4_l[1];
  int arg5_l[1];
  for (int d=0; d<1; d++) arg3_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg4_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg5_l[d] = ZERO_int;

  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1;
  arg1 += idx_x * 1*1;
  arg2 += idx_x * 1*1;

  if (idx_x < size0) {
    const ACC<double> argp0(arg0);
    const ACC<double> argp1(arg1);
    const ACC<double> argp2(arg2);
    checkop_kernel_gpu(argp0, argp1, argp2, arg3_l,
                   arg4_l, arg5_l);
  }
  for (int d=0; d<1; d++)
    ops_reduction_cuda<OPS_INC>(&arg3[d+(blockIdx.x + blockIdx.y*gridDim.x)*1],arg3_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_cuda<OPS_INC>(&arg4[d+(blockIdx.x + blockIdx.y*gridDim.x)*1],arg4_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_cuda<OPS_INC>(&arg5[d+(blockIdx.x + blockIdx.y*gridDim.x)*1],arg5_l[d]);

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_checkop_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_checkop_kernel_execute(ops_kernel_descriptor *desc) {
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
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,6,range,14)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,14,"checkop_kernel");
    block->instance->OPS_kernels[14].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[1];
  int end[1];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  #ifdef OPS_MPI
  int arg_idx[1];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];

  if (xdim0 != dims_checkop_kernel_h[0][0] || xdim1 != dims_checkop_kernel_h[1][0] || xdim2 != dims_checkop_kernel_h[2][0]) {
    dims_checkop_kernel_h[0][0] = xdim0;
    dims_checkop_kernel_h[1][0] = xdim1;
    dims_checkop_kernel_h[2][0] = xdim2;
    cutilSafeCall(block->instance->ostream(), cudaMemcpyToSymbol( dims_checkop_kernel, dims_checkop_kernel_h, sizeof(dims_checkop_kernel)));
  }


  #if defined(OPS_LAZY) && !defined(OPS_MPI)
  ops_block block = desc->block;
  #endif
  #ifdef OPS_MPI
  double *arg3h = (double *)(((ops_reduction)args[3].data)->data + ((ops_reduction)args[3].data)->size * block->index);
  #else
  double *arg3h = (double *)(((ops_reduction)args[3].data)->data);
  #endif
  #ifdef OPS_MPI
  double *arg4h = (double *)(((ops_reduction)args[4].data)->data + ((ops_reduction)args[4].data)->size * block->index);
  #else
  double *arg4h = (double *)(((ops_reduction)args[4].data)->data);
  #endif
  #ifdef OPS_MPI
  int *arg5h = (int *)(((ops_reduction)args[5].data)->data + ((ops_reduction)args[5].data)->size * block->index);
  #else
  int *arg5h = (int *)(((ops_reduction)args[5].data)->data);
  #endif

  int x_size = MAX(0,end[0]-start[0]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, 1, 1);
  dim3 tblock(block->instance->OPS_block_size_x,1,1);

  int nblocks = ((x_size-1)/block->instance->OPS_block_size_x+ 1);
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  size_t reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(int));
  reduct_size = MAX(reduct_size,sizeof(int)*1);

  reallocReductArrays(block->instance,reduct_bytes);
  reduct_bytes = 0;

  arg3.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg3.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg3.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg4.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg4.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg4.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg5.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg5.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((int *)arg5.data)[d+b*1] = ZERO_int;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(int));


  mvReductArraysToDevice(block->instance,reduct_bytes);
  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  long long int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);

  char *p_a[6];

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  p_a[0] = (char *)args[0].data_d + base0;

  long long int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  p_a[1] = (char *)args[1].data_d + base1;

  long long int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  p_a[2] = (char *)args[2].data_d + base2;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 6);
  ops_halo_exchanges(args,6,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[14].mpi_time += t2-t1;
  }

  size_t nshared = 0;
  int nthread = block->instance->OPS_block_size_x*block->instance->OPS_block_size_y*block->instance->OPS_block_size_z;

  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(int)*1);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0)
    ops_checkop_kernel<<<grid, tblock, nshared >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)arg3.data_d,
         (double *)arg4.data_d, (int *)arg5.data_d,x_size);

  cutilSafeCall(block->instance->ostream(), cudaGetLastError());

  mvReductArraysToHost(block->instance,reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg3h[d] = arg3h[d] + ((double *)arg3.data)[d+b*1];
    }
  }
  arg3.data = (char *)arg3h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg4h[d] = arg4h[d] + ((double *)arg4.data)[d+b*1];
    }
  }
  arg4.data = (char *)arg4h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg5h[d] = arg5h[d] + ((int *)arg5.data)[d+b*1];
    }
  }
  arg5.data = (char *)arg5h;

  if (block->instance->OPS_diags>1) {
    cutilSafeCall(block->instance->ostream(), cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[14].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 6);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[14].mpi_time += t2-t1;
    block->instance->OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_checkop_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 14;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 14;
  for ( int i=0; i<2; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 6;
  desc->args = (ops_arg*)ops_malloc(6*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->args[4] = arg4;
  desc->args[5] = arg5;
  desc->function = ops_par_loop_checkop_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,14,"checkop_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
