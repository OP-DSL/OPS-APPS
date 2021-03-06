//
// auto-generated by ops.py
//
__constant__ int dims_preprocessY [11][1];
static int dims_preprocessY_h [11][1] = {{0}};

//user function
__device__

void preprocessY_gpu(const ACC<double> &u,
  const ACC<double> &v,
  const double *time,
  ACC<double> &a,
  ACC<double> &b,
  ACC<double> &c,
  ACC<double> &du,
  ACC<double> &dv,
  ACC<double> resU,
  ACC<double> resV,
  int *idx) {
    resU(0, 0) = 0;
    resV(0, 0) = 0;
    if (idx[0] == 0 || idx[0] == nx - 1 || idx[1] == 0 || idx[1] == ny - 1) {
        a(0, 0) = 0;
        b(0, 0) = 1;
        c(0, 0) = 0;
        du(0, 0) =
            0.75 -
            1 / (4 * (1 + exp((-4 * idx[0] * h + 4 * idx[1] * h - (*time)) *
                              Re / 32)));
        dv(0, 0) =
            0.75 +
            1 / (4 * (1 + exp((-4 * idx[0] * h + 4 * idx[1] * h - (*time)) *
                              Re / 32)));
    } else {
        a(0, 0) = -r1 * v(0, 0) - r2;
        b(0, 0) = 1 + 2 * r2;
        c(0, 0) = -r1 * v(0, 0) + r2;
        du(0, 0) = (r1 * u(0, 0) + r2) * u(-1, 0) + (1 - 2 * r2) * u(0, 0) +
                   (-r1 * u(0, 0) + r2) * u(1, 0);
        dv(0, 0) = (r1 * u(0, 0) + r2) * v(-1, 0) + (1 - 2 * r2) * v(0, 0) +
                   (-r1 * u(0, 0) + r2) * v(1, 0);
    }
}



__global__ void ops_preprocessY(
double* __restrict arg0,
double* __restrict arg1,
const double arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
double* __restrict arg6,
double* __restrict arg7,
double* __restrict arg8,
double* __restrict arg9,
int arg_idx0, int arg_idx1,
int size0,
int size1 ){

  //Make sure constants are not optimized out
  if (size0==-1) dims_preprocessY[0][0]=0;


  int idx_y = hipBlockDim_y * hipBlockIdx_y + hipThreadIdx_y;
  int idx_x = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;

  int arg_idx[2];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[0][0];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[1][0];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[3][0];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[4][0];
  arg5 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[5][0];
  arg6 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[6][0];
  arg7 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[7][0];
  arg8 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[8][0];
  arg9 += idx_x * 1*1 + idx_y * 1*1 * dims_preprocessY[9][0];

  if (idx_x < size0 && idx_y < size1) {
    const ACC<double> argp0(dims_preprocessY[0][0], arg0);
    const ACC<double> argp1(dims_preprocessY[1][0], arg1);
    ACC<double> argp3(dims_preprocessY[3][0], arg3);
    ACC<double> argp4(dims_preprocessY[4][0], arg4);
    ACC<double> argp5(dims_preprocessY[5][0], arg5);
    ACC<double> argp6(dims_preprocessY[6][0], arg6);
    ACC<double> argp7(dims_preprocessY[7][0], arg7);
    ACC<double> argp8(dims_preprocessY[8][0], arg8);
    ACC<double> argp9(dims_preprocessY[9][0], arg9);
    preprocessY_gpu(argp0, argp1, &arg2, argp3,
                   argp4, argp5, argp6, argp7, argp8,
                   argp9, arg_idx);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_preprocessY(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8,
 ops_arg arg9, ops_arg arg10) {
#else
void ops_par_loop_preprocessY_execute(ops_kernel_descriptor *desc) {
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
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[11] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,11,range,2)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,2,"preprocessY");
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
  if (compute_ranges(args, 11,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];
  int xdim6 = args[6].dat->size[0];
  int xdim7 = args[7].dat->size[0];
  int xdim8 = args[8].dat->size[0];
  int xdim9 = args[9].dat->size[0];

  if (xdim0 != dims_preprocessY_h[0][0] || xdim1 != dims_preprocessY_h[1][0] || xdim3 != dims_preprocessY_h[3][0] || xdim4 != dims_preprocessY_h[4][0] || xdim5 != dims_preprocessY_h[5][0] || xdim6 != dims_preprocessY_h[6][0] || xdim7 != dims_preprocessY_h[7][0] || xdim8 != dims_preprocessY_h[8][0] || xdim9 != dims_preprocessY_h[9][0]) {
    dims_preprocessY_h[0][0] = xdim0;
    dims_preprocessY_h[1][0] = xdim1;
    dims_preprocessY_h[3][0] = xdim3;
    dims_preprocessY_h[4][0] = xdim4;
    dims_preprocessY_h[5][0] = xdim5;
    dims_preprocessY_h[6][0] = xdim6;
    dims_preprocessY_h[7][0] = xdim7;
    dims_preprocessY_h[8][0] = xdim8;
    dims_preprocessY_h[9][0] = xdim9;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol(HIP_SYMBOL(dims_preprocessY), dims_preprocessY_h, sizeof(dims_preprocessY)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, 1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  long long int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  long long int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  long long int dat5 = (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  long long int dat6 = (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);
  long long int dat7 = (block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size);
  long long int dat8 = (block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size);
  long long int dat9 = (block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size);

  char *p_a[11];

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

  long long int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  p_a[3] = (char *)args[3].data_d + base3;

  long long int base4 = args[4].dat->base_offset + 
           dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1]);
  p_a[4] = (char *)args[4].data_d + base4;

  long long int base5 = args[5].dat->base_offset + 
           dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1]);
  p_a[5] = (char *)args[5].data_d + base5;

  long long int base6 = args[6].dat->base_offset + 
           dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1]);
  p_a[6] = (char *)args[6].data_d + base6;

  long long int base7 = args[7].dat->base_offset + 
           dat7 * 1 * (start[0] * args[7].stencil->stride[0]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    (start[1] * args[7].stencil->stride[1]);
  p_a[7] = (char *)args[7].data_d + base7;

  long long int base8 = args[8].dat->base_offset + 
           dat8 * 1 * (start[0] * args[8].stencil->stride[0]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    (start[1] * args[8].stencil->stride[1]);
  p_a[8] = (char *)args[8].data_d + base8;

  long long int base9 = args[9].dat->base_offset + 
           dat9 * 1 * (start[0] * args[9].stencil->stride[0]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    (start[1] * args[9].stencil->stride[1]);
  p_a[9] = (char *)args[9].data_d + base9;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 11);
  ops_halo_exchanges(args,11,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[2].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    hipLaunchKernelGGL(ops_preprocessY,grid ,tblock ,0 ,0 , (double *)p_a[0], (double *)p_a[1],
         *(double *)arg2.data, (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],
         (double *)p_a[6], (double *)p_a[7],
         (double *)p_a[8], (double *)p_a[9],
         arg_idx[0], arg_idx[1],x_size, y_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[2].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 11);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[9],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[2].mpi_time += t2-t1;
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg9);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_preprocessY(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10) {
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
  desc->nargs = 11;
  desc->args = (ops_arg*)malloc(11*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  char *tmp = (char*)malloc(1*sizeof(double));
  memcpy(tmp, arg2.data,1*sizeof(double));
  desc->args[2].data = tmp;
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
  desc->function = ops_par_loop_preprocessY_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,2,"preprocessY");
  }
  ops_enqueue_kernel(desc);
}
#endif
