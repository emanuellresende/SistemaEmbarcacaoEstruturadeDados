#ifndef FILE_H
#define FILE_H
#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0
typedef int tipo_info;
typedef struct elem
{
    tipo_info info;
    struct elem *lig;
} tipo_elem;

typedef struct
{
    tipo_elem *inicio;
    tipo_elem *fim;
} fila;
fila *definirfila(void);
int filavazia(fila *q);
fila *inserirfila(fila *q, tipo_info info);
void imprimirfila(fila *q);
fila *filanavios;
#endif