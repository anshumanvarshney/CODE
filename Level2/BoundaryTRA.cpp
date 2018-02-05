/*
Boundary Traversal of binary tree
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.
 For example, boundary traversal of the following tree is “20 8 4 10 14 25 22”

		8
	  /   \
     3	  10
	/ \		\
   1   6	 14
	  /	\	 /
	 4	 7 	13

8 3 1 4 7 13 14 10	 
 */



void printLeaves(Node *root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
    }
    printLeaves(root->left);
    printLeaves(root->right);
}
//if we do not write if confition before recursion then o/p :20 8 L 20 22 R 8 4 L 8 12 R 12 10 L 12 14 R 22 25 R
//20 8 4 10 14 25 22 <- (correct) , 20 8 12 4 10 14 25 22 (incorrect)
void printLeftBoundry(Node *root)
{
    if(root==NULL)
        return ;
    if(root->left ==NULL && root->right ==NULL)
        return;
    cout<<root->data<<" ";
    if(root->left)
    {
        printLeftBoundry(root->left);
    }
    else if(root->right)
    {
        printLeftBoundry(root->right);
    }
}
/*case
		1
	   2
	  3
		4
	   5
	  6
	 7
*/
void printRightBoundry(Node *root)
{
    if(root==NULL)
        return ;
    if(root->left ==NULL && root->right ==NULL)
        return ;
    if(root->right)
    {
        printRightBoundry(root->right);
    }
    else if(root->left)
    {
        printRightBoundry(root->left);
    }
    cout<<root->data<<" ";
}

void printBoundary(Node *root)
{
//Your code here
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    printLeftBoundry(root->left);
    printLeaves(root);
    printRightBoundry(root->right);
}