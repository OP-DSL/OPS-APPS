//
// auto-generated by ops.py
//

extern int xdim0_mgrid_prolong_kernel;
int xdim0_mgrid_prolong_kernel_h = -1;
extern int xdim1_mgrid_prolong_kernel;
int xdim1_mgrid_prolong_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void mgrid_prolong_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  int *p_a2,
  int *global_idx,
  int *stride_0,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_mgrid_prolong_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  ops_arg args[3] = { arg0, arg1, arg2};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,3,range,2)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,2,"mgrid_prolong_kernel");
    block->instance->OPS_kernels[2].count++;
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

  if (xdim0 != xdim0_mgrid_prolong_kernel_h || xdim1 != xdim1_mgrid_prolong_kernel_h) {
    xdim0_mgrid_prolong_kernel = xdim0;
    xdim0_mgrid_prolong_kernel_h = xdim0;
    xdim1_mgrid_prolong_kernel = xdim1;
    xdim1_mgrid_prolong_kernel_h = xdim1;
  }


  int global_idx[2];
  #ifdef OPS_MPI
  global_idx[0] = arg_idx[0];
  global_idx[1] = arg_idx[1];
  #else //OPS_MPI
  global_idx[0] = start[0];
  global_idx[1] = start[1];
  #endif //OPS_MPI

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

  //set up initial pointers and exchange halos if necessary
  long long int base0 = args[0].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start_0[0] * args[0].stencil->stride[0];
  base0 = base0+ (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start_0[1] * args[0].stencil->stride[1];
  double *p_a0 = (double *)(args[0].data + base0);

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1+ (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  double *p_a1 = (double *)(args[1].data + base1);

  int *p_a2 = NULL;



  ops_H_D_exchanges_host(args, 3);
  ops_halo_exchanges(args,3,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[2].mpi_time += t1-t2;
  }

  mgrid_prolong_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    global_idx,
    stride_0,
    arg_idx[0], arg_idx[1],
    x_size, y_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[2].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 3);
  ops_set_halo_dirtybit3(&args[1],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}
