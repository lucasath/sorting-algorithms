#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
#include "random-numbers.h"
#include "heapsort.h"

#define MAX_L 9
#define MAX_EXEC 3
#define MAX_ALGORITH 2
#define MAX_TYPES 3
#define MAX 10 //Tamanho máximo do arranjo

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
            //Calculando tempo de execução para HEAPSORT
            soma_tempo = 0;
            for(int cont = 0; cont < MAX_EXEC; cont++){
                t_inicial = clock();
                heapsort(&heap);
                tempo = clock() - t_inicial;
                soma_tempo += tempo;
            }
            times_heap[j][i] = (soma_tempo/(CLOCKS_PER_SEC/1000))/MAX_EXEC;
            //Calculando tempo de execução para QUICKSORT
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
    //Gravando resultados no arquivo
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
