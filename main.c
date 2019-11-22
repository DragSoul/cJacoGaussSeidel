/**
 * \file main.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme de résolution iteratif de systèmes linéaires avec les methodes Jacobi/Gauss-Seidel.
 * \version 0.1
 * \date 11 novembre 2019
 *
 * Programme de résolution iteratif de systèmes linéaires avec les methodes Jacobi/Gauss-Seidel.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "jacobi.h"
#include "gs.h"
#include "display.h"
#include "testMatrice.h"
#include "testing.h"

int main(){
    //testing_Dim_gs(101);
    double tab[4]={-2,1,1,1}, res[2]={1,1}, e, tmpTab[2]={0,0}, error_end=0;
    a_bord1(tab,2);
    display_tab(tab,2);
    printf("jaco\n");
    jacobi_int_plan(tab,res,0.01,tmpTab,&error_end);
    printf("gs\n");
    gs_int_plan(tab,res,0.01,&error_end);
    return 0;
}
