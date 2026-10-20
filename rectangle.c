#include <stdlib.h>
#include <string.h>
#include "forme.h"


Forme *forme_creer_rectangle(int x, int y, int l, int h) {

    Forme *f = malloc(sizeof(Forme));
    if (f == NULL) {
        return NULL;
    }
    
    f->type = RECTANGLE;
    strcpy(f->style.stroke, "#000000");
    strcpy(f->style.fill, "none");
    f->transform.dx = 0;
    f->transform.dy = 0;
    f->transform.angle = 0;
    f->transform.flipX = 0;
    f->transform.flipY = 0;
    f->data.rectangle.corner.x = x;
    f->data.rectangle.corner.y = y;
    f->data.rectangle.h = h;
    f->data.rectangle.l = l;
    f->suivant = NULL;

    return f;

} 