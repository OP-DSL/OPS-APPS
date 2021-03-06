//
// auto-generated by ops.py
//
__constant__ int dims_complex_numbers_block0_cn_kernel [3][1];
static int dims_complex_numbers_block0_cn_kernel_h [3][1] = {0};

//user function
__device__

void complex_numbers_block0_cn_kernel_gpu(const ACC<double> &phi,
  double *real,
  double *imaginary)
{
    cuDoubleComplex z = make_cuDoubleComplex(0.0, 1.0);
    cuDoubleComplex coeff = z;

    *real = *real + phi(0);
    coeff = cuCmul(coeff, z);
    *real = *real + cuCreal(coeff)*phi(0);
    *imaginary = *imaginary + cuCimag(coeff)*phi(0);
}



__global__ void ops_complex_numbers_block0_cn_kernel(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
int size0 ){

  double arg1_l[1];
  double arg2_l[1];
  for (int d=0; d<1; d++) arg1_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg2_l[d] = ZERO_double;

  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1;

  if (idx_x < size0) {
    const ACC<double> argp0(arg0);
    complex_numbers_block0_cn_kernel_gpu(argp0, arg1_l, arg2_l);
  }
  for (int d=0; d<1; d++)
    ops_reduction_cuda<OPS_INC>(&arg1[d+(blockIdx.x + blockIdx.y*gridDim.x)*1],arg1_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_cuda<OPS_INC>(&arg2[d+(blockIdx.x + blockIdx.y*gridDim.x)*1],arg2_l[d]);

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_complex_numbers_block0_cn_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
#else
void ops_par_loop_complex_numbers_block0_cn_kernel_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[3] = { arg0, arg1, arg2};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,3,range,6)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,6,"complex_numbers_block0_cn_kernel");
    block->instance->OPS_kernels[6].count++;
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
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
  #endif

  int xdim0 = args[0].dat->size[0];

  if (xdim0 != dims_complex_numbers_block0_cn_kernel_h[0][0]) {
    dims_complex_numbers_block0_cn_kernel_h[0][0] = xdim0;
    cutilSafeCall(block->instance->ostream(), cudaMemcpyToSymbol( dims_complex_numbers_block0_cn_kernel, dims_complex_numbers_block0_cn_kernel_h, sizeof(dims_complex_numbers_block0_cn_kernel)));
  }


  #if defined(OPS_LAZY) && !defined(OPS_MPI)
  ops_block block = desc->block;
  #endif
  #ifdef OPS_MPI
  double *arg1h = (double *)(((ops_reduction)args[1].data)->data + ((ops_reduction)args[1].data)->size * block->index);
  #else
  double *arg1h = (double *)(((ops_reduction)args[1].data)->data);
  #endif
  #ifdef OPS_MPI
  double *arg2h = (double *)(((ops_reduction)args[2].data)->data + ((ops_reduction)args[2].data)->size * block->index);
  #else
  double *arg2h = (double *)(((ops_reduction)args[2].data)->data);
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

  reallocReductArrays(block->instance,reduct_bytes);
  reduct_bytes = 0;

  arg1.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg1.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg1.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg2.data = block->instance->OPS_reduct_h + reduct_bytes;
  arg2.data_d = block->instance->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg2.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));


  mvReductArraysToDevice(block->instance,reduct_bytes);
  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

  char *p_a[3];

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  p_a[0] = (char *)args[0].data_d + base0;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 3);
  ops_halo_exchanges(args,3,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[6].mpi_time += t2-t1;
  }

  size_t nshared = 0;
  int nthread = block->instance->OPS_block_size_x*block->instance->OPS_block_size_y*block->instance->OPS_block_size_z;

  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0)
    ops_complex_numbers_block0_cn_kernel<<<grid, tblock, nshared >>> (  (double *)p_a[0], (double *)arg1.data_d,
         (double *)arg2.data_d,x_size);

  cutilSafeCall(block->instance->ostream(), cudaGetLastError());

  mvReductArraysToHost(block->instance,reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg1h[d] = arg1h[d] + ((double *)arg1.data)[d+b*1];
    }
  }
  arg1.data = (char *)arg1h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg2h[d] = arg2h[d] + ((double *)arg2.data)[d+b*1];
    }
  }
  arg2.data = (char *)arg2h;

  if (block->instance->OPS_diags>1) {
    cutilSafeCall(block->instance->ostream(), cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[6].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 3);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[6].mpi_time += t2-t1;
    block->instance->OPS_kernels[6].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_complex_numbers_block0_cn_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 6;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 6;
  for ( int i=0; i<2; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 3;
  desc->args = (ops_arg*)ops_malloc(3*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->args[2] = arg2;
  desc->function = ops_par_loop_complex_numbers_block0_cn_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,6,"complex_numbers_block0_cn_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
