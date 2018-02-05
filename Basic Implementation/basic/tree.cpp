
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
	node *root=newnode(12);
	root->left=newnode(10);
	root->right=newnode(30);
	root->right->right=newnode(40);
	root->right->right->right=newnode(50);
	inorder(root);
}