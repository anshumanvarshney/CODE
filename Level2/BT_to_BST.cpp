/*
Binary Tree to BST

Given a binary tree, your task is to complete the function binaryTreeToBST which converts the binary tree to 
binary search tree(BST) and returns the root of the converted binary search tree.
Note : The conversion must be done in such a way that keeps the original structure of Binary Tree.

          1
       /    \
     2       3
   /        
4       

For the tree above the converted tree will be

        3
      /   \
    2     4
  /
1
*/
/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*Your code here*/
void inorder(Node *root,int a[],int &c)
{
    if(root!=NULL)
    {
        inorder(root->left,a,c);
        a[c++]=root->data;
        inorder(root->right,a,c);
    }
}

Node *insert(Node *root,int data)
{
    if(root==NULL)
    {
        Node *temp=new Node;
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    else
    {
        if(root->data > data)
            root->left=insert(root->left,data);
        else if(root->data < data)
            root->right=insert(root->right,data);
    }
    return root;
}


Node *binaryTreeToBST (Node *root)
{
    int a[1000],c=0,i;
    inorder(root,a,c);
    Node *r=NULL;
    sort(a,a+c);
    for(i=0;i<c;i++)
    {
        r=insert(r,a[i]);//instead of insert you can use inorder again and store in new node
    }
    return r;//r contains the inorder of BST but for BST we have to do inorder 
}
/*
'r' contains the tree in the following form

1 
 \
  2
	\
	 3
	  \
	   4

*/ 