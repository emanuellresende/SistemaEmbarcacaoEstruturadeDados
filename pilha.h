#ifndef PILHA_H
#define PILHA_H
#define MAXEMPILHADO 16
#define MAXTravessa 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fila.h"

typedef int tipoApontador;
// TIPO STRUCT
typedef struct
{
    tipoApontador conteineratraque[MAXEMPILHADO];
    tipoApontador topo;
} Pilha;

typedef struct
{
    tipoApontador conteinertravessa[MAXTravessa];
    tipoApontador topo;
} PilhaTravessa;

//Atraque
Pilha *criaPilha(void);
int pilhacheia(Pilha *p);
int pilhavazia(Pilha *p);
void empilhaatraque(Pilha *p, int x);
void empilha(Pilha *p);
int desempilha(Pilha *p);
//

//Travessa
PilhaTravessa *criaPilhaTravessa(void);
int pilhacheiaTravessa(PilhaTravessa *p);
int pilhavaziaTravessa(PilhaTravessa *p);
void empilhaTravessa(PilhaTravessa *p);
int desempilhaTravessa(PilhaTravessa *p);
void carro(int *c1, int *c2, int *c3, int *c4);
void mostrar_carro(int c1, int c2, int c3, int c4);
void atracando(fila *filanavios1, fila *filanavios2, fila *filanavios3, fila *filanavios4, Pilha *atraque1, Pilha *atraque2, Pilha *atraque3, Pilha *atraque4, int *num_atraque);
void remover_elemento_atraque_paratravessa(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, Pilha *a1, int travessa);
void empilhar_travessas(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, int aux, Pilha *a1, Pilha *a2, Pilha *a3, Pilha *a4, int *carro1, int *carro2, int *carro3, int *carro4);
int retornar_travessas(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, int *carro1, int *carro2, int *carro3, int *carro4);
#endif