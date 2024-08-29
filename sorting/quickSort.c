#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 101  // Definição correta de MAX sem ponto e vírgula

// Estrutura para armazenar uma lista de inteiros
typedef struct {
    int tamanho;
    int tabela[max];
} list;

// Declaração das funções
list criarListaVazia();
list criarListaAleatoria(int, int, int); // tamanho max, de x a y
void mostrarLista(list);
void quicksort(list *, int, int);


int main() {
    list A;
    A = criarListaVazia();
    A = criarListaAleatoria(max - 1, 1, 999);
    //mostrarLista(A); // Exibe a lista gerada
    quicksort(&A, 1, A.tamanho); // indice final e inicial
    mostrarLista(A); // Exibe a lista ordenada
    return 0;
}

// Função para criar uma lista vazia
list criarListaVazia() {
    list A;
    A.tamanho = 0;
    return A;
}

// Função para criar uma lista com números aleatórios
list criarListaAleatoria(int N, int a, int b) {
    list L;  // Corrige o tipo da lista
    int i, k, g, tam;
    double d;
    
    if (N >= max) tam = max - 1; else tam = N; // Usa `max` corretamente
    srand((int) time(NULL)); // Semente para o gerador de números aleatórios
    L.tamanho = tam;
    for (i = 1; i <= tam; i++) {  // Índice começa em 0
        d = (double)rand() / ((double)RAND_MAX + 1); // Gera número aleatório
        k = (int)(d * (b - a + 1));
        g = a + k;
        L.tabela[i] = g;
    }
    return L;
}

// Função para mostrar a lista
void mostrarLista(list A) {
    int n, i, cont;
    n = A.tamanho;
    if (n == 0) printf("\nLista vazia\n");
    else {
        printf("\nn = %d \n", n);
        cont = 0;
        for (i = 1; i <= n; i++) {  
            printf("%d ", A.tabela[i]);
            cont++;
            if (cont == 5) {
                printf("\n");
                cont = 0;
            }
        }
        printf("\n");
    }
}

void quicksort(list *ap, int p, int u){ //primeiro e ultimo
    int j;
    if (p < u)
    {
        j = separarLista(ap, p, u);
        quicksort(ap, p , j-1);
        quicksort(ap, j+1, u);
    }
    
}

int separarLista(list *ap, int p, int u ){
    int i, j, pivo, aux;
    i = p; j = u+1; pivo = ap->tabela[p];
    while (i < j)
    {
        do
        {
            i = i+1;
        } while ((ap->tabela[i] < pivo) && (i < u));
        do
        {
            j = j-1;
        } while (ap->tabela[j] > pivo);
        
        if (i < j)
        {
            aux = ap->tabela[i];
            ap->tabela[i] = ap->tabela[j];
            ap->tabela[j] = aux;
        }
    }
    aux = ap->tabela[p];
    ap->tabela[p] = ap->tabela[j];
    ap->tabela[j] = aux;
    return j;
}