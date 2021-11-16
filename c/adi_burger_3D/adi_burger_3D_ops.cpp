//
// auto-generated by ops.py
//


void ops_init_backend();
#include <cmath>
#include <string>
#include <vector>
#define OPS_3D
#include  "ops_lib_core.h"

//
// ops_par_loop declarations
//

void ops_par_loop_initKernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_CopyUVW(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
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
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_preprocessZ(char const *, ops_block, int , int*,
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
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );


#include "data.h"

//#include "init_kernel.h"

//#include "preproc_kernel.h"

double Re{1};

double xyzRange[2]{0, 1};
int nx{64};
int ny{nx};
int nz{nx};
double dx{(xyzRange[1] - xyzRange[0]) / (nx - 1)};
double dy{(xyzRange[1] - xyzRange[0]) / (ny - 1)};
double dz{(xyzRange[1] - xyzRange[0]) / (nz - 1)};
double h{dx};
double dt{0.0001};
double r1{dt / (4 * h)};
double r2{dt / (2 * Re * h * h)};
int iter{100};

void WriteDataToH5(const std::string &fileName, const ops_block &block,
                   const std::vector<ops_dat> &dataList) {
    ops_fetch_block_hdf5_file(block, fileName.c_str());
    for (auto data : dataList) {
        ops_fetch_dat_hdf5_file(data, fileName.c_str());
    }
}

int main(int argc, char *argv[]) {

    ops_init(argc, argv, 2);
  ops_init_backend();


    ops_block burger3D = ops_decl_block(3, "Burger3D");


    const int haloDepth{1};
    int d_p[3]{haloDepth, haloDepth, haloDepth};

    int d_m[3]{-haloDepth, -haloDepth, -haloDepth};

    int size[3]{nx, ny, nz};
    int base[3]{0, 0, 0};
    double *temp = NULL;

    ops_dat u{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "u")};
    ops_dat v{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "v")};
    ops_dat w{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "w")};

    ops_dat uStar{ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp,
                               "double", "uStar")};
    ops_dat vStar{ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp,
                               "double", "vStar")};
    ops_dat wStar{ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp,
                               "double", "wStar")};

    ops_dat a{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "a")};
    ops_dat b{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "b")};
    ops_dat c{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "c")};

    ops_dat du{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "du")};
    ops_dat dv{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "dv")};
    ops_dat dw{
        ops_decl_dat(burger3D, 1, size, base, d_m, d_p, temp, "double", "dw")};

    const std::vector<ops_dat> resList{u, v, w};
    const std::vector<ops_dat> debugList{u,     v,     w,     du, dv, dw,
                                         uStar, vStar, wStar, a,  b,  c};

    int s3D_000[]{0, 0, 0};
    ops_stencil S3D_000{ops_decl_stencil(3, 1, s3D_000, "000")};

    int s3D_7pt[]{0, 0, 0, -1, 0, 0, 1,  0, 0, 0, -1,
                  0, 0, 1, 0,  0, 0, -1, 0, 0, 1};
    ops_stencil S3D_7PT{ops_decl_stencil(3, 7, s3D_7pt, "3d7Point")};
    int iterRange[]{0, nx, 0, ny, 0, nz};

      ops_decl_const2( "nx",1, "int",&nx);
      ops_decl_const2( "ny",1, "int",&ny);
      ops_decl_const2( "nz",1, "int",&nz);
      ops_decl_const2( "Re",1, "double",&Re);
      ops_decl_const2( "h",1, "double",&h);
      ops_decl_const2( "r1",1, "double",&r1);
      ops_decl_const2( "r2",1, "double",&r2);

    ops_partition("BurgersEquation3D");

    double ct0, ct1, et0, et1, ct2, et2, ct3, et3;
    double totalPreprocX{0}, totalPreprocY{0}, totalPreprocZ{0}, totalX{0},
        totalY{0}, totalZ{0};

    ops_printf("\nNumber of iterations: %d\n", iter);
    ops_printf("\nGrid dimensions: %d x %d x %d\n", nx, ny, nz);
    ops_printf("\nh=%f r1=%f r2=%f\n", h, r1, r2);
    printf("\nLocal dimensions at rank %d: %d x %d x %d\n", ops_get_proc(),
           u->size[0], u->size[1], u->size[2]);
    ops_diagnostic_output();


    ops_par_loop_initKernel("initKernel", burger3D, 3, iterRange,
                 ops_arg_dat(u, 1, S3D_000, "double", OPS_WRITE),
                 ops_arg_dat(v, 1, S3D_000, "double", OPS_WRITE),
                 ops_arg_dat(w, 1, S3D_000, "double", OPS_WRITE),
                 ops_arg_idx());

    ops_tridsolver_params *trid_ctx = new ops_tridsolver_params(burger3D);

    ops_timers(&ct0, &et0);
    for (int it = 1; it <= iter; it++) {
        double time{it * dt};

        ops_par_loop_CopyUVW("CopyUVW", burger3D, 3, iterRange,
                     ops_arg_dat(u, 1, S3D_000, "double", OPS_READ),
                     ops_arg_dat(v, 1, S3D_000, "double", OPS_READ),
                     ops_arg_dat(w, 1, S3D_000, "double", OPS_READ),
                     ops_arg_dat(uStar, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(vStar, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(wStar, 1, S3D_000, "double", OPS_WRITE));

        ops_timers(&ct2, &et2);
        ops_par_loop_preprocessX("preprocessX", burger3D, 3, iterRange,
                     ops_arg_dat(uStar, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_dat(vStar, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_dat(wStar, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_gbl(&time, 1, "double", OPS_READ),
                     ops_arg_dat(a, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(b, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(c, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(du, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(dv, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(dw, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(u, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(v, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(w, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_idx());
        ops_timers(&ct3, &et3);
        totalPreprocX += et3 - et2;



        ops_timers(&ct2, &et2);
        ops_tridMultiDimBatch_Inc(3, 0, size, a, b, c, du, u, trid_ctx);
        ops_tridMultiDimBatch_Inc(3, 0, size, a, b, c, dv, v, trid_ctx);
        ops_tridMultiDimBatch_Inc(3, 0, size, a, b, c, dw, w, trid_ctx);
        ops_timers(&ct3, &et3);
        totalX += et3 - et2;


        ops_timers(&ct2, &et2);
        ops_par_loop_preprocessY("preprocessY", burger3D, 3, iterRange,
                     ops_arg_dat(u, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_dat(v, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_dat(w, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_gbl(&time, 1, "double", OPS_READ),
                     ops_arg_dat(a, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(b, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(c, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(du, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(dv, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(dw, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(uStar, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(vStar, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(wStar, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_idx());
        ops_timers(&ct3, &et3);
        totalPreprocY += et3 - et2;


        ops_timers(&ct2, &et2);
        ops_tridMultiDimBatch_Inc(3, 1, size, a, b, c, du, uStar, trid_ctx);
        ops_tridMultiDimBatch_Inc(3, 1, size, a, b, c, dv, vStar, trid_ctx);
        ops_tridMultiDimBatch_Inc(3, 1, size, a, b, c, dw, wStar, trid_ctx);
        ops_timers(&ct3, &et3);
        totalY += et3 - et2;


        ops_timers(&ct2, &et2);
        ops_par_loop_preprocessZ("preprocessZ", burger3D, 3, iterRange,
                     ops_arg_dat(uStar, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_dat(vStar, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_dat(wStar, 1, S3D_7PT, "double", OPS_READ),
                     ops_arg_gbl(&time, 1, "double", OPS_READ),
                     ops_arg_dat(a, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(b, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(c, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(du, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(dv, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(dw, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(u, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(v, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_dat(w, 1, S3D_000, "double", OPS_WRITE),
                     ops_arg_idx());
        ops_timers(&ct3, &et3);
        totalPreprocZ += et3 - et2;



        ops_timers(&ct2, &et2);
        ops_tridMultiDimBatch_Inc(3, 2, size, a, b, c, du, u, trid_ctx);
        ops_tridMultiDimBatch_Inc(3, 2, size, a, b, c, dv, v, trid_ctx);
        ops_tridMultiDimBatch_Inc(3, 2, size, a, b, c, dw, w, trid_ctx);
        ops_timers(&ct3, &et3);
        totalZ += et3 - et2;

    }
    ops_timers(&ct1, &et1);

    delete trid_ctx;

    const double time{iter * dt};
    double uSqrSum, vSqrSum, wSqrSum, uDiffSqrSum, vDiffSqrSum, wDiffSqrSum;
    ops_reduction uSqr;





















    WriteDataToH5("Burger3DRes.h5", burger3D, resList);
    ops_printf("\nTotal Wall time (s): %lf\n", et1 - et0);
    ops_printf("Preproc total time at X (s): %lf\n", totalPreprocX);
    ops_printf("Preproc total time at Y (s): %lf\n", totalPreprocY);
    ops_printf("Preproc total time at Z (s): %lf\n", totalPreprocZ);
    ops_printf("X Dim total time (s): %lf\n", totalX);
    ops_printf("Y Dim total time (s): %lf\n", totalY);
    ops_printf("Z Dim total time (s): %lf\n", totalZ);



    ops_exit();
}
