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
void jacobi_iteration(double tab[], double res[], double xinit[], int N);
void jacobi(double tab[], double res[], int N, float e);
#endif