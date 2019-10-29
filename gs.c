#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"
#include "display.h"

/*TODO: merge gs.c and jacobi.c to avoid duplicated code*/

void gs_iteration(double *tab, double *res, double *xinit, int N){
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

void gs(double *tab, double *res, int N){
    int count;
    double xinit[3]={0,0,0}, err;
    err = error(tab, xinit, N);
    while(err > 0.0001){
        gs_iteration(tab, res, xinit, N);
        err = error(tab, xinit, N);
        count++;
    }
    printf("gauss-seidel : %d itération\n", count);
    display_tab_res(xinit, 3);
}