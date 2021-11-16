//
// auto-generated by ops.py
//

int xdim0_generate_chunk_kernel;
int ydim0_generate_chunk_kernel;
int xdim1_generate_chunk_kernel;
int ydim1_generate_chunk_kernel;
int xdim2_generate_chunk_kernel;
int ydim2_generate_chunk_kernel;
int xdim3_generate_chunk_kernel;
int ydim3_generate_chunk_kernel;
int xdim4_generate_chunk_kernel;
int ydim4_generate_chunk_kernel;
int xdim5_generate_chunk_kernel;
int ydim5_generate_chunk_kernel;
int xdim6_generate_chunk_kernel;
int ydim6_generate_chunk_kernel;
int xdim7_generate_chunk_kernel;
int ydim7_generate_chunk_kernel;
int xdim8_generate_chunk_kernel;
int ydim8_generate_chunk_kernel;
int xdim9_generate_chunk_kernel;
int ydim9_generate_chunk_kernel;
int xdim10_generate_chunk_kernel;
int ydim10_generate_chunk_kernel;


//user function



void generate_chunk_kernel_c_wrapper(
  double * restrict vertexx_p,
  double * restrict vertexy_p,
  double * restrict vertexz_p,
  double * restrict energy0_p,
  double * restrict density0_p,
  double * restrict xvel0_p,
  double * restrict yvel0_p,
  double * restrict zvel0_p,
  double * restrict cellx_p,
  double * restrict celly_p,
  double * restrict cellz_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double vertexx = { vertexx_p + n_x*1 + n_y * xdim0_generate_chunk_kernel*0 + n_z * xdim0_generate_chunk_kernel * ydim0_generate_chunk_kernel*0, xdim0_generate_chunk_kernel, ydim0_generate_chunk_kernel};
        const ptr_double vertexy = { vertexy_p + n_x*0 + n_y * xdim1_generate_chunk_kernel*1 + n_z * xdim1_generate_chunk_kernel * ydim1_generate_chunk_kernel*0, xdim1_generate_chunk_kernel, ydim1_generate_chunk_kernel};
        const ptr_double vertexz = { vertexz_p + n_x*0 + n_y * xdim2_generate_chunk_kernel*0 + n_z * xdim2_generate_chunk_kernel * ydim2_generate_chunk_kernel*1, xdim2_generate_chunk_kernel, ydim2_generate_chunk_kernel};
        ptr_double energy0 = { energy0_p + n_x*1 + n_y * xdim3_generate_chunk_kernel*1 + n_z * xdim3_generate_chunk_kernel * ydim3_generate_chunk_kernel*1, xdim3_generate_chunk_kernel, ydim3_generate_chunk_kernel};
        ptr_double density0 = { density0_p + n_x*1 + n_y * xdim4_generate_chunk_kernel*1 + n_z * xdim4_generate_chunk_kernel * ydim4_generate_chunk_kernel*1, xdim4_generate_chunk_kernel, ydim4_generate_chunk_kernel};
        ptr_double xvel0 = { xvel0_p + n_x*1 + n_y * xdim5_generate_chunk_kernel*1 + n_z * xdim5_generate_chunk_kernel * ydim5_generate_chunk_kernel*1, xdim5_generate_chunk_kernel, ydim5_generate_chunk_kernel};
        ptr_double yvel0 = { yvel0_p + n_x*1 + n_y * xdim6_generate_chunk_kernel*1 + n_z * xdim6_generate_chunk_kernel * ydim6_generate_chunk_kernel*1, xdim6_generate_chunk_kernel, ydim6_generate_chunk_kernel};
        ptr_double zvel0 = { zvel0_p + n_x*1 + n_y * xdim7_generate_chunk_kernel*1 + n_z * xdim7_generate_chunk_kernel * ydim7_generate_chunk_kernel*1, xdim7_generate_chunk_kernel, ydim7_generate_chunk_kernel};
        const ptr_double cellx = { cellx_p + n_x*1 + n_y * xdim8_generate_chunk_kernel*0 + n_z * xdim8_generate_chunk_kernel * ydim8_generate_chunk_kernel*0, xdim8_generate_chunk_kernel, ydim8_generate_chunk_kernel};
        const ptr_double celly = { celly_p + n_x*0 + n_y * xdim9_generate_chunk_kernel*1 + n_z * xdim9_generate_chunk_kernel * ydim9_generate_chunk_kernel*0, xdim9_generate_chunk_kernel, ydim9_generate_chunk_kernel};
        const ptr_double cellz = { cellz_p + n_x*0 + n_y * xdim10_generate_chunk_kernel*0 + n_z * xdim10_generate_chunk_kernel * ydim10_generate_chunk_kernel*1, xdim10_generate_chunk_kernel, ydim10_generate_chunk_kernel};
        

  double radius, x_cent, y_cent, z_cent;
  int is_in = 0;


  OPS_ACC(energy0, 0,0,0)= states[0].energy;
  OPS_ACC(density0, 0,0,0)= states[0].density;
  OPS_ACC(xvel0, 0,0,0)=states[0].xvel;
  OPS_ACC(yvel0, 0,0,0)=states[0].yvel;
  OPS_ACC(zvel0, 0,0,0)=states[0].zvel;

  for(int i = 1; i<number_of_states; i++) {

    x_cent=states[i].xmin;
    y_cent=states[i].ymin;
    z_cent=states[i].zmin;

    if (states[i].geometry == g_cube) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            if(OPS_ACC(vertexx, 1+i1,0,0) >= states[i].xmin  && OPS_ACC(vertexx, 0+i1,0,0) < states[i].xmax) {
              if(OPS_ACC(vertexy, 0,1+j1,0) >= states[i].ymin && OPS_ACC(vertexy, 0,0+j1,0) < states[i].ymax) {
                if(OPS_ACC(vertexz, 0,0,1+k1) >= states[i].zmin && OPS_ACC(vertexz, 0,0,0+k1) < states[i].zmax) {
                  is_in=1;
                }
              }
            }
          }
        }
      }

      if(OPS_ACC(vertexx, 1,0,0) >= states[i].xmin  && OPS_ACC(vertexx, 0,0,0) < states[i].xmax) {
        if(OPS_ACC(vertexy, 0,1,0) >= states[i].ymin && OPS_ACC(vertexy, 0,0,0) < states[i].ymax) {
          if(OPS_ACC(vertexz, 0,0,1) >= states[i].zmin && OPS_ACC(vertexz, 0,0,0) < states[i].zmax) {
            OPS_ACC(energy0, 0,0,0) = states[i].energy;
            OPS_ACC(density0, 0,0,0) = states[i].density;
          }
        }
      }

      if (is_in) {
        OPS_ACC(xvel0, 0,0,0) = states[i].xvel;
        OPS_ACC(yvel0, 0,0,0) = states[i].yvel;
        OPS_ACC(zvel0, 0,0,0) = states[i].zvel;
      }
    }
    else if(states[i].geometry == g_sphe) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            radius = sqrt ((OPS_ACC(cellx, 0,0,0) - x_cent) * (OPS_ACC(cellx, 0,0,0) - x_cent) +
                     (OPS_ACC(celly, 0,0,0) - y_cent) * (OPS_ACC(celly, 0,0,0) - y_cent) +
                     (OPS_ACC(cellz, 0,0,0) - z_cent) * (OPS_ACC(cellz, 0,0,0) - z_cent));
            if(radius <= states[i].radius) is_in = 1;
          }
        }
      }
      if(radius <= states[i].radius) {
        OPS_ACC(energy0, 0,0,0) = states[i].energy;
        OPS_ACC(density0, 0,0,0) = states[i].density;
      }
      if (is_in) {
        OPS_ACC(xvel0, 0,0,0) = states[i].xvel;
        OPS_ACC(yvel0, 0,0,0) = states[i].yvel;
        OPS_ACC(zvel0, 0,0,0) = states[i].zvel;

      }
    }
    else if(states[i].geometry == g_point) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            if(OPS_ACC(vertexx, 0+i1,0,0) == x_cent && OPS_ACC(vertexy, 0,0+j1,0) == y_cent && OPS_ACC(vertexz, 0,0,0+k1) == z_cent)
              is_in = 1;
          }
        }
      }

      if(OPS_ACC(vertexx, 0,0,0) == x_cent && OPS_ACC(vertexy, 0,0,0) == y_cent && OPS_ACC(vertexz, 0,0,0) == z_cent) {
        OPS_ACC(energy0, 0,0,0) = states[i].energy;
        OPS_ACC(density0, 0,0,0) = states[i].density;
      }
      if (is_in) {
        OPS_ACC(xvel0, 0,0,0) = states[i].xvel;
        OPS_ACC(yvel0, 0,0,0) = states[i].yvel;
        OPS_ACC(zvel0, 0,0,0) = states[i].zvel;
      }
    }
  }

      }
    }
  }
}