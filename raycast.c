#include "raycast.h"


int main(int argc, char *argv[]){
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	object * scene = fill_scene(argv[1]);
	pixel * pix = malloc(sizeof(pixel)*width*height);
	//printf(scene[1].kind);
	//float* r1 = vector(5, 5, 5);
	//find_intersection_sphere(r1, scene[1].position, scene[1].radius);
	raycast(argv[1], 5, 5, pix);
	return 0;
}

float find_intersection_sphere(float* ray, int* position, int radius){
	//printf("%i", position[1]);
	//a = (x2-x1)^2+(y2-y1)^2+(z2-z1)^2;
	float a = (ray[0]*ray[0])+(ray[1]*ray[1])+(ray[2]*ray[2]);
	float b = 2*ray[0]*(0-position[0])+2*ray[1]*(0-position[1])+2*ray[2]*(0-position[2]);
	float c = (position[0]*position[0])+(position[1]*position[1])+(position[2]*position[2])-(radius*radius);
	float disc = b*b-4*a*c;
	float t = ((-1*b)-sqrtf(fabs(disc)))/(2*a);
	//printf("INTERSECTING RAY: %f %f %f\nWith SPHERE pos[%i %i %i] r %i\n", ray[0], ray[1], ray[2], position[0], position[1], position[2], radius);
	//printf("a=%f b=%f c=%f disc=%f t=%f\n", a, b, c, disc, t);
	return t;
	//if(t>0){
	//	return 1;
	//}
	//if(t<0){
	//	return 0;
	//}
	//printf("%i\n", ray[0]);
}

void raycast(char* filename, int img_width, int img_height, pixel* img){
	object * scene = fill_scene(filename);
	float cam_width = scene[0].width;
	float cam_height = scene[0].height;
	int t;
	// Scale pixels
	float pixel_dim_y = cam_height / img_height;
	float pixel_dim_x = cam_width / img_width;
	//for every pixel in image
	for(int i=0; i<img_height; i++){
		for(int j=0; j<img_width; j++){
			float* ray = vector(-1*(cam_width / 2.0) + pixel_dim_x * (j + 0.5), (cam_height / 2.0) + pixel_dim_y * (i + 0.5), 1);
			normalize_vector(ray);
			//for every object
			for(int k = 1; k < num_objects(filename); k++) {
				t = 0;
				if((scene[k].kind) != NULL) {
					//check intersection
					if(strcmp((scene[k].kind), "sphere") == 0){
						t = find_intersection_sphere(ray, scene[k].position, scene[k].radius);

					}
				}
			}
		}
	}
}