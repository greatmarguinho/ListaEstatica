#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

void Shell( int v[], int r, int s, int n ){
    int i, j, k, temp;
    bool achei;

    for( i=s+r; i<n; i+=r ){
        j = s;
        achei = false;
        while( j<i && !achei ){
            if( v[i] < v[j] ) achei = true;
            else j = j + r;
        }
        if( achei ){
            temp = v[i];
            k = i - r;
            while( k > j-r ){
                v[k+r] = v[k];
                k = k - r;
            }
            v[j] = temp;
        }
    }
}

void shellsort( int v[], int tam ){ //inicio grupo de 4
    for( int i=2; i>=0; i-- ){
        int inc = pow(2,i);
        for( int j=0; j<=inc; j++ ){
            Shell( v, inc, j, tam );
        }
    }
}

void shellsort2( int v[], int tam ){ //inicio grupo de 6
    int inc;
    for( int i=2; i>=0; i-- ){
        if(i == 2){
            inc = 6;
        }else if(i == 1){
            inc = 3;
        }else{
            inc = 1;
        }
        for( int j=0; j<=inc; j++ ){
            Shell( v, inc, j, tam );
        }
    }
}

void shellsort3( int v[], int tam ){ //inicio grupo de 8
    for( int i=3; i>=0; i-- ){
        int inc = pow(2,i);
        for( int j=0; j<=inc; j++ ){
            Shell( v, inc, j, tam );
        }
    }
}
