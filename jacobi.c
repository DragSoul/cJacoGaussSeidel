/**
 * \file jacobi.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme de la méthode de Jacobi.
 * \version 0.1
 * \date 11 novembre 2019
 *
 * Programme de la méthode de Jacobi.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"
#include "display.h"

/**
 * \fn jacobi_iteration(double tab[], double res[], double xinit[], int N)
 * \brief Fonction éxecutant la partie itérative de la méthode Jacobi.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param xinit tableau des inconnus qu'on cherche.
 * \param N dimension de nos matrices.
 */
void jacobi_iteration(double tab[], double res[], double xinit[], int N){
    int i, j;
    double *xnext;
    xnext = calloc(N, sizeof(double));
    init_zero(xnext, 1, N);
    for(i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if(i != j){
                xnext[i] -= (tab[i*N+j]*xinit[j])/tab[i*N+i];
            }
        }
        xnext[i] += res[i]/tab[i*N+i];
    }
    copy(xnext, xinit, N, 1);
    free(xnext);
}

void jacobi_iteration_tmp(double tab[], double res[], double xinit[], int N, double tpmTab[]){
    int i, j;
    init_zero(tpmTab, 1, N);
    for(i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if(i != j){
                tpmTab[i] -= (tab[i*N+j]*xinit[j])/tab[i*N+i];
            }
        }
        tpmTab[i] += res[i]/tab[i*N+i];
    }
    copy(tpmTab, xinit, N, 1);
}

/**
 * \fn jacobi(double tab[], double res[], int N, float e)
 * \brief Fonction servant de point d'entrée de la méthode Jacobi.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param N dimension de nos matrices.
 * \param e erreur qu'on cherche a approcher.
 */
void jacobi(double tab[], double res[], int N, float e){
    int count = 0;
    double *xinit, err;
    xinit = calloc(N, sizeof(double));
    err = error(tab, xinit, N);
    while(err > e){
        jacobi_iteration(tab, res, xinit, N);
        err = error(tab, xinit, N);
        //printf("error : %.20f\n",err);
        count++;
    }
    //printf("jacobi : %d itération\n", count);
    free(xinit);
    //display_tab_res(xinit, 3);
}

int jacobi_int(double tab[], double res[], int N, float e, double tmpTab[]){
    int count = 0;
    double *xinit, err;
    xinit = calloc(N, sizeof(double));
    err = error(tab, xinit, N);
    while(err > e){
        jacobi_iteration(tab, res, xinit, N);
        err = error(tab, xinit, N);
        //printf("error : %.20f\n",err);
        count++;
    }
    printf("errer %f\n", err);
    //printf("jacobi : %d itération\n", count);
    free(xinit);
    //display_tab_res(xinit, 3);
    return count;
}
