#include <stdio.h>
#include <stdlib.h>
#define TravessaCheia 5
#define TravessasExistentes 5
#define MaxAtrancamento 4
#define MaxConteiner 16
#define TDescarregarConteiner 1
typedef int TipoChave;
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

    Registro Atrancar[MaxAtrancamento];
    TipoChave qntNavios;
} Porto;

typedef struct
{
    TipoChave qntEmpilhado;
} TipoitemPilha;

typedef struct
{
    TipoChave fim;
    TipoitemPilha Travessias[TravessasExistentes];
} TipoPilha;

Porto *criarATRACAMENTO(void);

int main(int argc, char const *argv[])
{
    char encerrar;
    Porto *Aterramento1, *Aterramento2, *Aterramento3, *Aterramento4;
    Aterramento1 = criarATRACAMENTO();
    Aterramento2 = criarATRACAMENTO();
    Aterramento3 = criarATRACAMENTO();
    Aterramento4 = criarATRACAMENTO();

    return 0;
}

Porto *criarATRACAMENTO(void)
{
    Porto *l;
    l = (Porto *)malloc(1 * sizeof(Porto));
    l->qntNavios = 0;
    return l;
}
