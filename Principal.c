#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#include <time.h>
#include <string.h>
//ERRO ESTA NAS TRAVESSAS FICA SEMPRE FIXO 4443 ARRUMAR
//IMplementar funçao sleep
int main(void)
{
    //Variaveis
    int UnidadeTempogeral = 0, auxfila = 0, id_navio = 0, qntnovonavio = 0, tamanhofilanavios1 = 0, tamanhofilanavios2 = 0, tamanhofilanavios3 = 0, tamanhofilanavios4 = 0, aux = 0, auxtravessa = 0;
    int bb = 0, qnt_fila = 0, num_atraque = 1, carrinho1 = 0, carrinho2 = 0, carrinho3 = 0, carrinho4 = 0;
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

    while (bb < 100)
    {
        bb += 1;
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
            //NAO MEXER AQUI JA ESTA TUDO CERTO GARAIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
            if (auxfila == 5)
                break;
            atracando(filanavios1, filanavios2, filanavios3, filanavios4, atraque1, atraque2, atraque3, atraque4, &num_atraque);
            auxfila++;
        }

        carro(&carrinho1, &carrinho2, &carrinho3, &carrinho4);
        //Fim atracanmento
        auxfila = 1;
        //Inicio Travessas
        while (1)
        {

            if (auxfila == 5)
                break;
            empilhar_travessas(travessa1, travessa2, travessa3, travessa4, travessa5, auxfila, atraque1, atraque2, atraque3, atraque4, &carrinho1, &carrinho2, &carrinho3, &carrinho4);
            auxfila += 1;
        }
        // colocar dentro de um while e ir rodando cada travessa por vez inves de ser em todas, ou seja atraque1 tira 1 conteiner e roda depois passa pro atraque 2 vai ser melhor pra eu fazer

        //Fim travessas

    } //Fecha o while de controle geral
    mostrar_carro(carrinho1, carrinho2, carrinho3, carrinho4);
    printf("%d", carrinho1);
    printf("t1->topo %d", travessa1->topo);
    return 0;
}
