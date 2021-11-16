//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim3_poisson_kernel_populate;
int xdim3_poisson_kernel_populate_h = -1;
extern int xdim4_poisson_kernel_populate;
int xdim4_poisson_kernel_populate_h = -1;
extern int xdim5_poisson_kernel_populate;
int xdim5_poisson_kernel_populate_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void poisson_kernel_populate_c_wrapper(
  int p_a0,
  int p_a1,
  int *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_poisson_kernel_populate(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,6,range,0)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,0,"poisson_kernel_populate");
    block->instance->OPS_kernels[0].count++;
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
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  for ( int n=0; n<2; n++ ){
    arg_idx_base[n] = arg_idx[n];
  }

  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;


  //set up initial pointers
  int *p_a0 = (int *)args[0].data;
  int *p_a1 = (int *)args[1].data;
  int *p_a2 = NULL;

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

  long long int base5 = args[5].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) * start[0] * args[5].stencil->stride[0];
  base5 = base5 + (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    start[1] * args[5].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data_d + base5);
  #else
  double *p_a5 = (double *)((char *)args[5].data + base5);
  #endif


  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  //initialize global variable with the dimension of dats
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];
  if (xdim3 != xdim3_poisson_kernel_populate_h || xdim4 != xdim4_poisson_kernel_populate_h || xdim5 != xdim5_poisson_kernel_populate_h) {
    xdim3_poisson_kernel_populate = xdim3;
    xdim3_poisson_kernel_populate_h = xdim3;
    xdim4_poisson_kernel_populate = xdim4;
    xdim4_poisson_kernel_populate_h = xdim4;
    xdim5_poisson_kernel_populate = xdim5;
    xdim5_poisson_kernel_populate_h = xdim5;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 6);
  #else
  ops_H_D_exchanges_host(args, 6);
  #endif
  ops_halo_exchanges(args,6,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 6);
  #else
  ops_H_D_exchanges_host(args, 6);
  #endif
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[0].mpi_time += t2-t1;
  }

  poisson_kernel_populate_c_wrapper(
    *p_a0,
    *p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    arg_idx[0], arg_idx[1],
    x_size, y_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[0].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 6);
  #else
  ops_set_dirtybit_host(args, 6);
  #endif
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[0].mpi_time += t2-t1;
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg5);
  }
}
