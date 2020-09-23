#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#include <time.h>
#include <string.h>
//IMplementar funçao sleep
int main(void)
{
    //Variaveis
    int UnidadeTempogeral = 0, auxfila = 0, id_navio = 0, qntnovonavio = 0, tamanhofilanavios1 = 0, tamanhofilanavios2 = 0, tamanhofilanavios3 = 0, tamanhofilanavios4 = 0, aux = 0;
    //
    //Estrutura
    fila *filanavios1 = definirfila();
    fila *filanavios2 = definirfila();
    fila *filanavios3 = definirfila();
    fila *filanavios4 = definirfila();

    Pilha *atraque1 = criaPilha();
    Pilha *atraque2 = criaPilha();
    Pilha *atraque3 = criaPilha();
    Pilha *atraque4 = criaPilha();

    PilhaTravessa *travessa1 = criaPilhaTravessa();
    PilhaTravessa *travessa2 = criaPilhaTravessa();
    PilhaTravessa *travessa3 = criaPilhaTravessa();
    PilhaTravessa *travessa4 = criaPilhaTravessa();
    //
    //While para o controle geral
    while (1)
    {
        //Numero Aleatorio Para o while
        srand(time(NULL));
        qntnovonavio = (rand() % 4);
        //Esse While define os navios que estao chegando e os envia para as filas
        while (1)
        {
            if (auxfila == qntnovonavio)
                break;
            insertfila(filanavios1, filanavios2, filanavios3, filanavios4, &id_navio, &tamanhofilanavios1, &tamanhofilanavios2, &tamanhofilanavios3, &tamanhofilanavios4);
            auxfila++;
        }
        //Nessas verificacoes de if verifica se a pilha e a fila respectivas estao vazias se estiver empilha um atraque e remove 1 da fila
        if (pilhavazia(atraque1) && filavazia(filanavios1) == false)
        {
            aux = filanavios1->inicio->qntConteiner;
            empilhaatraque(atraque1, aux);
            removerfila(filanavios1);
        }

        if (pilhavazia(atraque2) && filavazia(filanavios2) == false)
        {
            aux = filanavios2->inicio->qntConteiner;
            empilhaatraque(atraque2, aux);
            removerfila(filanavios2);
        }

        if (pilhavazia(atraque3) && filavazia(filanavios3) == false)
        {
            aux = filanavios3->inicio->qntConteiner;
            empilhaatraque(atraque3, aux);
            removerfila(filanavios3);
        }
        if (pilhavazia(atraque4) && filavazia(filanavios4) == false)
        {
            aux = filanavios4->inicio->qntConteiner;
            empilhaatraque(atraque4, aux);
            removerfila(filanavios4);
        }

        //Fim sequencia de ifs
        if (pilhacheiaTravessa(travessa1))
        {
            printf("----- Travessa Cheia -----\n");
            printf(" Veiculo Enviando Travessa 1 para o Armazenamento \n");
            // Funçao Para chamar o carrinho para esvaziar a travessa
        }
        else
        {
            aux = travessa1->topo;
            if (aux <= 1)
            {
                empilhaTravessa(travessa1);
                empilhaTravessa(travessa2);
                empilhaTravessa(travessa3);
                empilhaTravessa(travessa4);
                desempilha(atraque1);
                desempilha(atraque2);
                desempilha(atraque3);
                desempilha(atraque4);
            }
            else if (aux == 4)
            {

                empilhaTravessa(travessa1);
                empilhaTravessa(travessa2);
                desempilha(atraque1);
                desempilha(atraque2);
            }
        }

        break; //Para o while de controle geral
    }          //Fecha o while de controle geral

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
