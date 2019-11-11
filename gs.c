/**
 * \file gs.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme de la méthode de Gauss-Seidel.
 * \version 0.1
 * \date 11 novembre 2019
 *
 * Programme de la méthode de Gauss-Seidel.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"
#include "display.h"

/**
 * \fn gs_iteration(double tab[], double res[], double xinit[], int N)
 * \brief Fonction éxecutant la partie itérative de la méthode Gauss-Seidel.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param xinit tableau des inconnus qu'on cherche.
 * \param N dimension de nos matrices.
 */
void gs_iteration(double tab[], double res[], double xinit[], int N){
    int i, j;
    for(i = 0; i < N; i++){
        xinit[i] = 0;
        for (j = 0; j < N; j++){
            if(i == j){
                continue;
            }
            xinit[i] -= (tab[i*N+j]*xinit[j])/tab[i*N+i];
        }
        xinit[i] += res[i]/tab[i*N+i];
    }    
}

/**
 * \fn gs(double tab[], double res[], int N, float e)
 * \brief Fonction servant de point d'entrée de la méthode Gauss-Seidel.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param N dimension de nos matrices.
 * \param e erreur qu'on cherche a approcher.
 */
void gs(double tab[], double res[], int N, float e){
    int count = 0;
    double xinit[3]={0,0,0}, err;
    err = error(tab, xinit, N);
    while(err > e){
        gs_iteration(tab, res, xinit, N);
        err = error(tab, xinit, N);
        count++;
    }
    printf("gauss-seidel : %d itération\n", count);
    //display_tab_res(xinit, 3);
}