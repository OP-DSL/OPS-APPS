//
// auto-generated by ops.py
//

int xdim0_preprocessX;
int ydim0_preprocessX;
int xdim1_preprocessX;
int ydim1_preprocessX;
int xdim2_preprocessX;
int ydim2_preprocessX;
int xdim4_preprocessX;
int ydim4_preprocessX;
int xdim5_preprocessX;
int ydim5_preprocessX;
int xdim6_preprocessX;
int ydim6_preprocessX;
int xdim7_preprocessX;
int ydim7_preprocessX;
int xdim8_preprocessX;
int ydim8_preprocessX;
int xdim9_preprocessX;
int ydim9_preprocessX;
int xdim10_preprocessX;
int ydim10_preprocessX;
int xdim11_preprocessX;
int ydim11_preprocessX;
int xdim12_preprocessX;
int ydim12_preprocessX;


//user function



void preprocessX_c_wrapper(
  double * restrict u_p,
  double * restrict v_p,
  double * restrict w_p,
  const double * restrict time,
  double * restrict a_p,
  double * restrict b_p,
  double * restrict c_p,
  double * restrict du_p,
  double * restrict dv_p,
  double * restrict dw_p,
  double * restrict resU_p,
  double * restrict resV_p,
  double * restrict resW_p,
  int * restrict idx,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        int idx[] = {arg_idx0+n_x, arg_idx1+n_y, arg_idx2+n_z};
        const ptr_double u = { u_p + n_x*1 + n_y * xdim0_preprocessX*1 + n_z * xdim0_preprocessX * ydim0_preprocessX*1, xdim0_preprocessX, ydim0_preprocessX};
        const ptr_double v = { v_p + n_x*1 + n_y * xdim1_preprocessX*1 + n_z * xdim1_preprocessX * ydim1_preprocessX*1, xdim1_preprocessX, ydim1_preprocessX};
        const ptr_double w = { w_p + n_x*1 + n_y * xdim2_preprocessX*1 + n_z * xdim2_preprocessX * ydim2_preprocessX*1, xdim2_preprocessX, ydim2_preprocessX};
        ptr_double a = { a_p + n_x*1 + n_y * xdim4_preprocessX*1 + n_z * xdim4_preprocessX * ydim4_preprocessX*1, xdim4_preprocessX, ydim4_preprocessX};
        ptr_double b = { b_p + n_x*1 + n_y * xdim5_preprocessX*1 + n_z * xdim5_preprocessX * ydim5_preprocessX*1, xdim5_preprocessX, ydim5_preprocessX};
        ptr_double c = { c_p + n_x*1 + n_y * xdim6_preprocessX*1 + n_z * xdim6_preprocessX * ydim6_preprocessX*1, xdim6_preprocessX, ydim6_preprocessX};
        ptr_double du = { du_p + n_x*1 + n_y * xdim7_preprocessX*1 + n_z * xdim7_preprocessX * ydim7_preprocessX*1, xdim7_preprocessX, ydim7_preprocessX};
        ptr_double dv = { dv_p + n_x*1 + n_y * xdim8_preprocessX*1 + n_z * xdim8_preprocessX * ydim8_preprocessX*1, xdim8_preprocessX, ydim8_preprocessX};
        ptr_double dw = { dw_p + n_x*1 + n_y * xdim9_preprocessX*1 + n_z * xdim9_preprocessX * ydim9_preprocessX*1, xdim9_preprocessX, ydim9_preprocessX};
        ptr_double resU = { resU_p + n_x*1 + n_y * xdim10_preprocessX*1 + n_z * xdim10_preprocessX * ydim10_preprocessX*1, xdim10_preprocessX, ydim10_preprocessX};
        ptr_double resV = { resV_p + n_x*1 + n_y * xdim11_preprocessX*1 + n_z * xdim11_preprocessX * ydim11_preprocessX*1, xdim11_preprocessX, ydim11_preprocessX};
        ptr_double resW = { resW_p + n_x*1 + n_y * xdim12_preprocessX*1 + n_z * xdim12_preprocessX * ydim12_preprocessX*1, xdim12_preprocessX, ydim12_preprocessX};
        
    OPS_ACC(resU, 0, 0, 0) = 0;
    OPS_ACC(resV, 0, 0, 0) = 0;
    OPS_ACC(resW, 0, 0, 0) = 0;
    const double x{h * idx[0]};
    const double y{h * idx[1]};
    const double z{h * idx[2]};
    const double t{*time};
    if (idx[0] == 0 || idx[0] == nx - 1 || idx[1] == 0 || idx[1] == ny - 1 ||
        idx[2] == 0 || idx[2] == nz - 1) {
        OPS_ACC(a, 0, 0, 0) = 0;
        OPS_ACC(b, 0, 0, 0) = 1;
        OPS_ACC(c, 0, 0, 0) = 0;
        OPS_ACC(du, 0, 0, 0) = 2 * exp(-t / Re) * sin(x) * sin(y) * cos(z) /
                      (Re * (cos(x) * sin(y) * cos(z) + 1));
        OPS_ACC(dv, 0, 0, 0) = -2 * exp(-t / Re) * cos(x) * cos(y) * cos(z) /
                      (Re * (cos(x) * sin(y) * cos(z) + 1));
        OPS_ACC(dw, 0, 0, 0) = 2 * exp(-t / Re) * cos(x) * sin(y) * sin(z) /
                      (Re * (cos(x) * sin(y) * cos(z) + 1));
    } else {
        OPS_ACC(a, 0, 0, 0) = -r1 * OPS_ACC(u, 0, 0, 0) - r2;
        OPS_ACC(b, 0, 0, 0) = 1 + 2 * r2;
        OPS_ACC(c, 0, 0, 0) = r1 * OPS_ACC(u, 0, 0, 0) - r2;
        OPS_ACC(du, 0, 0, 0) = (r1 * OPS_ACC(v, 0, 0, 0) + r2) * OPS_ACC(u, 0, -1, 0) +
                      (-r1 * OPS_ACC(v, 0, 0, 0) + r2) * OPS_ACC(u, 0, 1, 0) +
                      (r1 * OPS_ACC(w, 0, 0, 0) + r2) * OPS_ACC(u, 0, 0, -1) +
                      (-r1 * OPS_ACC(w, 0, 0, 0) + r2) * OPS_ACC(u, 0, 0, 1) +
                      (1 - 4 * r2) * OPS_ACC(u, 0, 0, 0);
        OPS_ACC(dv, 0, 0, 0) = (r1 * OPS_ACC(v, 0, 0, 0) + r2) * OPS_ACC(v, 0, -1, 0) +
                      (-r1 * OPS_ACC(v, 0, 0, 0) + r2) * OPS_ACC(v, 0, 1, 0) +
                      (r1 * OPS_ACC(w, 0, 0, 0) + r2) * OPS_ACC(v, 0, 0, -1) +
                      (-r1 * OPS_ACC(w, 0, 0, 0) + r2) * OPS_ACC(v, 0, 0, 1) +
                      (1 - 4 * r2) * OPS_ACC(v, 0, 0, 0);
        OPS_ACC(dw, 0, 0, 0) = (r1 * OPS_ACC(v, 0, 0, 0) + r2) * OPS_ACC(w, 0, -1, 0) +
                      (-r1 * OPS_ACC(v, 0, 0, 0) + r2) * OPS_ACC(w, 0, 1, 0) +
                      (r1 * OPS_ACC(w, 0, 0, 0) + r2) * OPS_ACC(w, 0, 0, -1) +
                      (-r1 * OPS_ACC(w, 0, 0, 0) + r2) * OPS_ACC(w, 0, 0, 1) +
                      (1 - 4 * r2) * OPS_ACC(w, 0, 0, 0);
    }

      }
    }
  }
}