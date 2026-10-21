#include <stdio.h>
#include "shape.h"
#include "svg.h"
#include "shape_list.h"

/**
 * @brief Returns the display name for a shape type.
 * @param type Shape type to describe.
 * @return A constant string naming the type, or "Unknown" for an unrecognized value.
 */
static const char *shape_name(ShapeType type) {
    switch (type) {
    case SHAPE_CIRCLE:
        return "Circle";
    case SHAPE_ELLIPSE:
        return "Ellipse";
    case SHAPE_RECTANGLE:
        return "Rectangle";
    case SHAPE_LINE:
        return "Line";
    }
    return "Unknown";
}

/**
 * @brief Runs the interactive shape creation, modification, and export menu.
 * @return 0 on normal exit, or 1 if reading the main menu fails.
 */
int main(void) {
    printf("Welcome to the place where you are now the master of SVG shapes.\n");
    Shape *head = NULL;
    int choice = 0;

    while (choice != 4) {
        printf("\nWhat would you like to do?\n");
        printf("\n1: Create\n");
        printf("\n2: Export\n");
        printf("\n3: Modify\n");
        printf("\n4: Quit\n");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid choice.\n");
            shape_list_free(head);
            return 1;
        }

        switch (choice) {
        case 1: {
            int shape_choice;
            int center_x;
            int center_y;
            int radius;
            printf("Which shape would you like to create?\n");
            printf("\n1: Circle\n");
            if (scanf("%d", &shape_choice) != 1) {
                fprintf(stderr, "Invalid shape choice.\n");
                shape_list_free(head);
                return 1;
            }
            if (shape_choice != 1) {
                printf("This shape is not supported yet.\n");
                break;
            }
            printf("Circle center x:\n");
            if (scanf("%d", &center_x) != 1) break;
            printf("Circle center y:\n");
            if (scanf("%d", &center_y) != 1) break;
            printf("Circle radius:\n");
            if (scanf("%d", &radius) != 1) break;

            Shape *shape = shape_create_circle(center_x, center_y, radius);
            if (shape == NULL) {
                fprintf(stderr, "Could not create the circle.\n");
                break;
            }
            shape_list_append(&head, shape);
            break;
        }
        case 2: {
            char path[256];
            if (head == NULL) {
                printf("There are no shapes to export.\n");
                break;
            }
            printf("SVG file path (e.g. shapes.svg):\n");
            if (scanf("%255s", path) != 1) {
                fprintf(stderr, "Invalid file path.\n");
                break;
            }
            if (svg_export(head, path)) {
                printf("Export successful: %s\n", path);
            } else {
                perror("Could not export the SVG file");
            }
            break;
        }
        case 3: {
            if (head == NULL) {
                printf("There are no shapes to modify.\n");
                break;
            }

            int index = 1;
            for (Shape *shape = head; shape != NULL; shape = shape->next) {
                printf("%d: %s\n", index++, shape_name(shape->type));
            }
            printf("Enter the number of the shape to modify:\n");
            int selection;
            if (scanf("%d", &selection) != 1 || selection < 1) {
                fprintf(stderr, "Invalid shape selection.\n");
                break;
            }

            Shape *target = head;
            for (int i = 1; target != NULL && i < selection; i++) {
                target = target->next;
            }
            if (target == NULL) {
                printf("That shape does not exist.\n");
                break;
            }

            int modification;
            printf("What would you like to modify?\n");
            printf("1: Translate\n");
            printf("2: Rotate\n");
            printf("3: Stroke color\n");
            printf("4: Fill color\n");
            printf("5: Flip horizontally\n");
            printf("6: Flip vertically\n");
            if (scanf("%d", &modification) != 1) {
                fprintf(stderr, "Invalid modification choice.\n");
                break;
            }

            int dx;
            int dy;
            int angle;
            char color[8];
            switch (modification) {
            case 1:
                printf("Horizontal translation:\n");
                if (scanf("%d", &dx) != 1) break;
                printf("Vertical translation:\n");
                if (scanf("%d", &dy) != 1) break;
                shape_translate(target, dx, dy);
                break;
            case 2:
                printf("Rotation angle in degrees:\n");
                if (scanf("%d", &angle) != 1) break;
                shape_rotate(target, angle);
                break;
            case 3:
                printf("New stroke color (e.g. #FF0000):\n");
                if (scanf("%7s", color) != 1) break;
                if (!shape_set_stroke(target, color)) {
                    fprintf(stderr, "Invalid stroke color.\n");
                }
                break;
            case 4:
                printf("New fill color (e.g. #00FF00):\n");
                if (scanf("%7s", color) != 1) break;
                if (!shape_set_fill(target, color)) {
                    fprintf(stderr, "Invalid fill color.\n");
                }
                break;
            case 5:
                shape_flip_x(target);
                break;
            case 6:
                shape_flip_y(target);
                break;
            default:
                printf("Invalid modification choice.\n");
                break;
            }
            break;
        }
        case 4:
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    shape_list_free(head);
    return 0;
}
