#ifndef SHAPE_LIST_H
#define SHAPE_LIST_H

#include "shape.h"

void shape_list_append(Shape **head, Shape *shape);
void shape_list_free(Shape *head);

#endif
