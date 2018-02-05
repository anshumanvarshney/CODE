/*
Print Nodes in Top View of Binary Tree
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 
Given a binary tree, print the top view of it. The output nodes can be printed in any order. 
Expected time complexity is O(n)

A node x is there in output if x is the topmost node at its horizontal distance.
Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1,
and that of right child is horizontal distance of x plus 1.

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7

Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6

The idea is to do something similar to vertical Order Traversal. Like vertical Order Traversal,
 we need to nodes of same horizontal distance together. We do a level order traversal so that the 
 topmost node at a horizontal node is visited before any other node of same horizontal distance below it. 
 Hashing is used to check if a node at given horizontal distance is seen or not.

 Note: For the problem the printing should be level wise, i.e. starting node should be root.
 1 2 3 4 7
 */

void topView(struct Node *root)
{
    queue <Node*> q;
    queue <int> hd;
    q.push(root);
    hd.push(0);
    map<int, int> m;
	
    while(!q.empty())
	{
        Node *temp=q.front(); 
		q.pop();
        int level=hd.front();
		hd.pop();
        if(m.find(level)==m.end())
		{
            m[level]=temp->data;
            cout<<temp->data<<" ";
        }
        if(temp->left)
		{
            q.push(temp->left);
			hd.push(level-1);
        }    
        if(temp->right)
		{
            q.push(temp->right);
			hd.push(level+1);
        }
    }
}

/*if printing is not level wise
		1
    /     \
   2       3
  /  \    / \
 4    5  6   7

Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
*/
void topViewUtil(Node *root,map<int,int>&m,int hd)
{
    if(!root) return;
    if(m.find(hd)==m.end())
    {
        m[hd]=root->data;
        cout<<root->data<<" ";
    }        
    topViewUtil(root->left,m,hd-1);
    topViewUtil(root->right,m,hd+1);
}
void topView(struct Node *root)
{
     if(!root)return;
     map<int,int> m;
     topViewUtil(root,m,0);
}