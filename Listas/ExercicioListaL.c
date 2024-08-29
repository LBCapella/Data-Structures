/* Lista Ligada - percorrer a lista */
/*
  Arquivo: exercicio1_LL.c
  Autor: Lisbete Madsen Barbosa
  Date: 12/05/24 09:48
  Descrição: Implementa o tipo Lista - uma lista encadeada com cabeça
             A lista contém inteiros não negativos.
*/

#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"
#define ghost -1

typedef struct Celula{
        int item;
        struct Celula* next;
}Celula;

typedef struct{
        int tamanho;
        Celula* inicio;
}Lista;

/* INTERFACE */

Lista criarLista();                   					// cria uma lista vazia	
bool verListaVazia(Lista*);             				// devolve TRUE se a lista é vazia
int obterTamanho(Lista*);              					// devolve o tamanho da lista

void mostrarLista(Lista*);              				// mostra na tela os elementos da lista					

void inserir(Lista*, int);           					// acrescenta um novo elemento ao inicio da lista

int localizarElemento(Lista*, int);						// devolve a ordem do registro que contém y ou zero

void buscaRemove ( Lista *, int );						// Remove a primeira ocorrência da célula que contém y

void buscaInsere ( Lista *, int );  					// Insere no início uma célula com o valor y somente se esse valor não ocorre na lista.

void trocarCelulas ( Lista *, Celula *, Celula *); 		// Troca a posição das duas células. Suponha que as referências sejam válidas, diferentes de NULL


int main(){
	Lista L;
	int w;
	int ordem;
	
	printf("\n");
	L = criarLista();  mostrarLista(&L);
	printf("\n");
	w = 10; printf(" inserir %d \n",w);
	inserir(&L,w);   	mostrarLista(&L);
	
	w = 20; printf("\n inserir %d \n",w);
	inserir(&L,w);   	mostrarLista(&L);
	
	w = 30; printf("\n inserir %d \n",w);
	inserir(&L,w);   	mostrarLista(&L);
	
	w = 40; printf("\n inserir %d \n",w);
	inserir(&L,w);   	mostrarLista(&L);
	
	w = 50; printf("\n inserir %d \n",w);
	inserir(&L,w);   	mostrarLista(&L);
	
	w = 30;
	ordem = localizarElemento(&L,w); printf("\n item = %d  ordem = %d ",w,ordem);
	

	printf("\n\n FIM ");
	return 0;
}

/* IMPLEMENTAÇÃO */
Lista criarLista(){     
    Lista L;
	L.tamanho = 0;
	L.inicio = NULL;
	return L;
}

bool verListaVazia(Lista * ap){
    bool vazia;
	if (ap -> inicio == NULL) vazia = TRUE;
	else vazia = FALSE;
	return vazia;

}

int obterTamanho(Lista * ap){
    return ap->tamanho;
}
     
void inserir(Lista *ap, int y){
    Celula * novo;
	novo = malloc(sizeof(Celula));
	novo -> item = y;
	novo -> next = ap -> inicio;
	ap -> inicio = novo;
	ap -> tamanho = ap -> tamanho + 1;
}
       
void mostrarLista(Lista * ap){
    Celula * seletor;
    seletor = ap->inicio;
    if(seletor != NULL){
    	do{
	    	printf(" %d ",seletor->item);
	    	seletor = seletor->next;
		} while(seletor != NULL);
	}else
		printf("Lista Vazia\n");
}

int localizarElemento(Lista* ap, int y){
	int cont = 1, ordem = 0;
	Celula * seletor;
    seletor = ap->inicio;
    while((seletor != NULL) && (seletor->item != y)){	
		seletor = seletor->next;
		cont++;
	}
	if(seletor != NULL)
		ordem = cont;
	return ordem;
}

void buscaRemove(Lista *ap, int y) {
	Celula *ant, *p;
	if (ap->inicio != NULL) {
		p = ap->inicio;
		if ( p->item == y) {
			ap->inicio = p->next;
			free(p); 
			ap->tamanho = ap->tamanho -1;
		}
		else {
			ant = p; p = p->next;
			while ((p != NULL) && (p->item != y)) {
				ant = p; p = p->next;
			}
			if (p != NULL) {
				ant->next = p->next;
				free(p); 
				ap->tamanho = ap->tamanho -1;
			}
		}
	}
}

void buscaInsere(Lista *ap, int y){
	Celula *p, *novo;
	p = ap->inicio;
	while ( (p != NULL) && (p->item != y) ) {
		p = p->next;
	}
	if ( p == NULL ) {
		novo = malloc(sizeof(Celula)); 
		novo->item = y; 
		novo->next = ap->inicio;
		ap->inicio = novo;
		ap->tamanho = ap->tamanho +1;
	}
}

void trocarCelulas(Lista *ap, Celula *cel1, Celula *cel2) {
	//A lista nao eh vazia e tem pelo menos dois elementos
	if(cel1!=cel2) {
		Celula *p = ap->inicio;	
		Celula *prev1 = NULL;
		Celula *prev2 = NULL;
		while(p!=NULL && (prev1==NULL || prev2==NULL)) {
			if(p->next==cel1) prev1 = p;
			else if(p->next==cel2) prev2 = p;
			p = p->next;
		}
		if(ap->inicio==cel1) {
			ap->inicio = cel2;
		}
		else if(ap->inicio==cel2) {
			ap->inicio = cel1;
		}
		if (prev1 != NULL) {
	        prev1->next = cel2;
	    }
	    if (prev2 != NULL) {
	        prev2->next = cel1;
	    }
	    Celula *temp = cel1->next;
	    cel1->next = cel2->next;
	    cel2->next = temp;		
	}
 
}
