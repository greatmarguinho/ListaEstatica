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

int escolherPivo(int v[], int esq, int dir, int x = NULL){
    int escolha;
    int pivo;
    int x;

    cout << "escolha o pivo: " << endl;
    cout << "[1] primeiro elemento" << endl;
    cout << "[2] último elemento" << endl;
    cout << "[3] elemento do meio" << endl;
    cout << "[4] mediana entre o primeiro, o último e o elemento do meio;" << endl;
    cin >> escolha;

    switch (escolha){
        case 1:
            x = v[0];
        case 2:
            x = v[dir];
        case 3:
            x = v[(esq+dir)/2];
        case 4:
            x = v[0];
        default:
            cout <<"Valor invalido" << endl;
            escolherPivo(v, esq, dir);
    } 
    return pivo;
}




void quicksort( int v[], int esq, int dir , int x){
    int aux;
    int i = esq;
    int j = dir;

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
    if( esq < j ) quicksort(v, esq, j, x);
    if( dir > i ) quicksort(v, i, dir, x);
}