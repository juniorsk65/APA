
// A C / C++ program for Prim's Minimum  
// Spanning Tree (MST) algorithm. The program is  
// for adjacency matrix representation of the graph 
#include <stdio.h> 
#include <limits.h> 
#include<stdbool.h> 
// Number of vertices in the graph 
#define V 10 
  
// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST 
int minKey(int key[], bool mstSet[]) 
{ 
// Initialize min value 
int min = INT_MAX, min_index; 
  
for (int v = 0; v < V; v++) 
    if (mstSet[v] == false && key[v] < min) 
        min = key[v], min_index = v; 
  
return min_index; 
} 
  
// A utility function to print the  
// constructed MST stored in parent[] 
int printMST(int parent[], int n, int graph[V][V]) 
{ 
printf("Aresta \tPeso\n"); 
for (int i = 1; i < V; i++) 
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
  
// Function to construct and print MST for  
// a graph represented using adjacency  
// matrix representation 
void primMST(int graph[V][V]) 
{ 
    // Array to store constructed MST 
    int parent[V];  
    // Key values used to pick minimum weight edge in cut 
    int key[V];  
    // To represent set of vertices not yet included in MST 
    bool mstSet[V];  
  
    // Initialize all keys as INFINITE 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    // Always include first 1st vertex in MST. 
    // Make key 0 so that this vertex is picked as first vertex. 
    key[0] = 0;      
    parent[0] = -1; // First node is always root of MST  
  
    // The MST will have V vertices 
    for (int count = 0; count < V-1; count++) 
    { 
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST 
        int u = minKey(key, mstSet); 
  
        // Add the picked vertex to the MST Set 
        mstSet[u] = true; 
  
        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST 
        for (int v = 0; v < V; v++) 
  
        // graph[u][v] is non zero only for adjacent vertices of m 
        // mstSet[v] is false for vertices not yet included in MST 
        // Update the key only if graph[u][v] is smaller than key[v] 
        if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
            parent[v] = u, key[v] = graph[u][v]; 
    } 
  
    // print the constructed MST 
    printMST(parent, V, graph); 
} 
  
  
// driver program to test above function 
int main() 
{ 
int G[V][V] =         {{0, 270, 3179, 2991, 2840, 3031, 3421, 3738, 4947, 6226},
                       {270, 0, 2903, 2715,2564, 2755, 3144, 4153, 5362, 6641},
                       {3179, 2903, 0, 504, 655, 908, 1299, 2237, 3446, 3682},
                       {2991, 2715, 504, 0, 151, 423, 723, 2040, 3249, 3485},
                       {2840, 2564,655, 151, 0, 272, 571, 1888, 3098, 3334},
                       {3031, 2755, 908, 423, 272, 0, 241, 1560, 2770, 3006},
                       {3421, 3144, 1299, 723, 571, 241, 0, 1617, 2827, 3063},
                       {3738, 4153, 2237, 2040, 1888, 1560, 1617, 0, 1274, 1510},
                       {4947, 5362, 3446, 3249, 3098, 2770, 2827, 1274, 0, 236},
                       {6226, 6641, 3682, 3485, 3334, 3006, 3063, 1510, 236, 0}};
    // Print the solution 
    primMST(G); 
  
    return 0; 
} 
