#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shape.h"

Shape *shape_create_circle(int center_x, int center_y, int radius) {

    Shape *shape = malloc(sizeof(Shape));
    if (shape == NULL) {
        return NULL;
    }
    
    shape->type = SHAPE_CIRCLE;
    char stroke[8];
    printf("Circle stroke color (e.g. #FF0000):\n");
    if (scanf("%7s", stroke) != 1) {
        free(shape);
        return NULL;
    }
    char fill[8];
    printf("Circle fill color (e.g. #00FF00):\n");
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
    shape->data.circle.center.x = center_x;
    shape->data.circle.center.y = center_y;
    shape->data.circle.radius = radius;
    shape->next = NULL;

    return shape;
}