/*
Check if two trees are Mirror
Given two Binary Trees, write a function that returns true if two trees are mirror of each other, else false.
 For example, the function should return true for following input trees.

 This problem is different from the problem discussed here.

For two trees ‘a’ and ‘b’ to be mirror images, the following three conditions must be true:

Their root node’s key must be same
Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
Right subtree of ‘a’ and left subtree of ‘b’ are mirror.
 */
/*
mine

int areMirror(Node* a, Node* b)
{
    if (a==NULL && b==NULL) return true;

    if (a==NULL || b == NULL) return false;
    
	if(a->data != b->data) return false;
	
    return  areMirror(a->left, b->right) && areMirror(a->right, b->left);
}


or 

take level order traversal l to r of one 
teke level order traversal r to l of other
check if they are same or not
*/
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to
   left child and a pointer to right child */
struct Node
{
    int data;
    Node* left, *right;
};
 
/* Given two trees, return true if they are
   mirror of each other */
int areMirror(Node* a, Node* b)
{
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        return true;
 
    // If only one is empty
    if (a==NULL || b == NULL)
        return false;
 
    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  a->data == b->data &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left);
}
 
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = new Node;
    node->data  = data;
    node->left  =  node->right  = NULL;
    return(node);
}
 
/* Driver program to test areMirror() */
int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);
 
    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);
 
    areMirror(a, b)? cout << "Yes" : cout << "No";
 
    return 0;
}