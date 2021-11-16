//
// auto-generated by ops.py
//
__constant__ int dims_initialise_chunk_kernel_zero_y [1][1];
static int dims_initialise_chunk_kernel_zero_y_h [1][1] = {0};

//user function
__device__

void initialise_chunk_kernel_zero_y_gpu(ACC<double> &var) {
  var(0,0) = 0.0;
}



__global__ void ops_initialise_chunk_kernel_zero_y(
double* __restrict arg0,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 0*1 + idx_y * 1*1 * dims_initialise_chunk_kernel_zero_y[0][0];

  if (idx_x < size0 && idx_y < size1) {
    ACC<double> argp0(dims_initialise_chunk_kernel_zero_y[0][0], arg0);
    initialise_chunk_kernel_zero_y_gpu(argp0);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zero_y(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0) {
#else
void ops_par_loop_initialise_chunk_kernel_zero_y_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[1] = { arg0};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,1,range,7)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"initialise_chunk_kernel_zero_y");
    block->instance->OPS_kernels[7].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  #ifdef OPS_MPI
  int arg_idx[2];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 1,block, range, start, end, arg_idx) < 0) return;
  #endif

  int xdim0 = args[0].dat->size[0];

  if (xdim0 != dims_initialise_chunk_kernel_zero_y_h[0][0]) {
    dims_initialise_chunk_kernel_zero_y_h[0][0] = xdim0;
    cutilSafeCall(block->instance->ostream(), cudaMemcpyToSymbol( dims_initialise_chunk_kernel_zero_y, dims_initialise_chunk_kernel_zero_y_h, sizeof(dims_initialise_chunk_kernel_zero_y)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, 1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

  char *p_a[1];

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  p_a[0] = (char *)args[0].data_d + base0;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 1);
  ops_halo_exchanges(args,1,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[7].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    ops_initialise_chunk_kernel_zero_y<<<grid, tblock >>> (  (double *)p_a[0],x_size, y_size);

  cutilSafeCall(block->instance->ostream(), cudaGetLastError());

  if (block->instance->OPS_diags>1) {
    cutilSafeCall(block->instance->ostream(), cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[7].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 1);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[7].mpi_time += t2-t1;
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zero_y(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 7;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 7;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 1;
  desc->args = (ops_arg*)ops_malloc(1*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->function = ops_par_loop_initialise_chunk_kernel_zero_y_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"initialise_chunk_kernel_zero_y");
  }
  ops_enqueue_kernel(desc);
}
#endif
