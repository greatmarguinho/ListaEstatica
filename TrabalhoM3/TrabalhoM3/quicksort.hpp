#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void quicksortMediana2( int v[], int esq, int dir){
    int aux;
    int i = esq;
    int j = dir;
    int x;
    int y = v[(esq+dir)/2];
    
    if(v[esq] >= v[dir] && v[dir] <= y){
        x = v[dir];
    }else if(v[dir] >= v[esq] && v[esq] <= y){
        x = v[esq];
    }else{
        x = y;
    }


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
    if( esq < j ) quicksortMediana2(v, esq, j);
    if( dir > i ) quicksortMediana2(v, i, dir);
}

void quicksortFinal( int v[], int esq, int dir){
    int aux;
    int i = esq;
    int j = dir;
    int x = v[dir];

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
    if( esq < j ) quicksortFinal(v, esq, j);
    if( dir > i ) quicksortFinal(v, i, dir);
}


void quicksortInicio( int v[], int esq, int dir){
    int aux;
    int i = esq;
    int j = dir;
    int x = v[esq];

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
    if( esq < j ) quicksortInicio(v, esq, j);
    if( dir > i ) quicksortInicio(v, i, dir);
}


void quicksortMediana1( int v[], int esq, int dir){
    int aux;
    int i = esq;
    int j = dir;
    int x = v[(esq+dir)/2];

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
    if( esq < j ) quicksortMediana1(v, esq, j);
    if( dir > i ) quicksortMediana1(v, i, dir);
}



// void quicks(int v[], int esq, int dir, int escolha = 1){
//     int x;

//     switch (escolha){
//         case 1:
//             quicksortInicio(v, esq, dir); // primeiro
//         break;

//         case 2:
//             quicksortFinal(v, esq, dir); // ultimo
//         break;

//         case 3:
//             quicksortMediana1(v, esq, dir); // mediana
//         break;

//         case 4:
//             quicksortMediana2(v, esq, dir); // mediana dos 3
//         break;

//         default:
//             quicksortMediana1(v, esq, dir);
//         break;
//     }
// }