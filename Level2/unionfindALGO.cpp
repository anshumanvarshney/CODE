// Naive implementation of find
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
  
// Naive implementation of union()
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}


/*
A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into
 a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two
 useful operations on such a data structure:

Find: Determine which subset a particular element is in. This can be used for determining if two elements 
are in the same subset.

Union: Join two subsets into a single subset.

In this post, we will discuss an application of Disjoint Set Data Structure. The application is to check
 whether a given graph contains a cycle or not.

Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. Note that
 we have discussed an algorithm to detect cycle. This is another method based on Union-Find. This method
 assumes that graph doesn’t contain any self-loops.
We can keeps track of the subsets in a 1D array, lets call it parent[].

0
	2
1

For each edge(order is not important), make subsets(for all which are connected through edges)using both 
the vertices of the edge. 
eg: A 
  /   \
B		C

find(A)=A ,find(B)=B ,find(C)=C, 
then union of A and B so find of(A)=find of (B)=B(or we take A) 
union of A and C so find(A)=B and Find(C)=C so there is no cycle

If both the vertices are in the same subset, a cycle is found.

Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).

0   1   2
-1 -1  -1 
Now process all edges one by one.

Edge 0-1: Find the subsets in which vertices 0 and 1 are. Since they are in different subsets, we take
 the union of them. For taking the union, either make node 0 as parent of node 1 or vice-versa.

0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
1  -1  -1
Edge 1-2: 1 is in subset 1 and 2 is in subset 2. So, take union.

0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
1   2  -1
Edge 0-2: 0 is in subset 2 and 2 is also in subset 2. Hence, including this edge forms a cycle.

How subset of 0 is same as 2?
0->1->2 // 1 is parent of 0 and 2 is parent of 1


idea :for each edge make subset using both the vertices of the edge. if both vertices are in same subset, a cycle is found

pseudocode
for each unvisited edge(u,v)in edge set E
{
	if(Find(u)==Find(v))
	{
		cycle detected
	}
	else
		union(x,y)
}

*/


#include<bits/stdc++.h>
using namespace std;
 
#define MAXX 1000005
int ranks[MAXX],parent[MAXX];

int find_p(int v)
{
	if(v==parent[v])return v;
	return parent[v]=find_p(parent[v]);//make parent
}
 
void union_me(int u,int v)
{
 /*
  if(u!=v)
  {
 
		if(ranks[u]>ranks[v])
		{
		  	parent[v]=u;
			ranks[u]+=ranks[v];
		}
		else if(ranks[v]>ranks[u])
		{
			parent[u]=v;
			ranks[v]+=ranks[u];
		}
		if(ranks[u]==ranks[v])
		{
			parent[v]=u;
		    ranks[u]++;
        }
   }
}*/
//run also if you make changes

parent[v]=u; 
 
// Task : Cycle detection using Union-Find-Disjoint...
 
int main()
{
	int n,m;   
	cout<<"Enter number of nodes and number of edges :";	// number of nodes,number of edges respectively...
	cin>>n>>m;
	int F=0;
	for(int i=0;i<=n;i++)
	{
		ranks[i]=-1;
		parent[i]=i;
	}
	cout<<"\nEnter Vertices  Edges in 'v' 'e' fashion:";
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		int pu=find_p(u);
		int pv=find_p(v);
		if(pu==pv)
		{
			cout<<"Cycle is present\n";
			F=1;
			break;
		}
		else
		{
			union_me(pu,pv);
		}
	}
	if(F==0)
	{
		cout<<"Cycle is not present\n";
	}
	return 0;
}
https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
http://stackoverflow.com/questions/4498833/implementing-disjoint-sets-union-find-in-c
http://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
