/**
 * \file testMatrice.h
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief fichier contenant le prototype des fonctions de création de matrices et d'opération sur les matrices
 * \version 0.1
 * \date 11 novembre 2019
 *
 * fichier contenant le prototype des fonctions de création de matrices et d'opération sur les matrices
 *
 */

#ifndef H_TEST_MATRICE
#define H_TEST_MATRICE

void init_zero(double tab[], int maxi, int maxj);
void transpose(double tab[], int N);
void copy(double src[], double dest[], int line, int col);
double error(double tab[], double res[], int N);
void a_bord1(double tab[], int N);
void a_bord2(double tab[], int N);
void ding_dong(double tab[], int N);
void franc(double tab[], int N);
void hilbertPlus(double tab[], int N, int plus);
void hilbert(double tab[], int N);
void hilbert2(double tab[], int N);
void kms(double tab[], int N);
void lehmer(double tab[], int N);
void lotkin(double tab[], int N);
void moler(double tab[], int N);
void matrice_creuse(double tab[], int N, int pourcent);
void matrice_sym_pos(double tab[], int N);

#endif