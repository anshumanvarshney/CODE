/*
Print all nodes that don’t have sibling
Given a Binary Tree, print all nodes that don’t have a sibling (a sibling is a node that has same parent. 
In a Binary Tree, there can be at most one sibling). \Root should not be printed as root cannot have a sibling.

		1
	 /	   \
   2 	     3
	\       /
	 4     5
	      /
	    6

	4 5 6	
*/
/*
this can also be done using level order 
if(root->left is null and right is not null or vice versa or both NULL take in seperate queue)
*/

/*simple  

//in this soluton the order may differ
void printSibling(Node* root)
{
	if (root == NULL)
		return;
	if((root->left != NULL && root->right == NULL))
		cout<<root->left->data<<" ";
    if((root->left == NULL && root->right != NULL))
		cout<<root->right->data<<" ";
	
	printSibling(root->left);
	printSibling(root->right);
}
*/


/* Program to find singles in a given binary tree */
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct node
{
    struct node *left, *right;
    int key;
};
 
// Utility function to create a new tree node
node* newNode(int key)
{
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}


//for order same concept as boundary traversal (for order)
void printSingles(struct node *root)
{
    // Base case
    if (root == NULL)
      return;
 
    // If this is an internal node, recur for left
    // and right subtrees
    if (root->left != NULL && root->right != NULL)
    {
        printSingles(root->left);
        printSingles(root->right);
    }
 
    // If left child is NULL and right is not, print right child
    // and recur for right child
    else if (root->right != NULL)
    {
        cout << root->right->key << " ";
        printSingles(root->right);
    }
 
    // If right child is NULL and left is not, print left child
    // and recur for left child
    else if (root->left != NULL)
    {
        cout << root->left->key << " ";
        printSingles(root->left);
    }
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);
    printSingles(root);
    return 0;
}
