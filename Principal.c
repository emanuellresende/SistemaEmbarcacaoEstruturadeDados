#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#include <time.h>
#include <string.h>
#include <unistd.h>
//  Aluno: Emanuel Resende Melo
//  R.a : 0049538
//  E-mail: marechalmelo@gmail.com
//  Sistema Operacional Desenvolvido: Linux

//Observaçao: A biblioteca <unistd.h> e importada para utilizar a funçao unsleep(), porem so funciona no linux
// Todavia para utilizar no Windows será necessario trocar essa biblioteca para a windows.h e trocar a funçao unsleep pela
// funçao Sleep()

int main(void)
{
    //Variaveis
    int UnidadeTempogeral = 0, auxfila = 0, id_navio = 0, qntnovonavio = 0, tamanhofilanavios1 = 0, tamanhofilanavios2 = 0, tamanhofilanavios3 = 0, tamanhofilanavios4 = 0, aux = 0, auxtravessa = 0;
    int Qnt_execucao = 0, qnt_fila = 0, num_atraque = 1, carros[4];
    carros[0] = 0;
    carros[1] = 0;
    carros[2] = 0;
    carros[3] = 0;

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
    PilhaTravessa *travessa5 = criaPilhaTravessa();
    //
    //While para o controle geral

    while (Qnt_execucao < 100)
    {
        Qnt_execucao += 1;
        //Numero Aleatorio Para o while
        auxfila = 0;
        qntnovonavio = 0;
        qntnovonavio = (rand() % 4);
        //Esse While define os navios que estao chegando e os envia para as filas
        while (1)
        {
            if (auxfila == qntnovonavio)
                break;
            insertfila(filanavios1, filanavios2, filanavios3, filanavios4, &id_navio, &tamanhofilanavios1, &tamanhofilanavios2, &tamanhofilanavios3, &tamanhofilanavios4, &qnt_fila);
            auxfila++;
        }

        //Nessas verificacoes de if verifica se a pilha e a fila respectivas estao vazias se estiver empilha um atraque e remove 1 da fila
        auxfila = 0;
        //Esse while verifica os 4 atraques e vai colocando os navios nele
        while (1)
        {
            //Funçao que realiza o atracamento e atraca nos 4 atraques
            if (auxfila == 5)
                break;
            atracando(filanavios1, filanavios2, filanavios3, filanavios4, atraque1, atraque2, atraque3, atraque4, &num_atraque);
            auxfila++;
        }

        //Fim atracanmento
        auxfila = 1;
        //Inicio Travessas
        carro(carros, travessa1, travessa2, travessa3, travessa4, travessa5);
        while (1)
        {

            if (auxfila == 5)
                break;
            empilhar_travessas(travessa1, travessa2, travessa3, travessa4, travessa5, auxfila, atraque1, atraque2, atraque3, atraque4);
            auxfila++;
        }
        //Fim travessas

        //Area de Imprimir
        printf("----- Navios na fila ----- \n");
        printf("Fila 1: ");
        imprimirfila(filanavios1);
        printf("Fila 2: ");
        imprimirfila(filanavios2);
        printf("FIla 3: ");
        imprimirfila(filanavios3);
        printf("Fila 4: ");
        imprimirfila(filanavios4);
        printf("----- Travessas ----- \n");
        imprimir_dados_travessas(travessa1, travessa2, travessa3, travessa4, travessa5);
        printf("----- Carros ----- \n");
        mostrar_carro(carros);
        printf("\n\n\n");
        //Fim area de impressao
        usleep(1000000); //Funçao para parar a execuçao por determinados segundos
    }                    //Fecha o while de controle geral

    return 0;
}
