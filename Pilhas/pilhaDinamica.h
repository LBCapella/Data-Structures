#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Booleano.h"

#define Max 101
#define sinal 0 // posição inicial da pilha
#define ghost 36

typedef struct
{
    int topo;
    char Vetor[Max];
} PilhaC;
typedef PilhaC * Pilha;

Pilha criarPilha();
bool pilhaVazia(Pilha );
char acessarPilha(Pilha);
void pushPilha(Pilha, char);
void popPilha(Pilha);
void esvaziar(Pilha);
int obterProfundidade(Pilha);
void mostrarPilha(Pilha);
void inverter(Pilha);               // fazer como usuário e como desenvolvedor
void copiarPilha(Pilha, Pilha); // fazer como usuário e como desenvolvedor
bool bemFormada(unsigned char * str);

Pilha criarPilha()
{
    Pilha P = (Pilha) malloc(sizeof(Pilha));
    P->topo = sinal;
    P->Vetor[0] = Max - 1; // posição da pilha cheia
    return P;
}

bool pilhaVazia(Pilha P)
{
    bool ok = TRUE;
    if (P->topo > sinal)
        ok = FALSE;
    return ok;
}

char acessarPilha(Pilha P)
{
    char y;
    if (P->topo > sinal)
    {
        y = P->Vetor[P->topo];
    }
    else
        y = ghost;
    return y;
}

void pushPilha(Pilha P, char ch)
{
    if (P->topo < P->Vetor[0])
    {
        P->topo++;
        P->Vetor[P->topo] = ch;
    }
}

void popPilha(Pilha P)
{
    if (P->topo > sinal)
    {
        P->topo--;
    }
}

void esvaziar(Pilha P)
{
    P->topo = sinal;
}

int obterProfundidade(Pilha P)
{
    int y = P->topo;
    return y;
}

void mostrarPilha(Pilha P) // aqui posso ter acesso direto, sou desenvolvedor
{
    int i;
    for (i = P->topo; i > sinal; i--)
    {
        printf("\n%d", P->Vetor[i]);
    }
}

// metodo desenvolvedor
/*void inverter(Pilha P)
{
    int i = 1, j = P->topo;
    for (i = 1; i <= (P->topo / 2); i++)
    {
        char aux;
        aux = P->Vetor[i];
        P->Vetor[i] = P->Vetor[j];
        printf("\n%d isso vale o 1\n",P->Vetor[i]);
        P->Vetor[j] = aux;
        j--;
    }
}*/

// metodo usuário
void inverter(Pilha P)
{
    char ch;
    Pilha aux, temp;
    aux = criarPilha();
    temp = criarPilha();
    while (!pilhaVazia(P))
    {
        ch = acessarPilha(P);
        pushPilha(aux, ch);
        popPilha(P);
    }
    while (!pilhaVazia(aux))
    {
        ch = acessarPilha(aux);
        pushPilha(temp, ch);
        popPilha(aux);
    }

    while (!pilhaVazia(temp))
    {
        ch = acessarPilha(temp);
        pushPilha(P, ch);
        popPilha(temp);
    }
}

// como dev
/*void copiarPilha(Pilha C, Pilha P)
{
    int i;
    for ( i = 1; i <= P->topo; i++)
    {
        C->topo++;
        C->Vetor[i] = P->Vetor[i];
    }

}*/

// como usuário
void copiarPilha(Pilha C, Pilha P)
{
    Pilha A;
    A = criarPilha();
    char ch;
    while (!pilhaVazia(P))
    {
        ch = acessarPilha(P);
        pushPilha(A, ch);
        popPilha(P);
    }

    while (!pilhaVazia(A))
    {
        ch = acessarPilha(A);
        pushPilha(P, ch);
        pushPilha(C, ch);
        popPilha(A);
    }
}

bool bemFormada(char *str)
{
    char ch; bool ok = TRUE;
    Pilha P; int i = 1;
    int tam = strlen(str);
    P = criarPilha();
    while (i <= tam && ok == TRUE)
    {
        /* code */
    }
    
}