#include <stdio.h>
#include <stdlib.h> 
#include "forme.h"
#include "svg.h"
#include "liste.h"

int main(void) {
Forme *premiere = NULL;
liste_ajouter(&premiere, forme_creer_cercle(1, 1, 1));
liste_ajouter(&premiere, forme_creer_rectangle(0, 0, 2, 2));
printf("%d\n", premiere->suivant->type == RECTANGLE);
liste_liberer(premiere);
}