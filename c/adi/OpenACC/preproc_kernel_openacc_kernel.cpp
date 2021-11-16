//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_preproc_kernel;
int xdim0_preproc_kernel_h = -1;
extern int ydim0_preproc_kernel;
int ydim0_preproc_kernel_h = -1;
extern int xdim1_preproc_kernel;
int xdim1_preproc_kernel_h = -1;
extern int ydim1_preproc_kernel;
int ydim1_preproc_kernel_h = -1;
extern int xdim2_preproc_kernel;
int xdim2_preproc_kernel_h = -1;
extern int ydim2_preproc_kernel;
int ydim2_preproc_kernel_h = -1;
extern int xdim3_preproc_kernel;
int xdim3_preproc_kernel_h = -1;
extern int ydim3_preproc_kernel;
int ydim3_preproc_kernel_h = -1;
extern int xdim4_preproc_kernel;
int xdim4_preproc_kernel_h = -1;
extern int ydim4_preproc_kernel;
int ydim4_preproc_kernel_h = -1;
extern int xdim5_preproc_kernel;
int xdim5_preproc_kernel_h = -1;
extern int ydim5_preproc_kernel;
int ydim5_preproc_kernel_h = -1;
extern int xdim6_preproc_kernel;
int xdim6_preproc_kernel_h = -1;
extern int ydim6_preproc_kernel;
int ydim6_preproc_kernel_h = -1;
extern int xdim7_preproc_kernel;
int xdim7_preproc_kernel_h = -1;
extern int ydim7_preproc_kernel;
int ydim7_preproc_kernel_h = -1;
extern int xdim8_preproc_kernel;
int xdim8_preproc_kernel_h = -1;
extern int ydim8_preproc_kernel;
int ydim8_preproc_kernel_h = -1;
extern int xdim9_preproc_kernel;
int xdim9_preproc_kernel_h = -1;
extern int ydim9_preproc_kernel;
int ydim9_preproc_kernel_h = -1;
extern int xdim10_preproc_kernel;
int xdim10_preproc_kernel_h = -1;
extern int ydim10_preproc_kernel;
int ydim10_preproc_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void preproc_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  int *p_a11,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_preproc_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[12] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,12,range,1)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,1,"preproc_kernel");
    block->instance->OPS_kernels[1].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block

  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[3];
  int arg_idx_base[3];
  #ifdef OPS_MPI
  if (compute_ranges(args, 12,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  for ( int n=0; n<3; n++ ){
    arg_idx_base[n] = arg_idx[n];
  }

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;
  int dat7 = args[7].dat->elem_size;
  int dat8 = args[8].dat->elem_size;
  int dat9 = args[9].dat->elem_size;
  int dat10 = args[10].dat->elem_size;


  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0 + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1 + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  long long int base2 = args[2].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2 + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  long long int base3 = args[3].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3 + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  long long int base4 = args[4].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4 + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4 + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif

  long long int base5 = args[5].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) * start[0] * args[5].stencil->stride[0];
  base5 = base5 + (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    start[1] * args[5].stencil->stride[1];
  base5 = base5 + (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    start[2] * args[5].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data_d + base5);
  #else
  double *p_a5 = (double *)((char *)args[5].data + base5);
  #endif

  long long int base6 = args[6].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) * start[0] * args[6].stencil->stride[0];
  base6 = base6 + (long long int)(block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
    args[6].dat->size[0] *
    start[1] * args[6].stencil->stride[1];
  base6 = base6 + (long long int)(block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    start[2] * args[6].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a6 = (double *)((char *)args[6].data_d + base6);
  #else
  double *p_a6 = (double *)((char *)args[6].data + base6);
  #endif

  long long int base7 = args[7].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) * start[0] * args[7].stencil->stride[0];
  base7 = base7 + (long long int)(block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
    args[7].dat->size[0] *
    start[1] * args[7].stencil->stride[1];
  base7 = base7 + (long long int)(block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
    args[7].dat->size[0] *
    args[7].dat->size[1] *
    start[2] * args[7].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a7 = (double *)((char *)args[7].data_d + base7);
  #else
  double *p_a7 = (double *)((char *)args[7].data + base7);
  #endif

  long long int base8 = args[8].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) * start[0] * args[8].stencil->stride[0];
  base8 = base8 + (long long int)(block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) *
    args[8].dat->size[0] *
    start[1] * args[8].stencil->stride[1];
  base8 = base8 + (long long int)(block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) *
    args[8].dat->size[0] *
    args[8].dat->size[1] *
    start[2] * args[8].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a8 = (double *)((char *)args[8].data_d + base8);
  #else
  double *p_a8 = (double *)((char *)args[8].data + base8);
  #endif

  long long int base9 = args[9].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) * start[0] * args[9].stencil->stride[0];
  base9 = base9 + (long long int)(block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) *
    args[9].dat->size[0] *
    start[1] * args[9].stencil->stride[1];
  base9 = base9 + (long long int)(block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) *
    args[9].dat->size[0] *
    args[9].dat->size[1] *
    start[2] * args[9].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a9 = (double *)((char *)args[9].data_d + base9);
  #else
  double *p_a9 = (double *)((char *)args[9].data + base9);
  #endif

  long long int base10 = args[10].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) * start[0] * args[10].stencil->stride[0];
  base10 = base10 + (long long int)(block->instance->OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) *
    args[10].dat->size[0] *
    start[1] * args[10].stencil->stride[1];
  base10 = base10 + (long long int)(block->instance->OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) *
    args[10].dat->size[0] *
    args[10].dat->size[1] *
    start[2] * args[10].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a10 = (double *)((char *)args[10].data_d + base10);
  #else
  double *p_a10 = (double *)((char *)args[10].data + base10);
  #endif

  int *p_a11 = NULL;


  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  //initialize global variable with the dimension of dats
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];
  int xdim7 = args[7].dat->size[0];
  int ydim7 = args[7].dat->size[1];
  int xdim8 = args[8].dat->size[0];
  int ydim8 = args[8].dat->size[1];
  int xdim9 = args[9].dat->size[0];
  int ydim9 = args[9].dat->size[1];
  int xdim10 = args[10].dat->size[0];
  int ydim10 = args[10].dat->size[1];
  if (xdim0 != xdim0_preproc_kernel_h || ydim0 != ydim0_preproc_kernel_h || xdim1 != xdim1_preproc_kernel_h || ydim1 != ydim1_preproc_kernel_h || xdim2 != xdim2_preproc_kernel_h || ydim2 != ydim2_preproc_kernel_h || xdim3 != xdim3_preproc_kernel_h || ydim3 != ydim3_preproc_kernel_h || xdim4 != xdim4_preproc_kernel_h || ydim4 != ydim4_preproc_kernel_h || xdim5 != xdim5_preproc_kernel_h || ydim5 != ydim5_preproc_kernel_h || xdim6 != xdim6_preproc_kernel_h || ydim6 != ydim6_preproc_kernel_h || xdim7 != xdim7_preproc_kernel_h || ydim7 != ydim7_preproc_kernel_h || xdim8 != xdim8_preproc_kernel_h || ydim8 != ydim8_preproc_kernel_h || xdim9 != xdim9_preproc_kernel_h || ydim9 != ydim9_preproc_kernel_h || xdim10 != xdim10_preproc_kernel_h || ydim10 != ydim10_preproc_kernel_h) {
    xdim0_preproc_kernel = xdim0;
    xdim0_preproc_kernel_h = xdim0;
    ydim0_preproc_kernel = ydim0;
    ydim0_preproc_kernel_h = ydim0;
    xdim1_preproc_kernel = xdim1;
    xdim1_preproc_kernel_h = xdim1;
    ydim1_preproc_kernel = ydim1;
    ydim1_preproc_kernel_h = ydim1;
    xdim2_preproc_kernel = xdim2;
    xdim2_preproc_kernel_h = xdim2;
    ydim2_preproc_kernel = ydim2;
    ydim2_preproc_kernel_h = ydim2;
    xdim3_preproc_kernel = xdim3;
    xdim3_preproc_kernel_h = xdim3;
    ydim3_preproc_kernel = ydim3;
    ydim3_preproc_kernel_h = ydim3;
    xdim4_preproc_kernel = xdim4;
    xdim4_preproc_kernel_h = xdim4;
    ydim4_preproc_kernel = ydim4;
    ydim4_preproc_kernel_h = ydim4;
    xdim5_preproc_kernel = xdim5;
    xdim5_preproc_kernel_h = xdim5;
    ydim5_preproc_kernel = ydim5;
    ydim5_preproc_kernel_h = ydim5;
    xdim6_preproc_kernel = xdim6;
    xdim6_preproc_kernel_h = xdim6;
    ydim6_preproc_kernel = ydim6;
    ydim6_preproc_kernel_h = ydim6;
    xdim7_preproc_kernel = xdim7;
    xdim7_preproc_kernel_h = xdim7;
    ydim7_preproc_kernel = ydim7;
    ydim7_preproc_kernel_h = ydim7;
    xdim8_preproc_kernel = xdim8;
    xdim8_preproc_kernel_h = xdim8;
    ydim8_preproc_kernel = ydim8;
    ydim8_preproc_kernel_h = ydim8;
    xdim9_preproc_kernel = xdim9;
    xdim9_preproc_kernel_h = xdim9;
    ydim9_preproc_kernel = ydim9;
    ydim9_preproc_kernel_h = ydim9;
    xdim10_preproc_kernel = xdim10;
    xdim10_preproc_kernel_h = xdim10;
    ydim10_preproc_kernel = ydim10;
    ydim10_preproc_kernel_h = ydim10;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 12);
  #else
  ops_H_D_exchanges_host(args, 12);
  #endif
  ops_halo_exchanges(args,12,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 12);
  #else
  ops_H_D_exchanges_host(args, 12);
  #endif
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[1].mpi_time += t2-t1;
  }

  preproc_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    p_a6,
    p_a7,
    p_a8,
    p_a9,
    p_a10,
    p_a11,
    arg_idx[0], arg_idx[1], arg_idx[2],
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[1].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 12);
  #else
  ops_set_dirtybit_host(args, 12);
  #endif
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[9],range);
  ops_set_halo_dirtybit3(&args[10],range);

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
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg9);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg10);
  }
}
