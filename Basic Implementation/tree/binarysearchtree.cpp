/*
traversal of binary tree
1-Depth order(inorder, preorder, postorder)
2-Level order (level by level)
*/

#include<bits/stdc++.h>
using namespace std;

class  btree
{
   private :
	struct node      //building a binary search tree
	{
		node *left;
		int data;
		node *right;
	}*root;           //root of a binary tree
	
   public:
	btree();
	void buildtree(int num);
	void insert(node **sr,int num);
	int height(node *sr);
	void traversal();
	void inorder(node *sr);
	void preorder(node *sr);
	void postorder(node *sr);
	void levelorder(node *sr);
	void del(node *sr);
	~btree();
};

btree::btree()  
{
	root=NULL;
}

void btree::buildtree(int num)
{
	insert(&root,num);
}

void btree::insert(node **sr,int num)
{
	if(*sr==NULL)// making of 'root node' in every recursion     
	{
		*sr=new node;
		(*sr)->left=NULL;
		(*sr)->data=num;
		(*sr)->right=NULL;
	}
	else
	{
		if(num<(*sr)->data)
		{
			insert(&((*sr)->left),num);
		}
		else
		{ 
	        insert(&((*sr)->right),num);
        }
	}
}

int btree :: height (node *sr)
{
	int l,r;
	if(sr==NULL)
	{
		return 0;
	}
	else 
	{
		l=height (sr->left); //recursive call
		r=height (sr->right);
		if(l>r)
			return (l+1);
		else return (r+1);
	}
}

void btree::traversal()
{
	cout<<"\nHeight :";
	int t=height(root);
	cout<<t;
	cout<<"\nIno-rder Traversal :";
	inorder(root);
	cout<<"\nPre-order Traversal :";
	preorder(root);
	cout<<"\nPostorder Traversal :";
	postorder(root);
	cout<<"\nLevel Traversal :";
	levelorder(root);
	
}
void btree :: inorder (node *sr)//because BST is recursive in nature
{
	if(sr!=NULL)
	{
		inorder(sr->left);
		cout<<(sr->data)<<" ";
		inorder(sr->right);
	}
}
void btree :: preorder (node *sr)
{
	if(sr!=NULL)
	{
		cout<<(sr->data)<<" ";
		preorder(sr->left);
		preorder(sr->right);
	}
}
void btree :: postorder (node *sr)
{
	if(sr!=NULL)
	{
		postorder(sr->left);
		postorder(sr->right);
		cout<<(sr->data)<<" ";
	}
}

void btree::levelorder(node *root)
{
	if(root==NULL) return;
	queue<node *> q;//queue of node i.e tree
	q.push(root);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		cout<< root->data <<" ";
		if(root->left!=NULL)
			q.push(root->left);
		if(root->right!=NULL)
			q.push(root->right);
	}
}

btree :: ~btree() // deallocate memory
{
	del(root);
}

void btree::del(node *sr)
{
	if(sr!=NULL)
	{
		del(sr->left);
		del(sr->right);
	}
	delete sr;
}
int main()
{
	btree bt;
	int req,i=0,num;
	cout<<"Specify the number of items to be inserted :";
	cin>>req;
	while(++i<=req)
	{
		cout<<"\nEnter data :";
		cin>>num;
		bt.buildtree(num);
	}
	bt.traversal();
	return 0;
}

