#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shape.h"


Shape *shape_create_ellipse(int cx, int cy, int rx, int ry){

    Shape *shape = malloc(sizeof(Shape));
    if (shape == NULL) {
        return NULL;
    }
    shape->type = SHAPE_ELLIPSE;

    char stroke[8];
    printf("Ellipse stroke color (e.g. #FF0000):\n");
    if (scanf("%7s", stroke) != 1) {
        free(shape);
        return NULL;
    }
    char fill[8];
    printf("Ellipse fill color (e.g. #00FF00):\n");
    if (scanf("%7s", fill) != 1) {
        free(shape);
        return NULL;
    }
    snprintf(shape->style.stroke, sizeof(shape->style.stroke), "%s", stroke);
    snprintf(shape->style.fill, sizeof(shape->style.fill), "%s", fill);
    
    shape->transform.dx = 0;
    shape->transform.dy = 0;
    shape->transform.angle = 0;
    shape->transform.flip_x = 0;
    shape->transform.flip_y = 0;
    shape->data.ellipse.center.x = cx;
    shape->data.ellipse.center.y = cy;
    shape->data.ellipse.radius_x = rx;
    shape->data.ellipse.radius_y = ry;
    shape->next = NULL;

    return shape;

} 