//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_complex_numbers_block0_2_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
#else
void ops_par_loop_complex_numbers_block0_2_kernel_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[4] = { arg0, arg1, arg2, arg3};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,4,range,4)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,4,"complex_numbers_block0_2_kernel");
    block->instance->OPS_kernels[4].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "complex_numbers_block0_2_kernel");
  #endif


  //compute locally allocated range for the sub-block
  int start[1];
  int end[1];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[1];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 4,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ phi_old_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ wk1_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ phi_p = (double *)(args[2].data + base2);

  double * __restrict__ rknew = (double *)args[3].data;




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 4);
  ops_halo_exchanges(args,4,range);
  ops_H_D_exchanges_host(args, 4);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[4].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for
  for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
    const ACC<double> phi_old(phi_old_p + n_x*1);
    const ACC<double> wk1(wk1_p + n_x*1);
    ACC<double> phi(phi_p + n_x*1);
    
phi(0) = deltat*rknew[0]*wk1(0) + phi_old(0);

  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[4].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 4);
  ops_set_halo_dirtybit3(&args[2],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[4].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_complex_numbers_block0_2_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 4;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 4;
  for ( int i=0; i<2; i++ ){
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
  char *tmp = (char*)ops_malloc(1*sizeof(double));
  memcpy(tmp, arg3.data,1*sizeof(double));
  desc->args[3].data = tmp;
  desc->function = ops_par_loop_complex_numbers_block0_2_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,4,"complex_numbers_block0_2_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
