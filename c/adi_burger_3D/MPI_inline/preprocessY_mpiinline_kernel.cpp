//
// auto-generated by ops.py
//

extern int xdim0_preprocessY;
int xdim0_preprocessY_h = -1;
extern int ydim0_preprocessY;
int ydim0_preprocessY_h = -1;
extern int xdim1_preprocessY;
int xdim1_preprocessY_h = -1;
extern int ydim1_preprocessY;
int ydim1_preprocessY_h = -1;
extern int xdim2_preprocessY;
int xdim2_preprocessY_h = -1;
extern int ydim2_preprocessY;
int ydim2_preprocessY_h = -1;
extern int xdim4_preprocessY;
int xdim4_preprocessY_h = -1;
extern int ydim4_preprocessY;
int ydim4_preprocessY_h = -1;
extern int xdim5_preprocessY;
int xdim5_preprocessY_h = -1;
extern int ydim5_preprocessY;
int ydim5_preprocessY_h = -1;
extern int xdim6_preprocessY;
int xdim6_preprocessY_h = -1;
extern int ydim6_preprocessY;
int ydim6_preprocessY_h = -1;
extern int xdim7_preprocessY;
int xdim7_preprocessY_h = -1;
extern int ydim7_preprocessY;
int ydim7_preprocessY_h = -1;
extern int xdim8_preprocessY;
int xdim8_preprocessY_h = -1;
extern int ydim8_preprocessY;
int ydim8_preprocessY_h = -1;
extern int xdim9_preprocessY;
int xdim9_preprocessY_h = -1;
extern int ydim9_preprocessY;
int ydim9_preprocessY_h = -1;
extern int xdim10_preprocessY;
int xdim10_preprocessY_h = -1;
extern int ydim10_preprocessY;
int ydim10_preprocessY_h = -1;
extern int xdim11_preprocessY;
int xdim11_preprocessY_h = -1;
extern int ydim11_preprocessY;
int ydim11_preprocessY_h = -1;
extern int xdim12_preprocessY;
int xdim12_preprocessY_h = -1;
extern int ydim12_preprocessY;
int ydim12_preprocessY_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void preprocessY_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  double *p_a11,
  double *p_a12,
  int *p_a13,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_preprocessY(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11, ops_arg arg12, ops_arg arg13) {

  ops_arg args[14] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,14,range,3)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,3,"preprocessY");
    block->instance->OPS_kernels[3].count++;
  }

  //compute localy allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];

  #ifdef OPS_MPI
  if (compute_ranges(args, 14,block, range, start, end, arg_idx) < 0) return;
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];
  int xdim7 = args[7].dat->size[0];
  int ydim7 = args[7].dat->size[1];
  int xdim8 = args[8].dat->size[0];
  int ydim8 = args[8].dat->size[1];
  int xdim9 = args[9].dat->size[0];
  int ydim9 = args[9].dat->size[1];
  int xdim10 = args[10].dat->size[0];
  int ydim10 = args[10].dat->size[1];
  int xdim11 = args[11].dat->size[0];
  int ydim11 = args[11].dat->size[1];
  int xdim12 = args[12].dat->size[0];
  int ydim12 = args[12].dat->size[1];

  //Timing
  double t1,t2,c1,c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
  }

  if (xdim0 != xdim0_preprocessY_h || ydim0 != ydim0_preprocessY_h || xdim1 != xdim1_preprocessY_h || ydim1 != ydim1_preprocessY_h || xdim2 != xdim2_preprocessY_h || ydim2 != ydim2_preprocessY_h || xdim4 != xdim4_preprocessY_h || ydim4 != ydim4_preprocessY_h || xdim5 != xdim5_preprocessY_h || ydim5 != ydim5_preprocessY_h || xdim6 != xdim6_preprocessY_h || ydim6 != ydim6_preprocessY_h || xdim7 != xdim7_preprocessY_h || ydim7 != ydim7_preprocessY_h || xdim8 != xdim8_preprocessY_h || ydim8 != ydim8_preprocessY_h || xdim9 != xdim9_preprocessY_h || ydim9 != ydim9_preprocessY_h || xdim10 != xdim10_preprocessY_h || ydim10 != ydim10_preprocessY_h || xdim11 != xdim11_preprocessY_h || ydim11 != ydim11_preprocessY_h || xdim12 != xdim12_preprocessY_h || ydim12 != ydim12_preprocessY_h) {
    xdim0_preprocessY = xdim0;
    xdim0_preprocessY_h = xdim0;
    ydim0_preprocessY = ydim0;
    ydim0_preprocessY_h = ydim0;
    xdim1_preprocessY = xdim1;
    xdim1_preprocessY_h = xdim1;
    ydim1_preprocessY = ydim1;
    ydim1_preprocessY_h = ydim1;
    xdim2_preprocessY = xdim2;
    xdim2_preprocessY_h = xdim2;
    ydim2_preprocessY = ydim2;
    ydim2_preprocessY_h = ydim2;
    xdim4_preprocessY = xdim4;
    xdim4_preprocessY_h = xdim4;
    ydim4_preprocessY = ydim4;
    ydim4_preprocessY_h = ydim4;
    xdim5_preprocessY = xdim5;
    xdim5_preprocessY_h = xdim5;
    ydim5_preprocessY = ydim5;
    ydim5_preprocessY_h = ydim5;
    xdim6_preprocessY = xdim6;
    xdim6_preprocessY_h = xdim6;
    ydim6_preprocessY = ydim6;
    ydim6_preprocessY_h = ydim6;
    xdim7_preprocessY = xdim7;
    xdim7_preprocessY_h = xdim7;
    ydim7_preprocessY = ydim7;
    ydim7_preprocessY_h = ydim7;
    xdim8_preprocessY = xdim8;
    xdim8_preprocessY_h = xdim8;
    ydim8_preprocessY = ydim8;
    ydim8_preprocessY_h = ydim8;
    xdim9_preprocessY = xdim9;
    xdim9_preprocessY_h = xdim9;
    ydim9_preprocessY = ydim9;
    ydim9_preprocessY_h = ydim9;
    xdim10_preprocessY = xdim10;
    xdim10_preprocessY_h = xdim10;
    ydim10_preprocessY = ydim10;
    ydim10_preprocessY_h = ydim10;
    xdim11_preprocessY = xdim11;
    xdim11_preprocessY_h = xdim11;
    ydim11_preprocessY = ydim11;
    ydim11_preprocessY_h = ydim11;
    xdim12_preprocessY = xdim12;
    xdim12_preprocessY_h = xdim12;
    ydim12_preprocessY = ydim12;
    ydim12_preprocessY_h = ydim12;
  }



  //set up initial pointers and exchange halos if necessary
  long long int base0 = args[0].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0+ (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0+ (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  double *p_a0 = (double *)(args[0].data + base0);

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1+ (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1+ (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  double *p_a1 = (double *)(args[1].data + base1);

  long long int base2 = args[2].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2+ (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2+ (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  double *p_a2 = (double *)(args[2].data + base2);

  double *p_a3 = (double *)args[3].data;


  long long int base4 = args[4].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4+ (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4+ (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  double *p_a4 = (double *)(args[4].data + base4);

  long long int base5 = args[5].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) * start[0] * args[5].stencil->stride[0];
  base5 = base5+ (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    start[1] * args[5].stencil->stride[1];
  base5 = base5+ (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    start[2] * args[5].stencil->stride[2];
  double *p_a5 = (double *)(args[5].data + base5);

  long long int base6 = args[6].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) * start[0] * args[6].stencil->stride[0];
  base6 = base6+ (long long int)(block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
    args[6].dat->size[0] *
    start[1] * args[6].stencil->stride[1];
  base6 = base6+ (long long int)(block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    start[2] * args[6].stencil->stride[2];
  double *p_a6 = (double *)(args[6].data + base6);

  long long int base7 = args[7].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) * start[0] * args[7].stencil->stride[0];
  base7 = base7+ (long long int)(block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
    args[7].dat->size[0] *
    start[1] * args[7].stencil->stride[1];
  base7 = base7+ (long long int)(block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
    args[7].dat->size[0] *
    args[7].dat->size[1] *
    start[2] * args[7].stencil->stride[2];
  double *p_a7 = (double *)(args[7].data + base7);

  long long int base8 = args[8].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) * start[0] * args[8].stencil->stride[0];
  base8 = base8+ (long long int)(block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) *
    args[8].dat->size[0] *
    start[1] * args[8].stencil->stride[1];
  base8 = base8+ (long long int)(block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) *
    args[8].dat->size[0] *
    args[8].dat->size[1] *
    start[2] * args[8].stencil->stride[2];
  double *p_a8 = (double *)(args[8].data + base8);

  long long int base9 = args[9].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) * start[0] * args[9].stencil->stride[0];
  base9 = base9+ (long long int)(block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) *
    args[9].dat->size[0] *
    start[1] * args[9].stencil->stride[1];
  base9 = base9+ (long long int)(block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) *
    args[9].dat->size[0] *
    args[9].dat->size[1] *
    start[2] * args[9].stencil->stride[2];
  double *p_a9 = (double *)(args[9].data + base9);

  long long int base10 = args[10].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) * start[0] * args[10].stencil->stride[0];
  base10 = base10+ (long long int)(block->instance->OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) *
    args[10].dat->size[0] *
    start[1] * args[10].stencil->stride[1];
  base10 = base10+ (long long int)(block->instance->OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) *
    args[10].dat->size[0] *
    args[10].dat->size[1] *
    start[2] * args[10].stencil->stride[2];
  double *p_a10 = (double *)(args[10].data + base10);

  long long int base11 = args[11].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[11].dat->type_size : args[11].dat->elem_size) * start[0] * args[11].stencil->stride[0];
  base11 = base11+ (long long int)(block->instance->OPS_soa ? args[11].dat->type_size : args[11].dat->elem_size) *
    args[11].dat->size[0] *
    start[1] * args[11].stencil->stride[1];
  base11 = base11+ (long long int)(block->instance->OPS_soa ? args[11].dat->type_size : args[11].dat->elem_size) *
    args[11].dat->size[0] *
    args[11].dat->size[1] *
    start[2] * args[11].stencil->stride[2];
  double *p_a11 = (double *)(args[11].data + base11);

  long long int base12 = args[12].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[12].dat->type_size : args[12].dat->elem_size) * start[0] * args[12].stencil->stride[0];
  base12 = base12+ (long long int)(block->instance->OPS_soa ? args[12].dat->type_size : args[12].dat->elem_size) *
    args[12].dat->size[0] *
    start[1] * args[12].stencil->stride[1];
  base12 = base12+ (long long int)(block->instance->OPS_soa ? args[12].dat->type_size : args[12].dat->elem_size) *
    args[12].dat->size[0] *
    args[12].dat->size[1] *
    start[2] * args[12].stencil->stride[2];
  double *p_a12 = (double *)(args[12].data + base12);

  int *p_a13 = NULL;



  ops_H_D_exchanges_host(args, 14);
  ops_halo_exchanges(args,14,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[3].mpi_time += t1-t2;
  }

  preprocessY_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    p_a6,
    p_a7,
    p_a8,
    p_a9,
    p_a10,
    p_a11,
    p_a12,
    p_a13,
    arg_idx[0], arg_idx[1], arg_idx[2],
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[3].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 14);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[9],range);
  ops_set_halo_dirtybit3(&args[10],range);
  ops_set_halo_dirtybit3(&args[11],range);
  ops_set_halo_dirtybit3(&args[12],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg9);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg10);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg11);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg12);
  }
}
