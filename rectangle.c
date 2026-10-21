#include <stdlib.h>
#include <string.h>
#include "shape.h"


Shape *shape_create_rectangle(int x, int y, int width, int height) {

    Shape *shape = malloc(sizeof(Shape));
    if (shape == NULL) {
        return NULL;
    }
    
    shape->type = SHAPE_RECTANGLE;
    strcpy(shape->style.stroke, "#000000");
    strcpy(shape->style.fill, "none");
    shape->transform.dx = 0;
    shape->transform.dy = 0;
    shape->transform.angle = 0;
    shape->transform.flip_x = 0;
    shape->transform.flip_y = 0;
    shape->data.rectangle.top_left.x = x;
    shape->data.rectangle.top_left.y = y;
    shape->data.rectangle.height = height;
    shape->data.rectangle.width = width;
    shape->next = NULL;

    return shape;

} 