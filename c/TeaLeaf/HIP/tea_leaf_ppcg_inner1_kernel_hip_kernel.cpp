//
// auto-generated by ops.py
//
__constant__ int dims_tea_leaf_ppcg_inner1_kernel [6][1];
static int dims_tea_leaf_ppcg_inner1_kernel_h [6][1] = {{0}};

//user function
__device__

void tea_leaf_ppcg_inner1_kernel_gpu(ACC<double> &rtemp,
  const ACC<double> &Kx,
  const ACC<double> &Ky,
  const ACC<double> &sd,
  const double *rx,
  const double *ry) {
	double smvp = 0.0;
  smvp = (1.0
    + (*ry)*(Ky(0, 1) + Ky(0,0))
    + (*rx)*(Kx(1, 0) + Kx(0,0)))*sd(0,0)
    - (*ry)*(Ky(0, 1) *sd(0, 1) + Ky(0,0)*sd(0, -1))
    - (*rx)*(Kx(1, 0) *sd(1, 0) + Kx(0,0)*sd(-1, 0));
  rtemp(0,0) = rtemp(0,0) - smvp;
}



__global__ void ops_tea_leaf_ppcg_inner1_kernel(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
const double arg4,
const double arg5,
int size0,
int size1 ){

  //Make sure constants are not optimized out
  if (size0==-1) dims_tea_leaf_ppcg_inner1_kernel[0][0]=0;


  int idx_y = hipBlockDim_y * hipBlockIdx_y + hipThreadIdx_y;
  int idx_x = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_tea_leaf_ppcg_inner1_kernel[0][0];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_tea_leaf_ppcg_inner1_kernel[1][0];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_tea_leaf_ppcg_inner1_kernel[2][0];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_tea_leaf_ppcg_inner1_kernel[3][0];

  if (idx_x < size0 && idx_y < size1) {
    ACC<double> argp0(dims_tea_leaf_ppcg_inner1_kernel[0][0], arg0);
    const ACC<double> argp1(dims_tea_leaf_ppcg_inner1_kernel[1][0], arg1);
    const ACC<double> argp2(dims_tea_leaf_ppcg_inner1_kernel[2][0], arg2);
    const ACC<double> argp3(dims_tea_leaf_ppcg_inner1_kernel[3][0], arg3);
    tea_leaf_ppcg_inner1_kernel_gpu(argp0, argp1, argp2, argp3,
                   &arg4, &arg5);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_tea_leaf_ppcg_inner1_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_tea_leaf_ppcg_inner1_kernel_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,6,range,46)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,46,"tea_leaf_ppcg_inner1_kernel");
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
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];

  if (xdim0 != dims_tea_leaf_ppcg_inner1_kernel_h[0][0] || xdim1 != dims_tea_leaf_ppcg_inner1_kernel_h[1][0] || xdim2 != dims_tea_leaf_ppcg_inner1_kernel_h[2][0] || xdim3 != dims_tea_leaf_ppcg_inner1_kernel_h[3][0]) {
    dims_tea_leaf_ppcg_inner1_kernel_h[0][0] = xdim0;
    dims_tea_leaf_ppcg_inner1_kernel_h[1][0] = xdim1;
    dims_tea_leaf_ppcg_inner1_kernel_h[2][0] = xdim2;
    dims_tea_leaf_ppcg_inner1_kernel_h[3][0] = xdim3;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol(HIP_SYMBOL(dims_tea_leaf_ppcg_inner1_kernel), dims_tea_leaf_ppcg_inner1_kernel_h, sizeof(dims_tea_leaf_ppcg_inner1_kernel)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, 1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  long long int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  long long int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);

  char *p_a[6];

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

  long long int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  p_a[2] = (char *)args[2].data_d + base2;

  long long int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  p_a[3] = (char *)args[3].data_d + base3;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 6);
  ops_halo_exchanges(args,6,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[46].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    hipLaunchKernelGGL(ops_tea_leaf_ppcg_inner1_kernel,grid ,tblock ,0 ,0 , (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         *(double *)arg4.data, *(double *)arg5.data,x_size, y_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[46].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 6);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[46].mpi_time += t2-t1;
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_tea_leaf_ppcg_inner1_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {
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
  desc->nargs = 6;
  desc->args = (ops_arg*)malloc(6*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  char *tmp = (char*)malloc(1*sizeof(double));
  memcpy(tmp, arg4.data,1*sizeof(double));
  desc->args[4].data = tmp;
  desc->args[5] = arg5;
  tmp = (char*)malloc(1*sizeof(double));
  memcpy(tmp, arg5.data,1*sizeof(double));
  desc->args[5].data = tmp;
  desc->function = ops_par_loop_tea_leaf_ppcg_inner1_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,46,"tea_leaf_ppcg_inner1_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
