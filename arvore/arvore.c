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
int obterAlturaSemRecursao( Arvore );
int contarNos( Arvore ); // num de nós
Arvore construirArvoreRam(int); // cosntruir arvore perfeitamente balanceada dado o numero de nos desejado
int numAleatorio(int p, int u);
No *buscar(Arvore, int);
No *buscarRecursivo(Arvore, int);

int main(){
    srand((unsigned int)time(NULL));
    No *busca;
    Arvore a;
    a = construirArvoreRam(7);
    a = construirExemplo();
    mostrarArvore(a);
    printf("\n\n altura: %d\n Nos: %d\n",obterAlturaSemRecursao(a), contarNos(a));
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
    c = ConstruirArvore(14,NULL,NULL);
    a = ConstruirArvore(10, a, c);

    c = ConstruirArvore(44, NULL,NULL);
    b = ConstruirArvore(34, NULL, NULL);
    b = ConstruirArvore(40,b, c);
    //agora construindo a raíz
    b = ConstruirArvore(30, a, b);
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

int obterAltura(Arvore ap){ //recursivo
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

int obterAlturaSemRecursao(Arvore ap){
    int altura = -1; int alturaDir, alturaEsq;
    No *p;
    if (ap != NULL)
    {
        p = ap; alturaEsq = 0; alturaDir = 0;
        while (p->esq != NULL)
        {
            alturaEsq++;
            p = p->esq;
        }
        p = ap;
        while (p->dir != NULL)
        {
            alturaDir++;
            p = p->esq;
        }
        if (alturaEsq > alturaDir)
            altura = alturaEsq;
        else
            altura = alturaDir;
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

No *buscar(Arvore ap, int n){ //não recursivo
    No *p, *y;
    y = NULL;
    if (ap != NULL)
    {
        Fila f;
        p = ap;
        criarFilaVazia(&f);
        pushFila(&f,p);
        do
        {
            p = acessarFila(&f);
            if (p->elemento == n)
            {
                y = p;
            }
            else
            {
                popFila(&f);
                if(p->esq != NULL) pushFila(&f, p->esq);
                if(p->dir != NULL) pushFila(&f, p->dir);
            }
        } while (verificarFilaVazia(&f) == FALSE && y == NULL);
    }
    return y;
}

No *buscarRecursivo(Arvore ap, int n){
    No *y = NULL;
    if (ap != NULL)
    {
        if (ap->elemento == n)
            y = ap;
        else if (n < ap->elemento)
        {
            y = buscarRecursivo(ap->esq, n);
        }
        else
            y = buscarRecursivo(ap->dir, n);
    }
    return y;
}



int numAleatorio(int p, int u){
    return p + rand() % (u - p + 1);
}