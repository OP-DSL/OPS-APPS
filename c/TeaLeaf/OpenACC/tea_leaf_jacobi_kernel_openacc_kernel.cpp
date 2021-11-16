//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_tea_leaf_jacobi_kernel;
int xdim0_tea_leaf_jacobi_kernel_h = -1;
extern int xdim1_tea_leaf_jacobi_kernel;
int xdim1_tea_leaf_jacobi_kernel_h = -1;
extern int xdim2_tea_leaf_jacobi_kernel;
int xdim2_tea_leaf_jacobi_kernel_h = -1;
extern int xdim3_tea_leaf_jacobi_kernel;
int xdim3_tea_leaf_jacobi_kernel_h = -1;
extern int xdim4_tea_leaf_jacobi_kernel;
int xdim4_tea_leaf_jacobi_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void tea_leaf_jacobi_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double p_a5,
  double p_a6,
  double *p_a7,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_tea_leaf_jacobi_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,8,range,42)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,42,"tea_leaf_jacobi_kernel");
    block->instance->OPS_kernels[42].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block

  int start[2];
  int end[2];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[2];
  int arg_idx_base[2];
  #ifdef OPS_MPI
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  for ( int n=0; n<2; n++ ){
    arg_idx_base[n] = arg_idx[n];
  }

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;

  #ifdef OPS_MPI
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data + ((ops_reduction)args[7].data)->size * block->index);
  #else
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data);
  #endif

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  long long int base2 = args[2].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  long long int base3 = args[3].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  long long int base4 = args[4].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4 + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif

  double *p_a5 = (double *)args[5].data;
  double *p_a6 = (double *)args[6].data;
  double *p_a7 = arg7h;

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  //initialize global variable with the dimension of dats
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  if (xdim0 != xdim0_tea_leaf_jacobi_kernel_h || xdim1 != xdim1_tea_leaf_jacobi_kernel_h || xdim2 != xdim2_tea_leaf_jacobi_kernel_h || xdim3 != xdim3_tea_leaf_jacobi_kernel_h || xdim4 != xdim4_tea_leaf_jacobi_kernel_h) {
    xdim0_tea_leaf_jacobi_kernel = xdim0;
    xdim0_tea_leaf_jacobi_kernel_h = xdim0;
    xdim1_tea_leaf_jacobi_kernel = xdim1;
    xdim1_tea_leaf_jacobi_kernel_h = xdim1;
    xdim2_tea_leaf_jacobi_kernel = xdim2;
    xdim2_tea_leaf_jacobi_kernel_h = xdim2;
    xdim3_tea_leaf_jacobi_kernel = xdim3;
    xdim3_tea_leaf_jacobi_kernel_h = xdim3;
    xdim4_tea_leaf_jacobi_kernel = xdim4;
    xdim4_tea_leaf_jacobi_kernel_h = xdim4;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 8);
  #else
  ops_H_D_exchanges_host(args, 8);
  #endif
  ops_halo_exchanges(args,8,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 8);
  #else
  ops_H_D_exchanges_host(args, 8);
  #endif
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[42].mpi_time += t2-t1;
  }

  tea_leaf_jacobi_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    *p_a5,
    *p_a6,
    p_a7,
    x_size, y_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[42].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 8);
  #else
  ops_set_dirtybit_host(args, 8);
  #endif
  ops_set_halo_dirtybit3(&args[0],range);

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[42].mpi_time += t2-t1;
    block->instance->OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
