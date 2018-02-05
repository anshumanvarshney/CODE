/*
Sorted Array to Balanced BST(i.e inorder to BST)

Given a sorted array. Write a program that creates a Balanced Binary Search Tree using array elements.
If there are n elements in array, then floor(n/2)'th element 
should be chosen as root and same should be followed recursively.

Examples:

Input:  Array {1, 2, 3}
Output: A Balanced BST
     2
   /  \
  1    3 
print preorder
Input: Array {1, 2, 3, 4}
Output: A Balanced BST
      3
    /  \
   2    4
 /
1

Input:
1
7
7 6 5 4 3 2 1

make it as inorder
		4
	  /	  \
	6 	   2
   / \	  / \
  7	  5  3	 1
Output:

print it as preorder
4 6 7 5 2 3 1
*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
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

node *convert(int a[],int l,int h)
{
	if(l>h) return NULL;
	int m=(l+h)/2;
	node *root=newnode(a[m]);
	root->left=convert(a,l,m-1);
	root->right=convert(a,m+1,h);
	return root;
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	cout<<"\n";
}

int main()
{
	int n,p,i,*a;
	cin>>p;
	while(p--)
	{
		cin>>n;
		a=new int[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		node *root=convert(a,0,n-1);
		preorder(root);
	}
}