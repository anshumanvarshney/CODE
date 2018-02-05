/*
Find a pair with given target in BST
Given a Binary Search Tree and a target sum, write a function that returns true if there is a pair with 
sum equals to target sum, otherwise return false

Example:
Input:
2
7 10
1 2 3 4 5 6 7
7 33
15 10 20 8 12 16 25  
Output:
1
1
*/

void inorder(node *root,int a[],int &c)
{
	if(root!=NULL)
	{
		inorder(root->left,a,c)'
		a[c++]=root->data;
		inorder(root->right,a,c);
	}
}

bool ispairsum(node *root,int sum)
{
	int a[1000];
	int c=0;
	inorder(root,a,c);
	int j=0,k=c-1;
	int s=a[j]+a[k];
	while(j<k)
	{
		if(s>sum)
		{
			s-=a[k];
			k--;
			s+=a[k];
		}
		else if(s<sum)
		{
			s-=a[j];
			j++;
			s+=a[j];
		}
		else if(s==sum) return true;
	}
}
