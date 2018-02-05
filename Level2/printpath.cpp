/*
Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3 #1 2 #
10 20 40 #10 20 60 #10 30 #
*/



/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/


 
 
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"#";    
}
void printpathutil(Node *root,int a[],int i)
{
    if(root==NULL)
        return;
    a[i]=root->data;
    i++;
    if(root->left==NULL && root->right==NULL)
        print(a,i);
    else
    {
        printpathutil(root->left,a,i);
        printpathutil(root->right,a,i);
    }
}
void printPaths(Node* root)
{
    int a[1000];
    printpathutil(root,a,0);//pass by value
    cout<<endl;
}