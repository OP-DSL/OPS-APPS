//
// auto-generated by ops.py
//
__constant__ int dims_flux_calc_kernely [4][2];
static int dims_flux_calc_kernely_h [4][2] = {0};

//user function
__device__

void flux_calc_kernely_gpu(ACC<double> &vol_flux_y,
  const ACC<double> &yarea,
  const ACC<double> &yvel0,
  const ACC<double> &yvel1) {

  vol_flux_y(0,0,0) = 0.125 * dt * (yarea(0,0,0)) *
  ( yvel0(0,0,0) + yvel0(1,0,0) + yvel0(0,0,1) + yvel0(1,0,1) +
    yvel1(0,0,0) + yvel1(1,0,0) + yvel1(0,0,1) + yvel1(1,0,1));
}



__global__ void ops_flux_calc_kernely(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_flux_calc_kernely[0][0] + idx_z * 1*1 * dims_flux_calc_kernely[0][0] * dims_flux_calc_kernely[0][1];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_flux_calc_kernely[1][0] + idx_z * 1*1 * dims_flux_calc_kernely[1][0] * dims_flux_calc_kernely[1][1];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_flux_calc_kernely[2][0] + idx_z * 1*1 * dims_flux_calc_kernely[2][0] * dims_flux_calc_kernely[2][1];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_flux_calc_kernely[3][0] + idx_z * 1*1 * dims_flux_calc_kernely[3][0] * dims_flux_calc_kernely[3][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ACC<double> argp0(dims_flux_calc_kernely[0][0], dims_flux_calc_kernely[0][1], arg0);
    const ACC<double> argp1(dims_flux_calc_kernely[1][0], dims_flux_calc_kernely[1][1], arg1);
    const ACC<double> argp2(dims_flux_calc_kernely[2][0], dims_flux_calc_kernely[2][1], arg2);
    const ACC<double> argp3(dims_flux_calc_kernely[3][0], dims_flux_calc_kernely[3][1], arg3);
    flux_calc_kernely_gpu(argp0, argp1, argp2, argp3);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_flux_calc_kernely(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
#else
void ops_par_loop_flux_calc_kernely_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[4] = { arg0, arg1, arg2, arg3};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,4,range,106)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,106,"flux_calc_kernely");
    block->instance->OPS_kernels[106].count++;
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
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 4,block, range, start, end, arg_idx) < 0) return;
  #endif

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];

  if (xdim0 != dims_flux_calc_kernely_h[0][0] || ydim0 != dims_flux_calc_kernely_h[0][1] || xdim1 != dims_flux_calc_kernely_h[1][0] || ydim1 != dims_flux_calc_kernely_h[1][1] || xdim2 != dims_flux_calc_kernely_h[2][0] || ydim2 != dims_flux_calc_kernely_h[2][1] || xdim3 != dims_flux_calc_kernely_h[3][0] || ydim3 != dims_flux_calc_kernely_h[3][1]) {
    dims_flux_calc_kernely_h[0][0] = xdim0;
    dims_flux_calc_kernely_h[0][1] = ydim0;
    dims_flux_calc_kernely_h[1][0] = xdim1;
    dims_flux_calc_kernely_h[1][1] = ydim1;
    dims_flux_calc_kernely_h[2][0] = xdim2;
    dims_flux_calc_kernely_h[2][1] = ydim2;
    dims_flux_calc_kernely_h[3][0] = xdim3;
    dims_flux_calc_kernely_h[3][1] = ydim3;
    cutilSafeCall(block->instance->ostream(), cudaMemcpyToSymbol( dims_flux_calc_kernely, dims_flux_calc_kernely_h, sizeof(dims_flux_calc_kernely)));
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

  char *p_a[4];

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


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 4);
  ops_halo_exchanges(args,4,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[106].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_flux_calc_kernely<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],x_size, y_size, z_size);

  cutilSafeCall(block->instance->ostream(), cudaGetLastError());

  if (block->instance->OPS_diags>1) {
    cutilSafeCall(block->instance->ostream(), cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[106].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 4);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[106].mpi_time += t2-t1;
    block->instance->OPS_kernels[106].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[106].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[106].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[106].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_flux_calc_kernely(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 106;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 106;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 4;
  desc->args = (ops_arg*)ops_malloc(4*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->function = ops_par_loop_flux_calc_kernely_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,106,"flux_calc_kernely");
  }
  ops_enqueue_kernel(desc);
}
#endif
