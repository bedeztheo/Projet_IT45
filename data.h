#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#define MAX_HEURES 35
#define NBR_HEURES_INT_INIT 18
#define NBR_INDIVIDUS_POP 5

#define NBR_INTERFACES        24
#define NBR_APPRENANTS        80
#define NBR_FORMATIONS        80
#define NBR_CENTRES_FORMATION 5
#define NBR_SPECIALITES       5
#define NBR_NODES 	      NBR_CENTRES_FORMATION+NBR_INTERFACES+NBR_APPRENANTS

/* code des comp�tence en langage des signes et en codage LPC */
#define COMPETENCE_SIGNES     0
#define COMPETENCE_CODAGE     1

/* competences des interfaces en SIGNES et CODAGE*/
extern int competences_interfaces[NBR_INTERFACES][2];

/* spécialités des interfaces */
#define SPECIALITE_SANS       -1 /* Enseign� dans le centre le plus proche */
#define SPECIALITE_MENUISERIE 0
#define SPECIALITE_ELECTRICITE 1
#define SPECIALITE_MECANIQUE 2
#define SPECIALITE_INFORMATIQUE 3
#define SPECIALITE_CUISINE 4

/* specialite des interfaces */
extern int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES];

/* coordonn�es des centres de formation, des interfaces et des apprenants */
extern float coord[NBR_NODES][2];

#define NBR_FORMATION          80

#define LUNDI                  1
#define MARDI                  2
#define MERCREDI               3
#define JEUDI                  4
#define VENDREDI               5
#define SAMEDI                 6

/* formation : id formation, specialite ou centre de formation, competence, jour, horaire debut formation, horaire fin formation */
extern int formation[NBR_FORMATION][6];

#endif
