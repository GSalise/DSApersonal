/*
    How to do Dijkstra's algorithm
    1. Create 2 functions
        a. FindMin
            - Used to find the vertex with the minimum distance between vertices 
            that has not been visited
        b. Dijkstra's algorithm
            - The main function
    
    2. How to create FindMin
        2.1. The parameters are dist and isVisited arrays
            - dist stores the distance between vertices
            - isVisited stores the information of each index on whether or not
            they have been visited
        2.1. Declare 2 variables (minimum and minimum index)
            - minimum stores the value of the distance
            - minimum index stores the index of the vertex with the minimum value
        2.2. Create a for loop
            2.2.1. Create a conditional statement. Perform code if:
                a. The vertex has not been visited
                b. The distance between the current minimum is greater than dist[i]
                    2.2.1.1. Code to perform is that minimum now stores the value of dist[i]
                    2.2.1.2. Set the minimum index to dist[i]
        2.4. Return minimum index
    
    3. Dijkstra's algorithm (Graph, Source Index)
        3.1. Create the dist and isVisited arrays
        3.2. Set the dist to INF and isVisited to false(0)
        3.3. Set the source index to 0 ALWAYS
        3.4. Create a for loop (number of vertices - 1)
            3.4.1. Call FindMin to find the minimum vertex and store it
            3.4.2. Set the minimum vertex to visited
            3.4.3. Create a for loop
                3.4.3.1. Create a conditional statement. Perform code if:
                    a. The minimum vertex has not been visited
                    b. There is a connection/edge between the minimum vertex and source
                    vertex (Check graph)
                    c. The minimum vertex is actually reachable
                    d. The combined value of the connection/edge is less than dist[v]
                        3.4.3.1.1. Set dist[v] to the value of the connection/edge
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 9999
#define V 5

int findMin(int dist[V], int isVisited[V]);
void dijkstra(int graph[V][V], int src);
void printDistances(int dist[V], int src);

int main(){
    int graph[V][V] = {
    //    0    1    2    3    4
        {0,    10, INF, INF,   5},   // Vertex 0 has connection with 1 and 4 
        {INF,   0,   1, INF,   2},    // Vertex 1 has connection with 2 and 4
        {INF, INF,   0,   4, INF},    // Vertex 2 has connection with 3
        {7,   INF,   6,   0, INF},    // Vertex 3 has connection with 0 and 2
        {INF,   3,   9,   2,   0}     // Vertex 4 has connection with 1, 2, and 3
    };

    //INF means that there is no connection between the vertices
    //A connection can also be reffered to an EDGE

    //We want to find the shortest path from each vertices starting from Vertex 0
    dijkstra(graph, 0);

}

void dijkstra(int graph[V][V], int src){
    //This is the output array this will display the shortest path from each vertices
    int dist[V];
    //This is array flags the vertices that have been visited
    //Goes hand-in-hand with the dist array
    int isVisited[V];

    //Initialize all the arrays
    //Initialize the distances between all of the arrays to INF
    //Initialize all the vertices to isVisited to False(0)
    for(int i = 0; i<V; i++){
        dist[i] = INF;
        isVisited[i] = 0;
    }

    //Always set the distance of the source vertex to 0
    dist[src] = 0;

    for(int i = 0; i < V-1; i++){
        //Find the vertex with the minimum distance
        int u = findMin(dist, isVisited);

        //Flag the visited index as visited
        isVisited[u] = 1;

        for(int v = 0; v < V; v++){
            /*
                Update dist[v] if:
                    1. dist[v] has not been visited (isVisited[v] != 1)
                    2. There is an edge between the u to v (graph[u][v] != INF)
                    3. dist[u] is reachable (dist[u] != INF)
                    4. The cost between u to v is less than the
                       current value dist[v] (graph[u][v] + dist[u] < dist[v])
            */

           if(isVisited[v]!=1 && graph[u][v]!=INF && dist[u] != INF && graph[u][v] + dist[u] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
           }

        }
    }

    printDistances(dist, src);


}

//Find the vertex with the minimum distance value
int findMin(int dist[V], int isVisited[V]){
    int min = INF;
    int min_index;

    for(int i = 0; i<V; i++){
        //Check if the vertex is not visited amd the value is less than min
        //If true, set the min to the value of the vertex and set the min_index
        //to the vertex index
        if(isVisited[i] == 0 && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printDistances(int dist[V], int src){
    printf("\nThe distance between the vertices from Vertex %d\n", src);

    for(int i = 0; i<V; i++){
        printf("Vertex %d = %d\n", i, dist[i]);
    }

    printf("\n");
}