#include "Booleano.h";
#define sinal -1
#define Max 10
#define Geist 0


typedef struct{
int inicio;
int fim;
int Vetor[Max];
} Fila;

Fila criarFilaVazia();
bool FilaVazia( Fila );
int acessarPrimeiro( Fila );
Fila pushFila( Fila, int );
Fila popFila( Fila );


Fila criarFilaVazia(){
    Fila F;
    F.inicio = sinal;
    F.fim = sinal;
    return F;
}

bool FilaVazia( Fila F ){
    bool ok = FALSE;
    if (F.inicio == sinal)
        ok = TRUE;
    return ok;
}

int acessarPrimeiro( Fila F){
    int y = Geist;
    if (F.inicio != sinal)
    {
        y = F.Vetor[F.inicio];
    }
    return y;
}

Fila pushFila( Fila F, int n){
    int m;
    m = (F.fim + 1)% Max;
    if (m != F.inicio)
    {
        F.Vetor[m] = n;
        if (F.inicio == sinal)
            F.inicio = m;
        F.fim = m;
    }
    return F;
}

Fila popFila( Fila F){
    int m;
    if ( F.inicio != sinal ) {
        if ( F.inicio == F.fim ) {
         F.inicio = sinal; 
         F.fim = sinal;
        } 
        else {
            m = (F.inicio + 1) % Max;
            F.inicio = m;
        }
    }
    return F;
}


