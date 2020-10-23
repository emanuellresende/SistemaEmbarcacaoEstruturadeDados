#ifndef PILHA_H
#define PILHA_H
#define MAXEMPILHADO 15 // Os valores começam valendo o tamanho total -1 pois iniciamos em -1
#define MAXTravessa 4   // Os valores começam valendo o tamanho total -1 pois iniciamos em -1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fila.h"

typedef int tipoApontador;
// TIPO STRUCT
typedef struct
{
    tipoApontador conteineratraque[MAXEMPILHADO]; // Conteiners para atraque
    tipoApontador topo;                           // O topo que e a quantidade de conteiners
} Pilha;

typedef struct
{
    tipoApontador conteinertravessa[MAXTravessa]; // Conteiners para atraque
    tipoApontador topo;                           // O topo que e a quantidade de conteiners
} PilhaTravessa;

//Atraque
Pilha *criaPilha(void);               // Inicializa uma Pilha e iguala seu topo a -1
int pilhacheia(Pilha *p);             // Retorna se a pilha esta cheia
int pilhavazia(Pilha *p);             // Retorna se a pilha esta vazia
void empilhaatraque(Pilha *p, int x); // Realiza o empilhamento da area de atraque
int desempilha(Pilha *p);             // Realiza o desempilhamento dos atraques
//

//Travessa
PilhaTravessa *criaPilhaTravessa(void);   // Cria uma pilha para a travessa e iguala seu topo a -1
int pilhacheiaTravessa(PilhaTravessa *p); // REtorna se a travessa esta cheia
int pilhavaziaTravessa(PilhaTravessa *p); // Retorna se a travessa esta vazia
void empilhaTravessa(PilhaTravessa *p);   // Realiza o empilhamento da travessa
int desempilhaTravessa(PilhaTravessa *p); // REaliza o desempilhamento da travessa

//Funçoes Gerais
void carro(int carro[4], PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5);                                         // Funçao utilizada para chamar o carro quando uma travessa esta cheia
void mostrar_carro(int c[4]);                                                                                                                                    // Imprimi quando um carro sai para ir ate a travessa
int pilhanaocheia(PilhaTravessa *p);                                                                                                                             // Retorna quando nao esta  cheia
void imprimir_dados_travessas(PilhaTravessa *travessa1, PilhaTravessa *travessa2, PilhaTravessa *travessa3, PilhaTravessa *travessa4, PilhaTravessa *travessa5); // Imprimi a quantidade de conteiners na travessa
void atracando(fila *filanavios1, fila *filanavios2, fila *filanavios3, fila *filanavios4, Pilha *atraque1, Pilha *atraque2, Pilha *atraque3, Pilha *atraque4, int *num_atraque, float *a1, float *a2, float *a3, float *a4, float *tm1, float *tm2, float *tm3, float *tm4, float *t1, float *t2, float *t3, float *t4);
void remover_elemento_atraque_paratravessa(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, Pilha *a1, int travessa);          // Desempilha o conteiner no atraque e empilha na travessa
void empilhar_travessas(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, int aux, Pilha *a1, Pilha *a2, Pilha *a3, Pilha *a4); // Funçao que chama a verificacao e verifica qual travessa empilhar
int retornar_travessas(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5);                                                       // Retorna uma travessa para ser empilhada
#endif