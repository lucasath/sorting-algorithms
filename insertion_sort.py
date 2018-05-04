import time
import random

def insertion_sort(lista):
    comparacoes = 0
    for j in range(1, len(lista)):
        chave = lista[j]
        i = j-1
        while i >= 0 and lista[i] > chave:
            comparacoes += 1
            lista[i+1] = lista[i]
            i = i-1
        lista[i+1] = chave
    print ('numero de comparacoes: ', comparacoes)


if __name__ == '__main__':
    #print 'lista inicial: \n', lista, '\n'
    soma_tempos = 0
    for i in range(0, 3):
        lista = [random.random() for i in range(200000)]
        #lista = lista[::-1]
        start = time.time()
        insertion_sort(lista)
        end = time.time() - start
        soma_tempos += end
        print ('Tempo para ordenar: ', end)
    '''print 'Tempo medio: ', soma_tempos/3
    #print 'lista final: \n', lista, '\n'
    if verifica(lista):
        print 'ORDENADO'
    else:
        print 'NAO ORDENADO'
    '''
    
    




