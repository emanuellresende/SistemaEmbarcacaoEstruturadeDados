#include "pilha.h"
Pilha *criaPilha(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int pilhacheia(Pilha *p)
{
    return (p->topo == MAXEMPILHADO);
}

int pilhavazia(Pilha *p)
{
    return p->topo < 0;
}

void empilha(Pilha *p)
{
    p->conteineratraque[p->topo++] = 1;
}
void empilhaatraque(Pilha *p, int x)
{
    int i = 0;
    while (1)
    {
        if (i == x || i == MAXEMPILHADO)
            break;
        p->conteineratraque[p->topo++] = 1;
        i += 1;
    }
}
int desempilha(Pilha *p)
{
    return p->conteineratraque[p->topo--];
}
//Aqui acaba as funçoes dos atraques

//Inicio Travessas
PilhaTravessa *criaPilhaTravessa(void)
{
    PilhaTravessa *p = (PilhaTravessa *)malloc(sizeof(PilhaTravessa));
    p->topo = -1;
    return p;
}

int pilhacheiaTravessa(PilhaTravessa *p)
{
    return (p->topo == MAXTravessa);
}

int pilhavaziaTravessa(PilhaTravessa *p)
{
    return p->topo < 0;
}

void empilhaTravessa(PilhaTravessa *p)
{
    p->conteinertravessa[p->topo++] = 1;
}

int desempilhaTravessa(PilhaTravessa *p)
{
    return p->conteinertravessa[p->topo--];
}
//FIm travessas