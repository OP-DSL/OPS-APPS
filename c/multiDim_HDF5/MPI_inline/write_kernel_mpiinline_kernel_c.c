//
// auto-generated by ops.py
//

int xdim0_write_kernel;
int ydim0_write_kernel;
int xdim1_write_kernel;
int ydim1_write_kernel;
int xdim2_write_kernel;
int ydim2_write_kernel;
int xdim3_write_kernel;
int ydim3_write_kernel;
int xdim4_write_kernel;
int ydim4_write_kernel;
int xdim5_write_kernel;
int ydim5_write_kernel;
int xdim6_write_kernel;
int ydim6_write_kernel;


//user function



void write_kernel_c_wrapper(
  double * restrict mult_p,
  double * restrict single_p,
  int * restrict digit_p,
  char * restrict dat_char_p,
  short * restrict dat_short_p,
  long * restrict dat_long_p,
  ll * restrict dat_ll_p,
  int * restrict idx,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        int idx[] = {arg_idx0+n_x, arg_idx1+n_y, arg_idx2+n_z};
        #ifdef OPS_SOA
        ptrm_double mult = { mult_p + n_x*1 + n_y * xdim0_write_kernel*1 + n_z * xdim0_write_kernel * ydim0_write_kernel*1, xdim0_write_kernel, ydim0_write_kernel, zdim0_write_kernel};
        #else
        ptrm_double mult = { mult_p + n_x*1 + n_y * xdim0_write_kernel*1 + n_z * xdim0_write_kernel * ydim0_write_kernel*1, xdim0_write_kernel, ydim0_write_kernel, 2};
        #endif
        ptr_double single = { single_p + n_x*1 + n_y * xdim1_write_kernel*1 + n_z * xdim1_write_kernel * ydim1_write_kernel*1, xdim1_write_kernel, ydim1_write_kernel};
        ptr_int digit = { digit_p + n_x*1 + n_y * xdim2_write_kernel*1 + n_z * xdim2_write_kernel * ydim2_write_kernel*1, xdim2_write_kernel, ydim2_write_kernel};
        ptr_char dat_char = { dat_char_p + n_x*1 + n_y * xdim3_write_kernel*1 + n_z * xdim3_write_kernel * ydim3_write_kernel*1, xdim3_write_kernel, ydim3_write_kernel};
        ptr_short dat_short = { dat_short_p + n_x*1 + n_y * xdim4_write_kernel*1 + n_z * xdim4_write_kernel * ydim4_write_kernel*1, xdim4_write_kernel, ydim4_write_kernel};
        ptr_long dat_long = { dat_long_p + n_x*1 + n_y * xdim5_write_kernel*1 + n_z * xdim5_write_kernel * ydim5_write_kernel*1, xdim5_write_kernel, ydim5_write_kernel};
        ptr_ll dat_ll = { dat_ll_p + n_x*1 + n_y * xdim6_write_kernel*1 + n_z * xdim6_write_kernel * ydim6_write_kernel*1, xdim6_write_kernel, ydim6_write_kernel};
        

  OPS_ACC(mult, 0, 0, 0, 0) = 1;

  OPS_ACC(mult, 1, 0, 0, 0) = 2;

  OPS_ACC(single, 0, 0, 0) = 3;

  OPS_ACC(digit, 0, 0, 0) = idx[0] + idx[1] * 4 + idx[2] * 20;
  OPS_ACC(dat_char, 0, 0, 0) = idx[0] + idx[1] * 4 + idx[2] * 20;
  OPS_ACC(dat_short, 0, 0, 0) = idx[0] + idx[1] * 4 + idx[2] * 20;
  OPS_ACC(dat_long, 0, 0, 0) = idx[0] + idx[1] * 4 + idx[2] * 20;
  OPS_ACC(dat_ll, 0, 0, 0) = idx[0] + idx[1] * 4 + idx[2] * 20;

      }
    }
  }
}
