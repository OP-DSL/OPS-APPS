//
// auto-generated by ops.py
//

extern int xdim0_complex_numbers_block0_2_kernel;
int xdim0_complex_numbers_block0_2_kernel_h = -1;
extern int xdim1_complex_numbers_block0_2_kernel;
int xdim1_complex_numbers_block0_2_kernel_h = -1;
extern int xdim2_complex_numbers_block0_2_kernel;
int xdim2_complex_numbers_block0_2_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void complex_numbers_block0_2_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_complex_numbers_block0_2_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  ops_arg args[4] = { arg0, arg1, arg2, arg3};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,4,range,4)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,4,"complex_numbers_block0_2_kernel");
    block->instance->OPS_kernels[4].count++;
  }

  //compute localy allocated range for the sub-block
  int start[1];
  int end[1];
  int arg_idx[1];

  #ifdef OPS_MPI
  if (compute_ranges(args, 4,block, range, start, end, arg_idx) < 0) return;
  #else
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];

  //Timing
  double t1,t2,c1,c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
  }

  if (xdim0 != xdim0_complex_numbers_block0_2_kernel_h || xdim1 != xdim1_complex_numbers_block0_2_kernel_h || xdim2 != xdim2_complex_numbers_block0_2_kernel_h) {
    xdim0_complex_numbers_block0_2_kernel = xdim0;
    xdim0_complex_numbers_block0_2_kernel_h = xdim0;
    xdim1_complex_numbers_block0_2_kernel = xdim1;
    xdim1_complex_numbers_block0_2_kernel_h = xdim1;
    xdim2_complex_numbers_block0_2_kernel = xdim2;
    xdim2_complex_numbers_block0_2_kernel_h = xdim2;
  }



  //set up initial pointers and exchange halos if necessary
  long long int base0 = args[0].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  double *p_a0 = (double *)(args[0].data + base0);

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  double *p_a1 = (double *)(args[1].data + base1);

  long long int base2 = args[2].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  double *p_a2 = (double *)(args[2].data + base2);

  double *p_a3 = (double *)args[3].data;




  ops_H_D_exchanges_host(args, 4);
  ops_halo_exchanges(args,4,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[4].mpi_time += t1-t2;
  }

  complex_numbers_block0_2_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    x_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[4].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 4);
  ops_set_halo_dirtybit3(&args[2],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}
