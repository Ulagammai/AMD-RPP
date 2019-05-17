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


// cl_int
// cl_kernel_initializer ( cl_command_queue theQueue,
//                         std::string kernelFile, std::string kernelName,
//                         cl_program& theProgram, cl_kernel& theKernel)
// {
//     cl_int err;
//     // File Handling
//     char *sourceStr;
//     size_t sourceSize;
//     std::string kernelFile_cl = kernelFile;
//     std::cout << kernelFile_cl;
//     FILE *filePtr = fopen( kernelFile_cl.c_str(), "rb");
//     if (!filePtr) {
//         fprintf(stderr, "Failed to load kernel.\n");
//         return 1;
//     }
//     fseek(filePtr, 0, SEEK_END);
//     size_t fileSize = ftell(filePtr);
//     rewind(filePtr);
//     sourceStr = (char*)malloc(fileSize + 1);
//     sourceStr[fileSize] = '\0';
//     fread(sourceStr, sizeof(char), fileSize, filePtr);
//     fclose(filePtr);

//     cl_context theContext;
//     clGetCommandQueueInfo(  theQueue,
//                             CL_QUEUE_CONTEXT,
//                             sizeof(cl_context), &theContext, NULL);
//     cl_device_id theDevice;
//     clGetCommandQueueInfo(  theQueue,
//                             CL_QUEUE_DEVICE, sizeof(cl_device_id), &theDevice, NULL);


//     theProgram = clCreateProgramWithSource(theContext, 1,
//                             (const char **)& sourceStr, NULL, &err);

//     clBuildProgram(theProgram, 0, NULL, NULL, NULL, NULL);
//     theKernel = clCreateKernel(theProgram, kernelName.c_str(), &err);

// }

// cl_int
// cl_kernel_implementer (cl_command_queue theQueue, size_t* globalDim3, size_t* localDim3,
//                         cl_program& theProgram, cl_kernel& theKernel  )
// {
//     cl_int err;

//     err = clEnqueueNDRangeKernel(theQueue, theKernel, 3, NULL, globalDim3, localDim3,
//                                                               0, NULL, NULL);
//     clFinish(theQueue);
//     clReleaseProgram(theProgram);
//     clReleaseKernel(theKernel);
//     return err;
// }


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
    h_c = (TYPE_t*)malloc(bytes);

    std::cout << "width:" << width << std::endl;
    std::cout << "height:" << height << std::endl;
    std::cout << "channel:" << channel << std::endl;

    
    TYPE_t* h_f;
    size_t f_bytes = 3*3*sizeof(TYPE_t);
    h_f = (TYPE_t*)malloc(f_bytes);
    for( int i = 0; i < 9; i++ )
    {
        h_f[i] = 1;
    }



    

    Rpp32f alpha=2;
    Rpp32s beta=1;

    RppiSize srcSize;
    srcSize.height=height;
    srcSize.width=width;

    //rppi_blur3x3_3C8U_pkd(h_a, srcSize, h_c);

    //rppi_contrast_3C8U_pkd(h_a, srcSize, h_c, 50, 200);
    //rppi_flip_3C8U_pln(h_a, srcSize, h_c, RPPI_HORIZONTAL_AXIS);
    rppi_flip_u8_pkd3_host(h_a, srcSize, h_c, RPPI_VERTICAL_AXIS);

    
    //print3d_pkd(h_c, height,width,channel);

    stbi_write_png("/home/neel/Lokesh/images/output_host_image_flipV.png",
                            width, height, channel, h_c, width*channel);

    
    rppi_flip_u8_pkd3_host(h_a, srcSize, h_c, RPPI_HORIZONTAL_AXIS);

    

    stbi_write_png("/home/neel/Lokesh/images/output_host_image_flipH.png",
                            width, height, channel, h_c, width*channel);
    
    rppi_brightness_u8_pkd3_host(h_a, srcSize, h_c, 1.0, 30);

    

    stbi_write_png("/home/neel/Lokesh/images/output_host_image_bright.png",
                            width, height, channel, h_c, width*channel);
    

    rppi_contrast_u8_pkd3_host(h_a, srcSize, h_c, 25, 200);

    
    //print3d_pkd(h_c, height,width,channel);

    stbi_write_png("/home/neel/Lokesh/images/output_host_image_contrast.png",
                            width, height, channel, h_c, width*channel);
    

    rppi_blur3x3_u8_pkd3_host(h_a, srcSize, h_c);

    //print3d_pkd(h_c, height,width,channel);

    stbi_write_png("/home/neel/Lokesh/images/output_host_image_blur.png",
                            width, height, channel, h_c, width*channel);
    
    
    

    free(h_a);
    free(h_c);

    return 0;
}
