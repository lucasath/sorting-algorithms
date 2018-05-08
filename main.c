#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_L 9
#define MAX_EXEC 3
#define MAX_ALGORITH 2
#define MAX_TYPES 3
#define MAX 10 //Tamanho máximo do arranjo

typedef struct theap // Define a estrutura heap
{ 
    int * vetor; //Arranjo com MAX posições
    int tam_arranjo; //Tamanho do arranjo
    int tam_heap; //Tamanho do heap
} theap;

void troca(int * vetor, int a, int b);
int partition(int *a, int p, int r);
void quicksort(int * a, int p, int r);

int * random_numbers(int type, int length);
void libera_matriz(int ** vector);
int ** numbers_vectors(int length);

int parent(int i);
int left(int i);
int right(int i);
void max_heapify(theap * a, int i);
void build_max_heap(theap * a);
void heapsort(theap * a);
//
int main()
{
    int lengths[MAX_L] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000}; //Tamanhos que serão testados
    double times_heap[MAX_TYPES][MAX_L]; // Tempos de execução do HEAPSORT para os lenghts[MAX_L]
    double times_quick[MAX_TYPES][MAX_L]; // Tempos de execução do QUICKSORT para os lenghts[MAX_L]
    int **matriz_vectors; // Matriz com Linha -1 Vetor Crescente, Linha -2 Vetor Decrescente e Linha -3 Vetor Aleatório
    clock_t t_inicial, tempo; //Usados para medir o tempo de execução
    double soma_tempo = 0, soma_tempo2 = 0; 
    theap heap;
    FILE * arq; //Arquivo que é gravado os resultados 
    arq = fopen("times.txt", "w");
    if (arq == NULL){
        printf("Não foi possível abrir o arquivo.\n");
    }

    for(int i = 0; i < MAX_L; i++){
        matriz_vectors = numbers_vectors(lengths[i]);
        for(int j = 0; j < MAX_TYPES; j++){
            heap.vetor = matriz_vectors[j];
            heap.tam_arranjo = lengths[i];
            soma_tempo = 0;
            for(int cont = 0; cont < MAX_EXEC; cont++){
                t_inicial = clock();
                heapsort(&heap);
                printf("Heap\n");
                tempo = clock() - t_inicial;
                soma_tempo += tempo;
            }
            times_heap[j][i] = (soma_tempo/(CLOCKS_PER_SEC/1000))/MAX_EXEC;
            soma_tempo2 = 0;
            for(int cont = 0; cont < MAX_EXEC; cont++){
                t_inicial = clock();
                quicksort(matriz_vectors[j], 1, lengths[i]);
                tempo = clock() - t_inicial;
                soma_tempo2 += tempo;
            }
            times_quick[j][i] = (soma_tempo2/(CLOCKS_PER_SEC/1000))/MAX_EXEC;
        }
        libera_matriz(matriz_vectors);
    }
    for(int j = 0; j<MAX_TYPES; j++){
        for(int i = 0; i < MAX_L; i++){
            if (i+1 != MAX_L)
                fprintf(arq, "%lf ", times_heap[j][i]);
            else
                fprintf(arq, "%lf\n", times_heap[j][i]);
        }
    }
    fprintf(arq, "\n%s\n", "---------");
    for(int j = 0; j<MAX_TYPES; j++){
        for(int i = 0; i < MAX_L; i++){
            if (i+1 != MAX_L)
                fprintf(arq, "%lf ", times_quick[j][i]);
            else
                fprintf(arq, "%lf\n", times_quick[j][i]);
        }
    }
    fclose(arq);

    return 0;
}






//////////////////////////////////////////////////////////
/////////////////////NUMBERS_VECTOR///////////////////////
//////////////////////////////////////////////////////////
/*
    Gera vetor crescente (type 1) de números inteiros de tamanho length.
    Gera vetor decrescente (type 2) de números  inteiros de tamanho length.
    Gera vetor aleatório (type 3) de números inteiros de tamanho length.

    Retorna o endereço do vetor alocado; 
*/
int * random_numbers(int type, int length)
{
    int * vetor;
    int j;
    vetor = malloc(length * sizeof(int));
    if(vetor == NULL){
        printf("Não espaço na memória!");
        exit(EXIT_FAILURE);
    }else{
        switch(type){
            //Crescente
            case 1:
                j = 1;
                for(int i = 0; i < length; i++){
                    vetor[i] = j;
                    j++;
                }
                break;
            //Decrescente
            case 2: 
                j = length;
                for(int i = 0; i < length; i++){
                    vetor[i] = j;
                    j--;
                }
                break;
            //Aleatório
            case 3: 
                srand(time(NULL));//Determina que o valor semente será o tempo decorrido
                                  //Dessa forma, as sequências aleatórios geradas são diferentes.
                for(int i = 0; i < length; i++)
                    vetor[i] = rand()%length; //Valor aleatório de no máximo length
                break;
            default: break;
        }
    }
    return vetor;
}

//DEVE USAR ESSA FUNÇÃO APÓS USAR A FUNÇÃO 
int ** numbers_vectors(int length)
{
    int ** vector;
    vector = malloc(MAX_TYPES * sizeof(int *));
    if(vector == NULL){
        printf("Não há espaço de memória suficiente!");
        exit(EXIT_FAILURE);
    }else{
        for(int i = 1; i <= MAX_TYPES; i++)
            vector[i-1] = random_numbers(i, length);
    }

    return vector;
   
}
//DEVE USAR ESSA FUNÇÃO APÓS USAR A FUNÇÃO numbers_vectors()
void libera_matriz(int ** vector){
    for(int i = 0; i < 3; i++){//Libera as linhas da matriz
        free(vector[i]);
        vector[i] = NULL;
    }
    free(vector); //Libera a matriz
    vector = NULL;

}







//////////////////////////////////////////////////////////
/////////////////////QUICKSORT////////////////////////////
//////////////////////////////////////////////////////////

void troca(int * vetor, int a, int b)
{
    int aux;

    aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

int partition(int * a, int p, int r)
{
    int x = a[(r+p)/2]; //O pivô é sempre o elemento do meio
    int i = p - 1;

    for(int j = p; j <= r-1; j++){
        if(a[j] < x){
            i = i + 1;
            troca(a, i, j);
        }
    }
    troca(a, i + 1, r);
    return i + 1;
}

void quicksort(int * a, int p, int r)
{
    int q;
    if (p < r){
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }else
        return;
}








//////////////////////////////////////////////////////////
/////////////////////HEAPSORT/////////////////////////////
/////////////////////////////////////////////////////////

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

//void troca(int* vetor, int a, int b)
//Troca o valor armazenado na posição a pelo valor da posição b no vetor
// e vice-versa
//{
//    int aux;
//    aux = vetor[a];
//    vetor[a] = vetor[b];
//    vetor[b] = aux;
//}

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
        troca(a->vetor, i, maior);
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
        troca(a->vetor, 1, i);
        a->tam_heap -= 1;
        max_heapify(a, 1);
    }
}
