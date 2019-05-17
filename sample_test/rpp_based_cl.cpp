//==============================================================================
// Only compiled with hipcc compiler
//==============================================================================

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <CL/cl.hpp>
#include <rpp.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


#define CL_USE_DEPRECATED_OPENCL_1_2_APIS


template<typename T> // pointer type
void print3d_pkd(T matrix, size_t height, size_t width, size_t channel = 1)
{
    std::cout << std::endl;

    for(size_t i=0; i<height; i++ ){
        for(size_t j=0; j<width; j++ ){
            std::cout << "[";
            for(size_t k=0; k<channel; k++ ){
                std::cout << (unsigned int)( matrix[ k + j*channel + i*width*channel] );
                if (channel-1-k) std::cout << " ,";
            }
            std::cout << "]\t" ;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T> // pointer type
void print3d_pln(T matrix, size_t height, size_t width, size_t channel = 1)
{
    std::cout << std::endl;
    for(size_t k=0; k<channel; k++ ){
        std::cout << "[" << std::endl;
        for(size_t i=0; i<height; i++ ){
            for(size_t j=0; j<width; j++ ){
                std::cout << (unsigned int)( matrix[ j + i*width + k*width*height ] ) << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << "]" << std::endl;
        std::cout << std::endl;
    }
}




int main( int argc, char* argv[] )
{
    typedef unsigned char TYPE_t;
    TYPE_t* h_a;
    TYPE_t* h_c;
    int height =500;
    int width = 400;
    int channel = 3;

    h_a = stbi_load( "/home/neel/Lokesh/images/violet_3c.png",
                        &width, &height, &channel, 0);

    size_t n = height * width * channel;
    size_t bytes = n*sizeof(TYPE_t);
    //h_a = (TYPE_t*)malloc(bytes);
    h_c = (TYPE_t*)malloc(bytes);

    std::cout << "width:" << width << std::endl;
    std::cout << "height:" << height << std::endl;
    std::cout << "channel:" << channel << std::endl;

    // for( int i = 0; i < n; i++ )
    // {
    //     h_a[i] = i;
    // }
    // print3d_pkd(h_a, height,width,channel);


    TYPE_t* h_f;
    size_t f_bytes = 3*3*sizeof(TYPE_t);
    h_f = (TYPE_t*)malloc(f_bytes);
    for( int i = 0; i < 9; i++ )
    {
        h_f[i] = 1;
    }


//------ CL Alloc Stuffs
    cl_mem d_a;
    cl_platform_id platform_id;        // OpenCL platform
    cl_device_id device_id;           // device ID
    cl_mem d_c;
    cl_context theContext;               // theContext
    cl_command_queue theQueue;           // command theQueue
    cl_program theProgram;               // theProgram
    cl_kernel theKernel;                 // theKernel

    cl_int err;
    err = clGetPlatformIDs(1, &platform_id, NULL);
    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
    theContext = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    theQueue = clCreateCommandQueue(theContext, device_id, 0, &err);


    d_a = clCreateBuffer(theContext, CL_MEM_READ_ONLY, bytes, NULL, NULL);
    d_c = clCreateBuffer(theContext, CL_MEM_WRITE_ONLY, bytes, NULL, NULL);

    err = clEnqueueWriteBuffer(theQueue, d_a, CL_TRUE, 0,
                                   bytes, h_a, 0, NULL, NULL);

    cl_mem d_f;
    d_f = clCreateBuffer(theContext, CL_MEM_READ_ONLY, f_bytes, NULL, NULL);
    err = clEnqueueWriteBuffer(theQueue, d_f, CL_TRUE, 0,
                                   f_bytes, h_f, 0, NULL, NULL);

//----------

    // size_t dim3[3];
    // dim3[0] = width; dim3[1] = height; dim3[2] = channel;

    // cl_kernel_initializer(theQueue, "gaussian_gen.cl", "gaussian_gen", theProgram, theKernel);


    // err  = clSetKernelArg(theKernel, 0, sizeof(cl_mem), &d_a);
    // err |= clSetKernelArg(theKernel, 1, sizeof(cl_mem), &d_c);
    // err |= clSetKernelArg(theKernel, 2, sizeof(cl_mem), &d_f);
    // err |= clSetKernelArg(theKernel, 3, sizeof(size_t), &height);
    // err |= clSetKernelArg(theKernel, 4, sizeof(size_t), &width);
    // err |= clSetKernelArg(theKernel, 5, sizeof(size_t), &channel);

    // cl_kernel_implementer (theQueue, dim3, NULL, theProgram, theKernel);

// ------

    Rpp32f alpha=2;
    Rpp32s beta=1;

    RppiSize srcSize;
    srcSize.height=height;
    srcSize.width=width;

    //rppi_blur3x3_3C8U_pkd(d_a, srcSize, d_c, theQueue);

    //rppi_contrast_3C8U_pkd(d_a, srcSize, d_c, 50, 200, theQueue);
    //rppi_flip_3C8U_pln(d_a, srcSize, d_c, RPPI_HORIZONTAL_AXIS, theQueue);
    rppi_flip_u8_pkd3_gpu(d_a, srcSize, d_c, RPPI_VERTICAL_AXIS, theQueue);

    clEnqueueReadBuffer(theQueue, d_c, CL_TRUE, 0,
                                bytes, h_c, 0, NULL, NULL );

    //print3d_pkd(h_c, height,width,channel);

    stbi_write_png("/home/neel/Lokesh/images/output_image_flipV.png",
                            width, height, channel, h_c, width*channel);

    
    rppi_flip_u8_pkd3_gpu(d_a, srcSize, d_c, RPPI_HORIZONTAL_AXIS, theQueue);

    clEnqueueReadBuffer(theQueue, d_c, CL_TRUE, 0,
                                bytes, h_c, 0, NULL, NULL );

    //print3d_pkd(h_c, height,width,channel);

    stbi_write_png("/home/neel/Lokesh/images/output_image_flipH.png",
                            width, height, channel, h_c, width*channel);
    
    rppi_brightness_u8_pkd3_gpu(d_a, srcSize, d_c, 1.0, 30, theQueue);

    clEnqueueReadBuffer(theQueue, d_c, CL_TRUE, 0,
                                bytes, h_c, 0, NULL, NULL );

    //print3d_pkd(h_c, height,width,channel);

    stbi_write_png("/home/neel/Lokesh/images/output_image_bright.png",
                            width, height, channel, h_c, width*channel);
    

    rppi_contrast_u8_pkd3_gpu(d_a, srcSize, d_c, 25, 200, theQueue);

    clEnqueueReadBuffer(theQueue, d_c, CL_TRUE, 0,
                                bytes, h_c, 0, NULL, NULL );

    //print3d_pkd(h_c, height,width,channel);

    stbi_write_png("/home/neel/Lokesh/images/output_image_contrast.png",
                            width, height, channel, h_c, width*channel);
    

    rppi_blur3x3_u8_pkd3_gpu(d_a, srcSize, d_c, theQueue);

    clEnqueueReadBuffer(theQueue, d_c, CL_TRUE, 0,
                                bytes, h_c, 0, NULL, NULL );

    //print3d_pkd(h_c, height,width,channel);

    stbi_write_png("/home/neel/Lokesh/images/output_image_blur.png",
                            width, height, channel, h_c, width*channel);
    
    
    
    
    

    clReleaseMemObject(d_a);
    clReleaseMemObject(d_c);

    clReleaseMemObject(d_f);

    clReleaseCommandQueue(theQueue);
    clReleaseContext(theContext);

    free(h_a);
    free(h_c);

    return 0;
}
