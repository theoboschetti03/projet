#ifndef FORME_H
#define FORME_H

#include <stdio.h>


typedef enum { CERCLE, ELLIPSE, RECTANGLE, LIGNE} TypeForme;

typedef struct { int x, y; } Point;

typedef struct {
    char stroke[8];
    char fill[8];
} Style;

typedef struct {
    int dx, dy;
    int angle;
    int flipX, flipY;
} Transform;

typedef struct Forme Forme;
struct Forme {
    TypeForme type;
    Style style;
    Transform transform;
    Forme *suivant;
    union {
        struct{ Point middle; int r; } cercle;
        struct {Point a; Point b; } ligne;
        struct {Point middle; int rx; int ry;} ellipse;
        struct {Point corner; int l; int h;} rectangle;
        
        
    } data;
};


Forme *forme_creer_cercle(int cx, int cy, int r);
Forme *forme_creer_ligne(int ax, int ay, int bx, int by);
Forme *forme_creer_rectangle(int x, int y, int l, int h);
Forme *forme_creer_ellipse(int cx, int cy, int rx, int ry);
void libérer_forme(Forme *f);

void forme_liberer(Forme *f);


int  forme_set_stroke(Forme *f, const char *couleur);
int  forme_set_fill(Forme *f, const char *couleur);
void forme_translater(Forme *f, int dx, int dy);
void forme_pivoter(Forme *f, int angle);
void forme_symetrie_x(Forme *f);
void forme_symetrie_y(Forme *f);



#endif
