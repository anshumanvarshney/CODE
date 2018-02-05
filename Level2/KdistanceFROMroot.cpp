/*
K distance from root

Given a Binary Tree and a number k. Print all nodes that are at distance k from root 
(root is considered at distance 0 from itself).  Nodes should be printed from left to right.
If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2.  Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8

using both iterative and recursive	  
	  */

#include<bits/stdc++.h>
using namespace std;

struct node
{
	node *left;
	int data;
	node *right;
};

node *newnode(int data)
{
	node *temp;
	temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

void level(node *root,int k)
{
	if(root==NULL)
		return;
	queue<node *> q;
	q.push(root);
	int c=-1;
	while(!q.empty())
	{
		c++;	
		int n=q.size();
		while(n--)
		{
			node *temp;
			temp=q.front();
			if(c==k)
				cout<<temp->data<<" ";
			q.pop();
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
	}	
}		


//using recursion
/*
void printKDistant(node *root , int k)    
{
   if(root == NULL) 
      return;
   if( k == 0 )
   {
      printf( "%d ", root->data );
      return ;
   }
   else
   {      
      printKDistant( root->left, k-1 ) ;
      printKDistant( root->right, k-1 ) ;
   }
}
*/

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->right->right=newnode(6);
	root->left->left=newnode(4);
	root->right->left=newnode(5);
	root->left->left->right=newnode(8);
	inorder(root);
	level(root,2);
}