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

void selectionsort( int v[], int tam ){
    int pos_menor, temp;

    for( int i=0; i<tam-1; i++ ){
        pos_menor = i;
        for( int j=i+1; j<tam; j++ ){
            if( v[j] < v[pos_menor] ) pos_menor = j;
        }
        temp = v[i];
        v[i] = v[pos_menor];
        v[pos_menor] = temp;
    }
}


int main(){
    srand(time(NULL));
    int vetor[15];

    preencher_vetor(vetor, 15);
    cout << "Vetor: ";
    mostrar_vetor(vetor, 15);

    selectionsort(vetor, 15);

    cout << endl << "Vetor: ";
    mostrar_vetor(vetor, 15);
    cout << endl;
}
