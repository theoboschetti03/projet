/**
 * @file shape_list.h
 * @brief Header file for managing a linked list of shapes.
 */

#ifndef SHAPE_LIST_H
#define SHAPE_LIST_H
#include "shape.h"

/**
 * @brief Appends a shape to the end of a linked list of shapes.
 * 
 * This function adds the specified `shape` to the linked list pointed to by `head`. 
 * If the list is empty (`*head == NULL`), the new shape becomes the head of the list.
 * 
 * @param head Double pointer to the head of the shape linked list.
 * @param shape Pointer to the `Shape` to be appended.
 */
void shape_list_append(Shape **head, Shape *shape);

/**
 * @brief Frees all memory allocated for a linked list of shapes.
 * 
 * This function traverses the linked list starting from the given `head` 
 * and recursively or iteratively frees each shape and its associated resources 
 * to prevent memory leaks.
 * 
 * @param head Pointer to the first shape in the linked list (`head`).
 */
void shape_list_free(Shape *head);

#endif