#include<stdio.h>
#include<limits.h>
#include<iostream>
#define INFINITO INT_MAX // INT_MAX = 2147483647
#define MAX 10 // 10 vertices
 
void dijkstra(int G[MAX][MAX],int n,int noinicial);
 
int main()
{   
    // Inserindo a matriz
    // n = numero de vertices
    // u = nó de inicio
    int n = 10, u = 1;
    int G[MAX][MAX] = {{0, 270, 3179, 2991, 2840, 3031, 3421, 3738, 4947, 6226},
                       {270, 0, 2903, 2715,2564, 2755, 3144, 4153, 5362, 6641},
                       {3179, 2903, 0, 504, 655, 908, 1299, 2237, 3446, 3682},
                       {2991, 2715, 504, 0, 151, 423, 723, 2040, 3249, 3485},
                       {2840, 2564,655, 151, 0, 272, 571, 1888, 3098, 3334},
                       {3031, 2755, 908, 423, 272, 0, 241, 1560, 2770, 3006},
                       {3421, 3144, 1299, 723, 571, 241, 0, 1617, 2827, 3063},
                       {3738, 4153, 2237, 2040, 1888, 1560, 1617, 0, 1274, 1510},
                       {4947, 5362, 3446, 3249, 3098, 2770, 2827, 1274, 0, 236},
                       {6226, 6641, 3682, 3485, 3334, 3006, 3063, 1510, 236, 0}};
    dijkstra(G,n,u);
    return 0;
}
 
void dijkstra(int G[MAX][MAX],int n,int noinicial)
{
 
    int custo[MAX][MAX],distancia[MAX],pred[MAX];
    int visitado[MAX],count,mindistancia,nextnode,i,j;
    
    //pred[] = salva o predecessor de cada nó
    //count = contador para salvar quantos nós foram visitados
    
    //Analizando a matriz de custos inserida
    //Setando para ~infinito quando na matriz de custo for apresentado o valor ZERO
    //Utilizando a biblioteca <limits.h> para encontrar o maior valor
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                custo[i][j]=INFINITO;
            else
                custo[i][j]=G[i][j];
    
    //Inicializando as variaveis

    // Distancia até o destino é igual ao custo do começo até o destino
    // distancia[destino] = custo[começo][destino]
    // Predecessor do destino é o começo
    // pred[destino] = começo
    // Visitado confere se o vertice já foi visitado
    // visitado[destino] = 0

    // n = numero de vertices
    for(i=0;i<n;i++)
    {
        distancia[i]=custo[noinicial][i];
        pred[i]=noinicial;
        visitado[i]=0;
    }
    
    //Setando no inicial como de distancia zero para ele mesmo
    distancia[noinicial]=0;
    visitado[noinicial]=1;
    count=1; 
    
    while(count<n-1)
    {
        mindistancia=INFINITO;
        
        //nextnode gives the node at minimum distancia
        //
        for(i=0;i<n;i++)
            //Se a distancia[destino] < infinito && naovisitado[destino]
            if(distancia[i]<mindistancia&&!visitado[i])
            {
                mindistancia=distancia[i];
                nextnode=i;
            }
            
            //check if a better path exists through nextnode            
            visitado[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visitado[i])
                    if(mindistancia+custo[nextnode][i]<distancia[i])
                    {
                        distancia[i]=mindistancia+custo[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
 
    //print the path and distancia of each node
    for(i=0;i<n;i++)
        if(i!=noinicial)
        {
            printf("\nDistance of node%d=%d",i,distancia[i]);
            printf("\nPath=%d",i);
            
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=noinicial);
    }
}