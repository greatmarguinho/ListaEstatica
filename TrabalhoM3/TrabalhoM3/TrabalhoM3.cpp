#include <iostream>
#include "shellsort.hpp"
#include "quicksort.hpp"
#include <chrono>

#define TAM1 5000
#define TAM2 10000
#define TAM3 15000

using namespace std;

int main(){
    srand(time(NULL));

    int count = 0;
    while(count < 20){
    int vetor[TAM1];


    preencher_vetor(vetor, TAM1); //gera elementos aleatorios
    cout << "Vetor: ";
    mostrar_vetor(vetor, TAM1);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    shellsort(vetor, TAM1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << endl << "Vetor Shellsort: ";
    //mostrar_vetor(vetor, TAM1);
    cout << endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[microSegundos]" << std::endl;

     cout << "Vetor: ";
     mostrar_vetor(vetor, TAM1);

    }
    // cout << "endl";

    // quicks(vetor, 0, TAM1-1, 1);

    // cout << endl << "Vetor Quicksort: ";
    // mostrar_vetor(vetor, TAM1);
    // cout << endl;
}
