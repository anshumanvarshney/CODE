/*
Create a Binary Search Tree from list 
and print preorder after given element

SAMPLE INPUT 
4
2 1 3 4
3

SAMPLE OUTPUT 
3
4

*/
#include <iostream>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
};

void insert(node **root,int data)
{
    if(*root==NULL)
    {
        *root=new node;
        (*root)->data=data;
        (*root)->left=(*root)->right=NULL;
    }
    else if((*root)->data>=data)
        insert(&((*root)->left),data);
    else insert(&((*root)->right),data);      
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"\n";
        preorder(root->left);
        preorder(root->right);
    }
}

node *search(node *root,int data)
{
    if(root==NULL) return NULL;
    if(root->data==data)
        return root;
    else if(root->data>=data)
        return search(root->left,data);
    else if(root->data<data)
        return search(root->right,data);
}

int main()
{
    node *root=NULL;
    long long int n,e,k,a[100000],c=0,i;
    cin>>n;
    while(n--)
    {
        cin>>e;
        insert(&root,e);
    }
    cin>>k;
    node *temp=search(root,k);//don't do with array traversal you won't get correct output
    preorder(temp);
 
    return 0;
}
