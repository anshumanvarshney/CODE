/*
Determine if Two Trees are Identical

Given  two  binary trees, your task is to find if both of them are identical or not . 
Example:
Input
2
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 3 L 1 2 R

Output
1
0

*/

//or O(n)

bool isIdentical(Node *r1, Node *r2)
{
   if(r1==NULL && r2==NULL) return true;
   if(r1 && r2)
		return (r1->data == r2->data && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right));
   return false;
    
}

//O(n^2)
void inorder(Node *root,int &c,int a[])
{
    if(root!=NULL)
    {
        inorder(root->left,c,a);
        a[c++]=root->data;
        inorder(root->right,c,a);
    } 
}

bool isIdentical(Node *r1, Node *r2)
{
    int a[1000],c=0;
    int b[1000],d=0;
    inorder(r1,c,a);
    inorder(r2,d,b);
    if(c!=d)
        return false;
    int i;
    for(i=0;i<c;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}


