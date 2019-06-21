Vision
******
   
Absolute Difference
-------------------
  
  Computes the absolute difference between two images.

  Absolute Difference is computed by
  
                                     .. centered:: out(x,y)=|in1(x,y)−in2(x,y)|

	rppi_absolute_difference_u8( RppPtr_t srcPtr1, RppPtr_t srcPtr2,RppiSize srcSize, RppPtr_t dstPtr,RppHandle_t rppHandle )
	
			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it             takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcPtr2- input image pointer2; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.
			
Accumulate
----------
	
  Accumulates an input image into output image.

  Accumulation is computed by:

	                             .. centered:: accum(x,y)=accum(x,y)+input(x,y)

	
	rppi_accumulate_u8( RppPtr_t srcPtr1, RppPtr_t srcPtr2,RppiSize srcSize,RppHandle_t rppHandle )

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcPtr2- input image pointer2; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.
			
Accumulate Weighted
-------------------

  Accumulates a weighted value from an input image to an output image.

  Weighted accumulation is computed by:

		                   .. centered:: accum(x,y)=(1−α)∗accum(x,y)+α∗input(x,y)

     Where 0≤α≤1 Conceptually, the rounding for this is defined as:

                           ..centered::output(x,y)=uint8((1−α)∗float32(int32(output(x,y)))+α∗float32(int32(input(x,y))))
			     
	rppi_accumulate_weighted_u8( RppPtr_t srcPtr1, RppPtr_t srcPtr2,RppiSize srcSize, Rpp64f alpha,RppHandle_t rppHandle )

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcPtr2- input image pointer2; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- alpha  - parameter value that ranges from 0 to 1
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.
			

Arithmetic Addition
-------------------

   Performs addition between two images.

   Arithmetic addition is performed between the pixel values in two U8 orS16 images. The output image can be U8 only if both source images are U8and the output image is explicitly set to U8. It is otherwise S16. If one of the input images is of type S16, all values are converted to S16. The overflow handling is controlled by an overflow-policy parameter. For each pixel value in the two input images:

					    .. centered:: out(x,y)=in1(x,y)+in2(x,y)
	
	rppi_add_u8( RppPtr_t srcPtr1, RppPtr_t srcPtr2,RppiSize srcSize, RppPtr_t dstPtr,RppHandle_t rppHandle )

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcPtr2- input image pointer2; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.

Arithmetic Subtraction
----------------------

    Performs subtraction between two images.

    Arithmetic subtraction is performed between the pixel values in two U8 or two S16 images. The output image can be U8 only if both source images are U8 and the output image is explicitly set to U8. It is otherwise S16. If one of the input images is of type S16, all values are converted to S16. The overflow handling is controlled by an overflow-policy parameter. For each pixel value in the two input images:

					         .. centered:: out(x,y)=in1(x,y)−in2(x,y)

	rppi_subtract_u8( RppPtr_t srcPtr1, RppPtr_t srcPtr2,RppiSize srcSize, RppPtr_t dstPtr,RppHandle_t rppHandle )

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcPtr2- input image pointer2; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.

Bilateral Filter
----------------

    Performs a Bilateral filter operation on a input image.

         rppi_bilateral_filter_u8(RppPtr_t srcPtr, RppiSize srcSize,RppPtr_t dstPtr, Rpp32u filterSize,Rpp64f sigmaI, Rpp64f sigmaS,RppHandle_t rppHandle)

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- filterSize- Size of the filter
			- sigmaI - parameter that resides in Intensity level
			- sigmaS - parameter that resides in Spatial level   
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.

Bitwise AND
-----------

   Performs a bitwise AND operation between two images.
 
   Bitwise AND is computed by the following, for each bit in each pixel in the input images:

				       .. centered:: out(x,y)=in1(x,y)∧in2(x,y)

          Or expressed as C code:
				       
				       .. centered:: out(x,y) = in_1(x,y) & in_2(x,y)

	rppi_bitwise_AND_u8( RppPtr_t srcPtr1, RppPtr_t srcPtr2,RppiSize srcSize, RppPtr_t dstPtr,RppHandle_t rppHandle )

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcPtr2- input image pointer2; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.

Bitwise EXCLUSIVE OR
--------------------

    Performs a bitwise EXCLUSIVE OR (XOR) operation between two images.

    Bitwise XOR is computed by the following, for each bit in each pixel in the input images:

				       .. centered:: out(x,y)=in1(x,y) ⊕ in2(x,y)

        Or expressed as C code:
				       
				       .. centered:: out(x,y) = in_1(x,y) ^ in_2(x,y)

	rppi_exclusive_OR_u8( RppPtr_t srcPtr1, RppPtr_t srcPtr2,RppiSize srcSize, RppPtr_t dstPtr,RppHandle_t rppHandle )

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcPtr2- input image pointer2; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.

Bitwise INCLUSIVE OR
--------------------

    Performs a bitwise INCLUSIVE OR operation between two images.

    Bitwise INCLUSIVE OR is computed by the following, for each bit in each pixel in the input images:

				      .. centered:: out(x,y)=in1(x,y)∨in2(x,y)

          Or expressed as C code:
				      
				      .. centered::  out(x,y) = in_1(x,y) | in_2(x,y)

	rppi_inclusive_OR_u8( RppPtr_t srcPtr1, RppPtr_t srcPtr2,RppiSize srcSize, RppPtr_t dstPtr,RppHandle_t rppHandle )

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcPtr2- input image pointer2; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.

Bitwise NOT
-----------

    Performs a bitwise NOT operation on a input image.
 
    Bitwise NOT is computed by the following, for each bit in each pixel in the input image:

				         .. centered:: out(x,y)=in(x,y)

         Or expressed as C code
	          
		                         .. centered:: out(x,y) = ~in_1(x,y)

	rppi_bitwise_NOT_u8( RppPtr_t srcPtr1,RppiSize srcSize, RppPtr_t dstPtr,RppHandle_t rppHandle )

			- srcPtr1- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.

Box Filter
----------

      Computes a Box filter over a window of the input image.

      This filter uses the following convolution matrix:
		
    """
    ::
               [1  4  7 ]
       Kbox =  [2  5  8 ] 
               [3  6  9 ]
    """
      rppi_box_filter_u8(RppPtr_t srcPtr, RppiSize srcSize, RppPtr_t dstPtr, RppHandle_t rppHandle)

			- srcPtr- input image pointer; it can have any number of channels,which are processed independently.it takes input from cl buffer for Device Backend and host buffer for CPU Backend.
			- srcSize- Image srcSize
			- dstPtr - output image pointer of the same size and type as src.
			- RppHandle_t rppHandle- It contains the Miscellanous function like command Queue.




