#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#include "structures.h"
#include "data.h"
#include "affichage.h"
#include "fonctions_pour_evaluation.h"
#include "tests_sur_population.h"
#include "actions_sur_population.h"

int main()
{

    int idMeilleurIndividu;

    Population P1 = (Population) malloc(sizeof(Individu) * NBR_INDIVIDUS_POP);

    srand( time( NULL ) );

    initialiserPopulation(P1);


    for(int i = 0; i < 10000; i++){
        croiserPopulation(P1);
        //printf("\nEvaluation individu 0 = %f\n", evaluerIndividu(P1, 0));
    }

    idMeilleurIndividu = trouverMeilleurIndividu(P1);

    printf("Meilleure solution individu %d, evaluation = %f", idMeilleurIndividu, evaluerIndividu(P1, idMeilleurIndividu));



}



