//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_advec_cell_kernel3_zdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
#else
void ops_par_loop_advec_cell_kernel3_zdir_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,8,range,118)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,118,"advec_cell_kernel3_zdir");
    block->instance->OPS_kernels[118].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "advec_cell_kernel3_zdir");
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
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_advec_cell_kernel3_zdir = args[0].dat->size[0];
  int ydim0_advec_cell_kernel3_zdir = args[0].dat->size[1];
  int xdim1_advec_cell_kernel3_zdir = args[1].dat->size[0];
  int ydim1_advec_cell_kernel3_zdir = args[1].dat->size[1];
  int xdim2_advec_cell_kernel3_zdir = args[2].dat->size[0];
  int ydim2_advec_cell_kernel3_zdir = args[2].dat->size[1];
  int xdim3_advec_cell_kernel3_zdir = args[3].dat->size[0];
  int ydim3_advec_cell_kernel3_zdir = args[3].dat->size[1];
  int xdim4_advec_cell_kernel3_zdir = args[4].dat->size[0];
  int ydim4_advec_cell_kernel3_zdir = args[4].dat->size[1];
  int xdim5_advec_cell_kernel3_zdir = args[5].dat->size[0];
  int ydim5_advec_cell_kernel3_zdir = args[5].dat->size[1];
  int xdim6_advec_cell_kernel3_zdir = args[6].dat->size[0];
  int ydim6_advec_cell_kernel3_zdir = args[6].dat->size[1];
  int xdim7_advec_cell_kernel3_zdir = args[7].dat->size[0];
  int ydim7_advec_cell_kernel3_zdir = args[7].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ vol_flux_z_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ pre_vol_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  int * __restrict__ zz_p = (int *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ vertexdz_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ density1_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ energy1_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ mass_flux_z_p = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ ener_flux_p = (double *)(args[7].data + base7);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 8);
  ops_halo_exchanges(args,8,range);
  ops_H_D_exchanges_host(args, 8);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[118].mpi_time += __t1-__t2;
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
        const ACC<double> vol_flux_z(xdim0_advec_cell_kernel3_zdir, ydim0_advec_cell_kernel3_zdir, vol_flux_z_p + n_x*1 + n_y * xdim0_advec_cell_kernel3_zdir*1 + n_z * xdim0_advec_cell_kernel3_zdir * ydim0_advec_cell_kernel3_zdir*1);
        const ACC<double> pre_vol(xdim1_advec_cell_kernel3_zdir, ydim1_advec_cell_kernel3_zdir, pre_vol_p + n_x*1 + n_y * xdim1_advec_cell_kernel3_zdir*1 + n_z * xdim1_advec_cell_kernel3_zdir * ydim1_advec_cell_kernel3_zdir*1);
        const ACC<int> zz(xdim2_advec_cell_kernel3_zdir, ydim2_advec_cell_kernel3_zdir, zz_p + n_x*0 + n_y * xdim2_advec_cell_kernel3_zdir*0 + n_z * xdim2_advec_cell_kernel3_zdir * ydim2_advec_cell_kernel3_zdir*1);
        const ACC<double> vertexdz(xdim3_advec_cell_kernel3_zdir, ydim3_advec_cell_kernel3_zdir, vertexdz_p + n_x*0 + n_y * xdim3_advec_cell_kernel3_zdir*0 + n_z * xdim3_advec_cell_kernel3_zdir * ydim3_advec_cell_kernel3_zdir*1);
        const ACC<double> density1(xdim4_advec_cell_kernel3_zdir, ydim4_advec_cell_kernel3_zdir, density1_p + n_x*1 + n_y * xdim4_advec_cell_kernel3_zdir*1 + n_z * xdim4_advec_cell_kernel3_zdir * ydim4_advec_cell_kernel3_zdir*1);
        const ACC<double> energy1(xdim5_advec_cell_kernel3_zdir, ydim5_advec_cell_kernel3_zdir, energy1_p + n_x*1 + n_y * xdim5_advec_cell_kernel3_zdir*1 + n_z * xdim5_advec_cell_kernel3_zdir * ydim5_advec_cell_kernel3_zdir*1);
        ACC<double> mass_flux_z(xdim6_advec_cell_kernel3_zdir, ydim6_advec_cell_kernel3_zdir, mass_flux_z_p + n_x*1 + n_y * xdim6_advec_cell_kernel3_zdir*1 + n_z * xdim6_advec_cell_kernel3_zdir * ydim6_advec_cell_kernel3_zdir*1);
        ACC<double> ener_flux(xdim7_advec_cell_kernel3_zdir, ydim7_advec_cell_kernel3_zdir, ener_flux_p + n_x*1 + n_y * xdim7_advec_cell_kernel3_zdir*1 + n_z * xdim7_advec_cell_kernel3_zdir * ydim7_advec_cell_kernel3_zdir*1);
        

  double sigmat, sigmav, sigmam, sigma3, sigma4;
  double diffuw, diffdw, limiter;
  double one_by_six = 1.0/6.0;

  int z_max=field.z_max;

  int upwind,donor,downwind,dif;

  if(vol_flux_z(0,0,0) > 0.0) {
    upwind   = -2;
    donor    = -1;
    downwind = 0;
    dif      = donor;
  }
  else if (zz(0,0,1) < z_max+2-2) {
    upwind   = 1;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  } else {
    upwind   = 0;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  }

  sigmat = fabs(vol_flux_z(0,0,0))/pre_vol(0,0,donor);
  sigma3 = (1.0 + sigmat)*(vertexdz(0,0,0)/vertexdz(0,0,dif));
  sigma4 = 2.0 - sigmat;

  sigmav = sigmat;

  diffuw = density1(0,0,donor) - density1(0,0,upwind);
  diffdw = density1(0,0,downwind) - density1(0,0,donor);

  if( (diffuw*diffdw) > 0.0)
    limiter=(1.0 - sigmav) * SIGN(1.0 , diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3*fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  mass_flux_z(0,0,0) = vol_flux_z(0,0,0) * ( density1(0,0,donor) + limiter );

  sigmam = fabs(mass_flux_z(0,0,0))/( density1(0,0,donor) * pre_vol(0,0,donor));
  diffuw = energy1(0,0,donor) - energy1(0,0,upwind);
  diffdw = energy1(0,0,downwind) - energy1(0,0,donor);

  if( (diffuw*diffdw) > 0.0)
    limiter = (1.0 - sigmam) * SIGN(1.0,diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3 * fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  ener_flux(0,0,0) = mass_flux_z(0,0,0) * ( energy1(0,0,donor) + limiter );

      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[118].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 8);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[118].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg7);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_advec_cell_kernel3_zdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 118;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 118;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 8;
  desc->args = (ops_arg*)ops_malloc(8*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg7.dat->index;
  desc->function = ops_par_loop_advec_cell_kernel3_zdir_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,118,"advec_cell_kernel3_zdir");
  }
  ops_enqueue_kernel(desc);
}
#endif
