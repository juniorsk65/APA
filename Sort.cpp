#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 101
int lista[MX];
int lista_selection[MX];
int lista_insertion[MX];
int lista_quicksort[MX];
int lista_mergesort[MX];

void insertionSort(int original[], int length) {
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];
		for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
			original[j + 1] = original[j];
        }
		original[j+1] = atual;
	}
}

void selectionSort(int num[], int tam) { 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min]) 
         min = j;
     }
     if (num[i] != num[min]) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;                                  
     }
  }
}

void quickSort(int num[], int inferior, int superior)
{
    int pivo, aux;
    int esquerda = inferior;
    int direita = superior;

    //Considerando o pivo como o meio
    pivo = num[(direita + esquerda)/2];

    while(esquerda <= direita){
        while(num[esquerda] < pivo && esquerda < superior){
            esquerda++;  
        }
        while(num[direita] > pivo && direita > inferior){
            direita--;
        }
        if(esquerda <= direita){
            aux = num[esquerda];
            num[esquerda] = num[direita];
            num[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if(direita > inferior){
        quickSort(num, inferior, direita);
    }
    if(esquerda < superior){
        quickSort(num, esquerda, superior);
    }
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
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
        lista_insertion[a] = lista[a];
        lista_selection[a] = lista[a];
        lista_quicksort[a] = lista[a];
        lista_mergesort[a] = lista[a];
    }
    
    Ticks[0] = clock();//Tempo Inicial
    insertionSort(lista_selection, i);
    Ticks[1] = clock();//Tempo Final

    Ticks[2] = clock();//Tempo Inicial
    selectionSort(lista_selection, i);
    Ticks[3] = clock();//Tempo Final

    Ticks[4] = clock();//Tempo Inicial
    quickSort(lista_quicksort, 0, i);
    Ticks[5] = clock();//Tempo Final
    
    Ticks[6] = clock();
    mergeSort(lista_mergesort, 0, i);
    Ticks[7] = clock();
    
    for(int j = 0; j < i; j++) {
        printf("%d ", lista_mergesort[j]); //Exibinid lista
        //printf("\n"); 
    }
    double tempoInsert = (double)(Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;
    double tempoSelect = (double)(Ticks[3] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;
    double tempoQuick = (double)(Ticks[5] - Ticks[4]) * 1000 / CLOCKS_PER_SEC;
    double tempoMerge = (double)(Ticks[7] - Ticks[6]) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo gasto Insertion: %g ms.\n", tempoInsert);
    printf("Tempo gasto Selection: %g ms.\n", tempoSelect);
    printf("Tempo gasto QuickSort: %g ms.\n", tempoQuick);
    printf("Tempo gasto MergeSort: %g ms.\n", tempoMerge);
    return 0;
}