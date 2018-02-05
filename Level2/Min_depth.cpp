/*
		1
	  /	  \
    2	   5
  /   \
3  	   4
 min depth =2;
*/


#include<bits/stdc++.h>
using namespace std;
 

struct Node
{
    int data;
    struct Node* left, *right;
};
 int minDepth(Node *root)
{
    if(root==NULL)
        return 0;                // If tree is empty return minimum height as 0.
    int l=minDepth(root->left);        // Find minimum height of left subtree..
	int r=minDepth(root->right);      //  Find minimum height of right subtree..
	int val=min(l,r);            // take minimum of both..
	if(val==0)
		return 1+max(mhl,mhr);                
	else										
		return 1+min(mhl,mhr);
									
	// If minimum of both found 0.That means either left or right subtree is not present. eg: 1 2R
	// So take maximum height of both subtree(will give you the non zero one) + 1
	// Else minimum height of both subtree +1 (for root)
}
 
// Utility function to create new Node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return (temp);
}
 
// Driver program
int main()
{
    // Let us construct the Tree shown in the above figure
    Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout << minDepth(root);
    return 0;
}