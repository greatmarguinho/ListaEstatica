#include <iostream>
#include "shellsort.hpp"
#include "quicksort.hpp"
#include <chrono>

#define TAM1 5000

using namespace std;

void copiaVetor(int vetorDes[], int vetorCopia[], int tam){
    for(int i=0; i < tam; i++){
        vetorCopia[i] = vetorDes[i];
    }
}


int main(){
    srand(time(NULL));

    int count = 0;
    int vetorDes[TAM1];
    int vetor[TAM1];
    int count2 = 0;
    double mediaPivoI = 0;
    double mediaPivoF = 0;
    double mediaPivoM1 = 0;
    double mediaPivoM2 = 0;
    double mediaShell1 = 0;
    double mediaShell2 = 0;
    double mediaShell3 = 0;

    while(count < 1){ // antes era 30, mas todas as informacoes nao caberiam no terminal

    //Muitas linhas estao comentadas, para que seja mais facil e mais rapido pegar o dados obtidos no terminal(estao em microsegundos)
    //Para mudar o método escolhido, apenas mude o metodo entre as variaveis begin e end, caso queira ver os vetores também sendo ordenados, descomente as outras linhas conforme suas necessidade

    preencher_vetor(vetorDes, TAM1); //gera elementos aleatorios
    copiaVetor(vetorDes, vetor, TAM1); //faz uma copia para poder ser usada sempre que for feita uma nova ordenação
    count2 = 0;


    cout << "pivo inicial:" << endl;
    while(count2 < 20){
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    quicksortInicio(vetor, 0, TAM1-1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    mediaPivoI = mediaPivoI + std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    count2++;
    }

    count2 = 0;

    cout << "pivo final:" << endl;
    while(count2 < 20){
    copiaVetor(vetorDes, vetor, TAM1);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    quicksortFinal(vetor, 0, TAM1-1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    mediaPivoF = mediaPivoF + std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    count2++;
    }

    count2 = 0;

    cout << "pivo mediana:" << endl;
    while(count2 < 20){
    copiaVetor(vetorDes, vetor, TAM1);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    quicksortMediana1(vetor, 0, TAM1-1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    mediaPivoM1 = mediaPivoM1 + std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    count2++;
    }

    count2 = 0;

    cout << "pivo mediana2:" << endl;
    while(count2 < 20){
    copiaVetor(vetorDes, vetor, TAM1);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    quicksortMediana2(vetor, 0, TAM1-1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    mediaPivoM2 = mediaPivoM2 + std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    count2++;
    }

    count2 = 0;

    cout << "shellsort grupo de 4:" << endl;
    while(count2 < 20){
    copiaVetor(vetorDes, vetor, TAM1);
    //mostrar_vetor(vetor, TAM1);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    shellsort(vetor, TAM1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    mediaShell1 = mediaShell1 + std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    count2++;
    }

    count2 = 0;

    cout << "shellsort grupo de 6" << endl;
    while(count2 < 20){
    copiaVetor(vetorDes, vetor, TAM1);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    shellsort2(vetor, TAM1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    mediaShell2 = mediaShell2 + std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    count2++;
    }

    count2 = 0;

    cout << "shellsort grupo de 8" << endl;
    while(count2 < 20){
    copiaVetor(vetorDes, vetor, TAM1);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    shellsort3(vetor, TAM1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    mediaShell3 = mediaShell3 + std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    count2++;
    }

    cout << "media Pivo Inicio, caso " << count + 1 << ": " << mediaPivoI/20 << endl;
    cout << "media Pivo Final, caso " << count + 1 << ": " << mediaPivoF/20 << endl;
    cout << "media Pivo Mediana, caso " << count + 1 << ": " << mediaPivoM1/20 << endl;
    cout << "media Pivo Mediana dos 3, caso " << count + 1 << ": " << mediaPivoM2/20 << endl;
    cout << "media Shell grupo 4, caso " << count + 1 << ": " << mediaShell1/20 << endl;
    cout << "media Shell grupo 6, caso " << count + 1 << ": " << mediaShell2/20 << endl;
    cout << "media Shell grupo 8, caso " << count + 1 << ": " << mediaShell3/20 << endl;

    mediaPivoI = 0;
    mediaPivoF = 0;
    mediaPivoM1 = 0;
    mediaPivoM2 = 0;
    mediaShell1 = 0;
    mediaShell2 = 0;
    mediaShell3 = 0;

    cout << "\n \n \n";

    // cout << endl << "Vetor ordenado: ";
    //mostrar_vetor(vetor, TAM1);
    // cout << endl;

    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[microSegundos]" << std::endl;
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    //  cout << "Vetor: ";
    //  mostrar_vetor(vetor, TAM1);
    count++;
    }
}
