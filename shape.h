/**
 * @file shape.h
 * @brief Header file defining geometric shapes, styling, transformations, and manipulation functions.
 */

#ifndef SHAPE_H
#define SHAPE_H

/**
 * @enum ShapeType
 * @brief Enumeration of the different types of supported geometric shapes.
 */
typedef enum {
    SHAPE_CIRCLE,    /**< Circle shape */
    SHAPE_ELLIPSE,   /**< Ellipse shape */
    SHAPE_RECTANGLE, /**< Rectangle shape */
    SHAPE_LINE,      /**< Straight line shape */
    SHAPE_POLYLINE,  /**< Open polyline shape */
    SHAPE_POLYGON    /**< Closed polygon shape */
} ShapeType;

/**
 * @struct Point
 * @brief Represents a 2D point with integer coordinates.
 */
typedef struct {
    int x; /**< X coordinate */
    int y; /**< Y coordinate */
} Point;

/**
 * @struct Style
 * @brief Defines the visual style (stroke and fill colors) for a shape.
 */
typedef struct {
    char stroke[8]; /**< Stroke (border) color string (e.g., hex code) */
    char fill[8];   /**< Fill color string (e.g., hex code) */
} Style;

/**
 * @struct Transform
 * @brief Defines geometric transformations applied to a shape.
 */
typedef struct {
    int dx;       /**< Translation displacement along the X-axis */
    int dy;       /**< Translation displacement along the Y-axis */
    int angle;    /**< Rotation angle in degrees */
    int flip_x;   /**< Flag indicating horizontal flip (1) or not (0) */
    int flip_y;   /**< Flag indicating vertical flip (1) or not (0) */
} Transform;

/**
 * @typedef Shape
 * @brief Forward declaration of the `Shape` structure.
 */
typedef struct Shape Shape;

/**
 * @struct Shape
 * @brief Represents a geometric shape containing its type, style, transformations, and specific data.
 */
struct Shape {
    ShapeType type;      /**< Type of the shape */
    Style style;         /**< Visual style of the shape */
    Transform transform; /**< Geometric transformations applied to the shape */
    Shape *next;         /**< Pointer to the next shape in a linked list */
    union {
        struct {
            Point center; /**< Center point of the circle */
            int radius;   /**< Radius of the circle */
        } circle;
        
        struct {
            Point start;  /**< Starting point of the line */
            Point end;    /**< Ending point of the line */
        } line;
        
        struct {
            Point center; /**< Center point of the ellipse */
            int radius_x; /**< Horizontal radius of the ellipse */
            int radius_y; /**< Vertical radius of the ellipse */
        } ellipse;
        
        struct {
            Point top_left; /**< Top-left corner point of the rectangle */
            int width;      /**< Width of the rectangle */
            int height;     /**< Height of the rectangle */
        } rectangle;
        
        struct {
            Point *points;  /**< Dynamic array of points forming the polyline */
            int count;      /**< Number of points in the polyline */
        } polyline;
        
        struct {
            Point *points;  /**< Dynamic array of points forming the polygon */
            int count;      /**< Number of points in the polygon */
        } polygon;
    } data; /**< Union containing specific geometric data depending on the shape type */
};

/**
 * @brief Allocates and initializes a new circle shape.
 * 
 * @param center_x X coordinate of the circle's center.
 * @param center_y Y coordinate of the circle's center.
 * @param radius Radius of the circle.
 * @return Shape* Pointer to the newly allocated circle shape, or NULL on failure.
 */
Shape *shape_create_circle(int center_x, int center_y, int radius);

/**
 * @brief Allocates and initializes a new line shape.
 * 
 * @param start_x X coordinate of the starting point.
 * @param start_y Y coordinate of the starting point.
 * @param end_x X coordinate of the ending point.
 * @param end_y Y coordinate of the ending point.
 * @return Shape* Pointer to the newly allocated line shape, or NULL on failure.
 */
Shape *shape_create_line(int start_x, int start_y, int end_x, int end_y);

/**
 * @brief Allocates and initializes a new rectangle shape.
 * 
 * @param x X coordinate of the top-left corner.
 * @param y Y coordinate of the top-left corner.
 * @param width Width of the rectangle.
 * @param height Height of the rectangle.
 * @return Shape* Pointer to the newly allocated rectangle shape, or NULL on failure.
 */
Shape *shape_create_rectangle(int x, int y, int width, int height);

/**
 * @brief Allocates and initializes a new ellipse shape.
 * 
 * @param center_x X coordinate of the ellipse's center.
 * @param center_y Y coordinate of the ellipse's center.
 * @param radius_x Horizontal radius of the ellipse.
 * @param radius_y Vertical radius of the ellipse.
 * @return Shape* Pointer to the newly allocated ellipse shape, or NULL on failure.
 */
Shape *shape_create_ellipse(int center_x, int center_y, int radius_x, int radius_y);

/**
 * @brief Frees all memory associated with a shape.
 * 
 * @param shape Pointer to the shape to be freed.
 */
void shape_free(Shape *shape);

/**
 * @brief Sets the stroke color for a given shape.
 * 
 * @param shape Pointer to the shape.
 * @param color String representing the stroke color.
 * @return int Returns 0 on success, or a non-zero value on failure.
 */
int shape_set_stroke(Shape *shape, const char *color);

/**
 * @brief Sets the fill color for a given shape.
 * 
 * @param shape Pointer to the shape.
 * @param color String representing the fill color.
 * @return int Returns 0 on success, or a non-zero value on failure.
 */
int shape_set_fill(Shape *shape, const char *color);

/**
 * @brief Translates a shape by a given offset.
 * 
 * @param shape Pointer to the shape.
 * @param dx Offset along the X-axis.
 * @param dy Offset along the Y-axis.
 */
void shape_translate(Shape *shape, int dx, int dy);

/**
 * @brief Rotates a shape by a specific angle.
 * 
 * @param shape Pointer to the shape.
 * @param angle Rotation angle in degrees.
 */
void shape_rotate(Shape *shape, int angle);

/**
 * @brief Flips a shape horizontally along the X-axis.
 * 
 * @param shape Pointer to the shape.
 */
void shape_flip_x(Shape *shape);

/**
 * @brief Flips a shape vertically along the Y-axis.
 * 
 * @param shape Pointer to the shape.
 */
void shape_flip_y(Shape *shape);

#endif