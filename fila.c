
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

tipo_elem entradanavios(void)
{

    printf("Entrou \n");
    tipo_elem aux;

    srand(time(NULL));
    aux.id = (rand() % 10000);
    aux.qntConteiner = 4 + (rand() % 16);
    aux.qtdTempofila = 7;
    return aux;
}

int menorfila(int a, int b, int c, int d)
{
    srand(time(NULL));
    if (a < b && a < c && a < d)
    {
        return 1;
    }
    else if (a == b && a == c && a == d)
    {
        return (1 + (rand() % 4));
    }
    else if (b < a && b < c && b < d)
    {
        return 2;
    }
    else if (c < a && c < b && c < d)
    {
        return 3;
    }
    else if (d < a && d < b && d < c)
    {
        return 4;
    }
}

void insertfila(void)
{
    verificarmenorfila = menorfila(tamanhofilanavios1, tamanhofilanavios2, tamanhofilanavios3, tamanhofilanavios4);
    filanaviosaux = entradanavios();
    if (verificarmenorfila == 1)
    {
        filanavios1 = inserirfila(filanavios1, &filanaviosaux, &tamanhofilanavios1);
    }
    else if (verificarmenorfila == 2)
    {
        filanavios1 = inserirfila(filanavios2, &filanaviosaux, &tamanhofilanavios2);
    }
    else if (verificarmenorfila == 3)
    {
        filanavios1 = inserirfila(filanavios3, &filanaviosaux, &tamanhofilanavios3);
    }
    else if (verificarmenorfila == 4)
    {
        filanavios1 = inserirfila(filanavios4, &filanaviosaux, &tamanhofilanavios4);
    }
}
