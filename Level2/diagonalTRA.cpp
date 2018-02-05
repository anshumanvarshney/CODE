/*
Diagonal Traversal of Binary Tree
Consider lines of slope -1 passing between nodes. Given a Binary Tree, 
print all diagonal elements in a binary tree belonging to same line.

		8
	  /   \
     3	  10
	/ \		\
   1   6	 14
	  /	\	 /
	 4	 7 	13
	 
Output : 
Diagonal Traversal of binary tree : 
 8 10 14
 3 6 7 13
 1 4
*/

#include <bits/stdc++.h>
using namespace std;
 
// Tree node
struct Node
{
    int data;
    Node *left, *right;
};
void diagonalutil(Node *root,int hd,map<int,vector<int>> &m)
{
    if(root==NULL) return;
    m[hd].push_back(root->data);
    diagonalutil(root->left,hd+1,m);
    diagonalutil(root->right,hd,m);
}

void diagonalPrint(Node *root)
{
    map<int,vector<int>> m;
    diagonalutil(root,0,m);
 
   for (auto i = m.begin();i != m.end(); i++)
   {
    for (auto j = i->second.begin();j!= i->second.end(); j++)
	{
		cout << *j << ' ';
	}
	//cout<<"\n";
   }
}

/*
//O(n)

void diagonalPrint(Node *root)
{
    if(root == NULL)
		return;
 
    queue<Node*> q;
    q.push(root);
 
    while(!q.empty())
    {
        int size = q.size();
        
        while(size--)
        {
			Node* temp = q.front();
            q.pop();
 
            while(temp!=NULL)
            {
                cout << temp -> data << " ";
                if(temp -> left)
                    q.push(temp -> left);
                temp = temp -> right;
            }
        }
    }
}
*/