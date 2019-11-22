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
#include "gs.h"

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
            if(i != j){
                xinit[i] -= (tab[i*N+j]*xinit[j])/tab[i*N+i];
            }
        }
        xinit[i] += res[i]/tab[i*N+i];
    }
}

/**
 * \fn gs_iteration_plan(double tab[], double res[], double xinit[])
 * \brief Fonction éxecutant la partie itérative de la méthode Gauss-Seidel pour une matrice de dimension 2.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param xinit tableau des inconnus qu'on cherche.
 * \param N dimension de nos matrices.
 */
void gs_iteration_plan(double tab[], double res[], double xinit[]){
    int i, j;
    for(i = 0; i < 2; i++){
        xinit[i] = 0;
        for (j = 0; j < 2; j++){
            if(i != j){
                xinit[i] -= (tab[i*2+j]*xinit[j])/tab[i*2+i];
            }
        }
        xinit[i] += res[i]/tab[i*2+i];
    }
    printf("%f;%f\n", xinit[0], xinit[1]);
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
    double *xinit, err;
    xinit = calloc(N, sizeof(double));
    err = error(tab, xinit, N);
    while(err > e){
        gs_iteration(tab, res, xinit, N);
        err = error(tab, xinit, N);
        count++;
    }
    printf("gauss-seidel : %d itération\n", count);
    free(xinit);
}

/**
 * \fn gs_int(double tab[], double res[], int N, float e)
 * \brief Fonction servant de point d'entrée de la méthode Gauss-Seidel.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param N dimension de nos matrices.
 * \param e erreur qu'on cherche a approcher.
 * \param error_end [out]erreur de la dernière itération.
 * \return nombre d'itération.
 */
int gs_int(double tab[], double res[], int N, float e, double *error_end){
    int count = 0;
    double *xinit, err, *init_res, tmpErr = 0;
    xinit = calloc(N, sizeof(double));
    init_res = calloc(N, sizeof(double));
    copy(res,init_res,N,1);
    err = error_wres(tab, xinit, N,init_res);
    while(err > e){
        gs_iteration(tab, res, xinit, N);
        tmpErr = error_wres(tab, xinit, N, init_res);
        count++;
        if(tmpErr > err){
            break;
        }
        err = tmpErr;
    }
    free(xinit);
    *error_end = err;
    return count;
}

/**
 * \fn int gs_int_plan(double tab[], double res[], float e, double *error_end)
 * \brief Fonction servant de point d'entrée de la méthode Gauss-Seidel pour une matrice de dimension 2.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param N dimension de nos matrices.
 * \param e erreur qu'on cherche a approcher.
 * \param error_end [out]erreur de la dernière itération.
 * \return nombre d'itération.
 */
int gs_int_plan(double tab[], double res[], float e, double *error_end){
    int count = 0;
    double *xinit, err, *init_res;
    xinit = calloc(2, sizeof(double));
    init_res = calloc(2, sizeof(double));
    copy(res,init_res,3,1);
    err = error_wres(tab, xinit, 2,init_res);
    xinit[0] = 3.0;
    xinit[1] = 3.0;
    while(err > e){
        gs_iteration_plan(tab, res, xinit);
        err = error_wres(tab, xinit, 2,init_res);
        count++;
    }
    free(xinit);
    *error_end = err;
    return count;
}