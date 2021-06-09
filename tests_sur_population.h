#ifndef TESTS_SUR_POPULATION_H_INCLUDED
#define TESTS_SUR_POPULATION_H_INCLUDED

int nombreHeureFormation(int idFormation);

int formationCompatible(Population population, int idIndividu, int idInterface, int idFormation);

int trouverMeilleurIndividu(Population population);

#endif // TESTS_SUR_POPULATION_H_INCLUDED
