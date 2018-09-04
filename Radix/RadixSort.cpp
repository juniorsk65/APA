#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 101
int lista[MX];
int lista_radix[MX];

void countSort(int num[], int tam, int rest){
    int out[tam];
    int count[tam+1] = {0};
    int i;

    for(i = 0; i < tam; i++)
        count[(num[i]/rest)%10]++;
    
    for(i = 1; i<10; i++)
        count[i] += count[i-1];

    for(i = tam - 1; i >= 0; i--)
    {
        out[count[(num[i]/rest)%10]-1] = num[i];
        count[(num[i]/rest)%10]--;
    }

    for(i = 0; i < tam; i++)
        num[i] = out[i];
}

void radixSort(int num[], int tam){
    
    int max = num[0];
    for(int i = 1; i < tam; i++)
        if(num[i] > max)
            max = num[i];

    for(int rest = 1; max/rest > 0; rest *= 10)
        countSort(num, tam, rest);
}

int main(void)
{
    clock_t Ticks[2];                 
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
        lista_radix[a] = lista[a];
    }
    
    Ticks[0] = clock();//Tempo Inicial
    radixSort(lista_radix, i);
    Ticks[1] = clock();//Tempo Final
    
    for(int j = 0; j < i; j++) {
        printf("%d ", lista_radix[j]); //Exibinid lista
        //printf("\n"); 
    }
    double tempoRadix = (double)(Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo gasto Bucket: %g ms.\n", tempoRadix);
    return 0;
}