//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_calc_dt_kernel_get(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_calc_dt_kernel_get_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,6,range,99)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,99,"calc_dt_kernel_get");
    block->instance->OPS_kernels[99].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "calc_dt_kernel_get");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[3];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_calc_dt_kernel_get = args[0].dat->size[0];
  int ydim0_calc_dt_kernel_get = args[0].dat->size[1];
  int xdim1_calc_dt_kernel_get = args[1].dat->size[0];
  int ydim1_calc_dt_kernel_get = args[1].dat->size[1];
  int xdim4_calc_dt_kernel_get = args[4].dat->size[0];
  int ydim4_calc_dt_kernel_get = args[4].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ cellx_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ celly_p = (double *)(args[1].data + base1);

  #ifdef OPS_MPI
  double * __restrict__ p_a2 = (double *)(((ops_reduction)args[2].data)->data + ((ops_reduction)args[2].data)->size * block->index);
  #else //OPS_MPI
  double * __restrict__ p_a2 = (double *)((ops_reduction)args[2].data)->data;
  #endif //OPS_MPI


  #ifdef OPS_MPI
  double * __restrict__ p_a3 = (double *)(((ops_reduction)args[3].data)->data + ((ops_reduction)args[3].data)->size * block->index);
  #else //OPS_MPI
  double * __restrict__ p_a3 = (double *)((ops_reduction)args[3].data)->data;
  #endif //OPS_MPI


  int base4 = args[4].dat->base_offset;
  double * __restrict__ cellz_p = (double *)(args[4].data + base4);

  #ifdef OPS_MPI
  double * __restrict__ p_a5 = (double *)(((ops_reduction)args[5].data)->data + ((ops_reduction)args[5].data)->size * block->index);
  #else //OPS_MPI
  double * __restrict__ p_a5 = (double *)((ops_reduction)args[5].data)->data;
  #endif //OPS_MPI




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 6);
  ops_halo_exchanges(args,6,range);
  ops_H_D_exchanges_host(args, 6);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[99].mpi_time += __t1-__t2;
  }

  double p_a2_0 = p_a2[0];
  double p_a3_0 = p_a3[0];
  double p_a5_0 = p_a5[0];
  #pragma omp parallel for reduction(+:p_a2_0) reduction(+:p_a3_0) reduction(+:p_a5_0)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd reduction(+:p_a2_0) reduction(+:p_a3_0) reduction(+:p_a5_0)
      #elif defined(__clang__)
      #pragma clang loop vectorize(assume_safety)
      #elif defined(__GNUC__)
      #pragma GCC ivdep
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        const ACC<double> cellx(xdim0_calc_dt_kernel_get, ydim0_calc_dt_kernel_get, cellx_p + n_x*1 + n_y * xdim0_calc_dt_kernel_get*0 + n_z * xdim0_calc_dt_kernel_get * ydim0_calc_dt_kernel_get*0);
        const ACC<double> celly(xdim1_calc_dt_kernel_get, ydim1_calc_dt_kernel_get, celly_p + n_x*0 + n_y * xdim1_calc_dt_kernel_get*1 + n_z * xdim1_calc_dt_kernel_get * ydim1_calc_dt_kernel_get*0);
        const ACC<double> cellz(xdim4_calc_dt_kernel_get, ydim4_calc_dt_kernel_get, cellz_p + n_x*0 + n_y * xdim4_calc_dt_kernel_get*0 + n_z * xdim4_calc_dt_kernel_get * ydim4_calc_dt_kernel_get*1);
        double xl_pos[1];
        xl_pos[0] = ZERO_double;
        double yl_pos[1];
        yl_pos[0] = ZERO_double;
        double zl_pos[1];
        zl_pos[0] = ZERO_double;
        
  *xl_pos = cellx(0,0,0);
  *yl_pos = celly(0,0,0);
  *zl_pos = cellz(0,0,0);

        p_a2_0 +=xl_pos[0];
        p_a3_0 +=yl_pos[0];
        p_a5_0 +=zl_pos[0];
      }
    }
  }
  p_a2[0] = p_a2_0;
  p_a3[0] = p_a3_0;
  p_a5[0] = p_a5_0;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[99].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 6);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[99].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[99].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[99].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[99].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_calc_dt_kernel_get(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 99;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 99;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 6;
  desc->args = (ops_arg*)ops_malloc(6*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->function = ops_par_loop_calc_dt_kernel_get_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,99,"calc_dt_kernel_get");
  }
  ops_enqueue_kernel(desc);
}
#endif