/*
Print Common Nodes in BST(find intersection of two BSTs.)
Given two Binary Search Trees, task is to complete the function printCommon, 
which print's the common nodes in them. In other words, 

Example

root1

                 5
              /    \
            1       10
          /   \    /
         0     4   7
                    \
                     9
root2:

               10
             /    \
            7     20
          /   \
         4     9

Output: 4 7 9 10
*/

// Iterative traversal based method to find common elements
// in two BSTs.
#include<bits/stdc++.h>
using namespace std;
 
// A BST node
struct Node
{
    int key;
    struct Node *left, *right;
};
//or find direct inorder and then find common
void printCommon(Node *root1, Node *root2)
{
	if(root1==NULL||root2==NULL) return;
	
	stack<Node *> s1,s2;
	Node *temp;
	int a[1000];
	
	s1.push(root1);
	s2.push(root2);
	int i=0,j=0;
	while(!s1.empty())
	{
		temp=s1.top();
		s1.pop();
		a[i++]=temp->key;
		if(temp->right!=NULL)
			s1.push(temp->right);
		if(temp->left!=NULL)
			s1.push(temp->left);
	}
	while(!s2.empty())
	{
		temp=s2.top();
		s2.pop();
		a[i++]=temp->key;
		if(temp->right!=NULL)
			s2.push(temp->right);
		if(temp->left!=NULL)
			s2.push(temp->left);
	}
	//int n=sizeof(a)/sizeof(int);
	sort(a,a+i);
	int c=0;
	for(j=0;j<i-1;j++)
	{
		if(a[j]==a[j+1])
			cout<<a[j]<<" ";
	}
	
}
 
void inorder(struct Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}


Node *newNode(int ele)
{
    Node *temp = new Node;
    temp->key = ele;
    temp->left = temp->right = NULL;
    return temp;
}

//concept 
struct Node* insert(struct Node* node, int key)
{
   
    if (node == NULL) return newNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    return node;
}

int main()
{
    
    Node *root1 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1,  0);
    root1 = insert(root1,  4);
    root1 = insert(root1,  7);
    root1 = insert(root1,  9);
 
    Node *root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);
 
    cout << "Tree 1 : ";
    inorder(root1);
    cout << endl;
 
    cout << "Tree 2 : ";
    inorder(root2);
 
    cout << "\nCommon Nodes: ";
   printCommon(root1, root2);
 
    return 0;
}
