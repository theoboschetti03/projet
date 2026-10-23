#include <stdio.h>
#include "shape.h"
#include "svg.h"



void svg_write_transform(const Shape *shape, FILE *output) {
    int scale_x = shape->transform.flip_x ? -1 : 1;
    int scale_y = shape->transform.flip_y ? -1 : 1;
    fprintf(output, " transform=\"translate(%d,%d) rotate(%d) scale(%d,%d)\"",
            shape->transform.dx, shape->transform.dy, shape->transform.angle,
            scale_x, scale_y);
}


void svg_write_shape(const Shape *shape, FILE *output) {
    if (shape == NULL || output == NULL) {
        return;
    }

    switch (shape->type) {
    case SHAPE_CIRCLE:
        fprintf(output, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"%s\" fill=\"%s\"",
                shape->data.circle.center.x, shape->data.circle.center.y,
                shape->data.circle.radius, shape->style.stroke, shape->style.fill);
                svg_write_transform(shape, output);
        fprintf(output, "/>\n");
        break;

    case SHAPE_RECTANGLE:
        fprintf(output, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" fill=\"%s\"",
                shape->data.rectangle.top_left.x, shape->data.rectangle.top_left.y,
                shape->data.rectangle.width, shape->data.rectangle.height,
                shape->style.stroke, shape->style.fill);
                svg_write_transform(shape, output);
        fprintf(output, "/>\n");
        break;

    case SHAPE_ELLIPSE:
        fprintf(output, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" stroke=\"%s\" fill=\"%s\"",
                shape->data.ellipse.center.x, shape->data.ellipse.center.y,
                shape->data.ellipse.radius_x, shape->data.ellipse.radius_y,
                shape->style.stroke, shape->style.fill);
                svg_write_transform(shape, output);
        fprintf(output, "/>\n");
        break;

    case SHAPE_LINE:
        fprintf(output, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\"",
                shape->data.line.start.x, shape->data.line.start.y,
                shape->data.line.end.x, shape->data.line.end.y,
                shape->style.stroke);
                svg_write_transform(shape, output);
        fprintf(output, "/>\n");
        break;
    case SHAPE_POLYLINE: {
        fprintf(output, "<polyline fill=\"none\" stroke=\"%s\" points=\"", shape->style.stroke);
            for (int j = 0; j < shape->data.polyline.count; j++) {
            fprintf(output, "%d,%d", shape->data.polyline.points[j].x, shape->data.polyline.points[j].y);
            if (j < shape->data.polyline.count - 1) {
                fprintf(output, " "); 
        }
    }
            fprintf(output, "\"");
            svg_write_transform(shape, output);
            fprintf(output, "/>\n");
            break;
}

    case SHAPE_POLYGON:
    break;
    }
}

int svg_export(const Shape *head, const char *path) {
    FILE *output = fopen(path, "w");
    if (output == NULL) {
        return 0;
    }

    fprintf(output, "<svg xmlns=\"http://www.w3.org/2000/svg\" "
                    "width=\"400\" height=\"400\" viewBox=\"-1000 -1000 2000 2000\">\n");
    for (const Shape *shape = head; shape != NULL; shape = shape->next) {
        svg_write_shape(shape, output);
    }
    fprintf(output, "</svg>\n");
    fclose(output);
    return 1;

}
