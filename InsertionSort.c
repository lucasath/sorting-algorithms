// MÉTODO INSERTION SORT

#include <stdio.h>
#include <stdlib.h>

void insertionSortD(int array[], int tamanho)
{
	int i, j, temp;
	for (i = 0; i < tamanho; i++)
	{
		j = i;
		while (j > 0 && array[j - 1] < array[j])
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
}

void insertionSortC(int array[], int tamanho)
{
	int i, j, temp;
	for (i = 0; i < tamanho; i++)
	{
		j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
}

int main(int argc, char** argv)
{
	printf("\n\tINSERTION SORT:");

	int i;
	int array[200000], tamanho, ordem;
	int *v = (int*) malloc(tamanho * sizeof(int));
	FILE *fp;

	printf("\n\n\tDigite o numero de termos a ordenar: ");
	scanf("%d", &tamanho);

	if( (fp = fopen("numeros.txt", "r")) == NULL ) // Nome do arquivo txt esta aqui
	{
		printf("\n\n\tErro na leitura do arquivo .txt !!!!");
		return -1;
	}
	else
	{
		int i = 0, z = 0;
		int x;
		char c;
		while( (c = fgetc(fp)) != EOF )
		{
			fscanf(fp, "%d", &x);
			v[z] = x; // esse vetor 'v' guarda todos os num's do arquivo
			z++;
		}
		for(i = 0; i < tamanho; i++)
		{
			array[i] = v[i];
		}
		fclose(fp);
		printf("\n\n\tLeitura do arquivo concluida !");
	}

	/*printf("\n\t Entre com os elementos do array...:");

	for(i = 0; i < tamanho; i++)
	{
		printf("\nDigite o %d número: ", i + 1);
		scanf("%d", &array[i]);
	}*/

	printf("\n\n\t Digite 1 para ordernar o array em ordem crescente ou 2 para ordem decrescente: ");
	scanf("%d", &ordem);

	while(ordem != 1 && ordem != 2)
	{
		printf("\n\nEntrada invalida! Digite novamente: ");
		scanf("%d", &ordem);
	}

	if (ordem == 1)
	{
		insertionSortC(array, tamanho);
		printf("\nArray em ordem crescente: ");
		for(i = 0; i < tamanho; i++)
		{
			printf("\n\t\t\t%d", array[i]);
		}

	}
	else if (ordem == 2)
	{
		insertionSortD(array, tamanho);
		printf("\nArray em ordem decrescente: ");
		for(i = 0; i < tamanho; i++)
		{
			printf("\n\t\t\t%d", array[i]);
		}
	}
	return 0;
}
