/*
You are given a pointer to the root of a binary tree. Print the top view of the binary tree. 
You only have to complete the function. 
For example :

     3
   /   \
  5     2
 / \   / \
1   4 6   7
 \       /
  9     8
Top View : 1 -> 5 -> 3 -> 2 -> 7
Input Format

You are given a function,

void top_view(node * root)
{

}
Output Format

Print the values on a single line separated by space.

Sample Input

     3
   /   \
  5     2
 / \   / \
1   4 6   7
 \       /
  9     8
Sample Output

1 5 3 2 7
Explanation

     3
   /   \
  5     2
 / \   / \
1   4 6   7
 \       /
  9     8
From the top only nodes 1,5,3,2 and 7 will be visible.
*/
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root)
{
 static int count=0;

if (root->left && count>=0) {
    count++;
    top_view(root->left);

}

printf("%d ", root->data);
count--;

if (root->right && count<0) {
    count--;
    top_view(root->right);
}
} 
//or using stack and queue
//very simple
void top_view(node * root)
{
    if(root==NULL)
      return;
     stack<node*> s;
     s.push(root);
     node *root2=root;
     while(root->left!=NULL)
     {
      s.push(root->left);
      root=root->left;
     }
     while(s.size()!=0)
	 {
		cout<<s.top()->data<<" ";
		s.pop();
	 }
     queue<node*> q;
     q.push(root2->right);
     root2=root2->right;     
     while(root2->right!=NULL)
     {
      q.push(root2->right);
      root2=root2->right;
     }
     while(q.size()!=0)
	 {
		 cout<<q.front()->data<<" ";
		 q.pop();
	 }
}