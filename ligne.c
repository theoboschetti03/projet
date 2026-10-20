#include <stdlib.h>
#include <string.h>
#include "forme.h"


Forme *forme_creer_ligne(int ax, int ay, int bx, int by) {

    Forme *f = malloc(sizeof(Forme));
    if (f == NULL) {
        return NULL;
    }
    f->type = LIGNE;
    strcpy(f->style.stroke, "#000000");
    f->transform.dx = 0;
    f->transform.dy = 0;
    f->transform.angle = 0;
    f->transform.flipX = 0;
    f->transform.flipY = 0;
    f->data.ligne.a.x = ax;
    f->data.ligne.a.y = ay;
    f->data.ligne.b.x = bx;
    f->data.ligne.b.y = by;

    f->suivant = NULL;

    return f;

} 