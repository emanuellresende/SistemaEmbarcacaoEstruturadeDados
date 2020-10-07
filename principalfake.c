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
        if (i == x + 1 || i == MAXEMPILHADO)
            break;
        p->conteineratraque[p->topo++] = 1;
        i += 1;
    }
}
int desempilha(Pilha *p)
{
    return p->conteineratraque[p->topo--] = 0;
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
    if (pilhacheiaTravessa(p))
        return;
    p->conteinertravessa[p->topo++] = 1;
}

int desempilhaTravessa(PilhaTravessa *p)
{
    return p->conteinertravessa[p->topo--] = 0;
}

//FIm travessas

//Passar essa void para outro lugar depois
void atracando(fila *filanavios1, fila *filanavios2, fila *filanavios3, fila *filanavios4, Pilha *atraque1, Pilha *atraque2, Pilha *atraque3, Pilha *atraque4, int *num_atraque)
{
    int aux = 0;
    if (pilhavazia(atraque1) && filavazia(filanavios1) == false && *num_atraque == 1)
    {
        aux = filanavios1->inicio->qntConteiner;
        empilhaatraque(atraque1, aux);
        removerfila(filanavios1);
        *num_atraque = 2;
        return;
    }

    else if (pilhavazia(atraque2) && filavazia(filanavios2) == false && *num_atraque == 2)
    {
        aux = filanavios2->inicio->qntConteiner;
        empilhaatraque(atraque2, aux);
        removerfila(filanavios2);
        *num_atraque = 3;
        return;
    }

    else if (pilhavazia(atraque3) && filavazia(filanavios3) == false && *num_atraque == 3)
    {
        aux = filanavios3->inicio->qntConteiner;
        empilhaatraque(atraque3, aux);
        removerfila(filanavios3);
        *num_atraque = 4;
        return;
    }
    else if (pilhavazia(atraque4) && filavazia(filanavios4) == false && *num_atraque == 4)
    {
        aux = filanavios4->inicio->qntConteiner;
        empilhaatraque(atraque4, aux);
        removerfila(filanavios4);
        *num_atraque = 1;
        return;
    }
}

void empilhar_travessas(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, int aux, Pilha *a1, Pilha *a2, Pilha *a3, Pilha *a4, int *carro1, int *carro2, int *carro3, int *carro4)
{
    int travessa;
    travessa = retornar_travessas(t1, t2, t3, t4, t5, carro1, carro2, carro3, carro4);
    //Mano esses ifs e pra ver qual fila vc vai desempilhar e empilhar no atraque seu zeruela
    if (aux == 1)
    {
        remover_elemento_atraque_paratravessa(t1, t2, t3, t4, t5, a1, travessa);
    }

    else if (aux == 2)
    {
        remover_elemento_atraque_paratravessa(t1, t2, t3, t4, t5, a2, travessa);
    }

    else if (aux == 3)
    {
        remover_elemento_atraque_paratravessa(t1, t2, t3, t4, t5, a3, travessa);
    }

    else if (aux == 4)
    {
        remover_elemento_atraque_paratravessa(t1, t2, t3, t4, t5, a4, travessa);
    }
}

void remover_elemento_atraque_paratravessa(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, Pilha *a1, int travessa)
{
    if (travessa == 1)
    {
        desempilha(a1);
        empilhaTravessa(t1);
    }

    else if (travessa == 2)
    {
        desempilha(a1);
        empilhaTravessa(t2);
    }

    else if (travessa == 3)
    {
        desempilha(a1);
        empilhaTravessa(t3);
    }

    else if (travessa == 4)
    {
        desempilha(a1);
        empilhaTravessa(t4);
    }
    else if (travessa == 5)
    {
        desempilha(a1);
        empilhaTravessa(t5);
    }
    else if (travessa == 0)
        printf("Todas travessas cheias \n");
}

int retornar_travessas(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, int *carro1, int *carro2, int *carro3, int *carro4)
{
    //Fazer as verificaçoes de qual travessa nao esta cheia
    if (pilhacheiaTravessa(t1))
    {
        if (*carro1 == 0)
            *carro1 += 1;
        else if (*carro1 == 3)
        {
            *carro1 = 0;
            t1 = NULL;
            t1 = criaPilhaTravessa();
            return 1;
        }
    }

    else
        return 1;

    if (pilhacheiaTravessa(t2))
    {
        if (*carro2 == 0)
            *carro2 += 1;
        else if (*carro2 == 3)
        {
            t2 = NULL;
            t2 = criaPilhaTravessa();
            *carro2 = 0;
            return 2;
        }
    }

    else
        return 2;

    if (pilhacheiaTravessa(t3))
    {
        if (*carro3 == 0)
            *carro3 += 1;
        else if (*carro3 == 3)
        {
            t3 = NULL;
            t3 = criaPilhaTravessa();
            *carro3 = 0;
            return 3;
        }
    }
    else
        return 3;

    if (pilhacheiaTravessa(t4))
    {
         if (*carro4 == 0)
            *carro2 += 1;
        else if (*carro2 == 3)
        {
            t2 = NULL;
            t2 = criaPilhaTravessa();
            *carro2 = 0;
            return 2;
        }
    }
    else
        return 4;

    if (pilhacheiaTravessa(t5))
        printf("Pilha 5 cheia \n");
    else
        return 5;

    return 0;
}

void carro(int *c1, int *c2, int *c3, int *c4)
{
    if (*c1 == 1 || *c1 == 2)
        *c1 += 1;
    if (*c2 == 1 || *c2 == 2)
        *c2 += 1;
    if (*c3 == 1 || *c3 == 2)
        *c3 += 1;
    if (*c4 == 1 || *c4 == 2)
        *c4 += 1;
}
void mostrar_carro(int c1, int c2, int c3, int c4)
{
    int aux = 0;
    if (c1 == 2)
        aux += 1;
    if (c2 == 2)
        aux += 1;
    if (c3 == 2)
        aux += 1;
    if (c4 == 2)
        aux += 1;
    printf("asd");
}