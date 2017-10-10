#ifndef PARSE_CSV_H
#define PARSE_CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

object * fill_scene(char* filename);
int num_objects(char* filename);

#endif