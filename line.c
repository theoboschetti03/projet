#include <stdlib.h>
#include <string.h>
#include "shape.h"


Shape *shape_create_line(int start_x, int start_y, int end_x, int end_y) {

    Shape *shape = malloc(sizeof(Shape));
    if (shape == NULL) {
        return NULL;
    }
    shape->type = SHAPE_LINE;
    strcpy(shape->style.stroke, "#000000");
    shape->transform.dx = 0;
    shape->transform.dy = 0;
    shape->transform.angle = 0;
    shape->transform.flip_x = 0;
    shape->transform.flip_y = 0;
    shape->data.line.start.x = start_x;
    shape->data.line.start.y = start_y;
    shape->data.line.end.x = end_x;
    shape->data.line.end.y = end_y;

    shape->next = NULL;

    return shape;

} 