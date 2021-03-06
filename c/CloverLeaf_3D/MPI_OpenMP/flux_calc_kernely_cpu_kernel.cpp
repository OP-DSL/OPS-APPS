//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_flux_calc_kernely(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
#else
void ops_par_loop_flux_calc_kernely_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,4,range,107)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,107,"flux_calc_kernely");
    block->instance->OPS_kernels[107].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "flux_calc_kernely");
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
  if (compute_ranges(args, 4,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_flux_calc_kernely = args[0].dat->size[0];
  int ydim0_flux_calc_kernely = args[0].dat->size[1];
  int xdim1_flux_calc_kernely = args[1].dat->size[0];
  int ydim1_flux_calc_kernely = args[1].dat->size[1];
  int xdim2_flux_calc_kernely = args[2].dat->size[0];
  int ydim2_flux_calc_kernely = args[2].dat->size[1];
  int xdim3_flux_calc_kernely = args[3].dat->size[0];
  int ydim3_flux_calc_kernely = args[3].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ vol_flux_y_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ yarea_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ yvel0_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ yvel1_p = (double *)(args[3].data + base3);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 4);
  ops_halo_exchanges(args,4,range);
  ops_H_D_exchanges_host(args, 4);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[107].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd
      #elif defined(__clang__)
      #pragma clang loop vectorize(assume_safety)
      #elif defined(__GNUC__)
      #pragma GCC ivdep
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        ACC<double> vol_flux_y(xdim0_flux_calc_kernely, ydim0_flux_calc_kernely, vol_flux_y_p + n_x*1 + n_y * xdim0_flux_calc_kernely*1 + n_z * xdim0_flux_calc_kernely * ydim0_flux_calc_kernely*1);
        const ACC<double> yarea(xdim1_flux_calc_kernely, ydim1_flux_calc_kernely, yarea_p + n_x*1 + n_y * xdim1_flux_calc_kernely*1 + n_z * xdim1_flux_calc_kernely * ydim1_flux_calc_kernely*1);
        const ACC<double> yvel0(xdim2_flux_calc_kernely, ydim2_flux_calc_kernely, yvel0_p + n_x*1 + n_y * xdim2_flux_calc_kernely*1 + n_z * xdim2_flux_calc_kernely * ydim2_flux_calc_kernely*1);
        const ACC<double> yvel1(xdim3_flux_calc_kernely, ydim3_flux_calc_kernely, yvel1_p + n_x*1 + n_y * xdim3_flux_calc_kernely*1 + n_z * xdim3_flux_calc_kernely * ydim3_flux_calc_kernely*1);
        

  vol_flux_y(0,0,0) = 0.125 * dt * (yarea(0,0,0)) *
  ( yvel0(0,0,0) + yvel0(1,0,0) + yvel0(0,0,1) + yvel0(1,0,1) +
    yvel1(0,0,0) + yvel1(1,0,0) + yvel1(0,0,1) + yvel1(1,0,1));

      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[107].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 4);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[107].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[107].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[107].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[107].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[107].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_flux_calc_kernely(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 107;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 107;
  for ( int i=0; i<6; i++ ){
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
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->function = ops_par_loop_flux_calc_kernely_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,107,"flux_calc_kernely");
  }
  ops_enqueue_kernel(desc);
}
#endif
