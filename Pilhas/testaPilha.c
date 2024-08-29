#include <stdio.h>
#include "exercicioPilhaPan.h"

int main(){
    int MP,n,q;
    Pilha Pan;
    MP = 2;
    Pan = construirPilha(MP);
    printf("\n\n  pilha de panquecas original ");     mostrarPilha(Pan);
    
    n = MP;
    do{
    	q = contarPilha(Pan,n);
    	if (q != n){
    		Pan = inverter(Pan,q);   // leva o maior para o topo
			Pan = inverter(Pan,n);   // leva o topo para a base
		}
		n--;
	} while (n!=1);
	
	printf("\n\n  pilha de panquecas ordenada ");	mostrarPilha(Pan);
	
    printf("\n FIM \n");
    return 0;
}