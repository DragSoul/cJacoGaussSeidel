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
#include "display.h"
#include "testMatrice.h"


int main(){
    double tab[100]={3,1,-1,1,2,0,-1,1,4}, res[3]={1,1,1};
    jacobi(tab, res, 3);

    return 0;
}
