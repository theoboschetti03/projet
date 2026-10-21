#ifndef SHAPE_H
#define SHAPE_H

/**
 * @brief Identifies the geometric type stored in a Shape.
 */
typedef enum {
    SHAPE_CIRCLE,    /**< Circle shape. */
    SHAPE_ELLIPSE,   /**< Ellipse shape. */
    SHAPE_RECTANGLE, /**< Rectangle shape. */
    SHAPE_LINE       /**< Line segment shape. */
} ShapeType;

/**
 * @brief A two-dimensional point.
 */
typedef struct {
    int x; /**< Horizontal coordinate. */
    int y; /**< Vertical coordinate. */
} Point;

/**
 * @brief SVG stroke and fill colors for a shape.
 *
 * Each field must hold a null-terminated color string shorter than 8 bytes.
 */
typedef struct {
    char stroke[8]; /**< Stroke color, for example "#FF0000". */
    char fill[8];   /**< Fill color, or "none". */
} Style;

/**
 * @brief Translation, rotation, and reflection applied when exporting a shape.
 */
typedef struct {
    int dx;       /**< Horizontal translation in SVG units. */
    int dy;       /**< Vertical translation in SVG units. */
    int angle;    /**< Rotation angle in degrees. */
    int flip_x;   /**< Nonzero when reflected across the x-axis. */
    int flip_y;   /**< Nonzero when reflected across the y-axis. */
} Transform;

/**
 * @brief A geometric shape, its styling, transform, and list link.
 */
typedef struct Shape Shape;
struct Shape {
    ShapeType type;   /**< Geometric type; selects the matching data member. */
    Style style;      /**< Stroke and fill colors. */
    Transform transform; /**< Transform applied during SVG export. */
    Shape *next;      /**< Next shape in a singly linked list, or NULL. */
    union {
        struct {
            Point center; /**< Circle center. */
            int radius;   /**< Circle radius. */
        } circle;
        struct {
            Point start; /**< Starting point of the line segment. */
            Point end;   /**< Ending point of the line segment. */
        } line;
        struct {
            Point center; /**< Ellipse center. */
            int radius_x; /**< Horizontal radius. */
            int radius_y; /**< Vertical radius. */
        } ellipse;
        struct {
            Point top_left; /**< Top-left corner of the rectangle. */
            int width;      /**< Rectangle width. */
            int height;     /**< Rectangle height. */
        } rectangle;
    } data; /**< Geometry for the member selected by @p type. */
};

/**
 * @brief Creates a circle and reads its stroke and fill colors from standard input.
 * @param center_x Horizontal coordinate of the circle center.
 * @param center_y Vertical coordinate of the circle center.
 * @param radius Circle radius.
 * @return The new circle, or NULL if allocation or color input fails.
 */
Shape *shape_create_circle(int center_x, int center_y, int radius);

/**
 * @brief Creates a line segment with the default black stroke.
 * @param start_x Horizontal coordinate of the starting point.
 * @param start_y Vertical coordinate of the starting point.
 * @param end_x Horizontal coordinate of the ending point.
 * @param end_y Vertical coordinate of the ending point.
 * @return The new line, or NULL if allocation fails.
 */
Shape *shape_create_line(int start_x, int start_y, int end_x, int end_y);

/**
 * @brief Creates a rectangle with a black stroke and no fill.
 * @param x Horizontal coordinate of the top-left corner.
 * @param y Vertical coordinate of the top-left corner.
 * @param width Rectangle width.
 * @param height Rectangle height.
 * @return The new rectangle, or NULL if allocation fails.
 */
Shape *shape_create_rectangle(int x, int y, int width, int height);

/**
 * @brief Creates an ellipse with a black stroke and no fill.
 * @param center_x Horizontal coordinate of the ellipse center.
 * @param center_y Vertical coordinate of the ellipse center.
 * @param radius_x Horizontal radius.
 * @param radius_y Vertical radius.
 * @return The new ellipse, or NULL if allocation fails.
 */
Shape *shape_create_ellipse(int center_x, int center_y, int radius_x, int radius_y);

/**
 * @brief Releases the memory occupied by a shape.
 * @param shape Shape to release; NULL is allowed.
 *
 * This function does not free any shapes linked through @p shape->next.
 */
void shape_free(Shape *shape);

/**
 * @brief Sets a shape's stroke color.
 * @param shape Shape to update.
 * @param color Null-terminated color string shorter than the stroke buffer.
 * @return 1 on success, or 0 if an argument is NULL or the color is too long.
 */
int shape_set_stroke(Shape *shape, const char *color);

/**
 * @brief Sets a shape's fill color.
 * @param shape Shape to update.
 * @param color Null-terminated color string shorter than the fill buffer.
 * @return 1 on success, or 0 if an argument is NULL or the color is too long.
 */
int shape_set_fill(Shape *shape, const char *color);

/**
 * @brief Adds a translation to a shape's current transform.
 * @param shape Shape to translate; NULL is ignored.
 * @param dx Horizontal translation to add.
 * @param dy Vertical translation to add.
 */
void shape_translate(Shape *shape, int dx, int dy);

/**
 * @brief Adds a rotation and normalizes the resulting angle to [0, 360).
 * @param shape Shape to rotate; NULL is ignored.
 * @param angle Rotation in degrees to add.
 */
void shape_rotate(Shape *shape, int angle);

/**
 * @brief Toggles reflection across the x-axis for a shape.
 * @param shape Shape to update; NULL is ignored.
 */
void shape_flip_x(Shape *shape);

/**
 * @brief Toggles reflection across the y-axis for a shape.
 * @param shape Shape to update; NULL is ignored.
 */
void shape_flip_y(Shape *shape);

#endif
