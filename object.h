#ifndef OBJECT_H
#define OBJECT_H

typedef struct object{
	// 0 = camera, 1 = sphere, 2 = plane
	char kind[64];
	double radius;
	double width;
	double height;
	int* position;
	float* color;
	int* normal;
} object;
#endif