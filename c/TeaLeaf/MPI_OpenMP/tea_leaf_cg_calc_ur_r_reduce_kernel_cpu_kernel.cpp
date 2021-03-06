//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_tea_leaf_cg_calc_ur_r_reduce_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
#else
void ops_par_loop_tea_leaf_cg_calc_ur_r_reduce_kernel_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,4,range,21)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,21,"tea_leaf_cg_calc_ur_r_reduce_kernel");
    block->instance->OPS_kernels[21].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "tea_leaf_cg_calc_ur_r_reduce_kernel");
  #endif


  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[2];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 4,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel = args[0].dat->size[0];
  int xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel = args[1].dat->size[0];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ r_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ w_p = (double *)(args[1].data + base1);

  double * __restrict__ alpha = (double *)args[2].data;


  #ifdef OPS_MPI
  double * __restrict__ p_a3 = (double *)(((ops_reduction)args[3].data)->data + ((ops_reduction)args[3].data)->size * block->index);
  #else //OPS_MPI
  double * __restrict__ p_a3 = (double *)((ops_reduction)args[3].data)->data;
  #endif //OPS_MPI




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 4);
  ops_halo_exchanges(args,4,range);
  ops_H_D_exchanges_host(args, 4);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[21].mpi_time += __t1-__t2;
  }

  double p_a3_0 = p_a3[0];
  #pragma omp parallel for reduction(+:p_a3_0)
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef __INTEL_COMPILER
    #pragma loop_count(10000)
    #pragma omp simd reduction(+:p_a3_0)
    #elif defined(__clang__)
    #pragma clang loop vectorize(assume_safety)
    #elif defined(__GNUC__)
    #pragma GCC ivdep
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      ACC<double> r(xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel, r_p + n_x*1 + n_y * xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel*1);
      const ACC<double> w(xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel, w_p + n_x*1 + n_y * xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel*1);
      double rnn[1];
      rnn[0] = ZERO_double;
      
  r(0,0) = r(0,0) - (*alpha)*w(0,0);
  *rnn = *rnn +  r(0,0)*r(0,0);

      p_a3_0 +=rnn[0];
    }
  }
  p_a3[0] = p_a3_0;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[21].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 4);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[21].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_tea_leaf_cg_calc_ur_r_reduce_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 21;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 21;
  for ( int i=0; i<4; i++ ){
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
  char *tmp = (char*)ops_malloc(1*sizeof(double));
  memcpy(tmp, arg2.data,1*sizeof(double));
  desc->args[2].data = tmp;
  desc->args[3] = arg3;
  desc->function = ops_par_loop_tea_leaf_cg_calc_ur_r_reduce_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,21,"tea_leaf_cg_calc_ur_r_reduce_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
