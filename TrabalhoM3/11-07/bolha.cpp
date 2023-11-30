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

void bubblesort( int v[], int tam ){
    int k, temp;

    bool troca = true;
    int lim = tam - 1;
    while( troca ){
		troca = false;
		for( int i=1; i<=lim; i++ ){
			if (v[i] > v[i + 1]){
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				k = i;
				troca = true;
			}
		}
		lim = k;
   }
}

void bubblesort2( int v[], int tam ){
    int temp;

    for( int i=0; i<tam-1; i++ ){
        for( int j=1; j<tam; j++ ){
            if( v[j-1] > v[j] ){
                temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
        }
    }

}


int main(){
    srand(time(NULL));
    int vetor[20];

    preencher_vetor(vetor, 15);
    cout << "Vetor: ";
    mostrar_vetor(vetor, 15);
    bubblesort2(vetor, 15);
    cout << endl << "Vetor: ";
    mostrar_vetor(vetor, 15);
    cout << endl;
}
