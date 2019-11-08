/**
 * \file testing.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme de test du temps d'execution des methodes gauss et cholesky.
 * \version 0.1
 * \date 21 octobre 2019
 *
 * Programme de test du temps d'execution des methodes gauss et cholesky.
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
 * \fn void gauss_testing_core(int maxDim, double tab[], double res[])
 * \brief Fonction qui exécute une résolution par gauss pour chaque dimension jusqu'a la dimension saisi, puis affiche le temps d'execution, la dimension et l'erreur dans l'entrée standard si le temps d'execution est suppérieur a zero 
 * \param maxDim dimension max de la matrice
 * \param tab tableau pour contenir une matrice
 * \param res tableau pour contenir les résultats d'une matrice.
 */
void testing(double tab[], double res[], int iter, int N){
    int i,j;
    double e = 1.0;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for(j = 0; j < iter; j++){
        start=clock();
        //jacobi(tab, res, N, e);
        gs(tab, res, N, e);
        end=clock();
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%f;%d\n",extime, j);
        }
       e = 0.1*e; 
    }
}

