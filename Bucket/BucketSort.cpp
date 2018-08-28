#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 101
int lista[MX];
int lista_bucket[MX];

void bucketSort(int num[], int tam){
    int i, j;
    int count[tam];

    for(i = 0; i < tam; i++){
        count[i] = 0;
    }

    for(i = 0; i < tam; i++){
        count[num[i]]++;
    }

    for (i = 0, j = 0; i < tam; i++)  
        for(; count[i] > 0; (count[i])--)
            num[j++] = i;
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
        lista_bucket[a] = lista[a];
    }
    
    Ticks[0] = clock();//Tempo Inicial
    bucketSort(lista_bucket, i);
    Ticks[1] = clock();//Tempo Final
    
    for(int j = 0; j < i; j++) {
        printf("%d ", lista_bucket[j]); //Exibinid lista
        //printf("\n"); 
    }
    double tempoBucket = (double)(Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo gasto Bucket: %g ms.\n", tempoBucket);
    return 0;
}