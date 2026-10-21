#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shape.h"


Shape *shape_create_line(int ax, int ay, int bx, int by){

    Shape *shape = malloc(sizeof(Shape));
    if (shape == NULL) {
        return NULL;
    }
    char stroke[8];
    printf("Line stroke color (e.g. #FF0000):\n");
    if (scanf("%7s", stroke) != 1) {
        free(shape);
        return NULL;
    }
    snprintf(shape->style.stroke, sizeof(shape->style.stroke), "%s", stroke);

    shape->type = SHAPE_LINE;
    shape->transform.dx = 0;
    shape->transform.dy = 0;
    shape->transform.angle = 0;
    shape->transform.flip_x = 0;
    shape->transform.flip_y = 0;
    shape->data.line.start.x = ax;
    shape->data.line.start.y = ay;
    shape->data.line.end.x = bx;
    shape->data.line.end.y = by;

    shape->next = NULL;

    return shape;

} 