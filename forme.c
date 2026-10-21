#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forme.h"

/**
 * @brief Frees the memory occupied by a shape.
 * @param f Shape to release; NULL is allowed.
 */
void forme_liberer(Forme *f) {
    if (f == NULL) {
        return;
    }
    free(f);
}

/**
 * @brief Sets a shape's stroke color.
 * @param f Shape to update.
 * @param couleur Null-terminated color string shorter than the stroke buffer.
 * @return 1 on success, or 0 if an argument is NULL or the color is too long.
 */
int  forme_set_stroke(Forme *f, const char *couleur){
    if (f == NULL || couleur == NULL || strlen(couleur) >= sizeof(f->style.stroke)) {
        return 0;
    }
    snprintf(f->style.stroke, sizeof(f->style.stroke), "%s", couleur);
    return 1; 

}

/**
 * @brief Sets a shape's fill color.
 * @param f Shape to update.
 * @param couleur Null-terminated color string shorter than the fill buffer.
 * @return 1 on success, or 0 if an argument is NULL or the color is too long.
 */
int  forme_set_fill(Forme *f, const char *couleur){
    if (f == NULL || couleur == NULL || strlen(couleur) >= sizeof(f->style.fill)) {
        return 0;
    }
    snprintf(f->style.fill, sizeof(f->style.fill), "%s", couleur);
    return 1;
}

/**
 * @brief Toggles reflection across the x-axis for a shape.
 * @param f Shape to update; NULL is ignored.
 */
void forme_symetrie_x(Forme *f){
    if (f == NULL){
        return;
    }
    f->transform.flipX = !f->transform.flipX;
}

/**
 * @brief Toggles reflection across the y-axis for a shape.
 * @param f Shape to update; NULL is ignored.
 */
void forme_symetrie_y(Forme *f){
    if (f == NULL){
        return;
    }
    f->transform.flipY = !f->transform.flipY;
}



/**
 * @brief Adds a translation to a shape's current transform.
 * @param f Shape to translate; NULL is ignored.
 * @param dx Horizontal translation to add.
 * @param dy Vertical translation to add.
 */
void forme_translater(Forme *f, int dx, int dy){
    if (f == NULL) {
        return;
    }
    f->transform.dx += dx;
    f->transform.dy += dy;
}

/**
 * @brief Adds a rotation and normalizes the resulting angle to [0, 360).
 * @param f Shape to rotate; NULL is ignored.
 * @param angle Rotation in degrees to add.
 */
void forme_pivoter(Forme *f, int angle){

    if (f == NULL){
        return;
    }
    f->transform.angle += angle;
    f->transform.angle = ((f->transform.angle % 360) + 360) % 360;
}
