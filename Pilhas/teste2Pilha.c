#include "Booleano.h"
#include <stdio.h>
#include <stdlib.h>

#define MaxPilha 5
#define sinal 0
#define fantasma '$'

typedef struct {
	int topo;
	unsigned char Vetor[MaxPilha];
}PilhaC;

typedef PilhaC *Pilha;

Pilha criarPilha();
bool PilhaVazia(Pilha);
unsigned char acessarPilha(Pilha);
void pushPilha(Pilha, unsigned char);
void popPilha(Pilha);
void esvaziarPilha(Pilha);
void mostrarPilha(Pilha);
int obterProfundidade(Pilha);
void inverter(Pilha);
void copy(Pilha, Pilha);

int main() {
	Pilha ap, bp;
	ap = criarPilha();
	bp = criarPilha();
	pushPilha(ap, 'a');
	pushPilha(ap, 'b');
	pushPilha(ap, 'b');
	pushPilha(ap, 'b');
	pushPilha(ap, 'b');
	pushPilha(ap, 'b');
	mostrarPilha(ap);
	free(ap);
	free(bp);
	return 0;
}

Pilha criarPilha() {
	Pilha ap = (Pilha)malloc(sizeof(Pilha));
	ap->topo = sinal;
	
	return ap;
}

bool PilhaVazia(Pilha A) {
	bool Vazio=FALSE;
	if(A->topo==sinal)
		Vazio=TRUE;
		
	return Vazio;
}

unsigned char acessarPilha(Pilha A) {
	unsigned char topo = fantasma;
	if(PilhaVazia(A)==FALSE)
		topo = A->Vetor[A->topo];
	
	return topo;
}

void pushPilha(Pilha A, unsigned char el) {
	int local;
	
	if(A->topo<MaxPilha){
		local = A->topo + 1;
		A->Vetor[local] = el;
		A->topo = local;
	}	
}

void popPilha(Pilha A) {
	if(PilhaVazia(A)==FALSE)
		A->topo = A->topo - 1;
}

void esvaziarPilha(Pilha A) {
	if(PilhaVazia(A)==FALSE)
		A->topo = sinal;
}

void mostrarPilha(Pilha A) {
	int i, tamanho = obterProfundidade(A);
	Pilha B, C;
	B = criarPilha();
	C = criarPilha(); 
	for(i = tamanho; i>0; i--) {
		pushPilha(B, acessarPilha(A));
		printf("%c\n", acessarPilha(A));
		popPilha(A);
	}
	tamanho = obterProfundidade(B);
	for(i = tamanho; i>0; i--) {
		pushPilha(A, acessarPilha(B));
		popPilha(B);
	}
	
	free(B);
	free(C);
	
	/*for(i = A->topo; i!=sinal; i--) //(i = A->topo; i>=1; i--)
		printf("%c\n", A->Vetor[i]);*/
}

int obterProfundidade(Pilha A) {
	int tamanho;
	tamanho = A->topo;
	return tamanho;
}

void copy(Pilha Orig, Pilha Dest) {
		
	/*unsigned char A[Orig->topo + 1];
	int tamanho = Orig->topo;
	int i;
	
	for(i=tamanho; i>=1; i--) {
		A[i] = acessarPilha(Orig);
		popPilha(Orig);
	}
	
	for(i=1; i<=tamanho; i++) {
		pushPilha(Orig, A[i]);
		pushPilha(Dest, A[i]);
	}*/
	Pilha A, B;
	A = criarPilha();
	B = criarPilha();
	int i, tamanho = obterProfundidade(Orig);
	for(i = tamanho; i>0; i--) {
		pushPilha(A, Orig->Vetor[i]); //invertida
		pushPilha(B, Orig->Vetor[i]); //invertida
		popPilha(Orig);
	}
	tamanho = obterProfundidade(A);
	for(i = tamanho; i>0; i--) {
		pushPilha(Dest, A->Vetor[i]); 
		pushPilha(Orig, B->Vetor[i]); 
		popPilha(A);
		popPilha(B);
	}
	free(A);
	free(B);
}

/*void inverter(PilhaCh *A) {
	int tamanho = A->topo;
	int i = 1, j = tamanho;
	unsigned char aux;
	
	while(i<j) {
		printf("\n\ni = %d\n\n", i);
		printf("\n\nj = %d\n\n", j);
		aux = A->Vetor[i];
		A->Vetor[i] = A->Vetor[j];
		A->Vetor[j] = aux;
		i++;
		j--;
	}
}*/

void inverter(Pilha A) {
	
	/*Pilha B = criarPilha();
	Pilha C = criarPilha();
	int i, tamanho = obterProfundidade(A);
	for(i = tamanho; i>0; i--) {
		pushPilha(B, A->Vetor[i]); // invertida
		popPilha(A);
	}
	tamanho = obterProfundidade(B);
	for(i = tamanho; i>0; i--) {
		pushPilha(C, B->Vetor[i]); // correta
		popPilha(B);
	}
	tamanho = obterProfundidade(C);
	for(i = tamanho; i>0; i--) {
		pushPilha(A, C->Vetor[i]); // invertida
		popPilha(C);
	}
	free(C);
	free(B);*/
	
	int i = 1, j = obterProfundidade(A);
	unsigned char copia;
	while(i<j) {
		copia = A->Vetor[j];
		A->Vetor[j] = A->Vetor[i];
		A->Vetor[i] = copia; 
		i++;
		j--;
	}
}