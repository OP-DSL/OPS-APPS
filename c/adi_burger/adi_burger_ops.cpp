//
// auto-generated by ops.py
//


void ops_init_backend();
#include <cmath>

#define OPS_2D

#include "data.h"
#include  "ops_lib_core.h"

//
// ops_par_loop declarations
//

void ops_par_loop_initKernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_preprocessX(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_preprocessY(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );


//#include "init_kernel.h"
//#include "preproc_kernel.h"


double Re{100};

double xyRange[2]{0, 1};
int nx{256};
int ny{nx};
double dx{(xyRange[1] - xyRange[0]) / (nx - 1)};
double dy{(xyRange[1] - xyRange[0]) / (ny - 1)};
double h{dx};
double dt{0.0001};
double r1{dt / (4 * h)};
double r2{dt / (2 * Re * h * h)};
int iter{1};
int main(int argc, const char **argv) {


    ops_init(argc, argv, 2);
  ops_init_backend();


    ops_block burger2D = ops_decl_block(2, "Burger2D");

    const int haloDepth{1};


    int d_p[2]{haloDepth, haloDepth};

    int d_m[2]{-haloDepth, -haloDepth};

    int size[2]{nx, ny};
    int pads[2]{nx, ny};
    int base[2]{0, 0};
    double *temp{nullptr};

    ops_dat u{
        ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp, "double", "u")};
    ops_dat uStar{ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp,
                               "double", "uStar")};
    ops_dat v{
        ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp, "double", "v")};
    ops_dat vStar{ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp,
                               "double", "vStar")};
    ops_dat a{
        ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp, "double", "a")};

    ops_dat b{
        ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp, "double", "b")};

    ops_dat c{
        ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp, "double", "c")};

    ops_dat du{
        ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp, "double", "du")};
    ops_dat dv{
        ops_decl_dat(burger2D, 1, size, base, d_m, d_p, temp, "double", "dv")};

    int s2D_00[]{0, 0};
    ops_stencil S2D_00{ops_decl_stencil(2, 1, s2D_00, "00")};

    int s2D_5pt[]{0, 0, 1, 0, -1, 0, 0, 1, 0, -1};
    ops_stencil S2D_5PT{ops_decl_stencil(2, 5, s2D_5pt, "2d5Point")};

      ops_decl_const2( "nx",1, "int",&nx);
      ops_decl_const2( "ny",1, "int",&ny);
      ops_decl_const2( "Re",1, "double",&Re);
      ops_decl_const2( "h",1, "double",&h);
      ops_decl_const2( "r1",1, "double",&r1);
      ops_decl_const2( "r2",1, "double",&r2);

    ops_partition("2D_BLOCK_DECOMPSE");

    double ct0, ct1, et0, et1, ct2, et2, ct3, et3;

    ops_printf("\nGrid dimensions: %d x %d\n", nx, ny);
    ops_diagnostic_output();

    int iterRange[]{0, nx, 0, ny};









    ops_par_loop_initKernel("initKernel", burger2D, 2, iterRange,
                 ops_arg_dat(u, 1, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(v, 1, S2D_00, "double", OPS_WRITE),
                 ops_arg_idx());
    ops_fetch_block_hdf5_file(burger2D, "adi_burger2D_init.h5");
    ops_fetch_dat_hdf5_file(u, "adi_burger2D_init.h5");
    ops_fetch_dat_hdf5_file(v, "adi_burger2D_init.h5");

    ops_timers(&ct0, &et0);

    ops_tridsolver_params *trid_ctx = new ops_tridsolver_params(burger2D);

    for (int it = 1; it <= iter; it++) {
        double time{it * dt};
        ops_timers(&ct2, &et2);
        ops_par_loop_preprocessX("preprocessX", burger2D, 2, iterRange,
                     ops_arg_dat(u, 1, S2D_5PT, "double", OPS_READ),
                     ops_arg_dat(v, 1, S2D_5PT, "double", OPS_READ),
                     ops_arg_gbl(&time, 1, "double", OPS_READ),
                     ops_arg_dat(a, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(b, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(c, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(du, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(dv, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(uStar, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(vStar, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_idx());
        ops_timers(&ct3, &et3);
        ops_printf("Elapsed preproc X (sec): %lf (s)\n", et3 - et2);
        ops_fetch_block_hdf5_file(burger2D, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(u, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(v, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(a, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(b, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(c, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(du, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(dv, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(uStar, "adi_burger2D_proc.h5");
        ops_fetch_dat_hdf5_file(vStar, "adi_burger2D_proc.h5");

        ops_timers(&ct2, &et2);
        ops_tridMultiDimBatch_Inc(2, 0, size, a, b, c, du, uStar, trid_ctx);
        ops_tridMultiDimBatch_Inc(2, 0, size, a, b, c, dv, vStar, trid_ctx);
        ops_fetch_block_hdf5_file(burger2D, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(u, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(v, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(a, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(b, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(c, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(du, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(dv, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(uStar, "adi_burger2D_X.h5");
        ops_fetch_dat_hdf5_file(vStar, "adi_burger2D_X.h5");
        ops_timers(&ct3, &et3);
        ops_printf("Elapsed trid_x (sec): %lf (s)\n", et3 - et2);

        ops_timers(&ct2, &et2);
        ops_par_loop_preprocessY("preprocessY", burger2D, 2, iterRange,
                     ops_arg_dat(uStar, 1, S2D_5PT, "double", OPS_READ),
                     ops_arg_dat(vStar, 1, S2D_5PT, "double", OPS_READ),
                     ops_arg_gbl(&time, 1, "double", OPS_READ),
                     ops_arg_dat(a, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(b, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(c, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(du, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(dv, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(u, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_dat(v, 1, S2D_00, "double", OPS_WRITE),
                     ops_arg_idx());
        ops_timers(&ct3, &et3);
        ops_printf("Elapsed preproc Y (sec): %lf (s)\n", et3 - et2);

        ops_timers(&ct2, &et2);
        ops_tridMultiDimBatch_Inc(2, 1, size, a, b, c, du, u, trid_ctx);
        ops_tridMultiDimBatch_Inc(2, 1, size, a, b, c, dv, v, trid_ctx);
        ops_timers(&ct3, &et3);
        ops_printf("Elapsed trid_y (sec): %lf (s)\n", et3 - et2);
        ops_printf("Finish time=%lf\n", time);
    }

    delete trid_ctx;

    ops_timers(&ct1, &et1);

    ops_fetch_block_hdf5_file(burger2D, "adi_burger2D.h5");
    ops_fetch_dat_hdf5_file(u, "adi_burger2D.h5");
    ops_fetch_dat_hdf5_file(v, "adi_burger2D.h5");

    ops_printf("\nTotal Wall time %lf\n", et1 - et0);
    ops_exit();
}