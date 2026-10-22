#include <stdio.h>
#include "shape.h"
#include "svg.h"
#include "shape_list.h"




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
            printf("Which shape would you like to create?\n");
            printf("\n1: Circle\n");
            printf("\n2: Ellipse\n");
            printf("\n3: Rectangle\n");
            printf("\n4: Line\n");
            if (scanf("%d", &shape_choice) != 1) {
                fprintf(stderr, "Invalid shape choice.\n");
                shape_list_free(head);
                return 1;
            }
            if (shape_choice < 1 || shape_choice > 4) {
                fprintf(stderr, "Invalid shape choice.\n");
                break;
            }

            switch (shape_choice) {
            case 1: { int cx, cy, r;
                    printf("Circle center x:\n");
                    scanf("%d", &cx);
                    printf("Circle center y:\n");
                    scanf("%d", &cy);
                    printf("Circle radius:\n");
                    scanf("%d", &r);
                Shape *shape = shape_create_circle(cx, cy, r);
                shape_list_append(&head, shape);}
                break;
            case 2:{ int cx,cy,rx,ry;
                    printf("Ellipse center x:\n");
                    scanf("%d", &cx);
                    printf("Ellipse center y:\n");
                    scanf("%d", &cy);
                    printf("Ellipse horizontal radius:\n");
                    scanf("%d", &rx);
                    printf("Ellipse vertical radius:\n");
                    scanf("%d", &ry);
                    Shape *shape = shape_create_ellipse(cx, cy, rx, ry);
                    shape_list_append(&head, shape);}
                break;
            case 3:{ int x, y, width, height;
                    printf("Rectangle top-left x:\n");
                    scanf("%d", &x);
                    printf("Rectangle top-left y:\n");
                    scanf("%d", &y);
                    printf("Rectangle width:\n");
                    scanf("%d", &width);
                    printf("Rectangle height:\n");
                    scanf("%d", &height);
                Shape *shape = shape_create_rectangle(x, y, width, height);
                shape_list_append(&head, shape);}
            
                break;
            case 4:{ int ax, ay, bx, by;
                    printf("Line start x:\n");
                    scanf("%d", &ax);
                    printf("Line start y:\n");
                    scanf("%d", &ay);
                    printf("Line end x:\n");
                    scanf("%d", &bx);
                    printf("Line end y:\n");
                    scanf("%d", &by);
                Shape *shape = shape_create_line(ax, ay, bx, by);
                shape_list_append(&head, shape);}
                break;
            }
            
            break;
        }
        case 2: {
            char path[256];
            printf("SVG file path (e.g. shapes.svg):\n");
            scanf("%255s", path);
            svg_export(head, path);
            
        } break;
        
        

        case 3: {
            printf("Enter the number of the shape to modify:\n");
            int selection;
            int index = 1;
            for (Shape *shape = head; shape != NULL; shape = shape->next) {
                printf("%d: %s\n", index++, shape_name(shape->type));
            }
            

            Shape *target = head;
            for (int i = 1; target != NULL && i < selection; i++) {
                target = target->next;
            }
            scanf("%d", &selection);
            int modification = 0;
            printf("What would you like to modify?\n");
            printf("1: Translate\n");
            printf("2: Rotate\n");
            printf("3: Stroke color\n");
            printf("4: Fill color\n");
            printf("5: Flip horizontally\n");
            printf("6: Flip vertically\n");
            scanf("%d", &modification);

            int dx;
            int dy;
            int angle;
            char color[8];
            switch (modification) {
            case 1: 
                printf("Horizontal translation:\n");
                    scanf("%d", &dx);
                
                printf("Vertical translation:\n");
                    scanf("%d", &dy);
                
                shape_translate(target, dx, dy);
                break;
            case 2:
                printf("Rotation angle in degrees:\n");
                scanf("%d", &angle);
                shape_rotate(target, angle);
                break;
            case 3:
                printf("New stroke color (e.g. #FF0000):\n");
                scanf("%7s", color);
                shape_set_stroke(target, color);
                
                break;
            case 4:
                printf("New fill color (e.g. #00FF00):\n");
                scanf("%7s", color);
                shape_set_fill(target, color);
                break;
            case 5:
                printf("Not available yet");
                break;
            case 6:
                printf("Not available yet");
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
