/*
Given a binary tree in which each node element contains a number.
 Find the maximum possible sum from one leaf node to another.
 
 Input: Root of below tree
       1
      / \
     2   3
	 
Output: 6

See below diagram for another example.
1+2+3
 */
 
int sum(Node *root,int &res)
{
    if(root==NULL) return 0;
	if(root->left==NULL && root->right==NULL) return root->data;
 
	int l = sum(root->left, res);
	int r = sum(root->right, res);
 
	// Try all possible combinations for optimal result
	res = max(res, l + root->data); 
	res = max(res, r + root->data);
	res = max(res, l + r + root->data);
	res = max(res, root->data);
 
	// return maximum of all possible paths 
	return max(root->data, max(l + root->data, r + root->data));
}

int maxPathSum(struct Node *root)
{
    int res=INT_MIN;
    sum(root,res);
    return res;
}

 