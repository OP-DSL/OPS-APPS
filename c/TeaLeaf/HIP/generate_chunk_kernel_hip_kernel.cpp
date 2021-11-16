//
// auto-generated by ops.py
//
__constant__ int dims_generate_chunk_kernel [7][1];
static int dims_generate_chunk_kernel_h [7][1] = {{0}};

//user function
__device__

void generate_chunk_kernel_gpu(const ACC<double> &vertexx,
  const ACC<double> &vertexy,
  ACC<double> &energy0,
  ACC<double> &density0,
  ACC<double> &u0,
  const ACC<double> &cellx,
  const ACC<double> &celly) {

  double radius, x_cent, y_cent;
  int is_in = 0;
  int is_in2 = 0;


  energy0(0,0)= states[0].energy;
  density0(0,0)= states[0].density;

  for(int i = 1; i<number_of_states; i++) {

    x_cent=states[i].xmin;
    y_cent=states[i].ymin;
    is_in = 0;
    is_in2 = 0;

    if (states[i].geometry == g_rect) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          if(vertexx(1+i1,0) >= states[i].xmin  && vertexx(0+i1,0) < states[i].xmax) {
            if(vertexy(0,1+j1) >= states[i].ymin && vertexy(0,0+j1) < states[i].ymax) {
              is_in = 1;
            }
          }
        }
      }
      if(vertexx(1,0) >= states[i].xmin  && vertexx(0,0) < states[i].xmax) {
        if(vertexy(0,1) >= states[i].ymin && vertexy(0,0) < states[i].ymax) {
          is_in2 = 1;
        }
      }
      if (is_in2) {
        energy0(0,0) = states[i].energy;
        density0(0,0) = states[i].density;
      }
    }
    else if(states[i].geometry == g_circ) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          radius = sqrt ((cellx(i1,0) - x_cent) * (cellx(i1,0) - x_cent) +
                     (celly(0,j1) - y_cent) * (celly(0,j1) - y_cent));
          if (radius <= states[i].radius) {
            is_in = 1;
          }
        }
      }
      if (radius <= states[i].radius) is_in2 = 1;

      if (is_in2) {
        energy0(0,0) = states[i].energy;
        density0(0,0) = states[i].density;
      }
    }
    else if(states[i].geometry == g_point) {
      if(vertexx(0,0) == x_cent && vertexy(0,0) == y_cent) {
        energy0(0,0) = states[i].energy;
        density0(0,0) = states[i].density;
      }
    }
  }
  u0(0,0) = energy0(0,0) * density0(0,0);
}



__global__ void ops_generate_chunk_kernel(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
double* __restrict arg6,
int size0,
int size1 ){

  //Make sure constants are not optimized out
  if (size0==-1) dims_generate_chunk_kernel[0][0]=0;


  int idx_y = hipBlockDim_y * hipBlockIdx_y + hipThreadIdx_y;
  int idx_x = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;

  arg0 += idx_x * 1*1 + idx_y * 0*1 * dims_generate_chunk_kernel[0][0];
  arg1 += idx_x * 0*1 + idx_y * 1*1 * dims_generate_chunk_kernel[1][0];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_generate_chunk_kernel[2][0];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_generate_chunk_kernel[3][0];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_generate_chunk_kernel[4][0];
  arg5 += idx_x * 1*1 + idx_y * 0*1 * dims_generate_chunk_kernel[5][0];
  arg6 += idx_x * 0*1 + idx_y * 1*1 * dims_generate_chunk_kernel[6][0];

  if (idx_x < size0 && idx_y < size1) {
    const ACC<double> argp0(dims_generate_chunk_kernel[0][0], arg0);
    const ACC<double> argp1(dims_generate_chunk_kernel[1][0], arg1);
    ACC<double> argp2(dims_generate_chunk_kernel[2][0], arg2);
    ACC<double> argp3(dims_generate_chunk_kernel[3][0], arg3);
    ACC<double> argp4(dims_generate_chunk_kernel[4][0], arg4);
    const ACC<double> argp5(dims_generate_chunk_kernel[5][0], arg5);
    const ACC<double> argp6(dims_generate_chunk_kernel[6][0], arg6);
    generate_chunk_kernel_gpu(argp0, argp1, argp2, argp3,
                   argp4, argp5, argp6);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_generate_chunk_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {
#else
void ops_par_loop_generate_chunk_kernel_execute(ops_kernel_descriptor *desc) {
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
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[7] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,7,range,1)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,1,"generate_chunk_kernel");
    block->instance->OPS_kernels[1].count++;
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
  if (compute_ranges(args, 7,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];
  int xdim6 = args[6].dat->size[0];

  if (xdim0 != dims_generate_chunk_kernel_h[0][0] || xdim1 != dims_generate_chunk_kernel_h[1][0] || xdim2 != dims_generate_chunk_kernel_h[2][0] || xdim3 != dims_generate_chunk_kernel_h[3][0] || xdim4 != dims_generate_chunk_kernel_h[4][0] || xdim5 != dims_generate_chunk_kernel_h[5][0] || xdim6 != dims_generate_chunk_kernel_h[6][0]) {
    dims_generate_chunk_kernel_h[0][0] = xdim0;
    dims_generate_chunk_kernel_h[1][0] = xdim1;
    dims_generate_chunk_kernel_h[2][0] = xdim2;
    dims_generate_chunk_kernel_h[3][0] = xdim3;
    dims_generate_chunk_kernel_h[4][0] = xdim4;
    dims_generate_chunk_kernel_h[5][0] = xdim5;
    dims_generate_chunk_kernel_h[6][0] = xdim6;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol(HIP_SYMBOL(dims_generate_chunk_kernel), dims_generate_chunk_kernel_h, sizeof(dims_generate_chunk_kernel)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, 1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  long long int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  long long int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  long long int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  long long int dat5 = (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  long long int dat6 = (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);

  char *p_a[7];

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


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 7);
  ops_halo_exchanges(args,7,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[1].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    hipLaunchKernelGGL(ops_generate_chunk_kernel,grid ,tblock ,0 ,0 , (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],
         (double *)p_a[6],x_size, y_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[1].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 7);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[1].mpi_time += t2-t1;
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_generate_chunk_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 1;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 1;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 7;
  desc->args = (ops_arg*)malloc(7*sizeof(ops_arg));
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
  desc->function = ops_par_loop_generate_chunk_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,1,"generate_chunk_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
