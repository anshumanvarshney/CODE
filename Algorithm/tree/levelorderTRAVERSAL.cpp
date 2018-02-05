/*
Print level order traversal line by line
Given a binary tree, print level order traversal in a way that nodes of all levels are printed in separate lines.
For example consider the following tree
          1
       /     \
      2       3
    /   \       \
   4     5       6
        /  \     /
       7    8   9

Output for above tree should be

1 2 3 4 5 6 7 8 9

line by line

1
2 3
4 5 6
7 8 9

Algo

1-use queue (FIFO)
2-push root node first
then print if q is not empty and check left and right child of root is present or not
push left and right child
repeat the process
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

void printLevelOrder(node *root)
{
	if(root==NULL) return;
	queue<node *> q;//queue of node i.e tree
	q.push(root);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		cout<< root->data <<" ";
		if(root->left!=NULL)
			q.push(root->left);
		if(root->right!=NULL)
			q.push(root->right);
	}
	cout<<"\n";
}

void printLevelOrderlbl(node *root)
{
	if(root==NULL) return;
	queue<node *> q;//queue of node i.e tree
	q.push(root);
	while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)//when queue is empty
            break;
 
		while(nodeCount > 0)
		{
			root=q.front();
			q.pop();
			cout<< root->data <<" ";
			if(root->left!=NULL)
				q.push(root->left);
			if(root->right!=NULL)
				q.push(root->right);
			nodeCount--;
		}
		cout<<"\n";
	}
}

node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    printLevelOrder(root);
	printLevelOrderlbl(root);//printing level by level
    return 0;
}