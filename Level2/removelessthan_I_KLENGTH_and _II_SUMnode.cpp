/*
Remove nodes on root to leaf paths of length < K

Given a Binary Tree and a number k, remove all nodes that lie only on root to leaf path(s) of length smaller than k. 
If a node X lies on multiple root-to-leaf paths and if any of the paths has path length >= k, then X is not deleted 
from Binary Tree. In other words a node is deleted if all paths going through it have lengths smaller than k.

Consider the following example Binary Tree

             1
           /   \
		 2       3
       /  \       \
     4     5       6
    /             /
   7             8 
Input: Root of above Binary Tree
       k = 4

Output: The tree should be changed to following  
           1
        /     \
      2          3
     /             \
   4                 6
 /                  /
7                  8

Algo:
//same logic as left and right view


There are 3 paths 
i) 1->2->4->7      path length = 4
ii) 1->2->5        path length = 3
iii) 1->3->6->8    path length = 4 

There is only one path " 1->2->5 " of length smaller than 4.  
The node 5 is the only node that lies only on this path, so 
node 5 is removed.
Nodes 2 and 1 are not removed as they are parts of other paths
of length 4 as well.

If k is 5 or greater than 5, then whole tree is deleted. 

If k is 3 or less than 3, then nothing is deleted.

The idea here is to use post order traversal of the tree. Before removing a node we need 
to check that all the children of that node in the shorter path are already removed.
There are 2 cases:
i) This node becomes a leaf node in which case it needs to be deleted.
ii) This node has other child on a path with path length >= k. In that case it needs not to be deleted
*/


// C++ program to remove nodes on root to leaf paths of length < K
#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
};
 
//New node of a tree
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


Node *removeShortPathNodesUtil(Node *root, int level, int k)
{
    //Base condition
    if (root == NULL)
        return NULL;
    root->left = removeShortPathNodesUtil(root->left, level + 1, k);
    root->right = removeShortPathNodesUtil(root->right, level + 1, k);
 
    if (root->left == NULL && root->right == NULL && level < k)
    {
        delete root;
        return NULL;
    }
    return root;//because in above function root->left or root->right is getting return value
}
 

Node *removeShortPathNodes(Node *root, int k)
{
    return removeShortPathNodesUtil(root, 1, k);
}
 
//Method to print the tree in inorder fashion.
void printInorder(Node *root)
{
    if (root)
    {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}
 
// Driver method.
int main()
{
    int k = 4;
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
    cout << "Inorder Traversal of Original tree" << endl;
    printInorder(root);
    cout << endl;
    Node *res = removeShortPathNodes(root, k);
	cout << "Inorder Traversal of Modified tree" << endl;
    printInorder(res);
    return 0;
}

/*
Remove all nodes which don’t lie in any path with sum>= k
Given a binary tree, a complete path is defined as a path from root to a leaf.
 The sum of all nodes on that path is defined as the sum of that path. Given a number K, you have to remove (prune the tree) all nodes which don’t lie in any path with sum>=k.

Note: A node can be part of multiple paths. So we have to delete it only in case when all 
paths from it have sum less than K.

Consider the following Binary Tree
          1 
      /      \
     2        3
   /   \     /  \
  4     5   6    7
 / \    /       /
8   9  12      10
   / \           \
  13  14         11
      / 
     15 

For input k = 20, the tree should be changed to following
(Nodes with values 6 and 8 are deleted)
          1 
      /      \
     2        3
   /   \        \
  4     5        7
   \    /       /
    9  12      10
   / \           \
  13  14         11
      / 
     15 

For input k = 45, the tree should be changed to following.
      1 
    / 
   2   
  / 
 4  
  \   
   9    
    \   
     14 
     /
    15 

*/

//simple
struct Node *prune(struct Node *root, int sum)
{
    // Base Case
    if (root == NULL) return NULL;
 
    // Recur for left and right subtrees
    root->left = prune(root->left, sum - root->data);
    root->right = prune(root->right, sum - root->data);
 
    // If we reach leaf whose data is smaller than sum,
    // we delete the leaf.  An important thing to note
    // is a non-leaf node can become leaf when its
    // chilren are deleted.
    if (root->left==NULL && root->right==NULL)
    {
        if (root->data < sum)
        {
            delete root;
            return NULL;
        }
    }
 
    return root;
}