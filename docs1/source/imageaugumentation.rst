Image Augumentation Functions
=============================
 
RPPDataType_t
-------------

  RPP integer and floating point datatypes are supported.

 Rpp8u
  
  8-bit unsigned char

 Rpp8s
  
  8-bit signed char

 Rpp16u

  16-bit unsigned short

 Rpp16s

  16-bit signed short
        
 Rpp32u

  32-bit unsigned int
                 
 Rpp32s
  
  32-bit int
 
 Rpp64u
  
  64-bit unsigned long long
  
 Rpp64s

  64-bit long 
               
 Rpp32f
 
  32-bit float
             
 Rpp64f

  64-bit double


RPPBrightness
-------------

 Brightens the image pixels using RPP brightness Modification function.

	rppi_brightness_u8(RppPtr_t srcPtr, RppiSize srcSize,RppPtr_t dstPtr, Rpp32f alpha, Rpp32s beta,RppHandle_t handle )

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize- Image srcSize.
   - dstPtr - output image pointer of the same size and type as src.
   - alpha  - simple Contrast control.
   - beta   - simple Brightness control.
   - RppHandle_t handle -for GPU:It contains the Miscellanous function like command Queue.
			 for CPU:NULL	

                                          .. centered::  f(y) = α×f(x) + βs

RPPContrast
-----------

  Increasing or Decreasing Contrast to the image pixels using RPP Contrast Modification Functions.

	rppi_contrast_u8(RppPtr_t srcPtr, RppiSize srcSize,RppPtr_t dstPtr,Rpp32u new_min = 0, Rpp32u new_max = 225)

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize-Image srcSize.
   - dstPtr - output image pointer of the same size and type as src.
   - new_min- Minimum value for contrast function(0)
   - new_max- Maximum value for Contrast function(225)
   - RppHandle_t handle - for GPU:It contains the Miscellanous function like command Queue.
			  for CPU:NULL
                                       
					                New Max - New Min   
                            .. centered:: I = (I-Min)    _______________     + New Min
				                             Max-Min

RPPBlur
-------

  Blurs an image using RPPBlur Function.Blurring is used in preprocessing tasks, such as removal of small details from an image prior to (large) object extraction, and bridging of small gaps in lines or curves.Noise reduction can be accomplished by blurring. 

	rppi_blur3x3_u8(RppPtr_t srcPtr, RppiSize srcSize,RppPtr_t dstPtr)

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize-Image srcSize.
   - dstPtr - output image pointer of the same size and type as src.
   
   """
    ::

                [1  1  1 ]                                  [1  2  1 ]             
          1/9   [1  1  1 ]                            1/16  [2  4  2 ]  
                [1  1  1 ]                                  [1  2  1 ]
                						
                 Averaging                                    Gaussian
    """

RPPFlip
-------

 Flips an image in Horizontal,Vertical and Both axis.

	rppi_flip_u8(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr,RppiAxis flipAxis)

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize- Image srcSize.
   - dstPtr - output image pointer of the same size and type as src.
   - flipAxis - Flips Performed in any one of axis like Horizontal,vertical and Both.

RPPHue
------

 Increasing or Decreasing Hue to the image using RPP Hue Modification function.

	rppi_hueRGB_u8(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr,Rpp32f hueShift = 0)

   - srcPtr - input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize-Image srcSize.
   - dstPtr - output image pointer of the same size and type as src.
   - hueshift - 
  
			                                           .. centered::  H=H+360 if H<0

RPPSaturation
-------------

 Increasing or Decreasing saturation to the image using RPP Saturation Modification function.

	rppi_saturationRGB_u8(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr,Rpp32f saturationFactor = 1)

   - srcPtr - input image pointer;it can have any number of channels, which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend. 
   - srcSize-Image srcSize.
   - dstPtr - output image pointer of the same size and type as src.
   - saturationFactor
   
                                                                   .. centered::  S=(max-min)/max         (or S = 0,V = 0) where V is Value

RPPRotate
---------

 Rotation of an image for an angle \theta is achieved by the transformation matrix of the form.

RPPGammaCorrection
------------------

 Gamma Correction is the name of a nonlinear operation used to code and decode luminance or tristimulus values in video or still image systems.Gamma encoded images store tones more efficiently.

RPPResize
---------

 Resizes an original image.	

RPPWarpAffine
-------------
 Performs an affine transform on an image.

 This kernel performs an affine transform with a 2x3 Matrix M with this method of pixel coordinate translation:


                                                 .. centered::  x0=M1,1∗x+M1,2∗y+M1,3
						
                                                 .. centered::  y0=M2,1∗x+M2,2∗y+M2,3
						
				                 .. centered::  output(x,y)=input(x0,y0)

RPPRandomResize
---------------

 Resize an image with some random Numbers.





