/*
Check for Balanced Tree

Given a binary tree, find if it is height balanced or not.  A tree is heigh balanced if difference 
between heights of left and right subtrees is not more than one for all nodes of tree.
    Expected time complexity is O(n).

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5
*/

int height(Node *root)
{
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    int max=(l>r)?l:r;
    return max+1;
}

bool isBalanced(Node *root)
{
    if(root==NULL)
        return 1;
       
    int l=height(root->left);
    int r=height(root->right);
    if(abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
    return false;
}
