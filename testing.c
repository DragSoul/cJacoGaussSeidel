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
 * \fn void testing(double tab[], double res[], int iter, int N)
 * \brief Fonction qui exécute une résolution par jacobi ou gs (au choix) suivant l'erreur à approcher, puis affiche le temps d'execution, la dimension, l'erreur dans l'entrée standard si le temps d'execution est suppérieur a zero et le nombre d'itération.
 * \param tab matrice de départ.
 * \param res matrice de résultats.
 * \param iter nombre d'iteration (nombre de fois que l'erreur sera réduite afin d'avoir des résultats plus précis).
 * \param N dimension de nos matrices
 */
void testing_err(double tab[], double res[], int iter, int N){
    int i,j;
    double e = 1.0;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for(j = 0; j < iter; j++){
        start=clock();
        jacobi(tab, res, N, e);
        //gs(tab, res, N, e);
        end=clock();
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%f;%d\n",extime, j);
        }
       e = 0.1*e; 
    }
}

void testing_Dim(int maxDim){
    double *tab, *a, *tmpTab; 
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
    int i,j, iter;
    double e = 0.00000000000000000001;
    clock_t start, end;
    printf("time(ms);dim;iter\n");
    for(j = 0; j < maxDim; j+=1){
        init_zero(tab,j,j);
        init_zero(tmpTab,1,j);
        
        a_bord1(tab, j);
        start=clock();
        iter = jacobi_int(tab, a, j, e, tmpTab);
        
        //iter = gs_int(tab, a, j, e);

        end=clock();
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%f;%d;%d\n",extime, j, iter);
        }
    }
}
