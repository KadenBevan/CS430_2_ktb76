#include "raycast.h"


int main(int argc, char *argv[]){
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	char* fn_in = argv[3];
	char* fn_out = argv[4];
	object * scene = fill_scene(argv[1]);
	raycast(fn_in, fn_out, width, height);
	return 0;
}

float find_intersection_plane(float* ray0, float* ray, int* position, float* normal){
	normalize_vector(normal);
	float a = (normal[0] * position[0]) + (normal[1] * position[1]) + (normal[2] * position[2]); 
	float b = (normal[0] * ray[0]) + (normal[1] * ray[1]) + (normal[2] * ray[2]);
	
	if(b < 10e-5){
		return -1;
	}
	float t = a / b;
	return (t >= 0) ? t : -1;
}

float find_intersection_sphere(float* ray0, float* ray1, int* position, int radius){
	
	float b = -2*(position[0]*ray1[0] + position[1]*ray1[1]+position[2]*ray1[2]);

	float c = pow(position[0], 2) + pow(position[1], 2) + pow(position[2], 2) - pow(radius, 2);

	float disc = pow(b, 2) - 4*c;
	float t1 = (-1 * b + sqrt(fabs(disc))) / 2;
	float t0 = (-1 * b - sqrt(fabs(disc))) / 2;

	if (disc < 0){
		return -1;
	}
	else if(t0 > 0 && t1 > 0){
		if(t0 > t1){
			return t1;
		}
		else{
			return t0;
		}
	}
	else if(t1 >= 0){
		return t1;
	}
	else if(t0 >= 0){
		return t0;
	}
}

void raycast(char* fn_in, char* fn_out, int img_width, int img_height){
	FILE* fh_out = fopen(fn_out, "w");
	fprintf(fh_out, "P3\n");
	fprintf(fh_out, "%d %d\n%d\n", img_width, img_height, 255);
	// Fill scene
	object * scene = fill_scene(fn_in);
	float cam_width = scene[0].width;
	float cam_height = scene[0].height;
	float pixel_dim_y = cam_height / img_height;
	float pixel_dim_x = cam_width / img_width;
	int color[3];
	//for every pixel in image
	for(int i=0; i<img_height; i++){
		for(int j=0; j<img_width; j++){
			float* ray = vector((cam_width/2)-pixel_dim_y+(i+0.5), -cam_height/2+pixel_dim_x*(i + 0.5), -1.0);
			float* r0 = vector(0, 0, 0);
			normalize_vector(ray);
			//for every object
			float tmp_t = INFINITY;
			for (int k=1; k < num_objects(fn_in); k++) {
				float t = 0.00;
				if(strcmp(scene[k].kind, "sphere") == 0){
					t = find_intersection_sphere(r0, ray, scene[k].position, scene[k].radius);
				}
				if(strcmp(scene[k].kind, "plane") == 0){
					t = find_intersection_plane(r0, ray, scene[k].position, scene[k].normal);
				}
				if (t > 0 && t <= tmp_t) {
					tmp_t = t;
					color[0] = (int)scene[k].color[0];
					color[1] = (int)scene[k].color[1];
					color[2] = (int)scene[k].color[2];
				}
			}
			if (tmp_t > 0 && tmp_t != INFINITY) {
				fprintf(fh_out, "%i %i %i ", color[0], color[1], color[2]);
			}
			else{
				fprintf(fh_out, "0 0 0 ");
			}
		}
	}
	fclose(fh_out);
}