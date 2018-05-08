#include <stdio.h>
#define MAX 10 //Tamanho máximo do arranjo

typedef struct theap // Define a estrutura heap
{ 
    int * vetor; //Arranjo com MAX posições
    int tam_arranjo; //Tamanho do arranjo
    int tam_heap; //Tamanho do heap
} theap;

int parent(int i)
// Retorna o índice do pai de i
{
    return i/2;
}

int left(int i)
//Retorna o índice do filho à esquerda de i
{
    return 2*i;
}

int right(int i)
//Retorna o índice do filho à direita de i
{
    return 2*i+1;
}

void troca1(int* vetor, int a, int b)
//Troca o valor armazenado na posição a pelo valor da posição b no vetor
// e vice-versa
{
    int aux;
    aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

void max_heapify(theap * a, int i)
// Caso o elemento a.vetor[i] não seja máximo, a função leva o 
// valor para baixo no heap máximo, de forma que a subárvore com 
// raiz no índice i se torne um heap máximo
{
    int l = left(i);
    int r = right(i);
    int maior;
    int aux;

    if(l <= a->tam_heap && a->vetor[l] > a->vetor[i])
        maior = l;
    else  
        maior = i;

    if (r <= a->tam_heap && a->vetor[r] > a->vetor[maior])
        maior = r;
    
    if (maior != i){
        troca1(a->vetor, i, maior);
        max_heapify(a,maior);
    }
}

void build_max_heap(theap * a)
//Percorre os nós restantes da árvore
// e executa MAX-HEAPIFY sobre cada um
{
    a->tam_heap = a->tam_arranjo;
    for(int i = a->tam_arranjo/2; i >= 1; i--){
        max_heapify(a, i);
    }
}

void heapsort(theap * a)
//Ordena o arranjo 'a'
{
    build_max_heap(a);
    for(int i = a->tam_arranjo; i >= 2; i--){
        troca1(a->vetor, 1, i);
        a->tam_heap -= 1;
        max_heapify(a, 1);
    }
}
