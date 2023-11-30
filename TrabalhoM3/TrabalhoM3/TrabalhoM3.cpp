#include <iostream>
#include "shellsort.hpp"
#include "quicksort.hpp"

using namespace std;

int main(){
    srand(time(NULL));
    int vetor[15];

    preencher_vetor(vetor, 15);
    cout << "Vetor: ";
    mostrar_vetor(vetor, 15);
    shellsort2(vetor, 15);
    cout << endl << "Vetor Shellsort: ";
    mostrar_vetor(vetor, 15);
    cout << endl;


    





    srand(time(NULL));
    int vetor[15];
    int pivo = escolherPivo(vetor, 0, 14);

    preencher_vetor(vetor, 15);
    cout << "Vetor: ";

    int pivo = escolherPivo(vetor, 0, 14);
    mostrar_vetor(vetor, 15), pivo;

    quicksort(vetor, 0, 14, pivo);

    cout << endl << "Vetor: ";
    mostrar_vetor(vetor, 15);
    cout << endl;
}
