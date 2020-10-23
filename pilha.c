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

int pilhanaocheia(PilhaTravessa *p)
{
    return (p->topo != MAXTravessa);
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
void atracando(fila *filanavios1, fila *filanavios2, fila *filanavios3, fila *filanavios4, Pilha *atraque1, Pilha *atraque2, Pilha *atraque3, Pilha *atraque4, int *num_atraque, float *a1, float *a2, float *a3, float *a4, float *tm1, float *tm2, float *tm3, float *tm4, float *t1, float *t2, float *t3, float *t4)
{
    //FUnçao funcionando perfeitamente
    int aux = 0;
    float x = 0;
    if (pilhavazia(atraque1) && filavazia(filanavios1) == false && *num_atraque == 1)
    {
        aux = filanavios1->inicio->qntConteiner;
        empilhaatraque(atraque1, aux);
        removerfila(filanavios1);
        *num_atraque = 2;
        *t1 = (*tm1 + *a1) / 2;
        *a1 = *tm1;
        *tm1 = 0;
        return;
    }

    else if (pilhavazia(atraque2) && filavazia(filanavios2) == false && *num_atraque == 2)
    {
        aux = filanavios2->inicio->qntConteiner;
        empilhaatraque(atraque2, aux);
        removerfila(filanavios2);
        *num_atraque = 3;
        *t2 = (*tm2 + *a2) / 2;
        *a2 = *tm2;
        *tm2 = 0;
        return;
    }

    else if (pilhavazia(atraque3) && filavazia(filanavios3) == false && *num_atraque == 3)
    {
        aux = filanavios3->inicio->qntConteiner;
        empilhaatraque(atraque3, aux);
        removerfila(filanavios3);
        *num_atraque = 4;
        *t3 = (*tm3 + *a3) / 2;
        *a1 = *tm3;
        *tm3 = 0;
        return;
    }
    else if (pilhavazia(atraque4) && filavazia(filanavios4) == false && *num_atraque == 4)
    {
        aux = filanavios4->inicio->qntConteiner;
        empilhaatraque(atraque4, aux);
        removerfila(filanavios4);
        *num_atraque = 1;
        *t4 = (*tm4 + *a4) / 2;
        *a4 = *tm4;
        *tm4 = 0;
        return;
    }
}

void empilhar_travessas(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5, int aux, Pilha *a1, Pilha *a2, Pilha *a3, Pilha *a4)
{
    int travessa = 0;
    travessa = retornar_travessas(t1, t2, t3, t4, t5);
    //Mano esses ifs e pra ver qual fila vc vai desempilhar e empilhar no atraque seu zeruela
    if (aux == 1)
    {
        if (pilhavazia(a1))
            return;
        remover_elemento_atraque_paratravessa(t1, t2, t3, t4, t5, a1, travessa); // Funcionando
        return;
    }

    else if (aux == 2)
    {
        if (pilhavazia(a2))
            return;
        remover_elemento_atraque_paratravessa(t1, t2, t3, t4, t5, a2, travessa);
        return;
    }

    else if (aux == 3)
    {
        if (pilhavazia(a3))
            return;
        remover_elemento_atraque_paratravessa(t1, t2, t3, t4, t5, a3, travessa);
        return;
    }

    else if (aux == 4)
    {
        if (pilhavazia(a4))
            return;
        remover_elemento_atraque_paratravessa(t1, t2, t3, t4, t5, a4, travessa);
        return;
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

int retornar_travessas(PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5)
{
    //Fazer as verificaçoes de qual travessa nao esta cheia
    if (pilhanaocheia(t1))
        return 1;

    if (pilhanaocheia(t2))
        return 2;

    if (pilhanaocheia(t3))
        return 3;

    if (pilhanaocheia(t4))
        return 4;

    if (pilhanaocheia(t5))
        return 5;

    return 0;
}

void carro(int carro[4], PilhaTravessa *t1, PilhaTravessa *t2, PilhaTravessa *t3, PilhaTravessa *t4, PilhaTravessa *t5)
{
    if (pilhacheiaTravessa(t1))
    {
        carro[0] += 1;
        if (carro[0] == 3)
        {
            while (t1->topo != -1)
                t1->conteinertravessa[t1->topo--];
            carro[0] = 0;
        }
    }
    if (pilhacheiaTravessa(t2))
    {
        carro[1] += 1;
        if (carro[1] == 3)
        {
            while (t2->topo != -1)
                t2->conteinertravessa[t2->topo--];
            carro[1] = 0;
        }
    }
    if (pilhacheiaTravessa(t3))
    {
        carro[2] += 1;
        if (carro[2] == 3)
        {
            while (t3->topo != -1)
                t3->conteinertravessa[t3->topo--];
            carro[2] = 0;
        }
    }
    if (pilhacheiaTravessa(t4))
    {
        carro[3] += 1;
        if (carro[3] == 3)
        {
            while (t4->topo != -1)
                t4->conteinertravessa[t4->topo--];
            carro[3] = 0;
        }
    }
    if (pilhacheiaTravessa(t5))
    {
        carro[1] += 1;

        if (carro[1] == 3)
        {
            while (t5->topo != -1)
                t5->conteinertravessa[t5->topo--];
            carro[1] = 0;
        }
    }
}
void mostrar_carro(int c[4])
{
    if (c[0] == 1)
        printf("Carro 1 Saiu para a travessa \n");
    if (c[1] == 1)
        printf("Carro 2 Saiu para a travessa \n");
    if (c[2] == 1)
        printf("Carro 3 Saiu para a travessa \n");
    if (c[3] == 1)
        printf("Carro 4 Saiu para a travessa \n");
    if (c[0] != 1 && c[1] != 1 && c[2] != 1 && c[3] != 1)
        printf("Nenhum carro saiu para a travessa\n");
}
void imprimir_dados_travessas(PilhaTravessa *travessa1, PilhaTravessa *travessa2, PilhaTravessa *travessa3, PilhaTravessa *travessa4, PilhaTravessa *travessa5)
{
    printf("Travessa 1 - %d \n", travessa1->topo + 1);
    printf("Travessa 2 - %d \n", travessa2->topo + 1);
    printf("Travessa 3 - %d \n", travessa3->topo + 1);
    printf("Travessa 4 - %d \n", travessa4->topo + 1);
    printf("Travessa 5 - %d \n", travessa5->topo + 1);
}