Handle
******

Handle types and functions.

enum RPPStatus
--------------

 Error codes that are returned by all MIOpen API calls.
 
 Values:

 RPP_SUCCESS = 0
 
 **No Errors**

 RPP_ERROR = 1

 **kernel not intialized**

enum  RppiAxis
--------------

 RPPI_HORIZONTAL_AXIS
  
 **Resultant image should be transformed to Horizontal axis.**
 
 RPPI_VERTICAL_AXIS
 
 **Resultant image should be transformed to Vertical axis.**
 
 RPPI_BOTH_AXIS
 
 **Resultant image should be transformed to Both axis.**

enum RppiFuzzyLevel
-------------------
 
 RPPI_LOW
 
 RPPI_MEDIUM
 
 RPPI_HIGH

enum  RppiChnFormat
-------------------
 
 RPPI channel format defines that the image channel format is of type planar and packed.   

 RPPI_CHN_PLANAR

 **The image format that contains a single channel called planar format.**  
 
 RPPI_CHN_PACKED
 
 **The image format that contains a single channel called packed format.**

enum RppiSize
-------------

 It returns the size of image with width and height.
 
 unsigned int width

 unsigned int height

enum RppiRect
-------------

 Draws a simple, thick, or filled up-right rectangle.

 int x
 
 int y

 int width

 int height

enum RppiBlur
-------------

 RPPiBlur is defined for Writing the Blur Kernel with different Sizes.

 GAUSS3
 
 **It is 3X3 Blur Kernel**

 GAUSS5

 **It is 5x5 Blur Kernel**

 GAUSS3x1

 **It is 3x1 Blur Kernel**

 GAUSS1x3
 
 **It is 1x3 Blur Kernel**

 AVG3 = 10
 
 **It is for Averaging a 3x3 Kernel** 

 AVG5

 **It is for Averaging a 5x5 Kernel**

enum RppiPad
------------

 Image padding introduces new pixels around the edges of an image. The border provides space for annotations or acts as a boundary when using advanced filtering techniques. 

 ZEROPAD

 **It simply refers to adding zeros to end of a time-domain signal to increase its length.There are a few reasons why you might want to zero pad time-domain data. The most common reason is to make a waveform have a power-of-two number of samples.**

 NOPAD

 **Not added any singals to it is known as NoPad**  

enum RppiFormat
----------------

RPP Format defines the two image format RGB and HSV

 RGB
 
 **RGB defines the Red,Blue,Green format.**
 
 HSV
 
 **HSV defines the Hue,Saturation,and value format.**

enum RppiPointPolar
------------------

 The use of a distance and direction as a means of describing position is therefore far more natural than using two distances on a grid. This means of location is used in polar coordinates and bearings.

 Rpp32f rho
  
 **Rho is the distance from the origin to the point.**

 Rpp32f theta
 
 **Theta is the same as the angle used in polar coordinates.** 
  

 
