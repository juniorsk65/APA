#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#define MX 101
int lista[MX];
int lista_heap[MX];

void maxHeapify(int num[], int tam, int i)
{
    int esq, dir, sup, aux;

    esq = 2*i + 1;
    dir = 2*i + 2;
    sup = i;

    if(esq < tam && num[esq] > num[sup])
        sup = esq;

    if(dir < tam && num[dir] > num[sup])
        sup = dir;

    if(sup != i)
    {
        aux = num[i];
        num[i] = num[sup];
        num[sup] = aux;

        maxHeapify(num, i, sup);
    }
}

void heapSort(int num[], int tam){
    int aux;

    for(int i = (tam-2)/2; i >=0; i--)
        maxHeapify(num, i, tam);

    for(int i = tam -1; i >= 1; i--)
    {
        aux = num[0];
        num[0] = num[i];
        num[i] = aux;

        maxHeapify(num, 0, i);
    }
}

int main(void)
{
    clock_t Ticks[8];                 
    int i = 0;
    FILE *file; // Abrindo arquivo
    file = fopen("couting.txt","r");
    while(!feof(file)){
        if(i == 0){ 
        }
        fscanf(file,"%d",&lista[i]);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        i++;
    }
    fclose(file);

    for(int a = 0; a < i; a++){
        lista_heap[a] = lista[a];
    }

    int tam = sizeof(lista_heap)/sizeof(lista_heap[0]);

    Ticks[0] = clock();//Tempo Inicial
    heapSort(lista_heap, tam);
    Ticks[1] = clock();//Tempo Final
    
    for(int j = 0; j < i; j++) {
        printf("%d ", lista_heap[j]); //Exibinido lista
        //printf("\n"); 
    }
    double tempoHeap = (double)(Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo gasto HeapSort: %g ms.\n", tempoHeap);
    return 0;
}

/*
#include <iostream>

using namespace std;

void HeapSort(int array[], int tam_heap);
void BuildMaxHeap(int array[], int tam_heap);
void MaxHeapify(int array[], int i, int tam_heap);
void Print(int array[], int n);

int main(){

	int array[] = {12,11,13,5,6,7};
	int tam = sizeof(array)/sizeof(array[0]);

	HeapSort(array, tam);

	Print(array, tam);
}

void HeapSort(int array[], int tam_heap){
	int aux = 0;

	BuildMaxHeap(array, tam_heap);

	for(int i = tam_heap - 1; i >= 0; i--){
		aux = array[0];
		array[0] = array[i];
		array[i] = aux;

		MaxHeapify(array,i, 0);
	}
}

void BuildMaxHeap(int array[], int tam_heap){
	int tam = tam_heap;

	for(int i = (tam/2) - 1; i >= 0; i--){
		MaxHeapify(array, tam_heap, i);
	}
}

// n é o comprimento do heap, i é o indice

void MaxHeapify(int array[], int tam_heap, int i){
	int esquerdo, direito, maior, aux = 0;

	esquerdo = 2*i + 1;
	direito = 2*i + 2;
	maior = i;
	
	if(esquerdo < tam_heap && array[esquerdo] > array[maior]){
		maior = esquerdo;
	}

	if(direito < tam_heap && array[direito] > array[maior]){
		maior = direito;
	}

	if(maior != i){
		aux = array[i];
		array[i] = array[maior];
		array[maior] = aux;

		MaxHeapify(array, i, maior);
	}
}

void Print(int array[], int n){
	for(int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}
*/