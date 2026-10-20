#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forme.h"

void forme_liberer(Forme *f) {
    if (f == NULL) {
        return;
    }
    free(f);
}

int  forme_set_stroke(Forme *f, const char *couleur){
    if (f == NULL || couleur == NULL || strlen(couleur) >= sizeof(f->style.stroke)) {
        return 0;
    }
    snprintf(f->style.stroke, sizeof(f->style.stroke), "%s", couleur);
    return 1; 

}

int  forme_set_fill(Forme *f, const char *couleur){
    if (f == NULL || couleur == NULL || strlen(couleur) >= sizeof(f->style.fill)) {
        return 0;
    }
    snprintf(f->style.fill, sizeof(f->style.fill), "%s", couleur);
    return 1;
}

void forme_symetrie_x(Forme *f){
    if (f == NULL){
        return;
    }
    f->transform.flipX = !f->transform.flipX;
}

void forme_symetrie_y(Forme *f){
    if (f == NULL){
        return;
    }
    f->transform.flipY = !f->transform.flipY;
}



void forme_translater(Forme *f, int dx, int dy){
    if (f == NULL) {
        return;
    }
    f->transform.dx += dx;
    f->transform.dy += dy;
}

void forme_pivoter(Forme *f, int angle){

    if (f == NULL){
        return;
    }
    f->transform.angle += angle;
    f->transform.angle = ((f->transform.angle % 360) + 360) % 360;
}
