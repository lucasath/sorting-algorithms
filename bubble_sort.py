import random
import time

def bubble_sort(lista):
    comp = 0
    for i in range(0, len(lista)-1):
        for j in range(0, len(lista)-1-i):
                if lista[j] > lista[j + 1]:
                        lista[j], lista[j + 1] = lista[j + 1], lista[j]
                        comp += 1

    print('Numero de comparações: ', comp)


def verifica(lista):
    for i in range(0, len(lista)-1):
        if lista[i+1] >= lista[i]:
            pass
        else:
            return False
    return True

if __name__ == '__main__':

    print('\n******* Ordenação Bubble Sort *******')
    print ('\n\nVetor em ordem crescente: ')
    lista = [i for i in range(1000)]  # TAMANHO DO VETOR AQUI
    start = time.time()
    bubble_sort(lista)
    end = time.time() - start
    print ('Tempo para ordenar: ', end)
    if verifica(lista):
        print ('ORDENADO')
        print('\n\n')
    else:
        print ('NAO ORDENADO')
        print('\n\n')

    print ('\n\nVetor em ordem decrescente: ')
    lista2 = [i for i in range(1000)]  # TAMANHO DO VETOR AQUI
    lista2 = lista2[::-1]
    start2 = time.time()
    bubble_sort(lista2)
    end2 = time.time() - start2
    print ('Tempo para ordenar: ', end2)
    if verifica(lista2):
        print ('ORDENADO')
        print('\n\n')
    else:
        print ('NAO ORDENADO')
        print('\n\n')

    print ('\n\nVetor em ordem aleatória: ')
    lista3 = [random.random() for i in range(1000)]  # TAMANHO DO VETOR AQUI
    start3 = time.time()
    bubble_sort(lista3)
    end3 = time.time() - start3
    print ('Tempo para ordenar: ', end3)
    if verifica(lista3):
        print ('ORDENADO')
        print('\n\n')
    else:
        print ('NAO ORDENADO')
        print('\n\n')