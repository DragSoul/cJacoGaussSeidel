#ifndef H_JACOBI
#define H_JACOBI
double error(double tab[], double res[], int N);
void jacobi_iteration(double *tab, double *res, double *xinit, int N);
void jacobi(double *tab, double *res, int N);
#endif