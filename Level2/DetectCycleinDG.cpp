/*
Detect Cycle in a Directed Graph

algorithm
Depth First Traversal can be used to detect cycle in a Graph. DFS for a connected graph produces a tree. 
There is a cycle in a graph only if there is a back edge(0->1->2->0 so here 2->0 is back edge or eg: 3->3) 
present in the graph. A back edge is an edge that is from a node to itself (selfloop) or one of its ancestor 
in the tree produced by DFS
 To detect a back edge, we can keep track of vertices currently in recursion stack of function for DFS traversal.
 If we reach a vertex that is already in the (recursion stack), then there is a cycle in the tree.
 The edge that connects current vertex to the vertex in the recursion stack is back edge.
 We have used recStack[] array to keep track of vertices in the recursion stack.
*/
// A C++ Program to detect cycle in a graph
#include<iostream>
#include <list>
#include <limits.h>
 
using namespace std;
 
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// This function is a variation of DFSUytil() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i])
			{
				if(isCyclicUtil(*i, visited, recStack) )//if not visited check for all using recursive call
					return true;
			}
            else if (recStack[*i]==true)//if visited check in recstack if present then there is a cycle
                return true;
        }
    }
    recStack[v] = false;  
    return false;
}// remove the vertex from recursion stack//ie. put false in the recstack no cycle detection so check for next
 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
 
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}