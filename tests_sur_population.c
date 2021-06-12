#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"
#include "structures.h"
#include "fonctions_pour_evaluation.h"

/**
 * @brief calcule le nombre d'heure que dure une formation
 * @param idFormation l'id de la formation dont on calcule la durée
 * @return le nombre d'heure que dure la formation
 */
int nombreHeureFormation(int idFormation){

    return formation[idFormation][5] - formation[idFormation][4];

}

/**
 * @brief permet de savoir si une formation est compatible avec l'emploi du temps d'une interface.
 * @param population la population qui contient l'individu qui contient l'interface
 * @param idIndividu l'id de l'individu qui contient l'interface
 * @param idInterface l'id de l'interface dont on calcule la compatibilité d'emploi du temps avec la nouvelle formation
 * @param ifFormation l'id de la nouvelle formation dont on calcule la compatibilité avec l'emploi du temps de l'interface
 * @return 1 si compatible, 0 sinon
 */
int formationCompatible(Population population, int idIndividu, int idInterface, int idFormation){

    int jourFormation = formation[idFormation][3], hDebutFormation = formation[idFormation][4], hFinFormation = formation[idFormation][5];

    for(int i = 0; i < 80; i++){

        if(population[idIndividu].listeBits[idInterface * 80 + i] == 1 && formation[i][3] == jourFormation){

            if((formation[i][4] >= hDebutFormation && formation[i][4] < hFinFormation) || (formation[i][5] > hDebutFormation && formation[i][5] <= hFinFormation)){
                return 0;
            }

        }

    }
    return 1;

}

/**
 * @brief permet de trouver l'individu qui possède le meilleur fitness au sein d'une population
 * @param population la population à étudier
 * @param idIndividu l'id de l'individu qui contient l'interface
 * @return l'id du meilleur individu
 */
int trouverMeilleurIndividu(Population population){

    float evalMeilleur = 100000;
    int idMeilleur;

    for(int i = 0; i < NBR_INDIVIDUS_POP; i++){

        if(evaluerIndividu(population, i) < evalMeilleur)
            idMeilleur = i;

    }

    return idMeilleur;

}
