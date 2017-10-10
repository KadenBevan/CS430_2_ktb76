#include "v3_math.h"


// vectors are defined as float arrays where index 0 = x, index 1 = y, and index 2 = z values.
float* vector(float x, float y, float z){
	//free vector after use?
	float* v = malloc(sizeof(float)*3);
	v[0] = x;
	v[1] = y;
	v[2] = z;
	return v;
}

void add_vector(float* result, float* v1, float* v2){
	// Space is allocated when vector is created, so no need to malloc again
	result[0] = v1[0] + v2[0];
	result[1] = v1[1] + v2[1];
	result[2] = v2[1] + v2[2];
}

void scale_vector(float* result, float* v_in, float factor){
	// again no need to allocate memory for result vector
	result[0] = v_in[0] * factor;
	result[1] = v_in[1] * factor;
	result[2] = v_in[2] * factor;
}

float dot_vector(float* v1, float* v2){
	return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

void normalize_vector(float* v_out, float* v_in){
    float w = sqrt( v_in[0] * v_in[0] + v_in[1] * v_in[1] + v_in[2] * v_in[2] );
    v_out[0] = v_in[0] / w;
    v_out[1] = v_in[1] / w;
	v_out[2] = v_in[2] / w;
}