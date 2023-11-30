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

void combinar( int vetor[], int comeco, int meio, int fim ){
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux = new int[tam];

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }
    while(com1 <= meio){
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }
    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }
    for(comAux = comeco; comAux <= fim; comAux++){
        vetor[comAux] = vetAux[comAux-comeco];
    }
    delete []vetAux;
}

void mergesort(int vetor[], int inicio, int fim ){
    if( inicio == fim ) return;

    int meio = (inicio+fim) / 2;
    mergesort( vetor, inicio, meio );
    mergesort( vetor, meio+1, fim );
    combinar(vetor, inicio, meio, fim );
}


int main(){
    srand(time(NULL));
    int vetor[15];

    preencher_vetor(vetor, 15);
    cout << "Vetor: ";
    mostrar_vetor(vetor, 15);

    mergesort( vetor, 0, 14 );

    cout << endl << "Vetor: ";
    mostrar_vetor(vetor, 15);
    cout << endl;
}
