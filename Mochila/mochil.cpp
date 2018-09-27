#include <stdio.h>
    //Função que retorna o maior de dois numeros
    //Esta função vai verificar na tabela auxiliar se o valoror avaloriado é maior
    int max(int a, int b) { return (a > b)? a : b; }
    //Retorna de acordo com a capacidade o maximo lucro
    int mochila(int pesoMax, int peso[], int valor[], int n){
       int i, w;
       int capacidade[n+1][pesoMax+1];

       for (i = 0; i <= n; i++){
           for (w = 0; w <= pesoMax; w++){
               //Zerando a primeira linha e a primeira coluna
               if (i==0 || w==0)
                   capacidade[i][w] = 0;
               else if (peso[i-1] <= w)
               //Verificando o ultimo valor inserido
                     capacidade[i][w] = max(valor[i-1] + capacidade[i-1][w-peso[i-1]],  capacidade[i-1][w]);
               else 
                     capacidade[i][w] = capacidade[i-1][w];
           }
       }
    //Retornando o ultimo campo da tabela que contem o maximo de lucro  
    return capacidade[n][pesoMax];
}

int main() 
{ 
    int valor[7] = {1,6,18,22,28,40,60}; 
    int peso[7] = {1,2,5,6,7,9,11}; 
    int pesoMax = 23; 
    int n = sizeof(valor)/sizeof(valor[0]); 
    printf("%d", mochila(pesoMax, peso, valor, n)); 
    return 0; 
} 
