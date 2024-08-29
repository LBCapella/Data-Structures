/* TAD Pilha = pilha de números inteiros positivos */
/*
  Arquivo: Luan_Capella_PARTE1.h
  Autor: Luan Bonasorte Capella
  Date: 20/05/24 11:00
  Descrição: Este programa implementa o tipo Pilha com números inteiros positivos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include "Booleano.h"
#define SINAL 0
#define Fantasma 0
 
#define MaxPilha 201
typedef struct {
      int topo;    // topo indica o local onde se encontra o topo da pilha
      unsigned char tabela[MaxPilha];	  // os itens são colocados na pilha a partir da posição 1 
} Pilha;
 
/* interface */
Pilha criarPilha();						// criar pilha vazia
Pilha construirPilha(int);				// construir uma pilha com os números inteiros de {1..n] em ordem aleatória
void mostrarPilha(Pilha);				// mostrar o topo e o conteúdo da pilha
bool PilhaVazia(Pilha);					// devolver TRUE se a pilha é vazia
unsigned char acessarTopo(Pilha);		// devolver o valor que está no topo da pilha
int obterTamanho(Pilha);				// devolver o tamanho da pilha
int contarPilha(Pilha, unsigned char);	// devolver a quantidade de itens da pilha até a ocorrência do valor dado.
 
Pilha pushPilha(Pilha, unsigned char);	// colocar um item na pilha
Pilha popPilha(Pilha);					// retirar um item da pilha
Pilha inverter(Pilha,int);				// inverter a parte superior da pilha, na quantidade indicada
 
 
/* implementações */
 
Pilha criarPilha(){
	Pilha P;
	P.topo = SINAL;
    P.tabela[0] = MaxPilha - 1;
    return P;
}
 
Pilha construirPilha(int n){
	int rd, p = 1, u = n, i;
	int aux;
	Pilha P;
    P.topo = SINAL;
    P.tabela[0] = MaxPilha - 1;
    if(n >= 0 && n < MaxPilha){
        P.topo = n;
        for(i = 1; i <= n; i++){
            P.tabela[i] = i;
        }
        srand(time(NULL));
        for(i = 1; i <= n; i++){
            aux = P.tabela[i];
            rd = p + (RAND_MAX*rand() + rand()) % (u-p+1);
            P.tabela[i] = P.tabela[rd];
            P.tabela[rd] = aux;
	    }
    }
	return P;
}

void mostrarPilha(Pilha P){
    int i;
    for (i = P.topo; i > SINAL; i--)
    {
        printf("\n%d", P.tabela[i]);
    }
}

bool PilhaVazia(Pilha P){
    bool ok = TRUE;
    if (P.topo > SINAL)
        ok = FALSE;
    return ok;
}

unsigned char acessarTopo(Pilha P){
    unsigned char y;
    if (P.topo > SINAL)
    {
        y = P.tabela[P.topo];
    }
    else
        y = Fantasma;
    return y;
}

int obterTamanho(Pilha P){
    int y;
    y = P.topo;
    return y;
}

int contarPilha(Pilha P, unsigned char ch){
    int i= P.topo, pos=0;
    while(i >= 1 && P.tabela[i]!= ch) {
	    i--; pos++;
    }
    if(pos > 0)
        pos++;    
	return pos;
}

Pilha pushPilha(Pilha P, unsigned char ch){
    if (P.topo < P.tabela[0])
    {
        P.topo++;
        P.tabela[P.topo] = ch;
    }
    return P;
}

Pilha popPilha(Pilha P){
    if (P.topo > SINAL)
    {
        P.topo--;
    }
    return P;
}

Pilha inverter(Pilha P,int n){
    int i, j;
    unsigned char aux;
    i = P.topo - n + 1; 
    j = P.topo;
    while (i < j)
    {
        aux = P.tabela[i];
        P.tabela[i] = P.tabela[j];
        P.tabela[j] = aux;
        i++; j--;
    }
    return P;
}