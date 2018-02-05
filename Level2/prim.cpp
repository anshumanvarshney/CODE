/*
Greedy Algorithms | Set 5 (Prim’s Minimum Spanning Tree (MST))

The idea is to maintain two sets of vertices. The first set contains the vertices already included in the MST, 
the other set contains the vertices not yet included. At every step, it considers all the edges that connect the two sets,
and picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of the 
edge to the set containing MST.

A group of edges that connects two set of vertices in a graph is called cut in graph theory. So, at every step of 
Prim’s algorithm, we find a cut (of two sets, one contains the vertices already included in MST 
and other contains rest of the verices), pick the
 minimum weight edge from the cut and include this vertex to MST Set (the set that contains already included vertices).

 How does Prim’s Algorithm Work?
 The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. 
 So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree.
 And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

 Algorithm
1) Create a set mstSet that keeps track of vertices already included in MST.
2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE.
   Assign key value as 0 for the first vertex so that it is picked first.
3) While mstSet doesn’t include all vertices
….a) Pick a vertex u which is not there in mstSet and has minimum key value.
….b) Include u to mstSet.
….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices.
	 For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value
	 as weight of u-v
*/
//http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/  for understanding the concept

// The program is for adjacency matrix representation of the graph
 
#include<bits/stdc++.h>
using namespace std;
 
int minKey(int key[], bool mstSet[],int V)
{
	
   int min = INT_MAX, index;
 
   for (int i = 0; i < V; i++)
     if (mstSet[i] == false && key[i] < min)//mstSet=false is neccessary for identifying already visited vertex  
         min = key[i], index = i;
 
   return index;
}

int printMST(int parent[], int n, int graph[][5])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < n; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 
void totalweight(int key[],int V)
{
	int sum=0,i;
	for(i=0;i<V;i++)
	{
		sum+=key[i];
	}
	cout<<"\n"<<sum<<"\n";
	
}

void primMST(int graph[][5],int V)
{
     int parent[V]; 
     int key[V]; 
     bool mstSet[V];  
 
     for (int i = 0; i < V; i++)
	 {
        key[i] = INT_MAX;
		mstSet[i] = false;
	 }

     key[0] = 0;  
     parent[0] = -1; //for parent
 
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet,V);
        mstSet[u] = true;
 
        for (int v = 0; v < V; v++)
		{	
          if (graph[u][v]!=0 && mstSet[v] == false && graph[u][v] <  key[v])
		  {           
			parent[v]  = u;
			key[v] = graph[u][v];
		  }
		}
     }
     printMST(parent, V, graph);
	 totalweight(key,V);
}

int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[5][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    primMST(graph,5);
 
    return 0;
}
/*
Run on IDE

Output:
Edge   Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5
Time Complexity of the above program is O(V^2). If the input graph is represented using adjacency list,
 then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of binary heap. 
*/