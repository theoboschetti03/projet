#include <stddef.h>
#include "shape.h"
#include "shape_list.h"

void shape_list_append(Shape **head, Shape *shape) {
    if (head == NULL || shape == NULL) {
        return;
    }
    shape->next = NULL;
    if (*head == NULL) {
        *head = shape;
    } else {
        Shape *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = shape;
    }
}

void shape_list_free(Shape *head) {
    while (head != NULL) {
        Shape *next = head->next;
        shape_free(head);
        head = next;
    }
}
