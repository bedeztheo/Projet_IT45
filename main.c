#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "structures.h"
#include "data.h"

/* competences des interfaces en SIGNES et CODAGE*/
int competences_interfaces[NBR_INTERFACES][2]={
    {1,0}, /* comp�tence en langages des SIGNES mais pas en CODAGE LPC */
    {0,1}, /* pas de comp�tence en langages des SIGNES mais comp�tence en CODAGE LPC */
    {1,0},
    {1,0},
    {1,0},
    {1,1},
    {1,0},
    {1,1},
    {1,0},
    {1,0},
    {0,1},
    {0,1},
    {1,0},
    {0,1},
    {1,0},
    {1,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {1,0}
};

/* specialite des interfaces */
int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES]={
    {1,0,0,1,1},
    {0,1,1,0,1},
    {0,0,0,1,1},
    {0,0,0,1,0},
    {1,0,0,0,0},
    {0,1,0,0,1},
    {1,0,1,0,0},
    {0,0,0,1,1},
    {0,0,0,0,0},
    {0,0,0,1,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {1,1,0,0,1},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,1,1,1,0},
    {0,0,0,0,1},
    {0,0,0,1,0},
    {0,0,0,1,0},
    {0,0,0,1,0},
    {0,0,1,0,0},
    {0,1,1,0,0},
    {1,0,0,1,0}
};

/* coordonn�es des centres de formation, des interfaces et des apprenants */
float coord[NBR_NODES][2]={

    /* Les interfaces se rendent du centre SESSAD � l'�cole de formation */
    {57,94}, /* centre 0 */

    /* Centres de formation */
    {39,14}, /* ecole formation SPECIALITE_MENUISERIE */
    {161,75}, /* ecole formation SPECIALITE_ELECTRICITE */
    {144,91}, /* ecole formation SPECIALITE_MECANIQUE */
    {178,67}, /* ecole formation SPECIALITE_INFORMATIQUE */
    {184,125}, /* ecole formation SPECIALITE_CUISINE */

    /* Apprenants */
    {100,191}, /* apprenant 0 */
    {161,0}, /* apprenant 1 */
    {176,93}, /* apprenant 2 */
    {85,175}, /* apprenant 3 */
    {190,40}, /* apprenant 4 */
    {152,37}, /* apprenant 5 */
    {136,96}, /* apprenant 6 */
    {30,142}, /* apprenant 7 */
    {175,20}, /* apprenant 8 */
    {167,148}, /* apprenant 9 */
    {101,142}, /* apprenant 10 */
    {165,57}, /* apprenant 11 */
    {24,175}, /* apprenant 12 */
    {94,34}, /* apprenant 13 */
    {79,104}, /* apprenant 14 */
    {60,68}, /* apprenant 15 */
    {141,34}, /* apprenant 16 */
    {87,19}, /* apprenant 17 */
    {148,69}, /* apprenant 18 */
    {102,1}, /* apprenant 19 */
    {95,30}, /* apprenant 20 */
    {106,140}, /* apprenant 21 */
    {130,56}, /* apprenant 22 */
    {48,177}, /* apprenant 23 */
    {141,60}, /* apprenant 24 */
    {92,58}, /* apprenant 25 */
    {88,46}, /* apprenant 26 */
    {151,135}, /* apprenant 27 */
    {35,60}, /* apprenant 28 */
    {40,51}, /* apprenant 29 */
    {193,199}, /* apprenant 30 */
    {82,111}, /* apprenant 31 */
    {97,41}, /* apprenant 32 */
    {4,171}, /* apprenant 33 */
    {135,164}, /* apprenant 34 */
    {154,22}, /* apprenant 35 */
    {130,159}, /* apprenant 36 */
    {175,135}, /* apprenant 37 */
    {118,49}, /* apprenant 38 */
    {197,109}, /* apprenant 39 */
    {53,193}, /* apprenant 40 */
    {199,140}, /* apprenant 41 */
    {109,63}, /* apprenant 42 */
    {67,83}, /* apprenant 43 */
    {161,65}, /* apprenant 44 */
    {140,56}, /* apprenant 45 */
    {89,91}, /* apprenant 46 */
    {41,42}, /* apprenant 47 */
    {154,99}, /* apprenant 48 */
    {178,93}, /* apprenant 49 */
    {73,122}, /* apprenant 50 */
    {191,82}, /* apprenant 51 */
    {158,156}, /* apprenant 52 */
    {149,103}, /* apprenant 53 */
    {140,82}, /* apprenant 54 */
    {82,182}, /* apprenant 55 */
    {185,26}, /* apprenant 56 */
    {96,106}, /* apprenant 57 */
    {152,101}, /* apprenant 58 */
    {184,188}, /* apprenant 59 */
    {145,125}, /* apprenant 60 */
    {56,101}, /* apprenant 61 */
    {93,59}, /* apprenant 62 */
    {52,174}, /* apprenant 63 */
    {159,178}, /* apprenant 64 */
    {154,55}, /* apprenant 65 */
    {17,143}, /* apprenant 66 */
    {158,101}, /* apprenant 67 */
    {193,33}, /* apprenant 68 */
    {113,25}, /* apprenant 69 */
    {24,161}, /* apprenant 70 */
    {127,148}, /* apprenant 71 */
    {54,184}, /* apprenant 72 */
    {162,13}, /* apprenant 73 */
    {158,36}, /* apprenant 74 */
    {170,153}, /* apprenant 75 */
    {70,53}, /* apprenant 76 */
    {153,5}, /* apprenant 77 */
    {156,148}, /* apprenant 78 */
    {153,28}/* apprenant 79 */
};

/* formation : id formation, specialite ou centre de formation, competence, jour, horaire debut formation, horaire fin formation */
int formation[NBR_FORMATION][6]={
   {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,16,18},
   {1,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,13,19},
   {2,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,8,11},
   {3,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,8,11},
   {4,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,8,10},
   {5,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,8,11},
   {6,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MERCREDI,15,18},
   {7,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,10,12},
   {8,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,8,10},
   {9,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,14,19},
   {10,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,13,19},
   {11,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,13,19},
   {12,SPECIALITE_CUISINE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {13,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,10,12},
   {14,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,13,15},
   {15,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,13,19},
   {16,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,10,12},
   {17,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,13,16},
   {18,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,10,12},
   {19,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,9,12},
   {20,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,16,19},
   {21,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,10,12},
   {22,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,16,18},
   {23,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,10,12},
   {24,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,9,12},
   {25,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,16,18},
   {26,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MERCREDI,16,18},
   {27,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,15,17},
   {28,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,14,19},
   {29,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,15,17},
   {30,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,13,19},
   {31,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,9,12},
   {32,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,LUNDI,13,15},
   {33,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MERCREDI,10,12},
   {34,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,8,10},
   {35,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,16,19},
   {36,SPECIALITE_CUISINE,COMPETENCE_SIGNES,LUNDI,13,17},
   {37,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,14,16},
   {38,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,15,17},
   {39,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MARDI,8,10},
   {40,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,16,18},
   {41,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,9,12},
   {42,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,13,18},
   {43,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,16,19},
   {44,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,8,10},
   {45,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,15,18},
   {46,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,14,17},
   {47,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MERCREDI,10,12},
   {48,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,14,19},
   {49,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,8,10},
   {50,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,13,18},
   {51,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,JEUDI,14,17},
   {52,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,15,19},
   {53,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,9,11},
   {54,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,15,19},
   {55,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,10,12},
   {56,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,16,19},
   {57,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,14,18},
   {58,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,9,12},
   {59,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,8,11},
   {60,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MERCREDI,14,18},
   {61,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,8,11},
   {62,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,10,12},
   {63,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,8,10},
   {64,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,9,12},
   {65,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,VENDREDI,13,15},
   {66,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,9,11},
   {67,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,14,18},
   {68,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,16,19},
   {69,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,14,16},
   {70,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,13,19},
   {71,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,JEUDI,8,10},
   {72,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,15,17},
   {73,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,8,11},
   {74,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,8,12},
   {75,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,14,17},
   {76,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {77,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,10,12},
   {78,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,LUNDI,15,17},
   {79,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,8,10}
};

Individu population[NBR_INTERFACES];

int nombreHeureFormation(int idFormation){

    return formation[idFormation][5] - formation[idFormation][4];

}

void afficherInterface(int idInterface){

    int i;

    printf("Interface %d: \t", idInterface);

    for(i = 0; i < NBR_FORMATIONS; i++)
        printf("%d", population[0].listeBits[idInterface * 80 + i]);

    printf("\n");

}

void afficherIndividu(int idIndividu){

    int i;

    printf("Individu ou solution n�%d\n", idIndividu);

    for(i = 0; i < 24; i++)
        afficherInterface(i);

}

void afficherNbHeuresInterfaces(){

    int i;

    for(i = 0; i < 24; i++)
        printf("nb heure semaine int %d: %d\n", i, population[0].nbHeuresSemaine[i]);

}

void afficherEDTInterface(int idInterface){

    int i;

    printf("Emploi du temps de l'interface %d\n", idInterface);

    for(i = 0; i < 80; i++){

        if(population[0].listeBits[idInterface * 80 + i] == 1){

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

int formationCompatible(int idInterface, int idFormation){

    /**
     *  @brief Fonction qui renvoie 1 si la formation est compatible avec l'emploi du temps de l'interface
    **/

    int i, jourFormation = formation[idFormation][3], hDebutFormation = formation[idFormation][4], hFinFormation = formation[idFormation][5];

    for(i = 0; i < 80; i++){

        if(population[0].listeBits[idInterface * 80 + i] == 1 && formation[i][3] == jourFormation){

            if((formation[i][4] >= hDebutFormation && formation[i][4] < hFinFormation) || (formation[i][5] > hDebutFormation && formation[i][5] <= hFinFormation)){
                return 0;
            }

        }

    }

    return 1;

}

float evaluerIndividu(int idIndividu){

    int evaluation, fCorr, nbPenalites;

    fCorr = calculerDistanceTotaleInterface(idIndividu) / NBR_FORMATIONS;

    nbPenalites = compterPenalites(idIndividu);

    return evaluation = 0.5 * (calculerTotalDistances(idIndividu) / NBR_INTERFACES + ecartTypeIndividu(idIndividu)) + 0.5 * fCorr * nbPenalites;

}

float calculerDistanceXY(int X1, int X2, int Y1, int Y2){

    return sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));

}

int calculerTotalDistances(int idIndividu){

    int i, distanceTotale = 0;

    for(i = 0; i < NBR_INTERFACES; i++){
        distanceTotale = distanceTotale + calculerDistanceTotaleInterface(i);
    }
    return distanceTotale;

}

int calculerDistanceTotaleInterface(int idInterface){

    int i, j, endroit1 = -1, endroit2 = -1;

    int distanceTotale = 0;

    int idCentresParHeures[14];

    idCentresParHeures[0] = 0;
    idCentresParHeures[13] = 0;

    for(i = 0; i < 7; i++){

        for(j = 1; j < 13; j++)
            idCentresParHeures[j] = -1;

        for(j = 0; j < NBR_FORMATIONS; j++){

            if(population[0].listeBits[idInterface * 80 + j] == 1 && formation[j][3] == i){

                idCentresParHeures[formation[j][4] - 7] = formation[j][1] + 1;

            }
        }

        endroit1 = idCentresParHeures[0];

        for(j = 1; j < 14; j++){

            if(idCentresParHeures[j] != -1){

                endroit2 = idCentresParHeures[j];

                distanceTotale = distanceTotale + calculerDistanceXY(coord[endroit1][0], coord[endroit2][0], coord[endroit1][1], coord[endroit2][1]);

                endroit1 = endroit2;

            }

        }

    }

    return distanceTotale;

}

int ecartTypeIndividu(int individu){

    int i, moyenne, resultat = 0;

    moyenne = calculerTotalDistances(0) / NBR_INTERFACES;

    for(i = 0; i < NBR_INTERFACES; i++){

        resultat = pow(moyenne - calculerDistanceTotaleInterface(i), 2);

    }

    resultat = resultat / NBR_INTERFACES;

    resultat = sqrt(resultat);

    return resultat;

}

int compterPenalites(int idIndividu){

    int i, j, specialiteFormation, penalites = 0;

    for(i = 0; i < NBR_FORMATIONS; i++){

        specialiteFormation = formation[i][1];
        j = 0;

        while(j < NBR_INTERFACES){

            if(population[0].listeBits[j * 80 + i] == 1 && specialite_interfaces[population[0].idIndividu[j]][specialiteFormation] == 0){

                penalites++;
                j = NBR_INTERFACES;

            }

            j++;

        }

    }

    return penalites;

}

void croiser2Interfaces(int id1, int id2){

    //afficherInterface(id1);
    //afficherInterface(id2);

    int i, valAlea, tempoListeBits, typeFormation, tempoHeuresInterface1, tempoHeuresInterface2, competencesId1, competencesId2;

    for(i = 0; i < 80; i++){

        valAlea = rand()% 2;

        typeFormation = formation[i][2];

        if(population[0].listeBits[id1 * 80 + i] == population[0].listeBits[id2 * 80 + i]){

            tempoHeuresInterface1 = population[0].nbHeuresSemaine[id1];
            tempoHeuresInterface2 = population[0].nbHeuresSemaine[id2];

        }else if(population[0].listeBits[id1 * 80 + i] == 1){

            tempoHeuresInterface1 = population[0].nbHeuresSemaine[id1] - nombreHeureFormation(i);
            tempoHeuresInterface2 = population[0].nbHeuresSemaine[id2] + nombreHeureFormation(i);

        }else{

            tempoHeuresInterface1 = population[0].nbHeuresSemaine[id1] + nombreHeureFormation(i);
            tempoHeuresInterface2 = population[0].nbHeuresSemaine[id2] - nombreHeureFormation(i);

        }

        competencesId1 = competences_interfaces[population[0].idIndividu[id1]][typeFormation];
        competencesId2 = competences_interfaces[population[0].idIndividu[id2]][typeFormation];

        //if(valAlea == 1 && competencesId1 == competencesId2 && formationCompatible(id1, i) == 1 && formationCompatible(id2, i) == 1 \
        //   && tempoHeuresInterface1 <= 35 && tempoHeuresInterface2 <= 35){

        if(valAlea == 1 && competencesId1 == competencesId2 \
           && tempoHeuresInterface1 <= 35 && tempoHeuresInterface2 <= 35){

            tempoListeBits = population[0].listeBits[id1 * 80 + i];
            population[0].listeBits[id1 * 80 + i] = population[0].listeBits[id2 * 80 + i];
            population[0].listeBits[id2 * 80 + i] = tempoListeBits;

            population[0].nbHeuresSemaine[id1] = tempoHeuresInterface1;
            population[0].nbHeuresSemaine[id2] = tempoHeuresInterface2;

        }

    }

    //afficherInterface(id1);
    //afficherInterface(id2);

}

void initialiserPopulation(){



    int i, j, nbInterfacesUniquementLPC = 0, nbInterfacesUniquementSignes = 0, nbInterfacesSignesLPC = 0;
    int nbInterSignesLPC_Placees = 0, nbInterSignesPlacees = 0, nbInterLPCPlacees = 0;
    int nbHeures, edtRempli;

    int compteur = 0;


    for(i = 0; i < NB_INTERFACES; i++){         // comptage comp�tences interfaces    commun � tous les individus

        if(competences_interfaces[i][0] == 1 && competences_interfaces[i][1] == 1 ){    //Interface codant et LPC et Signes
            nbInterfacesSignesLPC++;
        }else if(competences_interfaces[i][0] == 1){
            nbInterfacesUniquementSignes++;
        }else{
            nbInterfacesUniquementLPC++;
        }

    }

    for(i = 0; i < NB_INTERFACES; i++){         //Tri dans la population des interfaces selon leurs comp�tences        commun a tous les individus

        if(competences_interfaces[i][0] == 1 && competences_interfaces[i][1] == 1 ){    //Interface codant et LPC et Signes

            population[0].idIndividu[nbInterSignesLPC_Placees] = i;
            nbInterSignesLPC_Placees++;

        }else if(competences_interfaces[i][0] == 1){

            population[0].idIndividu[nbInterSignesPlacees + nbInterfacesSignesLPC] = i;
            nbInterSignesPlacees++;

        }else{

            population[0].idIndividu[nbInterLPCPlacees + nbInterfacesSignesLPC + nbInterfacesUniquementSignes] = i;
            nbInterLPCPlacees++;

        }

        population[0].nbHeuresSemaine[i] = 0;

    }

    for(i = 0; i < 1920; i++){

        population[0].listeBits[i] = 0;

    }

    for(i = 0; i < NB_INTERFACES; i++)
        printf("Interface n %d -> id n %d. Competences signes = %d, competences LPC = %d\n", i, population[0].idIndividu[i], competences_interfaces[population[0].idIndividu[i]][0], competences_interfaces[population[0].idIndividu[i]][1]);

    for(i = 0; i < NBR_FORMATIONS; i++){         //remplissage al�atoire des formations

        int nbHeuresAvecFormation = 0, competencesIntPourFormation;
        int formationPlacee = 0;
        int j = 0;

        while(formationPlacee != 1){        //Tant que la formation n'est pas plac�e

            nbHeuresAvecFormation = population[0].nbHeuresSemaine[j] + nombreHeureFormation(i);
            competencesIntPourFormation = competences_interfaces[population[0].idIndividu[j]][formation[i][2]];

            if(nbHeuresAvecFormation <= NBR_HEURES_INT_INIT && competencesIntPourFormation == 1 && formationCompatible(j, i) == 1){

                population[0].listeBits[j * 80 + i] = 1;
                population[0].nbHeuresSemaine[j] = population[0].nbHeuresSemaine[j] + nombreHeureFormation(i);
                formationPlacee = 1;

                //printf(" interface %d\n", j);

            }else{
                j++;
            }

        }




    }

    //printf("compteur = %d", compteur);
    printf("Nombre LPC : %d, nb Signes : %d, poly signes : %d \n", nbInterfacesUniquementLPC, nbInterfacesUniquementSignes, nbInterfacesSignesLPC);



    /*for(i = 0; i < 1920; i++){

        if(population[0].listeBits[i] == 1)
            compteur++;

        printf(" %d", population[0].listeBits[i]);

    }*/

    //printf("\ncompteur = %d\n", compteur);

}

int main()
{

    // Fait plutot ca : Population P1 = (Population)malloc(sizeof(Individu)*NbrIndividuPopulationBase); plutot qu'une variable global

    srand( time( NULL ) );

    //printf("nbr heure forma n 10 = %d", nombreHeureFormation(10));

    initialiserPopulation();

    afficherIndividu(0);

    //for(i = 0; i < 11; i++)
    //    croiser2Interfaces(2 * i, 2 * i + 1);

    //printf("\n");

    //afficherIndividu(0);

    //afficherNbHeuresInterfaces();

    afficherEDTInterface(0);
    /*afficherEDTInterface(1);
    afficherEDTInterface(2);*/

    printf("Nb penalites = %d\n", compterPenalites(0));

    printf("distance totale interface %d = %d\n", 0, calculerDistanceTotaleInterface(0));

    printf("distance totale = %d\n", calculerTotalDistances(0));

    printf("Evaluation individu 0 = %f", evaluerIndividu(0));

    for(int i = 0; i < 11; i++)
        croiser2Interfaces(2 * i, 2 * i + 1);

    printf("Evaluation individu 0 = %f", evaluerIndividu(0));

    for(int i = 0; i < 11; i++)
        croiser2Interfaces(2 * i, 2 * i + 1);

    printf("Evaluation individu 0 = %f", evaluerIndividu(0));

}



