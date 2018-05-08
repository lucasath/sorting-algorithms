void merge(int arr[], int e, int m, int d)
{
    int i, j, k;
    int n1 = m - e + 1;
    int n2 =  d - m;
 
    /* Cria dos arrays temporarios */
    int esq[n1], dir[n2];
 
    /* copia o conteudo para os arrays temporarios esq[] e dir[] */
    for (i = 0; i < n1; i++)
        esq[i] = arr[e + i];
    for (j = 0; j < n2; j++)
        dir[j] = arr[m + 1+ j];
 
    /* Da merge dos sub arrays no original arr[l..r]*/
    i = 0;
    j = 0;
    k = e;
    while (i < n1 && j < n2)
    {
        if (esq[i] <= dir[j])
        {
            arr[k] = esq[i];
            i++;
        }
        else
        {
            arr[k] = dir[j];
            j++;
        }
        k++;
    }
 

    while (i < n1)
    {
        arr[k] = esq[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = dir[j];
        j++;
        k++;
    }
}
 
/* e é o inicio do array a ser organizado e d o final do array */
void mergeSort(int arr[], int e, int d)
{
    if (e < d)
    {
        // calculo do elemento do meio do array
        int m = e+(d-e)/2;
 
        // ordenacao do primeiro e segundo sub-array
        mergeSort(arr, e, m);
        mergeSort(arr, m+1, d);
 
        merge(arr, e, m, d);
    }
}