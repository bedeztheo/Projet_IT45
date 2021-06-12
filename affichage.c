#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"
#include "structures.h"


/**
 * @brief fonction permettant d'afficher le programme bit par bit d'une interface d'un individu donné.
 * @param population la population dans laquelle est l'individu qui contient l'interface que l'on souhaite afficher
 * @param idIndividu l'id de l'individu dans lequel est contenue l'interface à afficher
 * @param idInterface l'id de l'interface à afficher
 * @return none
 */

void afficherInterface(Population population, int idIndividu, int idInterface){

    printf("Interface %d: \t", idInterface);

    for(int i = 0; i < NBR_FORMATIONS; i++)
        printf("%d", population[idIndividu].listeBits[idInterface * 80 + i]);

    printf("\n");

}

/**
 * @brief fonction permettant d'afficher le programme bit par bit le programme de toutes les interfaces dans un individu donné
 * @param population la population dans laquelle est l'individu à afficher
 * @param idIndividu l'id de l'individu à afficher
 * @return none
 */

void afficherIndividu(Population population, int idIndividu){

    printf("Individu ou solution n %d\n", idIndividu);

    for(int i = 0; i < 24; i++)
        afficherInterface(population, idIndividu, i);

}

/**
 * @brief fonction permettant d'afficher le programme bit par bit de tous les individus (ensemble de toutes les interfaces) d'une population
 * @param population la population à afficher
 * @return none
 */
void afficherPopulation(Population population){

    for(int i = 0; i < NBR_INDIVIDUS_POP; i++)
        afficherIndividu(population, i);

}

/**
 * @brief fonction permettant d'afficher le nombre d'heure de travail par semaine de toutes les interfaces d'un individu
 * @param population la population dans laquelle est l'individu à afficher
 * @param idIndividu l'id de l'individu à afficher
 * @return none
 */
void afficherNbHeuresInterfaces(Population population, int idIndividu){

    for(int i = 0; i < 24; i++)
        printf("nb heure semaine int %d: %d\n", i, population[idIndividu].nbHeuresSemaine[i]);

}

/**
 * @brief fonction permettant d'afficher l'emploi du temps d'une interface contenue dans un individu d'une population
 * @param population la population dans laquelle est l'individu qui contient l'interface à afficher
 * @param idIndividu l'id de l'individu  qui contient l'interface à afficher
 * @param idInterface l'id de l'interface à afficher
 * @return none
 */
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
