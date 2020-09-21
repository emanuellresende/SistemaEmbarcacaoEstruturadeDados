#include <stdio.h>
#include <stdlib.h>
#define TravessaCheia 5
#define TravessasExistentes 5
#define MaxAtrancamento 4
#define MaxConteiner 16
#define TDescarregarConteiner 1
typedef int TipoChave;
//Lista
typedef struct
{
    TipoChave ID;
    TipoChave Tempo;
    TipoChave qntConteiners;
    
} Registro;
typedef struct
{
    Registro Travessas[MaxAtrancamento];
    TipoChave qntTravessas;

    Registro navio[MaxAtrancamento];
    TipoChave qntNavios;
} Porto;

//Pilha
typedef struct
{
    TipoChave qntEmpilhado;
} TipoitemGRUA;

typedef struct
{
    TipoChave fim;
    TipoitemGRUA Travessias[TravessasExistentes];
} TipoGrua;
//
Porto *criarATRACAMENTO(void);
TipoGrua *criarGRUA(void);
int main(int argc, char const *argv[])
{
    char encerrar;
    Porto *Atrancamento1, *Atrancamento2, *Atrancamento3, *Atrancamento4;
    Atrancamento1 = criarATRACAMENTO();
    Atrancamento2 = criarATRACAMENTO();
    Atrancamento3 = criarATRACAMENTO();
    Atrancamento4 = criarATRACAMENTO();
    TipoGrua *travessa1, *travessa2, *travessa3, *travessa4, *travessa5;
    travessa1 = criarGRUA();
    travessa2 = criarGRUA();
    travessa3 = criarGRUA();
    travessa4 = criarGRUA();
    travessa5 = criarGRUA();
    return 0;
}

Porto *criarATRACAMENTO(void)
{
    Porto *l;
    l = (Porto *)malloc(1 * sizeof(Porto));
    l->qntNavios = 0;
    return l;
}
TipoGrua *criarGRUA(void)
{
    TipoGrua *l;
    l = (TipoGrua *)malloc(1 * sizeof(TipoGrua));
    l->fim = 0;
    return l;
}
