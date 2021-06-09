#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"
#include "structures.h"

int nombreHeureFormation(int idFormation){

    return formation[idFormation][5] - formation[idFormation][4];

}

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

int trouverMeilleurIndividu(Population population){

    float evalMeilleur = 100000;
    int idMeilleur;

    for(int i = 0; i < NBR_INDIVIDUS_POP; i++){

        if(evaluerIndividu(population, i) < evalMeilleur)
            idMeilleur = i;

    }

    return idMeilleur;

}
