#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include "data.h"

typedef struct {

    int8_t listeBits[NBR_FORMATIONS * NBR_INTERFACES];
    int nbHeuresSemaine[NBR_INTERFACES];

} Individu;

typedef Individu* Population;

#endif // STRUCTURES_H_INCLUDED
