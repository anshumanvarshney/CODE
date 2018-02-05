/*
Leftmost and rightmost nodes of binary tree
Given a Binary Tree, Print the corner nodes at each level. The node at the leftmost and the node at the rightmost.

Example:
Input:
2
6
15 10 L 10 8 L 10 12 R 15 20 R 20 16 L 20 25 R
2
1 2 R 2 3 R

Output:
15 10 20 8 25
1 2 3
*/
/* Function to print corner node at each level */
void printCorner(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while(1)
    {
        int n=q.size();
        int m=n;
        while(!q.empty() && n>0)
        {
            
            if(n==1 || m==n)
                cout<<q.front()->key<<" ";
            
            Node *temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            n--;    
        }
        if(q.empty())
            break;
    }
}