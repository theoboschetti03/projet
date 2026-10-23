/**
 * @file polyline.h
 * @brief Header file for managing and creating polyline shapes.
 */

#include <stdio.h>
#include <stdlib.h>
#include "shape.h"
#ifndef POLYLINE_H
#define POLYLINE_H

/**
 * @brief Allocates and initializes a new polyline shape with a specified number of points.
 * 
 * This function creates a new `Shape` structure configured as a polyline, 
 * allocating the necessary memory to store the given number of points.
 * 
 * @param nb_points The number of points that the polyline will contain.
 * @return Shape* A pointer to the newly allocated `Shape` structure, 
 *                or `NULL` if memory allocation fails.
 */
Shape *shape_create_polyline(int nb_points);

#endif