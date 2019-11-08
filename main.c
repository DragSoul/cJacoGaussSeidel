/**
 * \file main.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme de clacule matriciel avec les methodes gauss ou/et cholesky.
 * \version 0.1
 * \date 21 octobre 2019
 *
 * Programme de clacule matriciel avec les methodes gauss ou/et cholesky.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "jacobi.h"
#include "gs.h"
#include "display.h"
#include "testMatrice.h"
#include "testing.h"

//iter is the nb of iteration -> we want to see the number of iteration in function of the precision 'e' we want.
//if iter = 5, we will try for e=1; e=0.1; ...; e=0.0001.
int main(){
    double tab[100]={3,1,-1,1,2,0,-1,1,4}, res[3]={1,1,1};
    int iter = 10;
    testing(tab, res, iter, 3);
    //gs(tab, res, 3);
    return 0;
}
