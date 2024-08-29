#include <stdio.h>
#include "Booleano.h"

#define Max 10
#define sinal 0 // posição inicial da pilha
#define ghost 36

typedef struct
{
    int topo;
    char Vetor[Max];
} Pilhach;

Pilhach criarPilha();
bool pilhaVazia(Pilhach);
char acessarPilha(Pilhach);
Pilhach pushPilha(Pilhach, char);
Pilhach popPilha(Pilhach);
Pilhach esvaziar(Pilhach);
int obterProfundidade(Pilhach);
void mostrarPilha(Pilhach);
Pilhach inverter(Pilhach);    // fazer como usuário e como desenvolvedor
Pilhach copiarPilha(Pilhach); // fazer como usuário e como desenvolvedor

Pilhach criarPilha()
{
    Pilhach P;
    P.topo = sinal;
    P.Vetor[0] = Max - 1; // posição da pilha cheia
    return P;
}

bool pilhaVazia(Pilhach P)
{
    bool ok = TRUE;
    if (P.topo > sinal)
        ok = FALSE;
    return ok;
}

char acessarPilha(Pilhach P)
{
    char y;
    if (P.topo > sinal)
    {
        y = P.Vetor[P.topo];
    }
    else
        y = ghost;
    return y;
}

Pilhach pushPilha(Pilhach P, char ch)
{
    if (P.topo < P.Vetor[0])
    {
        P.topo++;
        P.Vetor[P.topo] = ch;
    }
    return P;
}

Pilhach popPilha(Pilhach P)
{
    if (P.topo > sinal)
    {
        P.topo--;
    }
    return P;
}

Pilhach esvaziar(Pilhach P)
{
    P.topo = sinal;
    return P;
}

int obterProfundidade(Pilhach P)
{
    int y = P.topo;
    return y;
}

void mostrarPilha(Pilhach P) // aqui posso ter acesso direto, sou desenvolvedor
{
    int i;
    for (i = P.topo; i > sinal; i--)
    {
        printf("\n%d", P.Vetor[i]);
    }
}

// metodo desenvolvedor
/*Pilhach inverter(Pilhach P)
{
    int i = 1, j = P.topo;
    for (i = 1; i <= (P.topo / 2); i++)
    {
        char aux;
        aux = P.Vetor[i];
        P.Vetor[i] = P.Vetor[j];
        printf("\n%d isso vale o 1\n",P.Vetor[i]);
        P.Vetor[j] = aux;
        j--;
    }
    return P;
}*/

//metodo usuário
Pilhach inverter(Pilhach P)
{
    char ch;
    Pilhach aux;
    aux = criarPilha();
    while (!pilhaVazia(P))
    {
        ch = acessarPilha(P);
        aux = pushPilha(aux, ch);
        P = popPilha(P);
    }
    return aux;
}

Pilhach copiarPilha(Pilhach P)
{
    return P;
}