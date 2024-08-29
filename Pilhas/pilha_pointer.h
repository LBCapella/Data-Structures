#include <stdio.h>
#include <string.h>
#include "Booleano.h"

#define Max 10
#define sinal 0 // posição inicial da pilha
#define ghost 36

typedef struct
{
    int topo;
    char Vetor[Max];
} Pilhach;

void criarPilha(Pilhach *);
bool pilhaVazia(Pilhach *);
char acessarPilha(Pilhach *);
void pushPilha(Pilhach *, char);
void popPilha(Pilhach *);
void esvaziar(Pilhach *);
int obterProfundidade(Pilhach *);
void mostrarPilha(Pilhach *);
void inverter(Pilhach *);               // fazer como usuário e como desenvolvedor
void copiarPilha(Pilhach *, Pilhach *); // fazer como usuário e como desenvolvedor
bool bemFormada(unsigned char *);
void inverterN(Pilhach *P, int n);
int contarPilha(Pilhach *P, char ch);

void criarPilha(Pilhach *P)
{
    P->topo = sinal;
    P->Vetor[0] = Max - 1; // posição da pilha cheia
}

bool pilhaVazia(Pilhach *P)
{
    bool ok = TRUE;
    if (P->topo > sinal)
        ok = FALSE;
    return ok;
}

char acessarPilha(Pilhach *P)
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

void pushPilha(Pilhach *P, char ch)
{
    if (P->topo < P->Vetor[0])
    {
        P->topo++;
        P->Vetor[P->topo] = ch;
    }
}

void popPilha(Pilhach *P)
{
    if (P->topo > sinal)
    {
        P->topo--;
    }
}

void esvaziar(Pilhach *P)
{
    P->topo = sinal;
}

int obterProfundidade(Pilhach *P)
{
    int y = P->topo;
    return y;
}

void mostrarPilha(Pilhach *P) // aqui posso ter acesso direto, sou desenvolvedor
{
    int i;
    for (i = P->topo; i > sinal; i--)
    {
        printf("\n%d", P->Vetor[i]);
    }
}

// metodo desenvolvedor
/*void inverter(Pilhach *P)
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
void inverter(Pilhach *P)
{
    char ch;
    Pilhach aux, temp;
    criarPilha(&aux);
    criarPilha(&temp);
    while (!pilhaVazia(P))
    {
        ch = acessarPilha(P);
        pushPilha(&aux, ch);
        popPilha(P);
    }
    while (!pilhaVazia(&aux))
    {
        ch = acessarPilha(&aux);
        pushPilha(&temp, ch);
        popPilha(&aux);
    }

    while (!pilhaVazia(&temp))
    {
        ch = acessarPilha(&temp);
        pushPilha(P, ch);
        popPilha(&temp);
    }
}

void inverterN(Pilhach *P, int n)
{
    char ch;
    int i = 1;
    Pilhach aux, temp;
    criarPilha(&aux);
    criarPilha(&temp);
    while (!pilhaVazia(P) && i <= n)
    {
        ch = acessarPilha(P);
        pushPilha(&aux, ch);
        popPilha(P);
        i++;
    }
    i = 1;
    while (!pilhaVazia(&aux) && i <= n)
    {
        ch = acessarPilha(&aux);
        pushPilha(&temp, ch);
        popPilha(&aux);
        i++;
    }
    i = 1;
    while (!pilhaVazia(&temp) && i <= n)
    {
        ch = acessarPilha(&temp);
        pushPilha(P, ch);
        popPilha(&temp);
        i++;
    }
}

// como dev
/*void copiarPilha(Pilhach *C, Pilhach *P)
{
    int i;
    for ( i = 1; i <= P->topo; i++)
    {
        C->topo++;
        C->Vetor[i] = P->Vetor[i];
    }

}*/

// como usuário
void copiarPilha(Pilhach *C, Pilhach *P)
{
    Pilhach A;
    criarPilha(&A);
    char ch;
    while (!pilhaVazia(P))
    {
        ch = acessarPilha(P);
        pushPilha(&A, ch);
        popPilha(P);
    }

    while (!pilhaVazia(&A))
    {
        ch = acessarPilha(&A);
        pushPilha(P, ch);
        pushPilha(C, ch);
        popPilha(&A);
    }
}

/*bool bemFormada(unsigned char *str)
{
    char ch;
    bool ok = TRUE;
    Pilhach P;
    int i = 0;
    criarPilha(&P);
    int tam = strlen(str);
    while (i < tam && ok == TRUE)
    {
        ch = str[i];
        if (ch == '(')
        {
            pushPilha(&P, ch);
        }
        else if (ch == ')')
        {
            if (pilhaVazia(&P))
                ok = FALSE;
            else
                popPilha(&P);
        }
        i++;
    }
    if (!pilhaVazia(&P))
        ok = FALSE;
    return ok;
}*/

int contarPilha(Pilhach *P, char ch)
{
    int qtd = 0;
    char ch2;
    Pilhach aux;
    criarPilha(&aux);
    do
    {
        ch2 = acessarPilha(P);
        if (ch2 != ch)
        {
            pushPilha(&aux, ch2);
            popPilha(P);
            qtd++;
        }
        else
            qtd++;
    } while (ch2 != ch);

    while (!pilhaVazia(&aux))
    {
        ch2 = acessarPilha(&aux);
        pushPilha(P, ch2);
        popPilha(&aux);
    }
    return qtd;
}