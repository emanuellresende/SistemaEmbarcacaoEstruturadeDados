#ifndef FILA_H
#define FILA_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define true 1
#define false 0
typedef int tipo_item_fila; //Define o tipo de elementos da fila
typedef struct elem
{
    tipo_item_fila id;
    tipo_item_fila qntConteiner;
    tipo_item_fila qtdTempofila;
    struct elem *lig;
} tipo_elem; //Tipos dos elementos das filas

typedef struct //Estrutura de uma fila com ponteiros apontado para o inicio e fim
{
    tipo_elem *inicio;
    tipo_elem *fim;
} fila;
fila *definirfila(void);                                         //Essa funçao define a fila alocando ela e colocando NULL nos ponteiros inicio e fim
fila *removerfila(fila *q);                                      //Essa funçao remove o primeiro elemento de uma fila
int filavazia(fila *q);                                          //Realiza a verificaçao se esta vazia a fila ou nao retorna true se estiver
fila *inserirfila(fila *q, tipo_elem *filanaviosaux, int *cont); //Funçao para inserir elemento na fila
int menorfila(int *a, int *b, int *c, int *d);                   // Retorna qual tem o menor tamanho de fila
void imprimirfila(fila *q);                                      //Imprime os ID das filas
tipo_elem entradanavios(int *id_navio);                          //Gera os dados aleatoriso do navio como o ID
fila *insertfila(fila *filanavios1, fila *filanavios2, fila *filanavios3, fila *filanavios4, int *id_navios, int *tamanhofilanavios1, int *tamanhofilanavios2, int *tamanhofilanavios3, int *tamanhofilanavios4);
#endif