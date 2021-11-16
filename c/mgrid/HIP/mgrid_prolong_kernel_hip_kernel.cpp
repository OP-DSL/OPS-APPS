//
// auto-generated by ops.py
//
__constant__ int dims_mgrid_prolong_kernel [3][1];
static int dims_mgrid_prolong_kernel_h [3][1] = {{0}};

//user function
__device__

void mgrid_prolong_kernel_gpu(const ACC<double> &coarse,
  ACC<double> &fine,
  int *idx) {
  fine(0,0) = coarse(0,0);
}



__global__ void ops_mgrid_prolong_kernel(
double* __restrict arg0,
int stride_00, int stride_01,
double* __restrict arg1,
int arg_idx0, int arg_idx1,
int global_idx0, int global_idx1,
int size0,
int size1 ){

  //Make sure constants are not optimized out
  if (size0==-1) dims_mgrid_prolong_kernel[0][0]=0;


  int idx_y = hipBlockDim_y * hipBlockIdx_y + hipThreadIdx_y;
  int idx_x = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;

  int arg_idx[2];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg0 += (idx_x+global_idx0%stride_00)/stride_00 * 1*1 + (idx_y+global_idx1%stride_01)/stride_01 * 1*1 * dims_mgrid_prolong_kernel[0][0];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_mgrid_prolong_kernel[1][0];

  if (idx_x < size0 && idx_y < size1) {
    const ACC<double> argp0(dims_mgrid_prolong_kernel[0][0], arg0);
    ACC<double> argp1(dims_mgrid_prolong_kernel[1][0], arg1);
    mgrid_prolong_kernel_gpu(argp0, argp1, arg_idx);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_mgrid_prolong_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
#else
void ops_par_loop_mgrid_prolong_kernel_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,3,range,2)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,2,"mgrid_prolong_kernel");
    block->instance->OPS_kernels[2].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[2];
  #ifdef OPS_MPI
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  int global_idx[2];
  #ifdef OPS_MPI
  global_idx[0] = arg_idx[0];
  global_idx[1] = arg_idx[1];
  #else
  global_idx[0] = start[0];
  global_idx[1] = start[1];
  #endif

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];

  if (xdim0 != dims_mgrid_prolong_kernel_h[0][0] || xdim1 != dims_mgrid_prolong_kernel_h[1][0]) {
    dims_mgrid_prolong_kernel_h[0][0] = xdim0;
    dims_mgrid_prolong_kernel_h[1][0] = xdim1;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol(HIP_SYMBOL(dims_mgrid_prolong_kernel), dims_mgrid_prolong_kernel_h, sizeof(dims_mgrid_prolong_kernel)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, 1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);

  char *p_a[3];
  //This arg has a prolong stencil - so create different ranges
  int start_0[2]; int end_0[2]; int stride_0[2];int d_size_0[2];
  #ifdef OPS_MPI
  for ( int n=0; n<2; n++ ){
    sub_dat *sd0 = OPS_sub_dat_list[args[0].dat->index];
    stride_0[n] = args[0].stencil->mgrid_stride[n];
    d_size_0[n] = args[0].dat->d_m[n] + sd0->decomp_size[n] - args[0].dat->d_p[n];
    start_0[n] = global_idx[n]/stride_0[n] - sd0->decomp_disp[n] + args[0].dat->d_m[n];
    end_0[n] = start_0[n] + d_size_0[n];
  }
  #else
  for ( int n=0; n<2; n++ ){
    stride_0[n] = args[0].stencil->mgrid_stride[n];
    d_size_0[n] = args[0].dat->d_m[n] + args[0].dat->size[n] - args[0].dat->d_p[n];
    start_0[n] = global_idx[n]/stride_0[n];
    end_0[n] = start_0[n] + d_size_0[n];
  }
  #endif

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start_0[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start_0[1] * args[0].stencil->stride[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  long long int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  p_a[1] = (char *)args[1].data_d + base1;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 3);
  ops_halo_exchanges(args,3,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[2].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    hipLaunchKernelGGL(ops_mgrid_prolong_kernel,grid ,tblock ,0 ,0 , (double *)p_a[0],stride_0[0],stride_0[1], (double *)p_a[1],
         arg_idx[0], arg_idx[1],global_idx[0], global_idx[1],x_size, y_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[2].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 3);
  ops_set_halo_dirtybit3(&args[1],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[2].mpi_time += t2-t1;
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_mgrid_prolong_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 2;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 2;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 3;
  desc->args = (ops_arg*)malloc(3*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->function = ops_par_loop_mgrid_prolong_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,2,"mgrid_prolong_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
