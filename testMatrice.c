/**
 * \file testMatrice.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \version 0.1
 * \date 21 octobre 2019
 * \brief Programme pour générer les matrices de test.
 *
 * Programme pour générer les matrices de test.
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * \fn void init_zero(double tab[], int N)
 * \brief Fonction pour l'initialisation d'une matrice à 0.
 *
 * \param tab tableau a initialiser à 0.
 * \param maxi nombre de lignes de tab.
 * \param maxj nombre de colonnes de tab.
 */
void init_zero(double tab[], int maxi, int maxj){
    int i,j;
    for(i = 0; i < maxi; i++){
        for(j = 0; j < maxj; j++){
            tab[i*maxi+j] = 0;
        }
    }
}

/**
 * \fn void transpose(double tab[], int N)
 * \brief Fonction pour transposer une matrice.
 *
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void transpose(double tab[], int N){
    int i, j, sauv;
    for(i = 0; i < N; i++){
        for(j = i+1; j < N; j++){
            sauv = tab[i*N+j];
            tab[i*N+j] = tab[j*N+i];
            tab[j*N+i] = sauv;
        }
    }
}

void copy(double src[], double dest[], int line, int col){
    int i, j;
    for(i = 0; i < line; i++){
        for (j = 0; j < col; j++){
            dest[i*col+j] = src[i*col+j];
        }
    }
}

/**
 * \fn a_bord1(double tab[], int N)
 * \brief Fonction pour générer une matrice a bord.
 *
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void a_bord1(double tab[], int N){
    
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i+1 == j+1){
                tab[i*N+j] = 1;
            }
            else{
                if(i == 0){
                    tab[i*N+j] = pow(2, -j);
                    tab[j*N] = pow(2, -j);
                }               
            }
        }
    }
}

/**
 * \fn a_bord2(double tab[], int N)
 * \brief Fonction pour générer une matrice a bord.
 *
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void a_bord2(double tab[], int N){
    
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i+1 == j+1){
                tab[i*N+j] = 1;
            }
            else{
                if(i+1 == N){
                    tab[i*N+j] = pow(2, N-(j+1));
                    tab[j*N+N-1] = pow(2, N-(j+1));
                }
                
            }  
        }
    }
}

/**
 * \fn void ding_dong(double tab[], int N)
 * \brief Fonction pour générer une matrice ding dong.
 *
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void ding_dong(double tab[], int N){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 1.0/(2*(N-(i+1)-(j+1)+1.5));
        }
    }
}

/**
 * \fn franc(double tab[], int N)
 * \brief Fonction pour générer une matrice franc.
 *
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void franc(double tab[], int N){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i >= j+2){
                tab[i*N+j] = 0;
            }
            else{
                tab[i*N+j] = fmin(i,j)+1;
            }
        }
    }
}

/**
 * \fn hilbertPlus(double tab[], int N, int plus)
 * \brief Fonction pour générer une matrice hilbert.
 * \param plus element de l'équation a ajouter.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void hilbertPlus(double tab[], int N, int plus){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 1.0/((i+1)+(j+1)+plus);
        }
    }
}

/**
 * \fn hilbert(double tab[], int N)
 * \brief Fonction pour générer une matrice hilbert +1.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void hilbert(double tab[], int N){
    hilbertPlus(tab, N, 1);
}

/**
 * \fn hilbert2(double tab[], int N)
 * \brief Fonction pour générer une matrice hilbert -1.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void hilbert2(double tab[], int N){
    hilbertPlus(tab, N, -1);
}

/**
 * \fn void kms(double tab[], int N)
 * \brief Fonction pour générer une matrice kms.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void kms(double tab[], int N){
    int i,j;
    double p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = pow(p, fabs(i-j));
        }
    }
}

/**
 * \fn void lehmer(double tab[], int N)
 * \brief Fonction pour générer une matrice lehmer.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void lehmer(double tab[], int N){
    int i,j;
    double p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i <= j){
                tab[i*N+j] = (i+1.0)/(j+1.0);
            }
            else{
                tab[i*N+j] = (j+1.0)/(i+1.0);
            }
        }
    }
}

/**
 * \fn void lotkin(double tab[], int N)
 * \brief Fonction pour générer une matrice lokin.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void lotkin(double tab[], int N){
    int i,j;
    double p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == 0){
                tab[i*N+j] = 1;
            }
            else{
                tab[i*N+j] = 1.0/((i+1)+(j+1)-1);
            }
        }
    }
}

/**
 * \fn void moler(double tab[], int N)
 * \brief Fonction pour générer une matrice moler.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void moler(double tab[], int N){
    int i,j;
    double p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == j){
                tab[i*N+j] = i+1;
            }
            else{
                tab[i*N+j] = fmin(i,j)-1;
            }
        }
    }
}

/**
 * \fn void matrice_creuse(double tab[], int N, int pourcent)
 * \brief Fonction pour générer une matrice creuse.
 * \param pourcent pourcentage de 0 dans la matrice.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void matrice_creuse(double tab[], int N, int pourcent){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(rand()%100+1 <= pourcent){
                tab[i*N+j] = 0;
            }
            else{
                tab[i*N+j] = 1;
            }
            
        }
    }
}

/**
 * \fn void matrice_sym_pos(double tab[], int N, int pourcent)
 * \brief Créer aléatoirement une matrice symétrique définie positive.
 * \param tab tableau ou est contenu la matrice.
 * \param N dimention de la matrice.
 */
void matrice_sym_pos(double tab[], int N){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == j){
                tab[i*N+j] = N;
            }
            else
            {
                tab[i*N+j] = 1;
            } 
        }
    }
}




