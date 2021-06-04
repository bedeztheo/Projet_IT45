#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include "data.h"

typedef struct {

    int idIndividu[NBR_INTERFACES];
    int listeBits[NBR_APPRENANTS * NBR_INTERFACES];
    int nbHeuresSemaine[24];

} Individu;

typedef Individu* Population;

#endif // STRUCTURES_H_INCLUDED
