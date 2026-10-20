#include <stdio.h>
#include "forme.h"
#include "svg.h"
#include "liste.h"

int main(void) {
    printf("Bienvenue dans le lieu où vous etes désormais le maitre des formes en SVG\n");
    Forme *premiere = NULL;
    int choice = 0;

    while (choice != 4) {
        printf("\nWhat do you want to do ?\n");
        printf("\n1 : Make\n");
        printf("\n2 : Export\n");
        printf("\n3 : Modify\n");
        printf("\n4 : Quit\n");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Choix invalide.\n");
            liste_liberer(premiere);
            return 1;
        }

        switch (choice) {
        case 1: {
            int shape_choice, cx, cy, r;
            printf("Which shape do you want to make ?\n");
            printf("\n 1 : Circle\n");
            if (scanf("%d", &shape_choice) != 1) {
                fprintf(stderr, "Choix de forme invalide.\n");
                liste_liberer(premiere);
                return 1;
            }
            if (shape_choice != 1) {
                printf("Forme non prise en charge.\n");
                break;
            }
            printf("Circle middle x :\n");
            if (scanf("%d", &cx) != 1) break;
            printf("Circle middle y :\n");
            if (scanf("%d", &cy) != 1) break;
            printf("Circle radius :\n");
            if (scanf("%d", &r) != 1) break;

            Forme *f = forme_creer_cercle(cx, cy, r);
            if (f == NULL) {
                fprintf(stderr, "Impossible de créer le cercle.\n");
                break;
            }
            liste_ajouter(&premiere, f);
            break;
        }
        case 2: {
            char chemin[256];
            if (premiere == NULL) {
                printf("Aucune forme à exporter.\n");
                break;
            }
            printf("Chemin du fichier SVG (ex. formes.svg) :\n");
            if (scanf("%255s", chemin) != 1) {
                fprintf(stderr, "Chemin de fichier invalide.\n");
                break;
            }
            if (svg_exporter(premiere, chemin)) {
                printf("Export réussi : %s\n", chemin);
            } else {
                perror("Impossible d'exporter le fichier SVG");
            }
            break;
        }
        case 4:
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }
    }

    liste_liberer(premiere);
    return 0;
}
