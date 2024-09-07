#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# include"Booleano.h"
# include"FilaPointer.h"
typedef struct No{
    int elemento;
    struct No *esq;
    struct No *dir;
} No;

typedef No *Arvore;

Arvore criarArvoreVazia();
Arvore ConstruirArvore(int, Arvore, Arvore);
Arvore construirExemplo( );
void mostrarArvore (Arvore);
int obterAltura( Arvore ); // devolve a altura
int contarNos( Arvore ); // num de nós
Arvore construirArvoreRam(int); // cosntruir arvore perfeitamente balanceada dado o numero de nos desejado
int numAleatorio(int p, int u);

int main(){
    srand((unsigned int)time(NULL));
    Arvore a;
    a = construirArvoreRam(3);
    mostrarArvore(a);
    printf("\n\n altura: %d\n Nos: %d\n",obterAltura(a), contarNos(a));
    return 0;
}

Arvore criarArvoreVazia(){
    Arvore ap;
    ap = NULL;
    return ap;
}

Arvore ConstruirArvore(int y, Arvore a1, Arvore a2){
    Arvore a3;
    a3 = malloc(sizeof(No));
    a3->elemento = y;
    a3->esq = a1;
    a3->dir = a2;
    return a3;
}

Arvore construirExemplo( ){
    Arvore a,b,c;
    a = ConstruirArvore(4, NULL, NULL);
    c = ConstruirArvore(5,NULL,NULL);
    a = ConstruirArvore(2, a, c);

    c = ConstruirArvore(7, NULL,NULL);
    b = ConstruirArvore(6, NULL, NULL);
    b = ConstruirArvore(3,b, c);
    //agora construindo a raíz
    b = ConstruirArvore(1, a, b);
    return b;
}

void mostrarArvore (Arvore ap){ //caminhamento eRd
    if (ap != NULL)
    {
        mostrarArvore(ap->esq);
        printf("\n %d \n",ap->elemento);
        mostrarArvore(ap->dir);
    }
    
}

/*void mostrarArvore (Arvore ap){ //caminhamento Red
    if (ap != NULL)
    {
        printf("\n %d \n",ap->elemento);
        mostrarArvore(ap->esq);
        mostrarArvore(ap->dir);
    }
    
}*/

/*void mostrarArvore (Arvore ap){ //caminhamento edR
    if (ap != NULL)
    {
        mostrarArvore(ap->esq);
        mostrarArvore(ap->dir);
        printf("\n %d \n",ap->elemento);
    }
    
}*/

/*void mostrarArvore (Arvore ap){ //caminhamento por nível
    No *p; Fila f;
    if (ap == NULL)
        printf("\narvore vazia \n");
    else{
        criarFilaVazia(&f); p = ap; pushFila(&f,p);
        do
        {
            p = acessarFila(&f);
            printf("\n %d \n", p->elemento);
            popFila(&f);
            if(p->esq != NULL) pushFila(&f, p->esq);
            if(p->dir != NULL) pushFila(&f, p->dir); 
        } while (verificarFilaVazia(&f) == FALSE);
        
    }
}*/

int obterAltura(Arvore ap){
    int altura, alturaEsq, alturaDir;
    if (ap == NULL)
        altura = -1;

    else
    {
        alturaEsq = obterAltura(ap->esq);
        alturaDir = obterAltura(ap->dir);
        if (alturaEsq > alturaDir)
            altura = 1 + alturaEsq;
        else
            altura = 1 + alturaDir;
    }
    return altura;
}

int contarNos (Arvore ap){
    int nos = 0;
    if (ap != NULL){
        nos = 1 + contarNos(ap->esq) + contarNos(ap->dir);
    }
    return nos;
}

Arvore construirArvoreRam(int n ){
    Arvore ap; int nEsq, nDir, num = n-1;
    if (n == 0)
    {
        ap = criarArvoreVazia();
    }
    else
    {
        ap = malloc(sizeof(No));
        ap->elemento = numAleatorio(1,30);
        if (num != 1)
        {
            nEsq = num/2; nDir = num-nEsq;
            ap->esq = construirArvoreRam(nEsq);
            ap->dir = construirArvoreRam(nDir);
        }
    }
    return ap;
}

int numAleatorio(int p, int u){
    return p + rand() % (u - p + 1);
}