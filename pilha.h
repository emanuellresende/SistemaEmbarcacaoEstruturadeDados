#ifndef PILHA_H
#define PILHA_H
#define MAXEMPILHADO 16
#define MAXTravessa 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

#endif