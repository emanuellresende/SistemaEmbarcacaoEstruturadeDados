#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <time.h>
int main()
{
    srand(time(NULL));
    int UnidadeTempogeral = 0;
    tamanhofilanavios1 = 0;
    tamanhofilanavios2 = 0;
    tamanhofilanavios3 = 0;
    tamanhofilanavios4 = 0;
    filanavios1 = definirfila();
    filanavios2 = definirfila();
    filanavios3 = definirfila();
    filanavios4 = definirfila();
    qntnovonavio = 0;
    while (1)
    {
        auxfila = 0;
        qntnovonavio = (rand() % 4);
        printf("Quantidade gerada %d\n", qntnovonavio);
        while (auxfila != qntnovonavio)
        {
            insertfila();

            auxfila++;
        }
        break;
    }
    printf("\nFila 1 \n");
    imprimirfila(filanavios1);
    printf("\nFila 2 \n");
    imprimirfila(filanavios2);
    printf("\nFila 3 \n");
    imprimirfila(filanavios3);
    printf("\nFila 4 \n");
    imprimirfila(filanavios4);

    return 0;
}
