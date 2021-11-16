//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_prolong_check;

//user function
inline 
void prolong_check(const ptr_double val,
  int *idx,
  int *err,
  const int *sizex,
  const int *sizey) {
  int lerr = 0;
  lerr |= (OPS_ACC(val, 0,0) != idx[0]/4 + (idx[1]/4)*(*sizex/4));


  int xm = (idx[0]-1)<0 ? *sizex-1 : idx[0]-1;
  int xp = (idx[0]+1)>=*sizex ? 0 : idx[0]+1;
  int ym = (idx[1]-1)<0 ? *sizey-1 : idx[1]-1;
  int yp = (idx[1]+1)>=*sizey ? 0 : idx[1]+1;
  lerr |= (OPS_ACC(val, 1,0) != xp/4 + (idx[1]/4)*(*sizex/4));


  lerr |= (OPS_ACC(val, -1,0) != xm/4 + (idx[1]/4)*(*sizex/4));


  lerr |= (OPS_ACC(val, 0,1) != idx[0]/4 + (yp/4)*(*sizex/4));


  lerr |= (OPS_ACC(val, 0,-1) != idx[0]/4 + (ym/4)*(*sizex/4));



  if (lerr != 0) *err = 1;
  else *err = 0;

}


void prolong_check_c_wrapper(
  double *p_a0,
  int *p_a1,
  int *p_a2,
  int p_a3,
  int p_a4,
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
      const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_prolong_check*1*1, xdim0_prolong_check};
      prolong_check( ptr0,
          arg_idx, &p_a2_0,
           &p_a3, &p_a4 );

    }
  }
  p_a2[0] = p_a2_0;
}