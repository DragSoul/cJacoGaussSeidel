#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"
#include "display.h"

void jacobi_iteration(double *tab, double *res, double *xinit, int N){
    int i, j;
    double xnext[3];
    init_zero(xnext, 1, 3);
    for(i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if(i == j){
                continue;
            }
            xnext[i] -= (tab[i*N+j]*xinit[j])/tab[i*N+i];
        }
        xnext[i] += res[i]/tab[i*N+i];
    }
    copy(xnext, xinit, 3, 1);
}

void jacobi(double *tab, double *res, int N){
    int count;
    double xinit[3]={0,0,0}, err;
    err = error(tab, xinit, N);
    while(err > 0.0001){
        jacobi_iteration(tab, res, xinit, N);
        err = error(tab, xinit, N);
        count++;
    }
    printf("gauss-seidel : %d itération\n", count);
    display_tab_res(xinit, 3);
}
