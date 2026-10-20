#include<stdio.h>
#include <stdlib.h>
#include"forme.h"
#include "liste.h"

void liste_ajouter(Forme **tete, Forme *f){
    if (tete == NULL || f == NULL){
        return;
    }
    f->suivant = NULL;
    if (*tete == NULL){
        *tete = f;

    } else {
        Forme *courant = *tete;
        while (courant->suivant != NULL)
        {
        courant = courant->suivant;
        }
        courant->suivant = f;
    }
}


void liste_liberer(Forme *tete){
    while (tete != NULL){
        Forme *suivant = tete->suivant;
        forme_liberer(tete);
        tete = suivant;
    }

}