#include <stdio.h>
#include "shape.h"
#include "svg.h"
#include "shape_list.h"

int main(void) {
    Shape *head = NULL;
    shape_list_append(&head, shape_create_circle(1, 1, 1));
    shape_list_append(&head, shape_create_rectangle(0, 0, 2, 2));
    printf("%d\n", head->next->type == SHAPE_RECTANGLE);
    shape_list_free(head);
    return 0;
}
