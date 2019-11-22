/**
 * \file jacobi.h
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief fichier contenant le prototype des fonctions du programme jacobi
 * \version 0.1
 * \date 11 novembre 2019
 *
 * fichier contenant le prototype des fonctions du programme jacobi
 *
 */

#ifndef H_JACOBI
#define H_JACOBI
int jacobi(double *tab, double *res, int N, double e, double *tmpTab, double *error_end);
void jacobi_iteration(double *tab, double *res, double *xinit, int N, double *tpmTab);
int jacobi_int_plan(double tab[], double res[], double e, double tmpTab[], double *error_end);
void jacobi_plan_iter(double tab[], double res[], double xinit[], double tpmTab[]);
#endif