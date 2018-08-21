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
//Função de mudança dos elementos do array;
void swap(int* num1, int* num2)
{
    int t = *num1;
    *num1 = *num2;
    *num2 = t;
}

void quickSort(int* num, int inferior, int superior)
{
    int pivo, aux;
    int esquerda = inferior;
    int direita = superior;
    
    //Se o array contem apenas um elemento, ou esta vazio
    //isso significa que este elemento ja esta ordenado
    //e não devemos continuar a iteração com o pivo
    if(inferior >= superior)
        return;
    //Passando como pivo o primeiro elemento do array
    //caso seja passado um elemento diferente do primeiro
    //deve ser alterado o while
    pivo = inferior;


    while(esquerda < direita){
        //Repita enquanto os elementos da primeira parte forem menores que o pivo
        while(num[esquerda] <= num[pivo] && esquerda < superior){
            esquerda++;  
        }
        //Repita enquanto os elementos da segunda parte forem maiores que o pivo
        while(num[direita] > num[pivo] && direita > inferior){
            direita--;
        }
        //Caso a posição do elemento da esquerda e da direita não
        //seja a adequada, devemos troca-lo de lugar e inverter
        //(muda de posição no array)
        if(esquerda < direita){
            //swap(&num[esquerda], &num[direita]);
            aux = num[esquerda];
            num[esquerda] = num[direita];
            num[direita] = aux;
         }
    }
    //Quando os indices se invertem devemos trocar a posição da direita
    //pela posição do pivo, isso no garante a ordenação mas garante que 
    //todos os elementos a direit e a esquerda do pivo são maiores ou
    //menores do que ele
    //swap(&num[direita], &num[pivo]);
    aux = num[pivo];
    num[pivo] = num[direita];
    num[direita] = aux;
    quickSort(num, inferior, direita - 1 );  
    quickSort(num, direita + 1, superior);
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));//Alocando tabela auxiliar

    while(com1 <= meio && com2 <= fim){//Colocando dentro da tabela auxiliar o resultado
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade copie
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade copie
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){//Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);//Ordena a metade inferior da tabela
        mergeSort(vetor, meio+1, fim);//Ordena a metade superior da tabela
        merge(vetor, comeco, meio, fim);//Intercalando as duas metades
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
    insertionSort(lista_selection, i-1);
    Ticks[1] = clock();//Tempo Final

    Ticks[2] = clock();//Tempo Inicial
    selectionSort(lista_selection, i-1);
    Ticks[3] = clock();//Tempo Final

    Ticks[4] = clock();//Tempo Inicial
    quickSort(lista_quicksort, 0, i-1);
    Ticks[5] = clock();//Tempo Final
    
    Ticks[6] = clock();
    mergeSort(lista_mergesort, 0, i-1);
    Ticks[7] = clock();
    
    for(int j = 0; j < i; j++) {
        printf("%d ", lista_quicksort[j]); //Exibinid lista
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