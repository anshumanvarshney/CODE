
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

int util(TreeNode* root1,TreeNode* root2)
{
    if(root1==NULL&&root2==NULL)
        return 1;
    if(root1==NULL||root2==NULL)
        return 0;
    return (root1->val==root2->val&&util(root1->left,root2->right)&&util(root1->right,root2->left));    
        
}
int Solution::isSymmetric(TreeNode* root) {

    if(root==NULL)
        return 1;
    return util(root->left,root->right);    
}