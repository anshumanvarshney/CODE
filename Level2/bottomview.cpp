/*
Bottom View of a Binary Tree
Given a Binary Tree, we need to print the bottom view from left to right. 
A node x is there in output if x is the bottommost node at its horizontal distance.
Horizontal distance of left child of a node x is equal to horizontal
distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Examples:

                      20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \      
                  10    14

For the above tree the output should be 5, 10, 3, 14, 25.

If there are multiple bottom-most nodes for a horizontal distance from root,
 then print the -->later one in level traversal. For example, in the below diagram, 3 and 4 
 are both the bottom-most nodes at horizontal distance 0, we need to print 4.

                   
                      20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \      
                  10    14 
For the above tree the output should be 5, 10, 4, 14, 25.
if you want 5 10 14 4 25 then use stack and revese iter_swap
if you want any order better to use queue
*/

/*
Algorithm

The following are steps to print Bottom View of Bianry Tree.
1. We put tree nodes in a queue for the level order traversal.
2. Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue 
along with the horizontal distance as hd-1 and right child as hd+1.
3. Also, use a TreeMap which stores key value pair sorted on key.
4. Every time, we encounter a new horizontal distance or an existing horizontal distance put the node data
 for the horizontal distance as key. For the first time it will add to the map, 
 next time it will replace the value. This will make sure that the bottom most element for that horizontal 
 distance is present in the map and if you see the tree from beneath that you will see that element.
*/

#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data; 
    Node *left, *right; 
 
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

void bottomViewUtil(Node *root,map<int,int> &mp,int hd)//passing address of map
{
    if(!root) return;
    mp[hd]=root->data;
    bottomViewUtil(root->left,mp,hd-1);
    bottomViewUtil(root->right,mp,hd+1);
}
void bottomView(Node *root)
{
   // Your Code Here
   map<int,int> mp;
   bottomViewUtil(root,mp,0);
   map<int,int>::iterator it;
   for(it=mp.begin();it!=mp.end();it++)
    cout<<it->second<<" ";
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}

/*
Run on IDE

Output:
Bottom view of the given binary tree:
5 10 4 14 25
*/