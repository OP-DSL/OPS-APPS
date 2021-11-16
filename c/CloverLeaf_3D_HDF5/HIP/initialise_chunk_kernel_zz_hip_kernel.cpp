//
// auto-generated by ops.py
//
__constant__ int dims_initialise_chunk_kernel_zz [2][2];
static int dims_initialise_chunk_kernel_zz_h [2][2] = {{0}};

//user function
__device__

void initialise_chunk_kernel_zz_gpu(ACC<int> &zz,
  int *idx) {
  zz(0,0,0) = idx[2]-2;
}



__global__ void ops_initialise_chunk_kernel_zz(
int* __restrict arg0,
int arg_idx0, int arg_idx1, int arg_idx2,
int size0,
int size1,
int size2 ){

  //Make sure constants are not optimized out
  if (size0==-1) dims_initialise_chunk_kernel_zz[0][0]=0;


  int idx_z =hipBlockDim_z* hipBlockIdx_z + hipThreadIdx_z;
  int idx_y = hipBlockDim_y *  hipBlockIdx_y + hipThreadIdx_y;
  int idx_x = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;

  int arg_idx[3];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg_idx[2] = arg_idx2+idx_z;
  arg0 += idx_x * 0*1 + idx_y * 0*1 * dims_initialise_chunk_kernel_zz[0][0] + idx_z * 1*1 * dims_initialise_chunk_kernel_zz[0][0] * dims_initialise_chunk_kernel_zz[0][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ACC<int> argp0(dims_initialise_chunk_kernel_zz[0][0], dims_initialise_chunk_kernel_zz[0][1], arg0);
    initialise_chunk_kernel_zz_gpu(argp0, arg_idx);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zz(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
#else
void ops_par_loop_initialise_chunk_kernel_zz_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[2] = { arg0, arg1};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,2,range,2)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,2,"initialise_chunk_kernel_zz");
    block->instance->OPS_kernels[2].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[3];
  #ifdef OPS_MPI
  if (compute_ranges(args, 2,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];

  if (xdim0 != dims_initialise_chunk_kernel_zz_h[0][0] || ydim0 != dims_initialise_chunk_kernel_zz_h[0][1]) {
    dims_initialise_chunk_kernel_zz_h[0][0] = xdim0;
    dims_initialise_chunk_kernel_zz_h[0][1] = ydim0;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol(HIP_SYMBOL(dims_initialise_chunk_kernel_zz), dims_initialise_chunk_kernel_zz_h, sizeof(dims_initialise_chunk_kernel_zz)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, (z_size-1)/block->instance->OPS_block_size_z +1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

  char *p_a[2];

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


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 2);
  ops_halo_exchanges(args,2,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[2].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    hipLaunchKernelGGL(ops_initialise_chunk_kernel_zz,grid ,tblock ,0 ,0 , (int *)p_a[0], arg_idx[0], arg_idx[1], arg_idx[2],x_size, y_size, z_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[2].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 2);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[2].mpi_time += t2-t1;
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zz(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 2;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 2;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 2;
  desc->args = (ops_arg*)malloc(2*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->function = ops_par_loop_initialise_chunk_kernel_zz_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,2,"initialise_chunk_kernel_zz");
  }
  ops_enqueue_kernel(desc);
}
#endif
