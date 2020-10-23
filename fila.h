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
    tipo_item_fila id;           //ID navios
    tipo_item_fila qntConteiner; // Quantidade de Conteiner Armazenada
    tipo_item_fila qtdTempofila; // Tempo na Fila
    struct elem *lig;
} tipo_elem; //Tipos dos elementos das filas

typedef struct //Estrutura de uma fila com ponteiros apontado para o inicio e fim
{
    tipo_elem *inicio;
    tipo_elem *fim;
} fila;

void hora_fila(tipo_elem *ponteiro);                             // Recebe como parametro a posicao inicial da fila e soma um no tempo geral
void imprimirfila(fila *q);                                      //Imprime os ID das filas
fila *definirfila(void);                                         //Essa funçao define a fila alocando ela e colocando NULL nos ponteiros inicio e fim
fila *removerfila(fila *q);                                      //Essa funçao remove o primeiro elemento de uma fila
fila *inserirfila(fila *q, tipo_elem *filanaviosaux, int *cont); //Funçao para inserir elemento na fila
fila *insertfila(fila *filanavios1, fila *filanavios2, fila *filanavios3, fila *filanavios4, int *id_navios, int *tamanhofilanavios1, int *tamanhofilanavios2, int *tamanhofilanavios3, int *tamanhofilanavios4, int *qnt_fila);
tipo_elem entradanavios(int *id_navio);        //Gera os dados aleatoriso do navio como o ID
int menorfila(int *a, int *b, int *c, int *d); // Retorna qual tem o menor tamanho de fila
int filavazia(fila *q);                        //Realiza a verificaçao se esta vazia a fila ou nao retorna true se estiver
#endif