/**
 * \file testing.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme de test du temps d'execution/nombre d'itérations des methodes Jacobi/Gauss-Seidel.
 * \version 0.1
 * \date 11 octobre 2019
 *
 * Programme de test du temps d'execution/nombre d'itérations des methodes Jacobi/Gauss-Seidel.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jacobi.h"
#include "gs.h"
#include "testMatrice.h"
#include "display.h"
#include "testing.h"


/**
 * \fn void testing_err(double tab[], double res[], int iter, int N)
 * \brief Fonction qui exécute une résolution par jacobi ou gs (au choix) suivant l'erreur à approcher, puis affiche le temps d'execution, la dimension, l'erreur dans l'entrée standard si le temps d'execution est suppérieur a zero et le nombre d'itération.
 * \param tab matrice de départ.
 * \param res matrice de résultats.
 * \param iter nombre d'iteration (nombre de fois que l'erreur sera réduite afin d'avoir des résultats plus précis).
 * \param N dimension de nos matrices
 */
void testing_err(double tab[], double res[], int iter, int N){
    int j;
    double e = 1.0, *tmpTab, error_end = 0;
    tmpTab = calloc(N, sizeof(double));
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for(j = 0; j < iter; j++){
        start=clock();
        jacobi(tab, res, N, e, tmpTab, &error_end);
        end=clock();
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%f;%d\n",extime, j);
        }
       e = 0.1*e; 
    }
}

/**
 * \fn void testing_Dim_gs(int maxDim)
 * \brief Fonction qui exécute une résolution par  gs  suivant l'erreur à approcher, puis affiche le temps d'execution, la dimension, l'erreur dans l'entrée standard si l'itération est suppérieur a zero et le nombre d'itération.
 * \param maxDim dimension de nos matrices
 */
void testing_Dim_gs(int maxDim){
    double *tab, *a, *tmpTab, error_end = 0;
    tab = calloc(maxDim*maxDim, sizeof(double));
    a = calloc(maxDim, sizeof(double));
    tmpTab = calloc(maxDim, sizeof(double));

    if(tab == NULL || a == NULL){
        printf("PB malloc");
        exit(0);
    }
    for(int i = 0; i < maxDim; i++){
            a[i] = 1;
    }
    int j, iter;
    double e = 0.0001;
    clock_t start, end;
    printf("time(ms);dim;iter\n");
    for(j = 0; j < maxDim; j+=1){
        init_zero(tab,j,j);
        init_zero(tmpTab,1,j);
        matrice_sym_pos(tab, j);
        start=clock();
        iter = gs_int(tab, a, j, e, &error_end);
        end=clock();
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(iter != 0){
            printf("%f;%d;%d;%f\n",extime, j, iter,error_end);
        }
    }
}

/**
 * \fn void testing_Dim_jaco(int maxDim)
 * \brief Fonction qui exécute une résolution par  jacobi  suivant l'erreur à approcher, puis affiche le temps d'execution, la dimension, l'erreur dans l'entrée standard si l'itération est suppérieur a zero et le nombre d'itération.
 * \param maxDim dimension de nos matrices
 */
void testing_Dim_jaco(int maxDim){
    double *tab, *a, *tmpTab, error_end = 0;
    tab = calloc(maxDim*maxDim, sizeof(double));
    a = calloc(maxDim, sizeof(double));
    tmpTab = calloc(maxDim, sizeof(double));

    if(tab == NULL || a == NULL){
        printf("PB malloc");
        exit(0);
    }
    for(int i = 0; i < maxDim; i++){
        a[i] = 1;
    }
    int j, iter;
    double e = 0.0001;
    clock_t start, end;
    printf("time(ms);dim;iter\n");
    for(j = 0; j < maxDim; j+=1){
        init_zero(tab,j,j);
        init_zero(tmpTab,1,j);
        matrice_sym_pos(tab, j);
        start=clock();
        iter = jacobi(tab, a, j, e, tmpTab, &error_end);
        end=clock();
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(iter != 0){
            printf("%f;%d;%d;%f\n",extime, j, iter,error_end);
        }
    }
}


