#ifndef SHAPE_LIST_H
#define SHAPE_LIST_H

#include "shape.h"

/**
 * @brief Appends a shape to the end of a singly linked list.
 * @param head Address of the list head; updated when the list is empty.
 * @param shape Shape to append. If non-NULL, its next pointer is reset to NULL.
 *
 * If @p head or @p shape is NULL, this function does nothing.
 */
void shape_list_append(Shape **head, Shape *shape);

/**
 * @brief Frees every shape in a singly linked list.
 * @param head First shape in the list; NULL is allowed.
 */
void shape_list_free(Shape *head);

#endif
