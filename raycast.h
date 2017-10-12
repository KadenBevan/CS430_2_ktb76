#ifndef RAYCAST_H
#define RAYCAST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parse_csv.h"
#include "object.h"
#include "v3_math.h"

float find_intersection_sphere(float* ray, int* position, int radius);
float find_intersection_plane();
void raycast(char* filename, int img_width, int img_height, pixel* img);


#endif