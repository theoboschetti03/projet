#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shape.h"
#include "polygon.h"

Shape *shape_create_polygon(int nb_points){
    Shape *shape = malloc(sizeof(Shape));
    if (shape == NULL){
        return NULL;
    }
    shape->type = SHAPE_POLYGON;


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
    shape->data.polygon.count = nb_points;
    shape->data.polygon.points = malloc(nb_points * sizeof(Point));
    if (shape->data.polygon.points == NULL) {
        free(shape);
        return NULL;
    }
    return shape;

}


