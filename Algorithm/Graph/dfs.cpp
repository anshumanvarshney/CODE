// C++ program to print DFS traversal for a given given graph

//Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
/*
idea:
to go forward (in depth) while there is a possibility, if not then, backtrack
use stack data structure

Algorithmic Steps

Step 1: Push the root node in the Stack. 
Step 2: Loop until stack is empty. 
Step 3: Peek the node of the stack. 
Step 4: If the node has unvisited child nodes, get the unvisited child node, mark it as traversed and push it on stack.
Step 5: If the node does not have any unvisited child nodes, pop the node from the stack.  
*/
#include<bits/stdc++.h>
using namespace std;
 
// This class represents a directed graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void DFS();  // prints all vertices in DFS manner
 
    // prints all not yet visited vertices reachable from s
    void DFSUtil(int s, vector<bool> &visited);
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
 
// prints all not yet visited vertices reachable from s
void Graph::DFSUtil(int s, vector<bool> &visited)
{
    // Create a stack for DFS
    list<int> stack;
 
    // Puah the current source node.
    stack.push_front(s);
    list<int> :: iterator i;
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.front();
        stack.pop_front();
 
        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }
 
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then puah it
        // to the stack.
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push_front(*i);
    }
}
 
// prints all vertices in DFS manner
void Graph::DFS()
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);//in one line
    
	//or use 2D array as we use in recursive method 
	
    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(i, visited);
}
 
// Driver program to test methods of graph class
int main()
{
     Graph g(4);
     g.addEdge(0, 1);
g.addEdge(0, 3);
g.addEdge(0, 2);
g.addEdge(2, 1);
	cout << "Following is Depth First Traversal\n";
    g.DFS();
    return 0;
}

//recursive
#include<iostream>
#include <list>
using namespace std;
 
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS();    // prints DFS traversal of the complete graph
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
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
 
// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)//in the order we entered
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(i, visited);
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
 
    cout << "Following is Depth First Traversal\n";
    g.DFS();
 
    return 0;
}
