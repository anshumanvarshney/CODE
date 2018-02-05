/*
Iterative Postorder Traversal | Set 1 (Using Two Stacks)
We have discussed iterative inorder and iterative preorder traversals. In this post, 
iterative postorder traversal is discussed which is more complex than the other two traversals 
(due to its nature of non-tail recursion, there is an extra statement after the final recursive call to itself).
 The postorder traversal can easily be done using two stacks though.
 The idea is to push reverse postorder traversal to a stack.
 Once we have reverse postorder traversal in a stack,
 we can just pop all items one by one from the stack and print them, 
 this order of printing will be in postorder because of LIFO property of stacks. 
 Now the question is, how to get reverse post order elements in a stack – the other stack is used for this purpose. 
 
 Constructed binary tree is
            1
          /   \
        2      3
      /  \    /  \
    4     5  6	  7
	postorder : 4 5 2 6 7 3 1 

 For example, in the following tree, we need to get 1, 3, 7, 6, 2, 5, 4 in a stack.
 If take a closer look at this sequence, we can observe that this sequence is very similar to preorder traversal. 
 The only difference is right child is visited before left child and therefore sequence is “root right left” 
 instead of “root left right”. 
 So we can do something like iterative preorder traversal with following differences.
a) Instead of printing an item, we push it to a stack.
b) We push left subtree before right subtree.

Following is the complete algorithm. After step 2, we get reverse postorder traversal in second stack. 
We use first stack to get this order.

1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
 
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 

struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node *root)
{
    // Base Case
    if (root == NULL)
       return;
    stack<node *> s1;
	stack<node *> s2;
	s1.push(root);
	while(!s1.empty())
	{
		node* temp=s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left!=NULL)
			s1.push(temp->left);
		if(temp->right!=NULL)
			s1.push(temp->right);
	}	
	while(!s2.empty())
	{
		node* temp=s2.top();
		cout<<temp->data<<" ";
		s2.pop();
	}
	
}
 
// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /  \
    4     5  6	  7
	postorder : 4 5 2 6 7 3 1 
  */
  struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
  iterativePreorder(root);
  return 0;
}
