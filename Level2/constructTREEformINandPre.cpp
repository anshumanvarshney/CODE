/*
Construct Tree from given Inorder and Preorder traversals
Let us consider the below traversals:

Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

In a Preorder sequence, leftmost element is the root of the tree. So we know ‘A’ is root for given sequences. 
By searching ‘A’ in Inorder sequence, we can find out all elements on left side of ‘A’ are in left subtree and 
elements on right are in right subtree. So we know below structure now.

                 A
               /   \
             /       \
           D B E     F C
We recursively follow above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F
Algorithm: buildTree()

root=first element of preorder
then let i = find the root in inorder 
left of i is left subtree and right of i is right subtree
recur for all


1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element
 in next recursive call.
2) Create a new tree node tNode with the data as picked element.
3) Find the picked element’s index in Inorder. Let the index be inIndex.
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
6) return tNode.
*/


#include<bits/stdc++.h>
using namespace std;

struct node
{
  char data;
  node* left;
  node* right;
};

node* buildtree(char in[],char pre[],int inst,int inend,int &preindex)
{
    if(inst>inend) return NULL;
    node *root=newNode(pre[preindex++]);
    if(inst==inend) return root;
    int inindex=search(in,inst,inend,root->data);
    root->left=buildtree(in,pre,inst,inindex-1,preindex);
    root->right=buildtree(in,pre,inindex+1,inend,preindex);
    return root;
}

int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

node* newNode(char data)
{
  node *node=new node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 

void printInorder(struct node* node)
{
  if (node == NULL)
     return;

  printInorder(node->left);
  printf("%c ", node->data);
  printInorder(node->right);
}
 
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  int preindex=0;
  struct node *root = buildtree(in, pre, 0, len - 1,preindex);
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
  getchar();
}
/*
Run on IDE
Output :

Inorder traversal of constructed tree is :
D B E A F C
Time Complexity: O(n^2). Worst case occurs when tree is left skewed. 
Example Preorder and Inorder traversals for worst case are {A, B, C, D} and {D, C, B, A}.
*/