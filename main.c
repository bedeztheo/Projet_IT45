#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <time.h>
#include <math.h>

#include "structures.h"
#include "data.h"
#include "affichage.h"
#include "fonctions_pour_evaluation.h"
#include "tests_sur_population.h"
#include "actions_sur_population.h"

int arret = 0;

void traitant_SIGINT(int num) {

    if (num != SIGINT){

    }else{

        arret = 1;
        printf("\nFin de la recherche ordonnée par l'utilisateur\n");

	}

}

int main(int argc, char **argv)
{

    clock_t debut, fin;

    int idMeilleurIndividu;

    char generationNouvelleInstance;

    Population P1 = (Population) malloc(sizeof(Individu) * NBR_INDIVIDUS_POP);

    srand( time( NULL ) );

    printf("********************************************************************************************\n\n\n\t\t\
           Bienvenue sur notre projet d'IT45\n\n\n");

    printf("Voulez-vous generez un nouvel ensemble de donnee à traiter par l'algorithme ?\n");
    printf("Tapez sur o pour OUI ou sur n'importe quel touche pour NON\n");
    generationNouvelleInstance = (char)getchar();
    if (generationNouvelleInstance == 'o')
    {
        execlp("bash","bash","remplacementData.sh",(char*) NULL);
        exit(0);
    }
    printf("La recherche de la meilleur solution est une boucle infinie. L'utilisateur peut appuyer sur \nCtrl + C afin d'arrêter la recherche et d'afficher la meilleur solution trouvée jusque la.");

    printf("\n\n********************************************************************************************\n");

    printf("\n\n\t\tAppuyez sur la touche entree pour lancer le programme");


    getchar();

    debut = clock();

    initialiserPopulation(P1);

    signal(SIGINT,traitant_SIGINT);

    while(arret == 0){

        croiserPopulation(P1);

    }

    fin = clock();

    idMeilleurIndividu = trouverMeilleurIndividu(P1);

    printf("\nMeilleure solution individu %d, evaluation = %f\n\n", idMeilleurIndividu, evaluerIndividu(P1, idMeilleurIndividu));

    printf("Temps d'execution = %.1f sec.\n", (float) ((fin - debut) * 1e-6));


}


