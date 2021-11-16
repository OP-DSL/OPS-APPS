//
// auto-generated by ops.py
//
__constant__ int dims_update_halo_kernel4_plus_2_a [3][1];
static int dims_update_halo_kernel4_plus_2_a_h [3][1] = {{0}};

//user function
__device__

inline void update_halo_kernel4_plus_2_a_gpu(ACC<double> &vol_flux_y,
  ACC<double> &mass_flux_y,
  const int* fields) {
  if(fields[FIELD_VOL_FLUX_Y] == 1) vol_flux_y(0,0) = vol_flux_y(2,0);
  if(fields[FIELD_MASS_FLUX_Y] == 1) mass_flux_y(0,0) = mass_flux_y(2,0);
}



__global__ void ops_update_halo_kernel4_plus_2_a(
double* __restrict arg0,
double* __restrict arg1,
const int* __restrict arg2,
int size0,
int size1 ){

  //Make sure constants are not optimized out
  if (size0==-1) dims_update_halo_kernel4_plus_2_a[0][0]=0;


  int idx_y = hipBlockDim_y * hipBlockIdx_y + hipThreadIdx_y;
  int idx_x = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_update_halo_kernel4_plus_2_a[0][0];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_update_halo_kernel4_plus_2_a[1][0];

  if (idx_x < size0 && idx_y < size1) {
    ACC<double> argp0(dims_update_halo_kernel4_plus_2_a[0][0], arg0);
    ACC<double> argp1(dims_update_halo_kernel4_plus_2_a[1][0], arg1);
    update_halo_kernel4_plus_2_a_gpu(argp0, argp1, arg2);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_update_halo_kernel4_plus_2_a(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
#else
void ops_par_loop_update_halo_kernel4_plus_2_a_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,3,range,46)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,46,"update_halo_kernel4_plus_2_a");
    block->instance->OPS_kernels[46].count++;
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
  #ifdef OPS_MPI
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];

  if (xdim0 != dims_update_halo_kernel4_plus_2_a_h[0][0] || xdim1 != dims_update_halo_kernel4_plus_2_a_h[1][0]) {
    dims_update_halo_kernel4_plus_2_a_h[0][0] = xdim0;
    dims_update_halo_kernel4_plus_2_a_h[1][0] = xdim1;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol(HIP_SYMBOL(dims_update_halo_kernel4_plus_2_a), dims_update_halo_kernel4_plus_2_a_h, sizeof(dims_update_halo_kernel4_plus_2_a)));
  }


  int *arg2h = (int *)arg2.data;

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, 1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);

  int consts_bytes = 0;

  consts_bytes += ROUND_UP(NUM_FIELDS*sizeof(int));

  reallocConstArrays(block->instance,consts_bytes);

  consts_bytes = 0;
  arg2.data = block->instance->OPS_consts_h + consts_bytes;
  arg2.data_d = block->instance->OPS_consts_d + consts_bytes;
  for (int d=0; d<NUM_FIELDS; d++) ((int *)arg2.data)[d] = arg2h[d];
  consts_bytes += ROUND_UP(NUM_FIELDS*sizeof(int));
  mvConstArraysToDevice(block->instance,consts_bytes);
  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);

  char *p_a[3];

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
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
    block->instance->OPS_kernels[46].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    hipLaunchKernelGGL(ops_update_halo_kernel4_plus_2_a,grid ,tblock ,0 ,0 , (double *)p_a[0], (double *)p_a[1],
         (int *)arg2.data_d,x_size, y_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[46].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 3);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[46].mpi_time += t2-t1;
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_update_halo_kernel4_plus_2_a(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 46;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 46;
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
  char *tmp = (char*)malloc(NUM_FIELDS*sizeof(int));
  memcpy(tmp, arg2.data,NUM_FIELDS*sizeof(int));
  desc->args[2].data = tmp;
  desc->function = ops_par_loop_update_halo_kernel4_plus_2_a_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,46,"update_halo_kernel4_plus_2_a");
  }
  ops_enqueue_kernel(desc);
}
#endif