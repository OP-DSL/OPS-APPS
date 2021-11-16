//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_update_halo_kernel4_plus_2_b(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
#else
void ops_par_loop_update_halo_kernel4_plus_2_b_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[3] = { arg0, arg1, arg2};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,3,range,78)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,78,"update_halo_kernel4_plus_2_b");
    block->instance->OPS_kernels[78].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "update_halo_kernel4_plus_2_b");
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
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_update_halo_kernel4_plus_2_b = args[0].dat->size[0];
  int ydim0_update_halo_kernel4_plus_2_b = args[0].dat->size[1];
  int xdim1_update_halo_kernel4_plus_2_b = args[1].dat->size[0];
  int ydim1_update_halo_kernel4_plus_2_b = args[1].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ vol_flux_y_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ mass_flux_y_p = (double *)(args[1].data + base1);

  int * __restrict__ fields = (int *)args[2].data;




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 3);
  ops_halo_exchanges(args,3,range);
  ops_H_D_exchanges_host(args, 3);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[78].mpi_time += __t1-__t2;
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
        ACC<double> vol_flux_y(xdim0_update_halo_kernel4_plus_2_b, ydim0_update_halo_kernel4_plus_2_b, vol_flux_y_p + n_x*1 + n_y * xdim0_update_halo_kernel4_plus_2_b*1 + n_z * xdim0_update_halo_kernel4_plus_2_b * ydim0_update_halo_kernel4_plus_2_b*1);
        ACC<double> mass_flux_y(xdim1_update_halo_kernel4_plus_2_b, ydim1_update_halo_kernel4_plus_2_b, mass_flux_y_p + n_x*1 + n_y * xdim1_update_halo_kernel4_plus_2_b*1 + n_z * xdim1_update_halo_kernel4_plus_2_b * ydim1_update_halo_kernel4_plus_2_b*1);
        
  if(fields[FIELD_VOL_FLUX_Y] == 1) vol_flux_y(0,0,0) = vol_flux_y(-2,0,0);
  if(fields[FIELD_MASS_FLUX_Y] == 1) mass_flux_y(0,0,0) = mass_flux_y(-2,0,0);

      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[78].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 3);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[78].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[78].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[78].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_update_halo_kernel4_plus_2_b(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 78;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 78;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 3;
  desc->args = (ops_arg*)ops_malloc(3*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  char *tmp = (char*)ops_malloc(NUM_FIELDS*sizeof(int));
  memcpy(tmp, arg2.data,NUM_FIELDS*sizeof(int));
  desc->args[2].data = tmp;
  desc->function = ops_par_loop_update_halo_kernel4_plus_2_b_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,78,"update_halo_kernel4_plus_2_b");
  }
  ops_enqueue_kernel(desc);
}
#endif
