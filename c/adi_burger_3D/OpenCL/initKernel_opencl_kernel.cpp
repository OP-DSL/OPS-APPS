//
// auto-generated by ops.py
//

    #ifdef OCL_FMA_SWITCH_ON
    #define OCL_FMA 1
    #else
    #define OCL_FMA 0
    #endif


    static bool isbuilt_initKernel = false;

    void buildOpenCLKernels_initKernel(OPS_instance *instance, int xdim0, int ydim0, int xdim1, int ydim1, int xdim2, int ydim2) {

      //int ocl_fma = OCL_FMA;
      if(!isbuilt_initKernel) {
        buildOpenCLKernels(instance);
        //clSafeCall( clUnloadCompiler() );
        cl_int ret;
        char* source_filename[1] = {(char*)"./OpenCL/initKernel.cl"};

        // Load the kernel source code into the array source_str
        FILE *fid;
        char *source_str[1] = {NULL};
        size_t source_size[1];

        for(int i=0; i<1; i++) {
          fid = fopen(source_filename[i], "r");
          if (!fid) {
            OPSException e(OPS_RUNTIME_ERROR, "Can't open the kernel source file: ");
            e << source_filename[i] << "\n";
            throw e;
          }

          source_str[i] = (char*)malloc(4*0x1000000);
          source_size[i] = fread(source_str[i], 1, 4*0x1000000, fid);
          if(source_size[i] != 4*0x1000000) {
            if (ferror(fid)) {
              OPSException e(OPS_RUNTIME_ERROR, "Error while reading kernel source file ");
              e << source_filename[i] << "\n";
              throw e;
            }
            if (feof(fid))
              instance->ostream() << "Kernel source file "<< source_filename[i] <<" succesfully read.\n";
          }
          fclose(fid);
        }

        instance->ostream() <<"Compiling initKernel "<<OCL_FMA<<" source -- start \n";

          // Create a program from the source
          instance->opencl_instance->OPS_opencl_core.program = clCreateProgramWithSource(instance->opencl_instance->OPS_opencl_core.context, 1, (const char **) &source_str, (const size_t *) &source_size, &ret);
          clSafeCall( ret );

          // Build the program
          char buildOpts[255*4];
          char* pPath = NULL;
          pPath = getenv ("OPS_INSTALL_PATH");
          if (pPath!=NULL)
            if(OCL_FMA)
              sprintf(buildOpts,"-cl-mad-enable -DOCL_FMA -I%s/include -DOPS_WARPSIZE=%d  -Dxdim0_initKernel=%d  -Dydim0_initKernel=%d  -Dxdim1_initKernel=%d  -Dydim1_initKernel=%d  -Dxdim2_initKernel=%d  -Dydim2_initKernel=%d ", pPath, 32,xdim0,ydim0,xdim1,ydim1,xdim2,ydim2);
            else
              sprintf(buildOpts,"-cl-mad-enable -I%s/include -DOPS_WARPSIZE=%d  -Dxdim0_initKernel=%d  -Dydim0_initKernel=%d  -Dxdim1_initKernel=%d  -Dydim1_initKernel=%d  -Dxdim2_initKernel=%d  -Dydim2_initKernel=%d ", pPath, 32,xdim0,ydim0,xdim1,ydim1,xdim2,ydim2);
          else {
            sprintf((char*)"Incorrect OPS_INSTALL_PATH %s\n",pPath);
            exit(EXIT_FAILURE);
          }

          #ifdef OPS_SOA
          sprintf(buildOpts, "%s -DOPS_SOA", buildOpts);
          #endif
          sprintf(buildOpts, "%s -I%s/c/include", buildOpts, pPath);
          ret = clBuildProgram(instance->opencl_instance->OPS_opencl_core.program, 1, &instance->opencl_instance->OPS_opencl_core.device_id, buildOpts, NULL, NULL);

          if(ret != CL_SUCCESS) {
            char* build_log;
            size_t log_size;
            clSafeCall( clGetProgramBuildInfo(instance->opencl_instance->OPS_opencl_core.program, instance->opencl_instance->OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size) );
            build_log = (char*) malloc(log_size+1);
            clSafeCall( clGetProgramBuildInfo(instance->opencl_instance->OPS_opencl_core.program, instance->opencl_instance->OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL) );
            build_log[log_size] = '\0';
            instance->ostream() << "=============== OpenCL Program Build Info ================\n\n" << build_log;
            instance->ostream() << "\n========================================================= \n";
            free(build_log);
            exit(EXIT_FAILURE);
          }
          instance->ostream() << "compiling initKernel -- done\n";

        // Create the OpenCL kernel
        instance->opencl_instance->OPS_opencl_core.kernel[0] = clCreateKernel(instance->opencl_instance->OPS_opencl_core.program, "ops_initKernel", &ret);
        clSafeCall( ret );

        isbuilt_initKernel = true;
        free(source_str[0]);
      }

    }

    
// host stub function
void ops_par_loop_initKernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[4] = { arg0, arg1, arg2, arg3};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,4,range,0)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,0,"initKernel");
    block->instance->OPS_kernels[0].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<3; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) start[n] = range[2*n];
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      end[n] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  int arg_idx[3];
  #ifdef OPS_MPI
  arg_idx[0] = sb->decomp_disp[0]+start[0];
  arg_idx[1] = sb->decomp_disp[1]+start[1];
  arg_idx[2] = sb->decomp_disp[2]+start[2];
  #else
  arg_idx[0] = start[0];
  arg_idx[1] = start[1];
  arg_idx[2] = start[2];
  #endif

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];

  //build opencl kernel if not already built

  buildOpenCLKernels_initKernel(block->instance,
  xdim0,ydim0,xdim1,ydim1,xdim2,ydim2);

  //set up OpenCL thread blocks
  size_t globalWorkSize[3] = {((x_size-1)/block->instance->OPS_block_size_x+ 1)*block->instance->OPS_block_size_x, ((y_size-1)/block->instance->OPS_block_size_y + 1)*block->instance->OPS_block_size_y, ((z_size-1)/block->instance->OPS_block_size_z+ 1)*block->instance->OPS_block_size_z};
  size_t localWorkSize[3] =  {block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z};






  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif
  int base0 = 1 *1*
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  base0 = base0 + args[0].dat->size[0] *1*
  (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - d_m[1]);
  base0 = base0 + args[0].dat->size[0] *1*  args[0].dat->size[1] *1*
  (start[2] * args[0].stencil->stride[2] - args[0].dat->base[2] - d_m[2]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif
  int base1 = 1 *1*
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  base1 = base1 + args[1].dat->size[0] *1*
  (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - d_m[1]);
  base1 = base1 + args[1].dat->size[0] *1*  args[1].dat->size[1] *1*
  (start[2] * args[1].stencil->stride[2] - args[1].dat->base[2] - d_m[2]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif
  int base2 = 1 *1*
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  base2 = base2 + args[2].dat->size[0] *1*
  (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - d_m[1]);
  base2 = base2 + args[2].dat->size[0] *1*  args[2].dat->size[1] *1*
  (start[2] * args[2].stencil->stride[2] - args[2].dat->base[2] - d_m[2]);


  ops_H_D_exchanges_device(args, 4);
  ops_halo_exchanges(args,4,range);
  ops_H_D_exchanges_device(args, 4);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[0].mpi_time += t2-t1;
  }

  if (globalWorkSize[0]>0 && globalWorkSize[1]>0 && globalWorkSize[2]>0) {

    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 0, sizeof(cl_mem), (void*) &arg0.data_d ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 1, sizeof(cl_mem), (void*) &arg1.data_d ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 2, sizeof(cl_mem), (void*) &arg2.data_d ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 3, sizeof(cl_double), (void*) &Re ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 4, sizeof(cl_double), (void*) &h ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 5, sizeof(cl_int), (void*) &base0 ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 6, sizeof(cl_int), (void*) &base1 ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 7, sizeof(cl_int), (void*) &base2 ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 8, sizeof(cl_int), (void*) &arg_idx[0] ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 9, sizeof(cl_int), (void*) &arg_idx[1] ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 10, sizeof(cl_int), (void*) &arg_idx[2] ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 11, sizeof(cl_int), (void*) &x_size ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 12, sizeof(cl_int), (void*) &y_size ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[0], 13, sizeof(cl_int), (void*) &z_size ));

    //call/enqueue opencl kernel wrapper function
    clSafeCall( clEnqueueNDRangeKernel(block->instance->opencl_instance->OPS_opencl_core.command_queue, block->instance->opencl_instance->OPS_opencl_core.kernel[0], 3, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL) );
  }
  if (block->instance->OPS_diags>1) {
    clSafeCall( clFinish(block->instance->opencl_instance->OPS_opencl_core.command_queue) );
  }

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[0].time += t1-t2;
  }

  ops_set_dirtybit_device(args, 4);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[0].mpi_time += t2-t1;
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}
