/**
 * \file gs.h
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief fichier contenant le prototype des fonctions du programme gs
 * \version 0.1
 * \date 11 novembre 2019
 *
 * fichier contenant le prototype des fonctions du programme gs
 *
 */

#ifndef H_gs
#define H_gs
void gs_iteration(double tab[], double res[], double xinit[], int N);
void gs(double tab[], double res[], int N, float e);
int gs_int(double tab[], double res[], int N, float e, double *error_end);
void gs_iteration_plan(double tab[], double res[], double xinit[]);
int gs_int_plan(double tab[], double res[], float e, double *error_end);
#endif