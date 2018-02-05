/*
Preorder to Postorder
Given an array representing preorder traversal of BST, print its postorder traversal. 

Algo:
check if the array represent preorder if yes then follow below step otherwise print NO
sort the preorder to get inorder
by using inorder and preorder construct tree 
find postorder


Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120
8
7  9 6 1 4 2 3 40

Output:
35 30 100 80 40
35 32 30 120 100 90 80 40
NO
*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *newnode(int data)
{
    node *temp=new node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

int search(int a[],int x,int y,int ele)
{
    int i;
    for(i=x;i<=y;i++)
    {
        if(a[i]==ele)
            return i;
    }
}

node* buildtree(int in[],int pre[],int inst,int inend,int &preindex)
{
    if(inst>inend) return NULL;
    node *root=newnode(pre[preindex++]);
    if(inst==inend) return root;
    int inindex=search(in,inst,inend,root->data);
    root->left=buildtree(in,pre,inst,inindex-1,preindex);
    root->right=buildtree(in,pre,inindex+1,inend,preindex);
    return root;
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

bool check(int a[],int n)
{
    stack<int> s;
    int root=INT_MIN,i;
    for(i=0;i<n;i++)
    {
        if(!s.empty()&& root>a[i])
            return false;
        while(!s.empty()&&s.top()<a[i]) 
        {
            root=s.top();
            s.pop();
        }
        s.push(a[i]);
    }
    return true;
}

int main()
{
   int p;
   cin>>p;
   while(p--)
   {
       int n,i;
       cin>>n;
       int pre[1000],in[1000];
       for(i=0;i<n;i++)
          cin>>pre[i];
        if(check(pre,n)==false)
            cout<<"NO";
        else
        {
            for(i=0;i<n;i++)
              in[i]=pre[i];
           sort(in,in+n);
            int preindex=0;
            node *root=buildtree(in,pre,0,n-1,preindex);
            postorder(root);
        }
       cout<<"\n";
   }
	return 0;
}