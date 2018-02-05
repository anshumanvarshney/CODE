/*
2 similar question 
1 st is check left and right node only
2 nd is to check whole left part and right part

Children Sum Parent (Function Program)

Given a binary tree, write a function that returns true if the tree satisfies the following property.

Example:
Input:
2
3
4 1 L 4 3 R 3 3 L
5
10 8 L 10 2 R 8 3 L 8 5 R 2 2 L​

Output:
1
1​
*/

//check second question also
int isSumProperty(Node* root)
{
    if(root==NULL||(root->left==NULL && root->right==NULL))  return 1;
    int ls=0;
    int rs=0;
    if(root->left!=NULL)
        ls=root->left->data;
    if(root->right!=NULL)
        rs=root->right->data;
    if(ls+rs==root->data && isSumProperty(root->left) && isSumProperty(root->right)) 
        return 1;
    return 0;    
}

//sum tree

/*
Check if a given Binary Tree is SumTree
Write a function that returns true if the given Binary Tree is SumTree else false.
A SumTree is a Binary Tree where the value of a node is equal to sum of the 
nodes present in its left subtree and right subtree. An empty tree is SumTree and
sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /   \
      10     3
    /    \     \
  4      6      3
  */

int sum(Node *root)
{
    if(root==NULL)  return 0;
    return sum(root->left)+root->data+sum(root->right);
}
bool isSumTree(Node* root)
{
     if(root==NULL||(root->left==NULL && root->right==NULL))  return true;
    int ls=sum(root->left);
    int rs=sum(root->right);
    if(ls+rs==root->data && isSumTree(root->left) && isSumTree(root->right)) 
        return true;
    return false;   
}