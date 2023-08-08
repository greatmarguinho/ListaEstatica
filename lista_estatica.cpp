#include <iostream>
using namespace std;
#define MAXTAM 20

/*
    TADS LISTA EST�TICA
*/
struct Lista{
    char vetor[MAXTAM];
    int ultimo;
};

// lista => lista a ser inicializadaçao
void inicializar(Lista &lista){
    lista.ultimo = -1;
}

// lista => lista a ser manipulada
// valor => valor a ser armazenado na lista
// ordem => ordem da inser��o: ''- sem ordem // 'C'-cresc // 'D'-descr
// Retorna true (inser��o OK) ou false (inser��o falhou)
bool inserir(Lista &lista, char valor, char ordem=' '){
    int pos;
    if( lista.ultimo == MAXTAM-1 ) return false; // se a lista estiver cheia, ele não deixa inserir mais valores

    switch(ordem){
        case 'C':
            pos=0;
            while( pos <= lista.ultimo && valor > lista.vetor[pos]) pos++;
            lista.ultimo++;
            for( int i=lista.ultimo; i>pos; i-- )
                lista.vetor[i] = lista.vetor[i-1];
            lista.vetor[pos] = valor;
            break;
        case 'D':
            pos=0;
            while( pos <= lista.ultimo && valor < lista.vetor[pos]) pos++;
            lista.ultimo++;
            for( int i=lista.ultimo; i>pos; i-- )
                lista.vetor[i] = lista.vetor[i-1];
            lista.vetor[pos] = valor;
            break;
        default:
            lista.ultimo++;
            lista.vetor[lista.ultimo] = valor;
            break;
    }
    return true;
}

// lista => lista a ser usada na pesquisa
// valor => valor a ser procurado
// retorna a posi��o do valor ou -1 se n�o achou
int pesquisar(Lista lista, char valor){
    for(int i=0; i<=lista.ultimo; i++)
        if(lista.vetor[i] == valor)
            return i;
    return -1;
}

// lista => lista a ser usada na retirada
// valor => valor a ser retirado
// retorna true (retirada ok) ou false (retirada falhou)
bool retirar(Lista &lista, char valor){
    int pos = pesquisar(lista, valor);
    int j;

    if(pos == -1)
        return false;

    for(int i = 0; i <= lista.ultimo; i++){
        if(lista.vetor[i] == valor){
            j = i;
            while(j <= lista.ultimo){
                lista.vetor[j] = lista.vetor[j+1];
                j++;
            }
            lista.ultimo--;
            i--;
        }
    }
    return true;
}


// lista => lista a ser usada na retirada
// pos => posicao do valor a ser retirado
// retorna true (retirada ok) ou false (retirada falhou)
bool retirar(Lista &lista, int pos) {
    if (pos > lista.ultimo || pos < 0)
        return false;

    for (int i = pos; i <= lista.ultimo; i++) {
        lista.vetor[i] = lista.vetor[i + 1];
    }

    lista.ultimo--;
    return true;
}


// Mostrar a lista na tela
void mostrar(Lista lista){
    for( int i=0; i<=lista.ultimo; i++ )
        cout << lista.vetor[i] << "\t";
}


// Clonar a lista
// Recebe uma lista e volta uma copia
Lista clonar(Lista lista){
    Lista copia;
    inicializar(copia);

    for(int i = 0; i <= lista.ultimo; i++){
    inserir(copia, lista.vetor[i], ' ');
    }
    return copia;
}



// Concatenar
// Recebe duas listas e retorna uma terceira com a junção das duas primeiras, em ordem ou não
Lista concatenar(Lista l1, Lista l2){
    Lista l3;
    inicializar(l3);

    for(int i = 0; i <= l1.ultimo; i++){
        inserir(l3, l1.vetor[i], ' ');
    }

    for(int i = 0; i <= l2.ultimo; i++){
        inserir(l3, l2.vetor[i], ' ');
    }

    return l3;
}

// Eliminar Duplicados
// Recebe uma lista e retira todos os valores duplicados dela
void eliminarDuplicados(Lista &lista){
    char valor;
    for(int i = 0; i <= lista.ultimo; i++){
        valor = lista.vetor[i];
        for(int j = i + 1; j <= lista.ultimo; j++){
            if(valor == lista.vetor[j]){
                retirar(lista, valor);
            }
        }
    }
}
/*
    FIM TADS
*/

int main(){
    Lista l1;
    Lista l2;

    inicializar(l2);
    inserir(l2, 'P', ' ');
    inserir(l2, 'E', ' ');
    inserir(l2, 'N', ' ');
    inserir(l2, 'N', ' ');

    inicializar(l1);
    inserir(l1, 'P', ' ');
    inserir(l1, 'E', ' ');
    inserir(l1, 'N', ' ');
    inserir(l1, 'N', ' ');
    inserir(l1, 'A', ' ');
    inserir(l1, 'M', ' ');
    inserir(l1, 'B', ' ');
    inserir(l1, 'B', ' ');
    inserir(l1, 'B', ' ');

    eliminarDuplicados(l1);

    mostrar(l1);
    cout << pesquisar(l1, 'P');
    cout << retirar(l1, 'N');
    cout << "\n";
    mostrar(l1);

    cout << endl;
    mostrar(clonar(l1));

    cout << endl;
    concatenar(l1,l2);
    mostrar(concatenar(l1,l2));

}
