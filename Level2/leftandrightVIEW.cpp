/*
Print Left View of a Binary Tree

          12
       /     \
     10       30
                 \
				  40 
					\
					50	

output: 12 10 40 50

The left view contains all nodes that are first nodes in their levels.
Algo 1:

 A simple solution is to do level order traversal and print the first node in every level.

Algo 2: 

maxlevel=0
level=1;

if(maxlevel<level)
	print 
    and maxlevel=level

recursive call (root->left,level+1,maxlevel)
recursive call (root->right,level+1,maxlevel)

note:
 	
	      12
       /     \
     10       30
                 \
				  40 
					\
					50	

Explanation:

	maxlevel=0
	level=1
 so print 12
 now maxlevel=1
	level=1
recursive call left so level=2
maxlevel=1
	level=2
so print 10
now maxlevel=2
	level=2
recursive call right so level=3 but right is not possinle so level=2 
now return so level =1;
recursive call left so level=2
now maxlevel=2
	level=2
nothing is printed
and so on,..,,,	
*/

#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Recursive function to print left view of a binary tree.
void leftViewUtil(struct node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;
 
    // If this is the first node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
 
    // Recur for left and right subtrees
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}
 
// A wrapper over leftViewUtil()
void leftView(struct node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
//right view 
void rightViewUtil(struct Node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;
 
    // If this is the last Node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
 
    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}
 
// A wrapper over rightViewUtil()
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
} 
 
// Driver Program to test above functions
int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
 
    leftView(root);
	rightView(root);
 
    return 0;
}
