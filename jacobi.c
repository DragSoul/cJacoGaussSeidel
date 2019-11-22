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
#include "jacobi.h"

/**
 * \fn jacobi_iteration(double tab[], double res[], double xinit[], int N, double *tpmTab)
 * \brief Fonction éxecutant la partie itérative de la méthode Jacobi.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param xinit tableau des inconnus qu'on cherche.
 * \param N dimension de nos matrices.
 * \param tmpTab tableau temporaire contenant le vecteur d'iteration.
 */
void jacobi_iteration(double *tab, double *res, double *xinit, int N, double *tpmTab){
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
 * \param tmpTab tableau temporaire pour stocker les itération.
 * \param error_end [out]erreur de la dernière itération.
 * \return  nombre d'iteration.
 */
int jacobi(double *tab, double *res, int N, double e, double *tmpTab, double *error_end){
    int count = 0;
    *error_end = 0;
    double *xinit, err, tmpErr = 0, *init_res;
    xinit = calloc(N, sizeof(double));
    init_res = calloc(N, sizeof(double));
    copy(res,init_res,N,1);
    err = error_wres(tab, xinit, N, init_res);
    while(err > e){
        jacobi_iteration(tab, res, xinit, N, tmpTab);
        tmpErr = error_wres(tab, xinit, N, init_res);
        count++;
        if(tmpErr > err){
            break;
        }
        err = tmpErr;
    }
    *error_end = err;
    free(xinit);
    return count;
}

/**
 * \fn jacobi_plan_iter(double tab[], double res[], double xinit[], double tpmTab[])
 * \brief Fonction éxecutant la partie itérative de la méthode Jacobi pour les matrices de dimension 2.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param xinit tableau des inconnus qu'on cherche.
 * \param N dimension de nos matrices.
 * \param tmpTab tableau temporaire contenant le vecteur d'iteration.
 */
void jacobi_plan_iter(double tab[], double res[], double xinit[], double tpmTab[]){
    int i, j;
    init_zero(tpmTab, 1, 2);
    for(i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            if(i != j){
                tpmTab[i] -= (tab[i*2+j]*xinit[j])/tab[i*2+i];
            }
        }
        tpmTab[i] += res[i]/tab[i*2+i];
    }
    copy(tpmTab, xinit, 2, 1);
    printf("%f;%f\n", xinit[0], xinit[1]);
}

/**
 * \fn jacobi_int_plan(double tab[], double res[], double e, double tmpTab[], double *error_end)
 * \brief Fonction servant de point d'entrée de la méthode Jacobi pour les matrices de dimension 2.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param res tableau contenant la matrice de résultats.
 * \param N dimension de nos matrices.
 * \param e erreur qu'on cherche a approcher.
 * \param tmpTab tableau temporaire pour stocker les itération.
 * \param error_end [out]erreur de la dernière itération.
 * \return  nombre d'iteration.
 */
int jacobi_int_plan(double tab[], double res[], double e, double tmpTab[], double *error_end){
    int count = 0, hope = 4;
    *error_end = 0;
    double *xinit, err, tmpErr = 0, *init_res;
    xinit = calloc(2, sizeof(double));
    init_res = calloc(2, sizeof(double));
    copy(res,init_res,3,1);
    xinit[0] = 3;
    xinit[1] = 3;
    err = error(tab, xinit, 2);
    while(err > e){
        jacobi_plan_iter(tab, res, xinit, tmpTab);
        tmpErr = error_wres(tab, xinit, 2,init_res);
        count++;
        if(tmpErr > err ){
                break;
        }
        err = tmpErr;
    }
    *error_end = err;
    free(xinit);
    return count;
}
