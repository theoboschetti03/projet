#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shape.h"

void shape_free(Shape *shape) {
    if (shape == NULL) {
        return;
    }
    free(shape);
}

int shape_set_stroke(Shape *shape, const char *color) {
    if (shape == NULL || color == NULL ||
        strlen(color) >= sizeof(shape->style.stroke)) {
        return 0;
    }
    snprintf(shape->style.stroke, sizeof(shape->style.stroke), "%s", color);
    return 1;
}

int shape_set_fill(Shape *shape, const char *color) {
    if (shape == NULL || color == NULL ||
        strlen(color) >= sizeof(shape->style.fill)) {
        return 0;
    }
    snprintf(shape->style.fill, sizeof(shape->style.fill), "%s", color);
    return 1;
}

void shape_flip_x(Shape *shape) {
    if (shape == NULL) {
        return;
    }
    shape->transform.flip_x = !shape->transform.flip_x;
}

void shape_flip_y(Shape *shape) {
    if (shape == NULL) {
        return;
    }
    shape->transform.flip_y = !shape->transform.flip_y;
}

void shape_translate(Shape *shape, int dx, int dy) {
    if (shape == NULL) {
        return;
    }
    shape->transform.dx += dx;
    shape->transform.dy += dy;
}

void shape_rotate(Shape *shape, int angle) {
    if (shape == NULL) {
        return;
    }
    shape->transform.angle += angle;
    shape->transform.angle = ((shape->transform.angle % 360) + 360) % 360;
}
