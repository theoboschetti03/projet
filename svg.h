#ifndef SVG_H
#define SVG_H
#include "shape.h"
#include <stdio.h>

/**
 * @brief Writes one shape as an SVG element.
 * @param shape Shape to write; NULL is ignored.
 * @param output Writable output stream; NULL is ignored.
 */
void svg_write_shape(const Shape *shape, FILE *output);

/**
 * @brief Exports a linked list of shapes as an SVG document.
 * @param head First shape to export, or NULL for an empty SVG document.
 * @param path Destination file path.
 * @return 1 if writing and closing the file succeed, otherwise 0.
 */
int svg_export(const Shape *head, const char *path);

#endif
