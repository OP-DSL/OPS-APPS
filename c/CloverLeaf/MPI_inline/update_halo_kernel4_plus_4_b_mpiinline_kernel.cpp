//
// auto-generated by ops.py
//

extern int xdim0_update_halo_kernel4_plus_4_b;
int xdim0_update_halo_kernel4_plus_4_b_h = -1;
extern int xdim1_update_halo_kernel4_plus_4_b;
int xdim1_update_halo_kernel4_plus_4_b_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void update_halo_kernel4_plus_4_b_c_wrapper(
  double *p_a0,
  double *p_a1,
  int *p_a2,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_update_halo_kernel4_plus_4_b(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  ops_arg args[3] = { arg0, arg1, arg2};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,3,range,47)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,47,"update_halo_kernel4_plus_4_b");
    block->instance->OPS_kernels[47].count++;
  }

  //compute localy allocated range for the sub-block
  int start[2];
  int end[2];
  int arg_idx[2];

  #ifdef OPS_MPI
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
  #else
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];

  //Timing
  double t1,t2,c1,c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
  }

  if (xdim0 != xdim0_update_halo_kernel4_plus_4_b_h || xdim1 != xdim1_update_halo_kernel4_plus_4_b_h) {
    xdim0_update_halo_kernel4_plus_4_b = xdim0;
    xdim0_update_halo_kernel4_plus_4_b_h = xdim0;
    xdim1_update_halo_kernel4_plus_4_b = xdim1;
    xdim1_update_halo_kernel4_plus_4_b_h = xdim1;
  }



  //set up initial pointers and exchange halos if necessary
  long long int base0 = args[0].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0+ (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  double *p_a0 = (double *)(args[0].data + base0);

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1+ (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  double *p_a1 = (double *)(args[1].data + base1);

  int *p_a2 = (int *)args[2].data;




  ops_H_D_exchanges_host(args, 3);
  ops_halo_exchanges(args,3,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[47].mpi_time += t1-t2;
  }

  update_halo_kernel4_plus_4_b_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    x_size, y_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[47].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 3);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[47].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[47].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}
