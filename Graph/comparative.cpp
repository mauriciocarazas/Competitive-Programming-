
#include <chrono>
#include <iostream>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <thread>
using namespace std;
#define V 9
#define V_2 4

#define INF 99999

void FLOYD_printSolution(int dist[][V]);

void floydWarshall(int graph[][V]) {
  int dist[V][V], i, j, k;

  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      dist[i][j] = graph[i][j];

  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  FLOYD_printSolution(dist);
}

void FLOYD_printSolution(int dist[][V]) {
   for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == 0)
        printf("%7s", "0");
      else
        printf("%7d", dist[i][j]);
    }
    printf("\n");
  }
}

////////////////////////////////////////////////////

int minDistance(int dist[], bool sptSet[]) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

void printSolution(int dist[]) {
  printf("Vertex \t\t Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
  int dist[V];

  bool sptSet[V];
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;

  dist[src] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;

    for (int v = 0; v < V; v++)

      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }

  printSolution(dist);
}

int main() {
  int graph[V][V] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},  
      {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},  
      {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
      {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},  
      {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}};

  // dijkstra(graph, 0);

  auto t1 = chrono::high_resolution_clock::now();
  dijkstra(graph, 0);
  auto t2 = chrono::high_resolution_clock::now();

  /* Getting number of milliseconds as a double. */
  auto duration = duration_cast<chrono::microseconds>(t2 - t1);

  cout <<"Dijkstra Algorithm: "<< duration.count() << " microseconds\n";

  int FLOYD_graph[V_2][V_2] = {
      {0, 5, INF, 10}, 
      {INF, 0, 3, INF}, 
      {INF, INF, 0, 1}, 
      {INF, INF, INF, 0}};

  auto t3 = chrono::high_resolution_clock::now();
  floydWarshall(graph);
  auto t4 = chrono::high_resolution_clock::now();

  /* Getting number of milliseconds as a double. */
  auto duration_2 = duration_cast<chrono::microseconds>(t4 - t3);

  cout <<"Floyd Warshall Algorithm: "<< duration_2.count() << " microseconds\n";

  return 0;
}
