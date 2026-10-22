#ifndef SHAPE_H
#define SHAPE_H


typedef enum {
    SHAPE_CIRCLE,    
    SHAPE_ELLIPSE,   
    SHAPE_RECTANGLE, 
    SHAPE_LINE,
    SHAPE_POLYLINE,
    SHAPE_POLYGON  
} ShapeType;


typedef struct {
    int x; 
    int y; 
} Point;


typedef struct {
    char stroke[8]; 
    char fill[8];  
} Style;

typedef struct {
    int dx;       
    int dy;       
    int angle;    
    int flip_x;   
    int flip_y;   
} Transform;


typedef struct Shape Shape;
struct Shape {
    ShapeType type;   
    Style style;      
    Transform transform; 
    Shape *next;      
    union {
        struct {
            Point center; 
            int radius;   
        } circle;
        
        struct {
            Point start; 
            Point end;   
        } line;
        
        struct {
            Point center; 
            int radius_x; 
            int radius_y; 
        } ellipse;
        
        struct {
            Point top_left; 
            int width;      
            int height;     
        } rectangle;
        
        struct {
            Point *points;
            int count;
        }polyline;
        
        struct {
            Point *points;
            int count;
        }polygon;
    } data; 
};


Shape *shape_create_circle(int center_x, int center_y, int radius);


Shape *shape_create_line(int start_x, int start_y, int end_x, int end_y);

Shape *shape_create_rectangle(int x, int y, int width, int height);


Shape *shape_create_ellipse(int center_x, int center_y, int radius_x, int radius_y);




void shape_free(Shape *shape);


int shape_set_stroke(Shape *shape, const char *color);


int shape_set_fill(Shape *shape, const char *color);


void shape_translate(Shape *shape, int dx, int dy);


void shape_rotate(Shape *shape, int angle);

void shape_flip_x(Shape *shape);


void shape_flip_y(Shape *shape);

#endif
