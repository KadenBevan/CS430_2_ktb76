#ifndef OBJECT_H
#define OBJECT_H

typedef struct object{
	// 0 = camera, 1 = sphere, 2 = plane
	char kind[64];
	int radius;
	double width;
	double height;
	int* position;
	float* color;
	float* normal;
} object;

#endif