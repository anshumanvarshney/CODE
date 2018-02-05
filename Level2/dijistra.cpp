/*
Greedy Algorithms | Set 7 (Dijkstra’s shortest path algorithm)
Given a graph and a source vertex in graph, find shortest paths from source to all vertices in the given graph.

Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. Like Prim’s MST,
 we generate a SPT (shortest path tree) with given source as root. We maintain two sets, one set contains 
 vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree.
 At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) 
 and has minimum distance from source.
 

Below are the detailed steps used in Dijkstra’s algorithm to find the shortest path from a single source
 vertex to all other vertices in the given graph.
Algorithm
1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree,
	i.e., whose minimum distance from source is calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE.
	Assign distance value as 0 for the source vertex so that it is picked first.
3) While sptSet doesn’t include all vertices
….a) Pick a vertex u which is not there in sptSetand has minimum distance value.
….b) Include u to sptSet.
….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate
 through all adjacent vertices. For every adjacent vertex v, if sum of distance value of u (from source) 
 and weight of edge u-v, is less than the distance value of v, then update the distance value of v.
 */
 
 //http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/ for understanding the algorithms
 
 // A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
  
#include <bits/stdc++.h>
using namespace std;
const int V=9;

int minDistance(int dist[], bool sptSet[],int V)
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
   {
	   if (sptSet[v] == false && dist[v] <= min)
	   {
		   min = dist[v];
		   min_index = v;
	   }
   }
   return min_index;
}
  
int printSolution(int dist[], int V)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
   {
      printf("%d \t\t %d\n", i, dist[i]);
	}
}

void dijkstra(int graph[V][V], int src,int V)
{
     int dist[V];     
     bool sptSet[V]; 
   
     for (int i = 0; i < V; i++)
	 {
        dist[i] = INT_MAX;
		sptSet[i] = false;
	 }
 
     dist[src] = 0;//note very important don't make starting index is zero
  
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet,V);
       sptSet[u] = true;
  
       for (int v = 0; v < V; v++)
	   {
         if ( graph[u][v]!=0 && sptSet[v]==false && dist[u]+graph[u][v] < dist[v])
		 {
			dist[v] = dist[u] + graph[u][v];
		 }
	   }
	 }

     printSolution(dist, V);
}
  
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14,10, 0, 2, 0, 0},
                      {0, 0, 0, 0,  0, 2, 0, 1, 6},
                      {8, 11,0, 0,  0, 0, 1, 0, 7},
                      {0, 0, 2, 0,  0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0,9);//0=source
  
    return 0;
}
/*
Run on IDE

Output:
Vertex   Distance from Source
0                0
1                4
2                12
3                19
4                21
5                11
6                9
7                8
8                14
*/