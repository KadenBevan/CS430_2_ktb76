#ifndef RAYCAST_H
#define RAYCAST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parse_csv.h"
#include "object.h"
#include "v3_math.h"
#include "ppmrw.h"

float find_intersection_sphere(float* ray0, float* ray1, int* position, int radius);
float find_intersection_plane(float* ray0, float* ray, int* position, float* normal);
void raycast(char* fn_in, char* fn_out, int img_width, int img_height);


#endif