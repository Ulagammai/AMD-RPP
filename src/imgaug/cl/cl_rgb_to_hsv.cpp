#include <cl/rpp_cl_common.hpp>
#include "cl_declarations.hpp"

RppStatus
cl_convert_rgbtohsv (    cl_mem srcPtr, RppiSize srcSize,
                            cl_mem dstPtr, 
                            RppiChnFormat chnFormat, size_t channel,
                            cl_command_queue theQueue)
{
    cl_kernel theKernel;
    cl_program theProgram;
    cl_kernel_initializer(theQueue,
                          "rgbtohsv.cl",
                          "rgbtohsv",
                          theProgram, theKernel);

    //---- Args Setter
    size_t n = srcSize.height * srcSize.width * channel ;
    clSetKernelArg(theKernel, 0, sizeof(cl_mem), &srcPtr);
    clSetKernelArg(theKernel, 1, sizeof(cl_mem), &dstPtr);
    clSetKernelArg(theKernel, 2, sizeof(size_t), &n);
    clSetKernelArg(theKernel, 3, sizeof(float), &alpha);
    clSetKernelArg(theKernel, 4, sizeof(int), &beta);
    //----


    size_t dim3[3];
    dim3[0] = srcSize.height;
    dim3[1] = srcSize.width;
    dim3[2] = channel;
    cl_kernel_implementer (theQueue, dim3, theProgram, theKernel);

    return RPP_SUCCESS;

}