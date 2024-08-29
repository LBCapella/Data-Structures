#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 11  // Definição correta de MAX sem ponto e vírgula

// Estrutura para armazenar uma lista de inteiros
typedef struct {
    int tamanho;
    int tabela[max];
} list;

// Declaração das funções
list criarListaVazia();
list criarListaAleatoria(int, int, int); // tamanho max, de x a y
void mostrarLista(list);
list selectionSort(list);
list insertionSort(list);
list bubbleSort(list);

int main() {
    list A;
    A = criarListaVazia();
    A = criarListaAleatoria(max - 1, 1, 10);
    mostrarLista(A); // Exibe a lista gerada
    A = bubbleSort(A);
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

// Função para ordenar a lista usando Selection Sort
list selectionSort(list A) {
    int fim = A.tamanho;
    for (int i = 1; i < fim - 1; i++) {  // Índice começa em 0
        int p = i; // o p vai encontrar o maior
        for (int j = i + 1; j < fim; j++) {
            if (A.tabela[j] < A.tabela[p]) {  // Corrigido para ordem crescente
                p = j;
            }
        }
        if (p != fim) {
            int aux;
            aux = A.tabela[i];
            A.tabela[i] = A.tabela[p];
            A.tabela[p] = aux;
        }
    }
    return A;
}

list insertionSort(list A){
	int k;
	for (int i = 2; i <= A.tamanho; i++)
	{
		A.tabela[0] = A.tabela[i];
		k = i-1;
		while (A.tabela[0] < A.tabela[k])
		{
			A.tabela[k+1] = A.tabela[k];
			k = k-1;
		}
		A.tabela[k+1] = A.tabela[0];	
	}	
	return A;
}

list bubbleSort(list A){
	int fim, i , j, aux;
	fim = A.tamanho;
	for ( i = 1; i < A.tamanho; i++)
	{
		for ( j = 1; j < fim; j++)
		{
			if (A.tabela[j] > A.tabela[j+1])
			{
				aux = A.tabela[j];
				A.tabela[j] = A.tabela[j+1];
				A.tabela[j+1] = aux;
			}
		}
		fim--;
	}
	return A;
}