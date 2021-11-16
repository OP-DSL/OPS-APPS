//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_restrict_check;

//user function
inline 
void restrict_check(const ptr_double val,
  int *idx,
  int *err,
  const int *sizex) {
  if (OPS_ACC(val, 0,0) != idx[0]*4 + idx[1]*4**sizex) {


    *err = 1;
  } else
    *err = 0;
}


void restrict_check_c_wrapper(
  double *p_a0,
  int *p_a1,
  int *p_a2,
  int p_a3,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  int p_a2_0 = p_a2[0];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0) reduction(max:p_a2_0)
  #pragma acc loop reduction(max:p_a2_0)
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop reduction(max:p_a2_0)
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      int arg_idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_restrict_check*1*1, xdim0_restrict_check};
      restrict_check( ptr0,
          arg_idx, &p_a2_0,
           &p_a3 );

    }
  }
  p_a2[0] = p_a2_0;
}
