##README

##Author:
Kaden Bevan - ktb76@nau.edu

##Included:

raycast.h,.c parse_csv.h,.c v3_math.h,.c object.h

##Functionality:

This program is a basic raycaster that outputs an image file in ppm format.
This program is uses a CSV formatted file to render spheres and planes. 

##Commandline Arguments:
arg1: Image width in pixels
arg2: Image height in pixels
arg3: CSV formatted file containing objects
arg4: PPM output file

Example: raycast 10 10 scene.txt output.ppm

Where output.ppm is the image file.

##Known Issues:

At the time of delivery this program has issues with the ray-object intersection algorithms.
This program relies on the first line in the scene (CSV) file to be the camera object.
