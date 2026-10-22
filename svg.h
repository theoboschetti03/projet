#ifndef SVG_H
#define SVG_H
#include "shape.h"
#include <stdio.h>


void svg_write_shape(const Shape *shape, FILE *output);


int svg_export(const Shape *head, const char *path);

#endif
