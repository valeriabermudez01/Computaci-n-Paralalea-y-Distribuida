#ifndef MODULO_C_H_INCLUDE
#define MODULO_C_H_INCLUDE


void sampleStart();
void sampleEnd();
double randNumber();
void initMatrix(int SZ, double *Ma, double *Mb, double *Mr);
void printMatrix(int SZ, double *M);
void MM1c(int size, double *Ma, double *Mb, double *Mr);
void MM1f(int size, double *Ma, double *Mb, double *Mr);
double ** ReservaMEM(int size);
void IniciarMatriz(double **Ma, double **Mb, double **Mc, int size);
void printMatrizH(double **M, int size);
void *multMM(void *arg);

struct data {
    int size, nTh;
    int *idTh;
    double **MA, **MB, **MC;
};

#endif
