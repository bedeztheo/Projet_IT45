#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "data.h"
#include "structures.h"


/**
 * @brief permet d'afficher la distance entre deux point sur le plan
 * @param X1 coordonnée en abcisse du premier point
 * @param X2 coordonnée en abcisse du deuxième point
 * @param Y1 coordonnée en ordonnée du premier point
 * @param Y2 coordonnée en ordonnée du deuxième point
 * @return distance entre le premier et le deuxième point
 */
float calculerDistanceXY(int X1, int X2, int Y1, int Y2){

    return sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));

}

/**
 * @brief permet de calculer la distance total parcouru par semaine pour assurer ses cours d'une interface contenu dans un individu
 * @param population la population dans laquelle est l'individu qui contient l'interface 
 * @param idIndividu l'id de l'individu qui contient l'interface 
 * @param idInterface l'id de l'interface dont on calcule la distance parcourue
 * @return la distance total parcouru par l'interface en une semaine pour son travail
 */
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

/**
 * @brief permet de calculer la distance total parcourue par semaine pour assurer ses cours de toutes les interfaces d'un individu
 * @param population la population dans laquelle est l'individu
 * @param idIndividu l'id de l'individu dont on calcule la distance total parcouru en une semaine par l'ensemble de ses interfaces pour le travail
 * @return la distance total parcouru par les interfaces de l'individu en une semaine pour leur travail
 */
float calculerTotalDistances(Population population, int idIndividu){

    float distanceTotale = 0;

    for(int i = 0; i < NBR_INTERFACES; i++){
        distanceTotale = distanceTotale + calculerDistanceTotaleInterface(population, idIndividu, i);
    }
    return distanceTotale;

}

/**
 * @brief permet de calculer l'écart type entre les distances parcourues en une semaien pour le travail pour l'ensemble de ses interfaces.
 * @param population la population dans laquelle est l'individu
 * @param idIndividu l'id de l'individu dont on calcule l'écart-type des distances parcourues en une semaine par chacune de ses interfaces pour le travail
 * @return l'écart-type des distances parcourues en une semaine par chacune des interfaces de l'individu pour le travail
 */
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

/**
 * @brief compte les pénalités d'un individu, càd le nombre de spécialités non satisfaites par l'emploi du temps de l'ensembles des interface
 * @param population la population dans laquelle est l'individu
 * @param idIndividu l'id de l'individu dont on compte le nombre de pénalité
 * @return le nombre de pénalité de l'individu
 */
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

/**
 * @brief fonction qui permet de calculer le fitness d'un individu -> à minimiser
 * @param population la population dans laquelle est l'individu
 * @param idIndividu l'id de l'individu dont on calcule le fitness
 * @return le fitness de l'individu
 */
float evaluerIndividu(Population population, int idIndividu){

    float evaluation, fCorr;

    int nbPenalites;

    fCorr = calculerTotalDistances(population, idIndividu) / NBR_FORMATIONS;

    nbPenalites = compterPenalites(population, idIndividu);

    return evaluation = 0.5 * (calculerTotalDistances(population, idIndividu) / NBR_INTERFACES + ecartTypeIndividu(population, idIndividu)) + 0.5 * fCorr * nbPenalites;

}
