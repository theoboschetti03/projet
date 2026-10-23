/**
 * @file polygon.h
 * @brief Header file for managing and creating polygon shapes.
 */

#ifndef POLYGON_H
#define POLYGON_H

#include <stdio.h>
#include <stdlib.h>
#include "shape.h"

/**
 * @brief Allocates and initializes a new polygon shape with a specified number of points.
 * 
 * This function creates a new `Shape` structure configured as a polygon, 
 * allocating the necessary memory to store the given number of vertices.
 * 
 * @param nb_points The number of points (vertices) that the polygon will contain.
 * @return Shape* A pointer to the newly allocated `Shape` structure, 
 *                or `NULL` if memory allocation fails.
 */
Shape *shape_create_polygon(int nb_points);

#endif

