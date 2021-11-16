//
// auto-generated by ops.py
//

int xdim0_preprocessY;
int xdim1_preprocessY;
int xdim3_preprocessY;
int xdim4_preprocessY;
int xdim5_preprocessY;
int xdim6_preprocessY;
int xdim7_preprocessY;
int xdim8_preprocessY;
int xdim9_preprocessY;


//user function



void preprocessY_c_wrapper(
  double * restrict u_p,
  double * restrict v_p,
  const double * restrict time,
  double * restrict a_p,
  double * restrict b_p,
  double * restrict c_p,
  double * restrict du_p,
  double * restrict dv_p,
  double * restrict resU_p,
  double * restrict resV_p,
  int * restrict idx,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      int idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      const ptr_double u = { u_p + n_x*1 + n_y * xdim0_preprocessY*1, xdim0_preprocessY};
      const ptr_double v = { v_p + n_x*1 + n_y * xdim1_preprocessY*1, xdim1_preprocessY};
      ptr_double a = { a_p + n_x*1 + n_y * xdim3_preprocessY*1, xdim3_preprocessY};
      ptr_double b = { b_p + n_x*1 + n_y * xdim4_preprocessY*1, xdim4_preprocessY};
      ptr_double c = { c_p + n_x*1 + n_y * xdim5_preprocessY*1, xdim5_preprocessY};
      ptr_double du = { du_p + n_x*1 + n_y * xdim6_preprocessY*1, xdim6_preprocessY};
      ptr_double dv = { dv_p + n_x*1 + n_y * xdim7_preprocessY*1, xdim7_preprocessY};
      ptr_double resU = { resU_p + n_x*1 + n_y * xdim8_preprocessY*1, xdim8_preprocessY};
      ptr_double resV = { resV_p + n_x*1 + n_y * xdim9_preprocessY*1, xdim9_preprocessY};
      
    OPS_ACC(resU, 0, 0) = 0;
    OPS_ACC(resV, 0, 0) = 0;
    if (idx[0] == 0 || idx[0] == nx - 1 || idx[1] == 0 || idx[1] == ny - 1) {
        OPS_ACC(a, 0, 0) = 0;
        OPS_ACC(b, 0, 0) = 1;
        OPS_ACC(c, 0, 0) = 0;
        OPS_ACC(du, 0, 0) =
            0.75 -
            1 / (4 * (1 + exp((-4 * idx[0] * h + 4 * idx[1] * h - (*time)) *
                              Re / 32)));
        OPS_ACC(dv, 0, 0) =
            0.75 +
            1 / (4 * (1 + exp((-4 * idx[0] * h + 4 * idx[1] * h - (*time)) *
                              Re / 32)));
    } else {
        OPS_ACC(a, 0, 0) = -r1 * OPS_ACC(v, 0, 0) - r2;
        OPS_ACC(b, 0, 0) = 1 + 2 * r2;
        OPS_ACC(c, 0, 0) = -r1 * OPS_ACC(v, 0, 0) + r2;
        OPS_ACC(du, 0, 0) = (r1 * OPS_ACC(u, 0, 0) + r2) * OPS_ACC(u, -1, 0) + (1 - 2 * r2) * OPS_ACC(u, 0, 0) +
                   (-r1 * OPS_ACC(u, 0, 0) + r2) * OPS_ACC(u, 1, 0);
        OPS_ACC(dv, 0, 0) = (r1 * OPS_ACC(u, 0, 0) + r2) * OPS_ACC(v, -1, 0) + (1 - 2 * r2) * OPS_ACC(v, 0, 0) +
                   (-r1 * OPS_ACC(u, 0, 0) + r2) * OPS_ACC(v, 1, 0);
    }

    }
  }
}