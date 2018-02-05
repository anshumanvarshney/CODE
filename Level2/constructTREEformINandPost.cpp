/*
Construct a Binary Tree from Postorder and Inorder
Given Postorder and Inorder traversals, construct the tree.

Examples:

Input : 
in[]   = {2, 1, 3}
post[] = {2, 3, 1}

Output : Root of below tree
      1
    /   \
   2     3 


Input : 
in[]   = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1} 

Output : Root of below tree
          1
       /     \
     2        3
   /    \   /   \
  4     5   6    7
    \
      8

Algo :
last node of postorder = root of tree 
then recur inorder as we did in contruction of tree by(pre and in)
Imp: first recur right then recur left

	  
We have already discussed construction of tree from iven Inorder and Preorder traversals. The idea is similar.

Let us see the process of constructing tree from in[] = {4, 8, 2, 5, 1, 6, 3, 7} and post[] = {8, 4, 5, 2, 6, 7, 3, 1}

1) We first find the last node in post[]. The last node is “1”, we know this value is root as root always appear in the 
end of postorder traversal.

2) We search “1” in in[] to find left and right subtrees of root. Everything on left of “1” in in[] is in left subtree
 and everything on right is in right subtree.

         1
       /    \
[4,8,2,5]   [6,3,7] 
3) We recur the above process for following two.
….b) Recur for in[] = {6,3,7} and post[] = {6,7,3}
…….Make the created tree as right child of root.
….a) Recur for in[] = {4,8,2,5} and post[] = {8,4,5,2}.
…….Make the created tree as left child of root.
*/

#include<bits/stdc++.h>
using namespace std;
 

struct Node
{
    int data;
    Node* left, * right;
};
/*C approach for passing reference
Node* buildUtil(int in[], int post[], int inStrt,int inEnd, int *pIndex)
{
    if (inStrt > inEnd)
        return NULL;

    Node *node = newNode(post[*pIndex]);
    (*pIndex)--;
 
    if (inStrt == inEnd)
        return node;
 
    int iIndex = search(in, inStrt, inEnd, node->data);
	
    node->right= buildUtil(in, post, iIndex+1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex-1, pIndex);
 
    return node;
}
 
Node *buildTree(int in[], int post[], int n)
{
    int pIndex = n-1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}
*/

int search(int a[],int x,int y,int ele)
{
    int i;
    for(i=x;i<=y;i++)
    {
        if(a[i]==ele)
            return i;
    }
}

Node* newnode(int data)
{
    Node *temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

Node *buildutil(int in[],int post[],int inst,int inend,int &postindex)
{
    if(inst>inend) return NULL;
    Node *root=newnode(post[postindex--]);
    if(inst==inend) return root;
    int inindex=search(in,inst,inend,root->data);
    root->right=buildutil(in,post,inindex+1,inend,postindex);
    root->left=buildutil(in,post,inst,inindex-1,postindex);
    return root;
    
}

Node *buildTree(int in[], int post[], int n)
{
    int postindex=n-1;
    return buildutil(in,post,0,n-1,postindex);
}

void preOrder(Node* node)
{
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in)/sizeof(in[0]);
 
    Node *root = buildTree(in, post, n);
 
    cout  << "Preorder of the constructed tree : \n";
    preOrder(root);
 
    return 0;
}
/*
Run on IDE
Output :

Preorder of the constructed tree : 
1 2 4 8 5 3 6 7 
Time Complexity : O(n2)
*/