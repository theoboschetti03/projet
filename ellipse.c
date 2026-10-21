#include <stdlib.h>
#include <string.h> 
#include "shape.h"


Shape *shape_create_ellipse(int center_x, int center_y, int radius_x, int radius_y) {

    Shape *shape = malloc(sizeof(Shape));
    if (shape == NULL) {
        return NULL;
    }
    shape->type = SHAPE_ELLIPSE;
    strcpy(shape->style.stroke, "#000000");
    strcpy(shape->style.fill, "none");
    shape->transform.dx = 0;
    shape->transform.dy = 0;
    shape->transform.angle = 0;
    shape->transform.flip_x = 0;
    shape->transform.flip_y = 0;
    shape->data.ellipse.center.x = center_x;
    shape->data.ellipse.center.y = center_y;
    shape->data.ellipse.radius_x = radius_x;
    shape->data.ellipse.radius_y = radius_y;
    shape->next = NULL;

    return shape;

} 