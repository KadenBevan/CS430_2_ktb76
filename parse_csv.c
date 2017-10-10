#include "parse_csv.h" 

object * fill_scene(char* filename){
	FILE* fh = fopen(filename, "r");
	char line[256];
	int line_count = 0;
	object* m_scene = malloc(sizeof(object)*128);
	//fgets(line, sizeof(line), fh);
	for (int line_count = 0; fgets(line, sizeof(line), fh); line_count++) {
		sscanf(line, "%[a-z]", m_scene[line_count].kind);
		if(strcmp(m_scene[line_count].kind, "camera") == 0){
			printf("ADDED CAMERA\n");
			sscanf(line, "%[a-z], width: %lf, height: %lf", m_scene[line_count].kind, &m_scene[line_count].width, &m_scene[line_count].height);
			//printf("%f %i\n", m_scene[line_count].width, line_count);
		}
		if(strcmp(m_scene[line_count].kind, "sphere") == 0){
			//printf("ADDED SPHERE\n");
			m_scene[line_count].color = malloc(sizeof(float)*3);
			m_scene[line_count].position = malloc(sizeof(int)*3);
			sscanf(line, "%[a-z], color: [%f, %f, %f], position: [%i, %i, %i], radius: %i", 
					m_scene[line_count].kind, 
					&m_scene[line_count].color[0], &m_scene[line_count].color[1], &m_scene[line_count].color[2],
					&m_scene[line_count].position[0], &m_scene[line_count].position[1], &m_scene[line_count].position[2],
					&m_scene[line_count].radius);
			m_scene[line_count].color[0] = 255*m_scene[line_count].color[0];
			m_scene[line_count].color[1] = 255*m_scene[line_count].color[1];
			m_scene[line_count].color[2] = 255*m_scene[line_count].color[2];
		}
		if(strcmp(m_scene[line_count].kind, "plane") == 0){
			//printf("ADDED PLANE\n");
			m_scene[line_count].color = malloc(sizeof(float)*3);
			m_scene[line_count].position = malloc(sizeof(int)*3);
			m_scene[line_count].normal = malloc(sizeof(int)*3);
			
			sscanf(line, "%[a-z], color: [%f, %f, %f], position: [%i, %i, %i], normal: [%i, %i, %i]", 
					m_scene[line_count].kind, 
					&m_scene[line_count].color[0], &m_scene[line_count].color[1], &m_scene[line_count].color[2],
					&m_scene[line_count].position[0], &m_scene[line_count].position[1], &m_scene[line_count].position[2],
					&m_scene[line_count].normal[0], &m_scene[line_count].normal[1], &m_scene[line_count].normal[2]);
			m_scene[line_count].color[0] = m_scene[line_count].color[0]*255;
			m_scene[line_count].color[1] = m_scene[line_count].color[0]*255;
			m_scene[line_count].color[2] = m_scene[line_count].color[0]*255;
		}
	}
	fclose(fh);
	return m_scene;
}

int num_objects(char* filename){
	FILE* fh = fopen(filename, "r");
	char line[256];
	int lines = 0;
	for(int line_count = 0; fgets(line, sizeof(line), fh); line_count++){
		lines++;
	}
	return lines;
}