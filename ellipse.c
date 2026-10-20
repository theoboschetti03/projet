#include <stdlib.h>
#include <string.h> 
#include "forme.h"


Forme *forme_creer_ellipse(int cx, int cy, int rx, int ry) {

    Forme *f = malloc(sizeof(Forme));
    if (f == NULL) {
        return NULL;
    }
    f->type = ELLIPSE;
    strcpy(f->style.stroke, "#000000");
    strcpy(f->style.fill, "none");
    f->transform.dx = 0;
    f->transform.dy = 0;
    f->transform.angle = 0;
    f->transform.flipX = 0;
    f->transform.flipY = 0;
    f->data.ellipse.middle.x = cx;
    f->data.ellipse.middle.y = cy;
    f->data.ellipse.rx = rx;
    f->data.ellipse.ry = ry;
    f->suivant = NULL;

    return f;

} 