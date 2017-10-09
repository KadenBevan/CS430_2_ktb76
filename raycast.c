#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct ray_vector{
	double vx;
	double vy;
	double vz;
} St_ray_vector;

typedef struct object{
	char kind[64];
	
	//SPHERE
	double radius;
	struct position{
		int x;
		int y;
		int z;
	} Position;
	//0-1 color;
	struct color{
		int red;
		int green;
		int blue;
	} Color;
	struct normal{
		int a;
		int b;
		int c;
	} Normal;
	double width;
	double height;
} Object;

int normalize_color(float, int, int, int, int);

St_ray_vector * vector(float, float, float);
St_ray_vector * add_vector(St_ray_vector, St_ray_vector);
St_ray_vector * normalize_vector(St_ray_vector * v);
St_ray_vector * scale_vector(St_ray_vector *v_in, float);
St_ray_vector * dot_product(St_ray_vector *v1, St_ray_vector *v2);

void fill_scene(char*);
Object m_scene[128];

int main(int argc, char *argv[]){
	//if(argc != 4){
	//	// ERROR: This program takes 3 and only 3 arguments.
	//	// Close Files
	//	printf("ERROR: The amount of arguments passed does not reflect usage.\nSee README.md for help.\n");
	//	fclose(output_file);
	//	fclose(input_file);
	//	return -1;
	//}else {
	//	FILE *output_file = fopen(argv[3], "wb");
	//	FILE *input_file = fopen(argv[2], "rb");
	//}
	//const char* tok;
	//
    //for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n"))
    //{
    //    if (!--num)
    //        return tok;
    //}
    //return NULL;
	//printf("%i", normalize_color(.5, 0, 1, 0, 255));
	//printf("%s", argv[1]);
	//fill_scene(argv[1]);
	//St_ray_vector * v1 = (St_ray_vector*)malloc(sizeof(St_ray_vector));
	//St_ray_vector * v1 = vector(5.0, 6.4, -8.4);
	//v1 = scale_vector(v1, 5.2);
	////v1 = normalize_vector(v1);
	//printf("%f", v1->vy);
	//printf("Passing pointer, fields: c:%c, i:%3i, w:\"%s\"\n",
   //   p -> c, p -> i, p -> w);
	int pix_width = 10;
	int pix_height = 10;
	Object sp = {.radius=4.204, .Position={.x=8, .y=5, .z=6}, .Color={.red=1, .green=4, .blue=2}};
	printf("Radius: %f\nPosition: x=%d y=%d z=%d\nColor: red=%d green=%d blue=%d", sp.radius, sp.Position.x, sp.Position.y, sp.Position.z, sp.Color.red, sp.Color.green, sp.Color.blue);
	for(int i = -1*(pix_width/2); i <= pix_width/2; i++){
		for(int j = -1*(pix_height/2); j <= pix_height/2; j++){
			// create a vector at the start of with V1: x=i y=j
			// z scales by creating an ident
		}
	}
	return 0;
}

// Result := ((Input - InputLow) / (InputHigh - InputLow)) * (OutputHigh - OutputLow) + OutputLow;
int normalize_color(float input, int input_low, int input_high, int output_low, int output_high){
	int result = ((input-input_low) / (input_high - input_low))*(output_high - output_low) + output_low;
	return result;
}

/*
Start of vector math file
*/
St_ray_vector * dot_product(St_ray_vector *v1, St_ray_vector *v2){
		St_ray_vector * vf = (St_ray_vector*)malloc(sizeof(St_ray_vector));
		
}

St_ray_vector * scale_vector(St_ray_vector *v_in, float scale){
	//TODO: ERROR check NULL values
	St_ray_vector * v1 = (St_ray_vector*)malloc(sizeof(St_ray_vector));
	v1->vx = (scale*v_in->vx);
	v1->vy = (scale*v_in->vy);
	v1->vz = v_in->vz;
	return v1;
}

St_ray_vector * vector(float x, float y, float z){
	St_ray_vector * v1 = (St_ray_vector*)malloc(sizeof(St_ray_vector));
	v1->vx = x;
	v1->vy = y;
	v1->vz = z;
	return v1;
}

St_ray_vector * normalize_vector(St_ray_vector * v){
	St_ray_vector * normal_v = (St_ray_vector*)malloc(sizeof(St_ray_vector));
    float w = sqrt( v->vx * v->vx + v->vy * v->vy + v->vz * v->vz );
    normal_v->vx = v->vx / w;
    normal_v->vy = v->vy / w;
    normal_v->vz = v->vz / w;
	return normal_v;
}

//void print_sphere(Object * sphere){
//	printf("Kind: %s, Red: %")
//}

float find_intersection_circle(St_ray_vector * v_in, Object * obj){
	
}

void fill_scene(char* fn){
	FILE* fh = fopen(fn, "r");
	char line[256];
	//int line_count = 0;
	for (int line_count = 0; fgets(line, sizeof(line), fh); line_count++) {
        sscanf(line, "%[a-z],", m_scene[line_count].kind);
		//printf("%s %i\n", &m_scene[line_count].kind, line_count);
	//	//printf("%s", m_scene[line_count].kind);
		if(strcmp(m_scene[line_count].kind, "camera") == 0){
			sscanf(line, "%[a-z], width: %lf, height: %lf", m_scene[line_count].kind, &m_scene[line_count].width, &m_scene[line_count].height);
			printf("%f %i\n", m_scene[line_count].width, line_count);
		}
		if(strcmp(m_scene[line_count].kind, "sphere") == 0){
			sscanf(line, "%[a-z], color: [%[lf,], %[lf,], %[lf]]], position: [%i, %i, %i], radius: %i", 
			m_scene[line_count].kind, 
			&m_scene[line_count].Color.red, &m_scene[line_count].Color.green, &m_scene[line_count].Color.blue,
			&m_scene[line_count].Position.x, &m_scene[line_count].Position.y, &m_scene[line_count].Position.z,
			&m_scene[line_count].radius);
			printf("%f %i\n", m_scene[line_count].Color.red, line_count);
		}

		//if(strcmp(m_scene[line_count].kind, "plane") == 0){
		//	sscanf(line, "%[a-z], color: [%i, %i, %i], position: [%i, %i, %i], normal: [%i, %i, %i]", 
		//	m_scene[line_count].kind, 
		//	&m_scene[line_count].Color.red, &m_scene[line_count].Color.green, &m_scene[line_count].Color.blue,
		//	&m_scene[line_count].Position.x, &m_scene[line_count].Position.y, &m_scene[line_count].Position.z,
		//	&m_scene[line_count].Normal.a, &m_scene[line_count].Normal.b, &m_scene[line_count].Normal.c);
		//	printf("%i %i\n", m_scene[line_count].Position.x, line_count);
		//}
		//m_scene[line_count].Color.red = normalize_color(m_scene[line_count].Color.red, 0, 1, 0, 255);
		//m_scene[line_count].Color.green = normalize_color(m_scene[line_count].Color.green, 0, 1, 0, 255);
		//m_scene[line_count].Color.blue = normalize_color(m_scene[line_count].Color.blue, 0, 1, 0, 255);
		//line_count++;
	}
	//printf("%i", m_scene[1].Color.red);
		//if(strcmp(m_scene[line_count].kind, "plane") == 0){
		//	sscanf(line, "%[a-z], width: %lf, height: %lf", m_scene[line_count].kind, &m_scene[line_count].width, &m_scene[line_count].height);
		//}
		
		//printf("%s %f %f", m_scene[line_count].kind, m_scene[line_count].width, &m_scene[line_count].height);
	//	if(strcmp(m_scene[line_count].kind, "plane") == 0){
	//		printf("%s", m_scene[line_count].kind);
	//	}
	//	if(strcmp(m_scene[line_count].kind, "sphere") == 0){
	//		printf("%s", m_scene[line_count].kind);
	//	}
	//	line_count++;
    //}
	fclose(fh);
	//fscanf(fh, "%s, ");
	//return m_scene;
}