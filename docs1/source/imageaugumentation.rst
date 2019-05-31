Image Augumentation Functions
=============================
 
RPPDataType_t
-------------

  RppiSize- Size 

RPPBrightness
-------------

 
  Brightens the image using RPP brightness Modification function.

rppi_brightness_u8(RppPtr_t srcPtr, RppiSize srcSize,RppPtr_t dstPtr, Rpp32f alpha, Rpp32s beta,RppHandle_t handle )


   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl
              buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize- KernelSize.
   - dstPtr - output image pointer of the same size and type as src.
   - alpha  - simple Contrast control.
   - beta   - simple Brightness control.
   - RppHandle_t handle - It contains the Miscellanous function like command Queue.


RPPContrast
-----------

  Adding Contrast to the image using RPP Contrast Modification Functions

rppi_contrast_u8(RppPtr_t srcPtr, RppiSize srcSize,RppPtr_t dstPtr,Rpp32u new_min = 0, Rpp32u new_max = 225)

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl
              buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize- KernelSize.
   - dstPtr - output image pointer of the same size and type as src.
   - new_min- Minimum value for contrast function(0)
   - new_max- Maximum value for Contrast function(225)
   - RppHandle_t handle - It contains the Miscellanous function like command Queue.

RPPBlur
-------

  Blurs an image using RPPBlur Function

rppi_blur3x3_u8(RppPtr_t srcPtr, RppiSize srcSize,RppPtr_t dstPtr)

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl
              buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize- KernelSize.
   - dstPtr - output image pointer of the same size and type as src.

RPPFlip
-------

rppi_flip_u8(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr,RppiAxis flipAxis)

  Flips an image in Horizontal,Vertical and Both axis.

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl
              buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize- KernelSize.
   - dstPtr - output image pointer of the same size and type as src.
   - flipAxis - Flips Performed in any one of axis like Horizontal,vertical and Both.

RPPHue
------

rppi_hueRGB_u8(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr,Rpp32f hueShift = 0)

  Adding Hue to the image using RPP Hue Modification function.

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl
              buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize- KernelSize.
   - dstPtr - output image pointer of the same size and type as src.
   - hueshift - 

RPPSaturation
-------------

rppi_saturationRGB_u8(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr,Rpp32f saturationFactor = 1)

  Adding saturation to the image using RPP Saturation Modification function.

   - srcPtr - input image pointer;it can have any number of channels, which are processed independently.it takes input from cl
              buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize- KernelSize.
   - dstPtr - output image pointer of the same size and type as src.
   - saturationFactor-






   
