#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main()
{
    int * vetor[3];
    int length;

    scanf("%d", &length);

    for(int i = 1; i <= 3; i++)
        vetor[i-1] = random_numbers(i, length);

    for(int i = 0; i < 3; i++){
        printf("Type %d : [", i+1);
        for(int j = 0; j < length; j++)
            printf(" %d ", vetor[i][j]);
        printf("]\n");
    }

    for(int i = 0; i < 3; i++){
        free(vetor[i]);
        vetor[i] = NULL;
    }
    return 0;
}