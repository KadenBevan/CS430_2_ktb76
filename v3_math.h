#ifndef V3_MATH_H
#define V3_MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* vector(float x, float y, float z);
float dot_vector(float* v1, float* v2);
void add_vector(float* result, float* v1, float* v2);
void scale_vector(float* result, float* v_in, float factor);
void normalize_vector(float* v_out, float* v_in);

#endif