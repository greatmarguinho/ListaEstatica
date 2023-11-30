#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void preencher_vetor( int v[], int tam, int limite=100 ){
    for( int i=0; i<tam; i++ ){
        v[i] = rand() % limite;
    }
}

void mostrar_vetor( int v[], int tam ){
    for( int i=0; i<tam; i++ ){
        cout << v[i] << "  ";
    }
}

void insercao( int v[], int tam ){
    int chave, i;
    for( int j=1; j<=tam-1; j++ ){
        chave = v[j];
        i = j -1;
        while( i>=0 && v[i]> chave ){
            v[i+1] = v[i];
            i = i-1;
        }
        v[i+1] = chave;
    }
}

int main(){
    srand(time(NULL));
    int vetor[15];

    preencher_vetor(vetor, 15);
    cout << "Vetor: ";
    mostrar_vetor(vetor, 15);
    insercao(vetor, 15);
    cout << endl << "Vetor: ";
    mostrar_vetor(vetor, 15);
    cout << endl;
}
