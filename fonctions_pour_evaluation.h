#ifndef FONCTIONS_POUR_EVALUATION_H_INCLUDED
#define FONCTIONS_POUR_EVALUATION_H_INCLUDED

float calculerDistanceXY(int X1, int X2, int Y1, int Y2);

int calculerDistanceTotaleInterface(Population population, int idIndividu, int idInterface);

int calculerTotalDistances(Population population, int idIndividu);

int ecartTypeIndividu(Population population, int idIndividu);

int compterPenalites(Population population, int idIndividu);

float evaluerIndividu(Population population, int idIndividu);

#endif // FONCTIONS_POUR_EVALUATION_H_INCLUDED
