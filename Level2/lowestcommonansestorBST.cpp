/*
Lowest Common Ancestor in a Binary Search Tree.

Following is definition of LCA from Wikipedia:
Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 
is defined as the lowest node in T that has both n1 and n2 as descendants 
(where we allow a node to be a descendant of itself).

The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root. 
Computation of lowest common ancestors may be useful, for instance, as part of a procedure for 
determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed 
as the distance from the root to n1, plus the distance from the root to n2,
minus twice the distance from the root to their lowest common ancestor. 

					  20
                    /    \
                  8       22
                /   \      
              4      12      
                    / \      
                  10    14
				  
algo:

if both node < root then it goes left sub tree else right sub tree
if one node is > than node and second is smaller,then root is LCA				  
*/


#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    node* left, *right;
};
 //recursive version
/*
   node *lca(struct node* root, int n1, int n2)
{
    if (root == NULL) return NULL;
 
    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
 
    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
 
    return root;
}*/
 /*Time complexity of above solution is O(h) where h is height of tree. 
 Also, the above solution requires O(h) extra space in function call stack for recursive function calls. 
 We can avoid extra space using iterative solution.*/

node *lca(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
         // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
           root = root->left;
 
        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (root->data < n1 && root->data < n2)
           root = root->right;
 
        else break;
    }
    return root;
}

node* newNode(int data)
{
	node* temp  = new node;
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return(temp);
}
 
/* Driver program to test lca() */
int main()
{
    // Let us construct the BST shown in the above figure
    node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    return 0;
}