#include <stdio.h>
#include <stdlib.h>
#include "shape.h"
#include "polyline.h"

Shape *shape_create_polyline(int nb_points){
    Shape *shape = malloc(sizeof(Shape));
    if (shape == NULL){
        return NULL;
    }
    shape->type = SHAPE_POLYLINE;

    char stroke[8];
    printf("Polyline stroke color (e.g. #FF0000):\n");
    if (scanf("%7s", stroke) != 1) {
        free(shape);
        return NULL;
    }
    

    snprintf(shape->style.stroke, sizeof(shape->style.stroke), "%s", stroke);
    
    shape->transform.dx = 0;
    shape->transform.dy = 0;
    shape->transform.angle = 0;
    shape->transform.flip_x = 0;
    shape->transform.flip_y = 0;
    
    shape->data.polyline.count = nb_points;
    shape->data.polyline.points = malloc(nb_points * sizeof(Point));
    if (shape->data.polyline.points == NULL) {
        free(shape);
        return NULL;
    }
    return shape;
}
