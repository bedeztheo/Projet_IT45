#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"
#include "structures.h"

void afficherInterface(Population population, int idIndividu, int idInterface){

    printf("Interface %d: \t", idInterface);

    for(int i = 0; i < NBR_FORMATIONS; i++)
        printf("%d", population[idIndividu].listeBits[idInterface * 80 + i]);

    printf("\n");

}

void afficherIndividu(Population population, int idIndividu){

    printf("Individu ou solution n %d\n", idIndividu);

    for(int i = 0; i < 24; i++)
        afficherInterface(population, idIndividu, i);

}

void afficherNbHeuresInterfaces(Population population, int idIndividu){

    for(int i = 0; i < 24; i++)
        printf("nb heure semaine int %d: %d\n", i, population[idIndividu].nbHeuresSemaine[i]);

}

void afficherEDTInterface(Population population, int idIndividu, int idInterface){

    printf("Emploi du temps de l'interface %d\n", idInterface);

    for(int i = 0; i < 80; i++){

        if(population[idIndividu].listeBits[idInterface * 80 + i] == 1){

            switch(formation[i][3]){

                case 1 : printf("LUNDI \t\t");
                    break;

                case 2 : printf("MARDI \t\t");
                    break;

                case 3 : printf("MERCREDI \t");
                    break;

                case 4 : printf("JEUDI \t\t");
                    break;

                case 5 : printf("VENDREDI \t");
                    break;

                case 6 : printf("SAMEDI \t\t");
                    break;

            }

            printf("%d\t%d\tformation num %d\n", formation[i][4], formation[i][5], i);

        }

    }

}
