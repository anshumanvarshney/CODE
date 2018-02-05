/*
Reverse alternate levels of a perfect binary tree
Given a Perfect Binary Tree, reverse the alternate level nodes of the binary tree.

  
Given tree: 
               a
            /     \
           b       c
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
      h  i j  k l  m  n  o 

Modified tree:
			   a
            /     \
           c       b
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
      o  n m  l k  j  i  h
	  
Method 1 (Simple)

A simple solution is to do following steps.
1) Access nodes level by level.
2) If current level is odd, then store nodes of this level in an array.
3) Reverse the array and store elements back in tree.

Implemented algo

store root->left in root1 and root->right in root2
now traverse outer area of both swap if even 
then traverse inner area 
and do the same for left and right
swap if NULL


*/



// C++ program to reverse alternate levels of a binary tree
#include<bits/stdc++.h>
using namespace std;
 
// A Binary Tree node
struct Node
{
    char data;
    Node *left, *right;
};
 
Node *newNode(char item)
{
	Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void printInorder(Node *root)
{
	if(root!=NULL)
	{
		printInorder(root->left);
		cout<<root->data<<" ";
		printInorder(root->right);
	}
}

void preorder(struct Node *root1, struct Node* root2, int lvl)
{
    // Base cases
    if (root1 == NULL || root2==NULL)
        return;
 
    // Swap subtrees if level is even
    if (lvl%2 == 0)
        swap(root1->data, root2->data);
 
    // Recur for left and right subtrees (Note : left of root1
    // is passed and right of root2 in first call and opposite
    // in second call.
    preorder(root1->left, root2->right, lvl+1);
    preorder(root1->right, root2->left, lvl+1);
}
 
// This function calls preorder() for left and right children
// of root
void reverseAlternate(struct Node *root)
{
   preorder(root->left, root->right, 0);
}

int main()
{
    Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');
 
    cout << "Inorder Traversal of given tree\n";
    printInorder(root);
 
    reverseAlternate(root);
 
    cout << "\n\nInorder Traversal of modified tree\n";
    printInorder(root);
 
    return 0;
}