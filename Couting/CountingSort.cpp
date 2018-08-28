#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 101
int lista[MX];
int lista_counting[MX];

void countingSort(int num[], int tam){
    
    int resultado = 0;

    for(int i = 1; i < tam; i++)
    {
            if(num[i] > resultado)
                resultado = num[i];
    }
    int out[tam]; // auxiliar de saida
    int aux[resultado + 1]; // criando aux com a quantidade de indices maior que o vetor

    for(int i = 0; i < resultado; i++){
        aux[i] = 0;
    }
    //Utilizando o vetor inicial devemos verificar quantos elementos
    for(int i = 0; i < tam; i++){
        aux[num[i]]++;
    }

    for(int i = 1; i <= resultado; i++){
        aux[i] += aux[i-1];
    }

    for(int j = tam; j >= 0; j--){
        out[aux[num[j]] - 1] = num[j];
        aux[num[j]]--;
    }

    for(int i = 0; i < tam; ++i){
        num[i] = out[i];
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
        lista_counting[a] = lista[a];
    }
    
    Ticks[0] = clock();//Tempo Inicial
    countingSort(lista_counting, i);
    Ticks[1] = clock();//Tempo Final
    
    for(int j = 0; j < i; j++) {
        printf("%d ", lista_counting[j]); //Exibinid lista
        //printf("\n"); 
    }
    double tempoCouting = (double)(Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo gasto Insertion: %g ms.\n", tempoCouting);
    return 0;
}