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

void quicksort( int v[], int esq, int dir ){
    int aux;
    int i = esq;
    int j = dir;
    int x = v[(i+j)/2];

    do{
        while( x>v[i] ) i++;
        while( x<v[j] ) j--;
        if( i<= j ){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }while( i <= j );
    if( esq < j ) quicksort(v, esq, j );
    if( dir > i ) quicksort(v, i, dir );
}


int main(){
    srand(time(NULL));
    int vetor[15];

    preencher_vetor(vetor, 15);
    cout << "Vetor: ";
    mostrar_vetor(vetor, 15);

    quicksort(vetor, 0, 14);

    cout << endl << "Vetor: ";
    mostrar_vetor(vetor, 15);
    cout << endl;
}
