#include <stdlib.h>
#include <string.h>
#include "forme.h"

Forme *forme_creer_cercle(int cx, int cy, int r) {

    Forme *f = malloc(sizeof(Forme));
    if (f == NULL) {
        return NULL;
    }
    
    f->type = CERCLE;
    char stroke[8];
    printf("Circle stroke color (ex #FF0000)\n");
    scanf("%7s", stroke);
    char fill[8];
    printf("Circle fill color (ex #00FF00):\n");
    scanf("%7s", fill);
    f->transform.dx = 0;
    f->transform.dy = 0;
    f->transform.angle = 0;
    f->transform.flipX = 0;
    f->transform.flipY = 0;
    f->data.cercle.middle.x = cx;
    f->data.cercle.middle.y = cy;
    f->data.cercle.r = r;
    f->suivant = NULL;

    return f;
}