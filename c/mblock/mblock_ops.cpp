//
// auto-generated by ops.py
//



void ops_init_backend();
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define OPS_2D
#include  "ops_lib_core.h"

//
// ops_par_loop declarations
//

void ops_par_loop_mblock_populate_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );



//#include "mblock_populate_kernel.h"

int main(int argc, char **argv)
{


  ops_init(argc,argv,2);
  ops_init_backend();

  ops_block grid0 = ops_decl_block(2, "grid0");
  ops_block grid1 = ops_decl_block(2, "grid1");

  int s2D_00[]         = {0,0};
  ops_stencil S2D_00 = ops_decl_stencil( 2, 1, s2D_00, "00");

  int d_p[2] = {2,2};
  int d_m[2] = {-2,-2};
  int size[2] = {20, 20};
  int base[2] = {0,0};
  double* temp = NULL;

  ops_dat data0 = ops_decl_dat(grid0, 1, size, base, d_m, d_p, temp, "double", "data0");
  ops_dat data1 = ops_decl_dat(grid1, 1, size, base, d_m, d_p, temp, "double", "data1");



  ops_halo_group halos0;
  {
    int halo_iter[] = {2,20};
    int base_from[] = {18,0};
    int base_to[] = {-2,0};
    int dir[] = {1,2};
    ops_halo h0 = ops_decl_halo(data0, data1, halo_iter, base_from, base_to, dir, dir);

    base_from[0] = 0; base_to[0] = 20;
    ops_halo h1 = ops_decl_halo(data1, data0, halo_iter, base_from, base_to, dir, dir);
    ops_halo grp[] = {h0,h1};
    halos0 = ops_decl_halo_group(2,grp);

  }



  ops_halo_group halos1;
  {
    int halo_iter[] = {20,2};
    int base_from[] = {0,18};
    int base_to[] = {0,-2};
    int dir[] = {1,2};
    ops_halo h0 = ops_decl_halo(data0, data1, halo_iter, base_from, base_to, dir, dir);
    base_from[1] = 0; base_to[1] = 20;
    ops_halo h1 = ops_decl_halo(data1, data0, halo_iter, base_from, base_to, dir, dir);
    ops_halo grp[] = {h0,h1};
    halos1 = ops_decl_halo_group(2,grp);
  }


  ops_halo_group halos2;
  {
    int halo_iter[] = {2,20};
    int base_from[] = {0,0};
    int base_to[] = {20,0};
    int dir[] = {1,2};
    int dir_to[] = {1,-2};
    ops_halo h0 = ops_decl_halo(data0, data1, halo_iter, base_from, base_to, dir, dir_to);
    base_from[0] = 18; base_to[0] = -2;
    ops_halo h1 = ops_decl_halo(data1, data0, halo_iter, base_from, base_to, dir_to, dir);
    ops_halo grp[] = {h0,h1};
    halos2 = ops_decl_halo_group(2,grp);
  }


  ops_halo_group halos3;
  {
    int halo_iter[] = {20,2};
    int base_from[] = {0,0};
    int base_to[] = {0,20};
    int dir[] = {1,2};
    int dir_to[] = {-1,2};
    ops_halo h0 = ops_decl_halo(data0, data1, halo_iter, base_from, base_to, dir, dir_to);
    base_from[1] = 18; base_to[1] = -2;
    ops_halo h1 = ops_decl_halo(data1, data0, halo_iter, base_from, base_to, dir_to, dir);
    ops_halo grp[] = {h0,h1};
    halos3 = ops_decl_halo_group(2,grp);
  }


  ops_halo_group halos4;
  {
    int halo_iter[] = {2,20};
    int base_from[] = {18,0};
    int base_to[] = {0,-2};
    int dir[] = {1,2};
    int dir_to[] = {2,1};
    ops_halo h0 = ops_decl_halo(data0, data1, halo_iter, base_from, base_to, dir, dir_to);
    base_from[0] = 0; base_to[0] = 20; base_to[1] = 0;
    ops_halo h1 = ops_decl_halo(data1, data0, halo_iter, base_from, base_to, dir_to, dir);
    ops_halo grp[] = {h0,h1};
    halos4 = ops_decl_halo_group(2,grp);
  }

  ops_partition("");


  double ct0, ct1, et0, et1;
  ops_timers(&ct0, &et0);

  int iter_range[] = {0,20,0,20};
  ops_par_loop_mblock_populate_kernel("mblock_populate_kernel", grid0, 2, iter_range,
               ops_arg_dat(data0, 1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());
  ops_par_loop_mblock_populate_kernel("mblock_populate_kernel", grid1, 2, iter_range,
               ops_arg_dat(data1, 1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());

  ops_fetch_block_hdf5_file(grid0, "mblocktest.h5");
  ops_fetch_block_hdf5_file(grid1, "mblocktest.h5");

  ops_fetch_dat_hdf5_file(data0, "mblocktest.h5");
  ops_fetch_dat_hdf5_file(data1, "mblocktest.h5");

  ops_fetch_block_hdf5_file(grid0, "mblocktest0.h5");
  ops_fetch_block_hdf5_file(grid1, "mblocktest1.h5");

  ops_fetch_dat_hdf5_file(data0, "mblocktest0.h5");
  ops_fetch_dat_hdf5_file(data1, "mblocktest1.h5");

  ops_halo_transfer(halos0);
  ops_halo_transfer(halos1);
  ops_halo_transfer(halos2);
  ops_halo_transfer(halos3);
  ops_halo_transfer(halos4);
  ops_print_dat_to_txtfile(data0, "data0.txt");
  ops_print_dat_to_txtfile(data1, "data1.txt");

  ops_printf("This test is considered PASSED\n");

  ops_timers(&ct1, &et1);
  ops_timing_output(std::cout);

  ops_printf("\nTotal Wall time %lf\n",et1-et0);
  ops_printf("\nThe test is considered as PASSED!");

  ops_exit();
}
