
#include "fila.h"

fila *definirfila(void)
{ /*Cria uma fila vazia. Deve ser usado antes de qualquer outra operação*/
    fila *q = (fila *)malloc(1 * sizeof(fila));
    q->inicio = NULL;
    q->fim = NULL;
    return q;
}

int filavazia(fila *q)
{ /*Retorna true se fila não contém elementos, false caso contrário*/

    if (q->inicio == NULL)
        return true;
    else
        return false;
}

fila *inserirfila(fila *q, tipo_elem *filanaviosaux, int *cont)
{ /*Adiciona um item no fim da fila q. Retorna true se operação realizada com sucesso, false caso contrário*/
    tipo_elem *p;
    int aux, t;

    aux = filavazia(q);

    p = malloc(sizeof(tipo_elem));

    p->id = filanaviosaux->id;
    p->qntConteiner = filanaviosaux->qntConteiner;
    p->qtdTempofila = filanaviosaux->qtdTempofila;
    p->lig = NULL;
    if (aux == true)
        q->inicio = p;
    else
        q->fim->lig = p;
    q->fim = p;
    *cont += 1;
    return q;
}

void imprimirfila(fila *q)
{
    int aux;
    tipo_elem *ponteiro = q->inicio;
    aux = filavazia(q);
    if (aux == true)
    {
        printf("FILA VAZIA!\n");
    }
    else
    {
        while (ponteiro != NULL)
        {
            printf("%d\n", ponteiro->id);
            printf("CONTEINER :%d \n", ponteiro->qntConteiner);
            printf("OutroBAND:%d \n", ponteiro->qtdTempofila);
            ponteiro = ponteiro->lig;
        }
    }
}
fila *removerfila(fila *q)
{
    int aux;
    aux = filavazia(q);
    tipo_elem *p;
    if (aux == true)
    {
        printf("FILA VAZIA!\n");
        return 0;
    }
    else
    {

        p = q->inicio;
        q->inicio = p->lig;
        if (q->inicio == NULL)
            q->fim == NULL;
        free(p);
    }
    return q;
}

tipo_elem entradanavios(int *id_navio)
{
    tipo_elem aux;
    (*id_navio) += 1;
    aux.id = (*id_navio);
    aux.qntConteiner = (4 + (rand() % 4));
    aux.qtdTempofila = 7 + (*id_navio);
    return aux;
}

int menorfila(int *a, int *b, int *c, int *d)
{
    srand(time(NULL));
    int menor = *a;
    if (menor > *b)
    {
        menor = *b;
    }
    else if (menor > *c)
    {
        menor = *c;
    }
    else if (menor > *d)
    {
        menor = *d;
    }
    if (*a == *b && *a == *c && *a == *d)
    {
        return (1 + (rand() % 4));
    }
    else if (menor == *a)
    {
        return 1;
    }
    else if (menor == *b)
    {
        return 2;
    }
    else if (menor == *c)
    {
        return 3;
    }
    else if (menor == *d)
    {
        return 4;
    }
}

fila *insertfila(fila *filanavios1, fila *filanavios2, fila *filanavios3, fila *filanavios4, int *id_navios, int *tamanhofilanavios1, int *tamanhofilanavios2, int *tamanhofilanavios3, int *tamanhofilanavios4)
{
    int verificarmenorfila;
    tipo_elem filanaviosaux;
    memset(&filanaviosaux, 0, sizeof(tipo_elem));
    verificarmenorfila = 0;
    verificarmenorfila = menorfila(tamanhofilanavios1, tamanhofilanavios2, tamanhofilanavios3, tamanhofilanavios4);
    printf("Variavel verificarmenorfila: %d \n", verificarmenorfila);
    filanaviosaux = entradanavios(id_navios);
    if (verificarmenorfila == 1)
    {
        filanavios1 = inserirfila(filanavios1, &filanaviosaux, tamanhofilanavios1);
        return filanavios1;
    }
    else if (verificarmenorfila == 2)
    {
        filanavios2 = inserirfila(filanavios2, &filanaviosaux, tamanhofilanavios2);
        return filanavios2;
    }
    else if (verificarmenorfila == 3)
    {
        filanavios3 = inserirfila(filanavios3, &filanaviosaux, tamanhofilanavios3);
        return filanavios3;
    }
    else if (verificarmenorfila == 4)
    {
        filanavios4 = inserirfila(filanavios4, &filanaviosaux, tamanhofilanavios4);
        return filanavios4;
    }
}
