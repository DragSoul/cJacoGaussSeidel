#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"
#include "display.h"

/*double error(double tab[], double res[], int N){
    int i,j;
    double tmp;
    double error;
    for(i =0; i<N; i++){
        tmp = 0;
        for(j =0; j < N; j++){
            tmp = tmp + tab[i*N+j] * res[j];
        }
        error =  1.0-tmp;
    }
    return error;
}*/

double error(double tab[], double res[], int N){
    int i,j;
    double tmp;
    double error;
    for(i =0; i<N; i++){
        tmp = 0;
        for(j =0; j < N; j++){
            tmp = tmp + tab[i*N+j] * res[j];
        }
        error = error + pow(1.0-tmp, 2);
    }
    return sqrt(error);
}

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
    double xinit[3]={0,0,0}, err;
    err = error(tab, xinit, N);
    while(err > 0.0001 || err < -0.0001){
        display_tab_res(xinit, 3);
        jacobi_iteration(tab, res, xinit, N);
        err = error(tab, xinit, N);
        //printf("%f\n", err);
    }
    //printf("%f\n", error(tab, xinit, N));
    //display_tab_res(xinit, 3);
}