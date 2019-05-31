Installation
************
 
  Build and Install Instructions
  -------------------------------

MIOpen supports two programming models

   1. OpenCL 
   2. `[HIP](https://github.com/ROCm-Developer-Tools/HIP)`_

 Prerequisites
 -------------
 
   1. OpenCL - OpenCL libraries and header files
   2. HIP    - HIP and HCC libraries and header files
   3. Ubuntu 16.04/18.04
   4  `[ROCm supported hardware](https://rocm.github.io/hardware.html)`_
   5. `[ROCm](https://rocm.github.io/install.html)`_

 Functions Included
 ------------------
 
    - Brightness
    - Contrast
    - Flip(Horizontal, Vertical and Both)
    - Blur (Gaussian 3x3)
    - Hue and Saturation modification
    - HSV2RGB
    - RGB2HSV

 Variations
 -----------

    - Support for 3C(RGB) and 1C(Grayscale) images
    - Planar and Packed
    - Host and GPU

 **Build & Install RPP library**
 
 **Using CMake on Linux**
 
git clone `https://github.com/LokeshBonta/AMD-RPP.git`_
 
 cd AMD-RPP

 **Building RPP from source**
 
 **Configuring with cmake**
 
First create a build directory:
 
mkdir build; cd build;
 
Next configure cmake. The preferred backend for RPP can be set using the `-DBACKEND` cmake variable.

 For OpenCL, run:
 
 cmake -DBACKEND=OCL ..`

The library can be built, from the `build` directory using the 'make' configuration:

 `make -j4`

 And can be installed by using the 'install' target:
 
 `sudo make install`

 MIVisionX(OpenVX) Support

Extended RPP support as a functionality through OpenVX `[MIVisionX](https://github.com/GPUOpen-ProfessionalCompute-Libraries/MIVisionX)`_ 

 To build OpenVX with 'RPP extension'

RPP should be installed, follow Instructions to build the library

`git  clone https://github.com/mythreyi22/MIVisionX.git`_
  
  cd MIVisionX
  
  git  checkout gdf_test

 For GPU support:
 
 `mkdir build;`
 `cd build;` 
 `cmake ..` 
 `make -j4` 

            or

 For CPU support:
 

 `cd build;` 
 
 `cmake -DCMAKE_DISABLE_FIND_PACKAGE_OpenCL=TRUE;` 
 
 `make -j4`
 
 `sudo make install`


