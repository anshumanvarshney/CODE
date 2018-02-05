/*
The space complexity of adjacency list is O(V + E) because in an adjacency list information is stored only for 
those edges that actually exist in the graph.
*/
#include<bits/stdc++.h>

    using namespace std;

    vector <int> adj[10];//two dimentional vector
	/*
	vector <int> *adj;
	cin>>V;
	adj = new vector<int>[V];
    */
    int main()
    {
        int x, y, nodes, edges;
		cout<<"\nEnter no. of nodes and edges :";
        cin >> nodes;       //Number of nodes
        cin >> edges;       //Number of edges
		cout<<"\nEnter like 1 2 ie 1->2 :";
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y;
			adj[x].push_back(y);        //Insert y in adjacency list of x
         }
		 
    for(int i = 1;i <=nodes;++i)
    {   
        cout << "Adjacency list of node " << i << ": ";
        for(int j = 0;j < adj[i].size();++j)
        {
            if(j == adj[i].size() - 1)//last node
                    cout << adj[i][j] << endl;
            else
                cout << adj[i][j] << " --> ";
		}
    }
    return 0;
  }