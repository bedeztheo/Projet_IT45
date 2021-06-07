#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"
#include "structures.h"
#include "tests_sur_population.h"

void croiser2Interfaces(Population population, int idIndividu, int id1, int id2){

    int valAlea, tempoListeBits, typeFormation, croisementCompatible, tempoHeuresInterface1, tempoHeuresInterface2, competencesId1, competencesId2;

    for(int i = 0; i < 80; i++){

        valAlea = rand()% 2;

        typeFormation = formation[i][2];

        if(population[idIndividu].listeBits[id1 * 80 + i] == population[idIndividu].listeBits[id2 * 80 + i]){

            tempoHeuresInterface1 = population[idIndividu].nbHeuresSemaine[id1];
            tempoHeuresInterface2 = population[idIndividu].nbHeuresSemaine[id2];

        }else if(population[0].listeBits[id1 * 80 + i] == 1){

            tempoHeuresInterface1 = population[idIndividu].nbHeuresSemaine[id1] - nombreHeureFormation(i);
            tempoHeuresInterface2 = population[idIndividu].nbHeuresSemaine[id2] + nombreHeureFormation(i);

            croisementCompatible = formationCompatible(population, idIndividu, id2, i);

        }else{

            tempoHeuresInterface1 = population[idIndividu].nbHeuresSemaine[id1] + nombreHeureFormation(i);
            tempoHeuresInterface2 = population[idIndividu].nbHeuresSemaine[id2] - nombreHeureFormation(i);

            croisementCompatible = formationCompatible(population, idIndividu, id1, i);

        }

        competencesId1 = competences_interfaces[population[idIndividu].idIndividu[id1]][typeFormation];
        competencesId2 = competences_interfaces[population[idIndividu].idIndividu[id2]][typeFormation];


        if(valAlea == 1 && competencesId1 == competencesId2 && croisementCompatible == 1\
           && tempoHeuresInterface1 <= 35 && tempoHeuresInterface2 <= 35){

            tempoListeBits = population[idIndividu].listeBits[id1 * 80 + i];
            population[idIndividu].listeBits[id1 * 80 + i] = population[idIndividu].listeBits[id2 * 80 + i];
            population[idIndividu].listeBits[id2 * 80 + i] = tempoListeBits;

            population[idIndividu].nbHeuresSemaine[id1] = tempoHeuresInterface1;
            population[idIndividu].nbHeuresSemaine[id2] = tempoHeuresInterface2;

        }

    }

}

void croiserIndividu(Population population, int idIndividu){

    int tableauCroisement[NBR_INTERFACES], valAlea, idInt1, idInt2;

    for(int i = 0; i < NBR_INTERFACES; i++){

        tableauCroisement[i] = i;

    }

    for(int i = 0; i < NBR_INTERFACES / 2; i++){

        valAlea = rand()% (NBR_INTERFACES - 2 * i);

        idInt1 = tableauCroisement[valAlea];

        tableauCroisement[valAlea] = tableauCroisement[NBR_INTERFACES - 2 * i - 1];

        valAlea = rand()% (NBR_INTERFACES - 2 * i - 1);

        idInt2 = tableauCroisement[valAlea];

        tableauCroisement[valAlea] = tableauCroisement[NBR_INTERFACES - 2 * i - 2];

        croiser2Interfaces(population, idIndividu, idInt1, idInt2);

    }

}

void croiserPopulation(Population population){

    for(int i = 0; i < NBR_INDIVIDUS_POP; i++)
        croiserIndividu(population, i);

}

void initialiserPopulation(Population population){



    int nbInterfacesUniquementLPC = 0, nbInterfacesUniquementSignes = 0, nbInterfacesSignesLPC = 0;
    int nbInterSignesLPC_Placees, nbInterSignesPlacees, nbInterLPCPlacees;


    for(int i = 0; i < NBR_INTERFACES; i++){         // comptage competences interfaces, commun à tous les individus

        if(competences_interfaces[i][0] == 1 && competences_interfaces[i][1] == 1 ){    //Interface codant et LPC et Signes
            nbInterfacesSignesLPC++;
        }else if(competences_interfaces[i][0] == 1){
            nbInterfacesUniquementSignes++;
        }else{
            nbInterfacesUniquementLPC++;
        }

    }

    for(int i = 0; i < NBR_INDIVIDUS_POP; i++){

        nbInterSignesLPC_Placees = 0;
        nbInterSignesPlacees = 0;
        nbInterLPCPlacees = 0;

        for(int j = 0; j < NBR_INTERFACES; j++){         //Tri dans la population des interfaces selon leurs competences, commun a tous les individus

            if(competences_interfaces[j][0] == 1 && competences_interfaces[j][1] == 1 ){    //Interface codant et LPC et Signes

                population[i].idIndividu[nbInterSignesLPC_Placees] = j;
                nbInterSignesLPC_Placees++;

            }else if(competences_interfaces[j][0] == 1){

                population[i].idIndividu[nbInterSignesPlacees + nbInterfacesSignesLPC] = j;
                nbInterSignesPlacees++;

            }else{

                population[i].idIndividu[nbInterLPCPlacees + nbInterfacesSignesLPC + nbInterfacesUniquementSignes] = j;
                nbInterLPCPlacees++;

            }

            population[i].nbHeuresSemaine[j] = 0;

        }

    }

    /*for(int i = 0; i < NBR_INDIVIDUS_POP; i++){

        for(int j = 0; j < NBR_INTERFACES; j++){
            printf("Interface n %d -> id n %d.\tCompetences signes = %d, competences LPC = %d\n", j, population[i].idIndividu[j], competences_interfaces[population[i].idIndividu[j]][0], competences_interfaces[population[i].idIndividu[j]][1]);
        }
        printf("\n");
    }*/

    for(int i = 0; i < NBR_INDIVIDUS_POP; i++){

        for(int j = 0; j < (NBR_FORMATIONS * NBR_INTERFACES); j++){
            population[i].listeBits[j] = 0;
        }

    }

    for(int i = 0; i < NBR_INDIVIDUS_POP; i++){

        for(int j = 0; j < NBR_FORMATIONS; j++){         //remplissage aleatoire des formations

            int nbHeuresAvecFormation = 0, competencesIntPourFormation;
            int formationPlacee = 0;
            int idInt = 0;


            while(formationPlacee != 1){        //Tant que la formation n'est pas placee

                nbHeuresAvecFormation = population[i].nbHeuresSemaine[idInt] + nombreHeureFormation(j);
                competencesIntPourFormation = competences_interfaces[population[i].idIndividu[idInt]][formation[j][2]];

                if(nbHeuresAvecFormation <= NBR_HEURES_INT_INIT && competencesIntPourFormation == 1 && formationCompatible(population, i, idInt, j) == 1){

                    population[i].listeBits[idInt * 80 + j] = 1;
                    population[i].nbHeuresSemaine[idInt] = population[i].nbHeuresSemaine[idInt] + nombreHeureFormation(j);
                    formationPlacee = 1;

                }else{
                    idInt++;

                }

            }

        }

    }

    printf("Nombre LPC : %d, nb Signes : %d, poly signes : %d \n", nbInterfacesUniquementLPC, nbInterfacesUniquementSignes, nbInterfacesSignesLPC);

}
