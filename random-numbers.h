/*
    Author: Luis Carlos da SIlva Filho
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_TYPES 3
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
    vetor = malloc((length+1) * sizeof(int));
    if(vetor == NULL){
        printf("Não espaço na memória!");
        exit(EXIT_FAILURE);
    }else{
        switch(type){
            //Crescente
            case 1:
                j = 1;
                for(int i = 1; i <=length; i++){
                    vetor[i] = j;
                    j++;
                }
                break;
            //Decrescente
            case 2: 
                j = length;
                for(int i = 1; i <=length; i++){
                    vetor[i] = j;
                    j--;
                }
                break;
            //Aleatório
            case 3: 
                srand(time(NULL));//Determina que o valor semente será o tempo decorrido
                                  //Dessa forma, as sequências aleatórios geradas são diferentes.
                for(int i = 1; i <= length; i++)
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