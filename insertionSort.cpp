#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 101
int lista[MX];
int lista_selection[MX];
int lista_insertion[MX];

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

int main(void)
{
    clock_t Ticks[4];                 
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
    }
    
    Ticks[0] = clock();//Tempo Inicial
    insertionSort(lista_selection, MX);
    Ticks[1] = clock();//Tempo Final

    Ticks[2] = clock();
    selectionSort(lista_selection, MX);
    Ticks[3] = clock();
    
    for(int j = 0; j < i; j++) {
        printf("%d ", lista_selection[j]);
        printf("\n"); 
    }
    double tempoInsert = (double)(Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;
    double tempoSelect = (double)(Ticks[3] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;
    printf("Tempo gasto Insertion: %g ms.\n", tempoInsert);
    printf("Tempo gasto Selection: %g ms.", tempoSelect);
    return 0;
}