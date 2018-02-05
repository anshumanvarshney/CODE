/*
Binary tree is full when no. of node should be odd 
and 
Method 2
/*
		1        
	  /   \	 
	2	   3
   / \	  / \
 4 	  5	 9	 8

Explanation: it goes like first it check 1 is NULL or not then 1->left!=NULL and 1->right!=NULL
then it goto 2 then it check if 2->left!=NULL and 2->right!=NULL 
then it goto 4 then it check if 4->left==NULL and 4->right==NULL so true
then it goto 5 then it check if 5->left==NULL and 5->right==NULL so true
true && true = true to 2
similarly true && true = true to 3
so true && true = true to 1
*/



#include<iostream>
using namespace std;

struct Node
{
	Node *left;
    int data;
	Node *right;
};
 
Node* newNode(int data)
{
    Node *temp;
	temp = new Node;
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}
 
bool isFullTree (struct Node* root)
{
    // If empty tree
    if (root == NULL)
        return true;
 
    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return true;
 
    // If both left and right are not NULL, and left & right subtrees
    // are full
    if ((root->left) && (root->right) ) //if ((root->left)!=NULL && (root->right)!=NULL )
        return (isFullTree(root->left) && isFullTree(root->right));
 
    // We reach here when none of the above if conditions work
    return false;
}


int main()
{
	Node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
 
    root->left->right = newNode(40);
    root->left->left = newNode(50);
    root->right->left = newNode(60);
    root>right->right = newNode(70);
 
    root->left->left->left = newNode(80);
    root->left->left->right = newNode(90);
    root->left->right->left = newNode(80);
    root->left->right->right = newNode(90);
    root->right->left->left = newNode(80);
    root->right->left->right = newNode(90);
    root->right->right->left = newNode(80);
    //root->right->right->right = newNode(90);
 
    if (isFullTree(root))
        printf("The Binary Tree is full\n");
    else
        printf("The Binary Tree is not full\n");
 
    return(0);
}