import random
import time
import counter

def selection_sort(lista):
   for fillslot in range(len(lista)-1,0,-1):
       positionOfMax=0
       for location in range(1,fillslot+1):
           if lista[location]>lista[positionOfMax]:
               positionOfMax = location

       temp = lista[fillslot]
       lista[fillslot] = lista[positionOfMax]
       lista[positionOfMax] = temp

def verifica(lista):
    for i in range(0, len(lista)-1):
        if lista[i+1] >= lista[i]:
            pass
        else:
            return False
    return True

if __name__ == '__main__':

    print('\n******* Ordenação SelectionSort *******')
    print ('\n\nVetor em ordem crescente: ')
    lista = [i for i in range(100000)]
    start = time.time()
    selection_sort(lista)
    end = time.time() - start
    print ('Tempo para ordenar: ', end)
    if verifica(lista):
        print ('ORDENADO')
        print('\n\n')
    else:
        print ('NAO ORDENADO')
        print('\n\n')

    print ('\n\nVetor em ordem decrescente: ')
    lista2 = [i for i in range(1000)]
    lista2 = lista2[::-1]
    start2 = time.time()
    selection_sort(lista2)
    end2 = time.time() - start2
    print ('Tempo para ordenar: ', end2)
    if verifica(lista2):
        print ('ORDENADO')
        print('\n\n')
    else:
        print ('NAO ORDENADO')
        print('\n\n')

    print ('\n\nVetor em ordem aleatória: ')
    lista3 = [random.random() for i in range(1000)]
    start3 = time.time()
    selection_sort(lista3)
    end3 = time.time() - start3
    print ('Tempo para ordenar: ', end3)
    if verifica(lista3):
        print ('ORDENADO')
        print('\n\n')
    else:
        print ('NAO ORDENADO')
        print('\n\n')