#include <rppdefs.h>
#include <rppi_image_augumentation_functions.h>

//#include "cpu/host_rgb2hsv.hpp"

#include <iostream>
#ifdef HIP_COMPILE
#include <hip/rpp_hip_common.hpp>
#include "hip/hip_brightness_contrast.hpp"
#elif defined(OCL_COMPILE)
#include <cl/rpp_cl_common.hpp>
#include "cl/cl_declarations.hpp"
#endif //backend

/*RppStatus
rppi_rgb2hsv_3C8U_pln_host(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr)
{

    host_rgb2hsv<Rpp8u>(static_cast<Rpp8u*>(srcPtr), srcSize,
                                    static_cast<Rpp8u*>(dstPtr));
    return RPP_SUCCESS;

}*/

RppStatus
rppi_hsv2rgb_3C8U_pln(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr,  RppHandle_t rppHandle)
{
    #ifdef HIP_COMPILE
   /*Still needs to be implemented*/

    #elif defined (OCL_COMPILE)

    cl_convert_hsv2rgb(   static_cast<cl_mem>(srcPtr), srcSize,
                            static_cast<cl_mem>(dstPtr),
                            RPPI_CHN_PLANAR, 3 /*Channel*/,
                            static_cast<cl_command_queue>(rppHandle));

    #endif //backend
    
    return RPP_SUCCESS;

}