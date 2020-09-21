#ifndef FILE_H
#define FILE_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define true 1
#define false 0
typedef int tipo_item_fila;
typedef struct elem
{
    tipo_item_fila id;
    tipo_item_fila qntConteiner;
    tipo_item_fila qtdTempofila;
    struct elem *lig;
} tipo_elem;

typedef struct
{
    tipo_elem *inicio;
    tipo_elem *fim;
} fila;
fila *definirfila(void);
fila *removerfila(fila *q);
int filavazia(fila *q);
fila *inserirfila(fila *q, tipo_elem *filanaviosaux, int *cont);
int menorfila(int a, int b, int c, int d);
void imprimirfila(fila *q);
tipo_elem entradanavios(void);
tipo_elem filanaviosaux;
fila *filanavios1;
fila *filanavios2;
fila *filanavios3;
fila *filanavios4;
void insertfila(void);
int tamanhofilanavios1, tamanhofilanavios2, tamanhofilanavios3, tamanhofilanavios4, qntnovonavio, verificarmenorfila, auxfila;
#endif