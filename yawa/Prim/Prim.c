/*
    YOOOOOOOOOO
    Prim's and Dijkstra's algorithms have similar structure!

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 5
#define INF 999

int findMinKey(int key[],  int isVisited[]);
void primMST(int graph[V][V]);
void printMST(int graph[V][V], int parent[]);

int main(){
    int graph[V][V] = {
        {  0,   2, INF,   6, INF},
        {  2,   0,   3,   8,   5},
        {INF,   3,   0, INF,   7},
        {  6,   8, INF,   0,   9},
        {  0,   5,   7,   9,   0},
    };

    primMST(graph);

    return 0;
}

//No changes, same algorithm and explanation with Dijkstra's algorithm
int findMinKey(int key[],  int isVisited[]){
    int min = INF;
    int minIndex;
    for(int i = 0; i<V; i++){
        if(isVisited[i] == 0 && key[i] < min){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V]){
    //Stores the values to pick for the minimum cost edge that connects each vertex,
    //this will be referred to as the key
    int key[V];
    //Stores the MST
    int parent[V];
    //Flags the vertices that have been visited
    //Goes hand-in-hand with key[]
    int isVisited[V];

    //Initialize the arrays
    //Initiailize the cost between vertices to INF (key)
    //Initialize the vertices of isVisited to false(0)
    for(int i = 0; i<V; i++){
        key[i] = INF;
        isVisited[i] = 0;
    }

    //Set the first vertex of the array to 0 so that it starts as the first vertex
    key[0] = 0;
    //Set the first vertex as the parent, making it the root of the MST
    parent[0] = -1;

    for(int i = 0; i<V-1; i++){
        //Find the minimum key vertex that have not been visited
        int u = findMinKey(key, isVisited);
        //Set the minimum key vertex as visited, this will no longer be
        //a candidate vertices for future selection, it effectively
        //becomes a permanent member of the MST
        isVisited[u] = 1;

        for(int v = 0; v<V; v++){
            /*
                Update the key and set the parent if:
                    1. The vertex has not been visited (isVisited[v] != 1)
                    2. There is a connection between u to v (graph[u][v] != INF)
                    3. The cost between u to v is less than the minimum key vertex
                    (graph[u][v] < key[v])
            */
            if(isVisited[v] != 1 && graph[u][v]!=INF && graph[u][v] < key[v]){
                //Key will now store the cost between vertex
                key[v] = graph[u][v];
                //This will then record the parent of index v which is u
                parent[v] = u;
            }
        }


    }

    printMST(graph, parent);

}

void printMST(int graph[V][V], int parent[]){
    printf("Edge \tWeight\n");
    for(int i = 1; i<V; i++){
        printf("%d-%d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}