#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#include "structures.h"
#include "data.h"
#include "affichage.h"
#include "fonctions_pour_evaluation.h"

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




int main()
{

    Population P1 = (Population) malloc(sizeof(Individu) * NBR_INDIVIDUS_POP);

    srand( time( NULL ) );

    initialiserPopulation(P1);

    //afficherIndividu(P1, 0);

    //printf("Evaluation individu 0 = %f\n", evaluerIndividu(P1, 0));

    //for(int i = 0; i < 11; i++)
       // croiser2Interfaces(P1, 0, 2 * i, 2 * i + 1);

    printf("\nouaissss");

    //afficherNbHeuresInterfaces(P1, 0);

    //afficherEDTInterface(P1, 0, 0);

    //croiser2Interfaces(P1, 0, 0, 18);

    //printf("Nb penalites = %d\n", compterPenalites(P1, 0));

   // for(int i = 0; i < 11; i++)
     //   croiser2Interfaces(P1, 1, 2 * i, 2 * i + 1);

    afficherIndividu(P1, 0);
    afficherIndividu(P1, 1);
    afficherIndividu(P1, 2);
    afficherIndividu(P1, 3);
    afficherIndividu(P1, 4);

    /*for(int i = 0; i < 11; i++)
        croiser2Interfaces(P1, 0, 2 * i, 2 * i + 1);

    printf("Evaluation individu 0 = %f\n", evaluerIndividu(P1, 0));

    for(int i = 0; i < 11; i++)
        croiser2Interfaces(P1, 0, 2 * i, 2 * i + 1);

    printf("Evaluation individu 0 = %f\n", evaluerIndividu(P1, 0));*/


}



