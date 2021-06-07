#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "data.h"
#include "structures.h"

float calculerDistanceXY(int X1, int X2, int Y1, int Y2){

    return sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));

}

float calculerDistanceTotaleInterface(Population population, int idIndividu, int idInterface){

    int endroit1 = -1, endroit2 = -1;

    float distanceTotale = 0;

    int idCentresParHeures[14];

    idCentresParHeures[0] = 0;
    idCentresParHeures[13] = 0;

    for(int i = 0; i < 7; i++){

        for(int j = 1; j < 13; j++)
            idCentresParHeures[j] = -1;

        for(int j = 0; j < NBR_FORMATIONS; j++){

            if(population[idIndividu].listeBits[idInterface * 80 + j] == 1 && formation[j][3] == i){

                idCentresParHeures[formation[j][4] - 7] = formation[j][1] + 1;

            }
        }

        endroit1 = idCentresParHeures[0];

        for(int j = 1; j < 14; j++){

            if(idCentresParHeures[j] != -1){

                endroit2 = idCentresParHeures[j];

                distanceTotale = distanceTotale + calculerDistanceXY(coord[endroit1][0], coord[endroit2][0], coord[endroit1][1], coord[endroit2][1]);

                endroit1 = endroit2;

            }

        }

    }

    return distanceTotale;

}

float calculerTotalDistances(Population population, int idIndividu){

    float distanceTotale = 0;

    for(int i = 0; i < NBR_INTERFACES; i++){
        distanceTotale = distanceTotale + calculerDistanceTotaleInterface(population, idIndividu, i);
    }
    return distanceTotale;

}

float ecartTypeIndividu(Population population, int idIndividu){

    float moyenne, resultat = 0;

    moyenne = calculerTotalDistances(population, idIndividu) / NBR_INTERFACES;

    for(int i = 0; i < NBR_INTERFACES; i++){

        resultat = pow(moyenne - calculerDistanceTotaleInterface(population, idIndividu, i), 2);

    }

    resultat = resultat / NBR_INTERFACES;

    resultat = sqrt(resultat);

    return resultat;

}

int compterPenalites(Population population, int idIndividu){

    int j, specialiteFormation, penalites = 0;

    for(int i = 0; i < NBR_FORMATIONS; i++){

        specialiteFormation = formation[i][1];
        j = 0;

        while(j < NBR_INTERFACES){

            if(population[idIndividu].listeBits[j * 80 + i] == 1 && specialite_interfaces[population[idIndividu].idIndividu[j]][specialiteFormation] == 0){

                penalites++;
                j = NBR_INTERFACES;

            }

            j++;

        }

    }

    return penalites;

}

float evaluerIndividu(Population population, int idIndividu){

    float evaluation, fCorr;

    int nbPenalites;

    fCorr = calculerTotalDistances(population, idIndividu) / NBR_FORMATIONS;

    nbPenalites = compterPenalites(population, idIndividu);

    return evaluation = 0.5 * (calculerTotalDistances(population, idIndividu) / NBR_INTERFACES + ecartTypeIndividu(population, idIndividu)) + 0.5 * fCorr * nbPenalites;

}
