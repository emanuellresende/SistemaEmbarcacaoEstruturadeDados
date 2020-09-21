
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

fila *inserirfila(fila *q, tipo_info info)
{ /*Adiciona um item no fim da fila q. Retorna true se operação realizada com sucesso, false caso contrário*/
    tipo_elem *p;
    int aux;
    aux = filavazia(q);
    p = malloc(sizeof(tipo_elem));

    p->info = info;
    p->lig = NULL;
    if (aux == true)
        q->inicio = p;
    else
        q->fim->lig = p;
    q->fim = p;

    return q;
}

void imprimirfila(fila *q)
{
    tipo_elem *ponteiro = q->inicio;

    while (ponteiro != NULL)
    {
        printf("%d\n", ponteiro->info);
        ponteiro = ponteiro->lig;
    }
}
