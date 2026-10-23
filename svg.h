/**
 * @file svg.h
 * @brief Header file for exporting shapes into SVG file format.
 */

#ifndef SVG_H
#define SVG_H

#include "shape.h"
#include <stdio.h>

/**
 * @brief Writes the SVG transformation attributes for a given shape to an output stream.
 * 
 * This function translates internal shape transformations (such as translation, 
 * rotation, or flipping) into standard SVG transformation attributes (e.g., `transform="..."`).
 * 
 * @param shape Pointer to the constant `Shape` whose transformations are to be exported.
 * @param output Pointer to the output file or stream (`FILE *`) where the SVG attributes will be written.
 */
void svg_write_transform(const Shape *shape, FILE *output);

/**
 * @brief Writes the SVG representation of a single shape to an output stream.
 * 
 * This function determines the type of the shape (circle, rectangle, line, etc.) 
 * and outputs the corresponding SVG tag along with its style, data, and transformations.
 * 
 * @param shape Pointer to the constant `Shape` to be written.
 * @param output Pointer to the output file or stream (`FILE *`) where the SVG code will be written.
 */
void svg_write_shape(const Shape *shape, FILE *output);

/**
 * @brief Exports an entire linked list of shapes into an SVG file.
 * 
 * This function opens the file at the specified path, writes the SVG document header, 
 * iterates through the shape linked list writing each shape using `svg_write_shape`, 
 * closes the SVG root tag, and safely closes the file.
 * 
 * @param head Pointer to the first `Shape` in the linked list (`head`).
 * @param path Path to the destination SVG file where the export will be saved.
 * @return int Returns 0 on success, or a non-zero error code/value if the file could not be opened or written.
 */
int svg_export(const Shape *head, const char *path);

#endif