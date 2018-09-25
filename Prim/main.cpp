#include <stdio.h> 
#include <limits.h> 
#include <stdbool.h> 
#define V 10  // Numero de vertices do grafo

int menor(int key[], bool espMin[]) 
{ 
// Inicializando com o menor valor 
int min = INT_MAX, menor_aresta; //INT_MAX = 2147483647
  
for (int v = 0; v < V; v++) 
    if (espMin[v] == false && key[v] < min) 
        min = key[v], menor_aresta = v; 
  
return menor_aresta; //
} 

// Funçao pra exibir os caminhos
int printMST(int raiz[], int n, int graph[V][V]) 
{ 
printf("Aresta \tPeso\n"); 
for (int i = 1; i < V; i++) 
    printf("%d - %d \t%d \n", raiz[i], i, graph[i][raiz[i]]); 
} 

void primMST(int graph[V][V]) 
{ 
    // Array pra construir a arvore de espalhamento minimo 
    int raiz[V];  
    // Chave usada pra pegar o menor caminho da aresta 
    int key[V];  
    // Verificando se já foi incluido na arvore de espalhamento minimo 
    bool espMin[V];  
  
    // Inicializando com o maior inteiro 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, espMin[i] = false; 

    key[0] = 0;      
    raiz[0] = -1; 

    for (int count = 0; count < V-1; count++) 
    { 
        int u = menor(key, espMin); 
  
        espMin[u] = true; 
  
        for (int v = 0; v < V; v++) 
        if (graph[u][v] && espMin[v] == false && graph[u][v] < key[v]) 
            raiz[v] = u, key[v] = graph[u][v]; 
    } 
  
    printMST(raiz, V, graph); 
} 

int main() 
{ 
    int G[V][V] =      {{0, 270, 3179, 2991, 2840, 3031, 3421, 3738, 4947, 6226},
                       {270, 0, 2903, 2715,2564, 2755, 3144, 4153, 5362, 6641},
                       {3179, 2903, 0, 504, 655, 908, 1299, 2237, 3446, 3682},
                       {2991, 2715, 504, 0, 151, 423, 723, 2040, 3249, 3485},
                       {2840, 2564,655, 151, 0, 272, 571, 1888, 3098, 3334},
                       {3031, 2755, 908, 423, 272, 0, 241, 1560, 2770, 3006},
                       {3421, 3144, 1299, 723, 571, 241, 0, 1617, 2827, 3063},
                       {3738, 4153, 2237, 2040, 1888, 1560, 1617, 0, 1274, 1510},
                       {4947, 5362, 3446, 3249, 3098, 2770, 2827, 1274, 0, 236},
                       {6226, 6641, 3682, 3485, 3334, 3006, 3063, 1510, 236, 0}};
    primMST(G); 
  
    return 0; 
} 