#include <stdio.h>
#include <stdlib.h>
#include "forme.h"
#include "svg.h"
#include "liste.h"



int main (){
    printf("Bienvenue dans le lieu où vous etes désormais le maitre des formes en SVG\n");
    Forme *premiere = NULL;
    int choice = 0;
    while (choice != 4) 
      {
        printf("\nWhat do you want to do ?\n");
        printf("\n1 : Make\n");
        printf("\n2 : Export\n");
        printf("\n3 : Modify\n");
        printf("\n4 : Quit\n");
        scanf("%d", &choice);


        switch (choice)
        {
        case 1 : printf("Which shape do you want to make ?\n");
                 printf("\n 1 : Circle\n");
                 scanf("%d", &choice);
                 int cx, cy, r;
                 switch(choice){
                    case 1 :
                             printf("Circle middle x :\n");
                             scanf("%d", &cx);
                             printf("Circle middle y :\n");
                             scanf("%d", &cy);
                             printf(" Circle radius : \n");
                             scanf("%d", &r);
                             Forme *f = forme_creer_cercle(cx, cy, r );
                             liste_ajouter(&premiere, f);
                             

                 }
                
            break;
        case 2 : svg_exporter_forme(const Forme *f, FILE *out);
                 
        default:
            break;
        }

    }

return 0;
}