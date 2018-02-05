/*
Level order traversal in spiral form

		1
	  /   \
     2	   3
   /  \	  / \
  7   6  5	 4
Write a function to print spiral order traversal of a tree. For below tree, function should print 1, 2, 3, 4, 5, 6, 7.
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

void levelspiral(node *root)
{
	if(root==NULL)
		return;
	stack<node *>s1;
	stack<node *>s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			node *temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right!=NULL)
				s2.push(temp->right);
			if(temp->left!=NULL)
				s2.push(temp->left);
		}
		while(!s2.empty())
		{
			node *temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
				s1.push(temp->left);
			if(temp->right!=NULL)
				s1.push(temp->right);
		}
	}	
}		




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
	cout<<"\n";
	levelspiral(root);
}