/*
Check for BST

Given a binary tree, return true if it is BST, else false. For example, the following tree is not BST,
 because 11 is in left subtree of 10.

        10
     /     \
   7       39
     \
      11
	  
my algo:
do the iterative inorder traversal(of binary tree gives sorted array) and stored in a temporary array  a[i++]=
then check the array like 
for(j=0;j<i-1;j++)
{
	if(a[i]>a[i+1]) return 0	  
}
return 1;  
*/

bool isBST(node *root)	
{
	
}  