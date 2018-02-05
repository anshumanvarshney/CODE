/*#include<iostream>
using namespace std;

class  btree
{
   private :
	struct node      //building a binary tree
	{
		node *left;
		int data;
		node *right;
	}*root;           //root of a binary tree
	char *arr;  //Because we are using array here
	int *lc;
	int *rc;
   public:
	btree(char *a,int *l ,int *r,int size);
	void buildtree(int index);
	btree::node* insert(char *a,int *l ,int *r,int index);
	void display();
	void inorder(node *sr);
	~btree();
	void del(node *sr);
};

btree::btree(char *a,int *l,int *r,int size)  //size = no. of nodes
{
	root=NULL;
	arr=new char[size];
	lc=new int[size];
	rc=new int[size];
	int i;
	for(i=0;i<size;i++)
	{
		*(arr+i)=*(a+i);
		*(lc+i)=*(l+i);
		*(rc+i)=*(r+i);
	}
}

void btree:: buildtree(int index)
{
	root=insert(arr,lc,rc,index);
}

btree::node* btree::insert(char *a,int *l,int *r,int index)
{
	node *temp=NULL; //otherwise it takes garbage value
	if(index!=-1)    //-1 belongs to NULL i.e leaf node
	{
		temp=new node;
		temp->left=insert(a,l,r,*(l+index));
		temp->data=*(a+index);
		temp->right=insert(a,l,r,*(r+index));
	}
	return temp;
}
void btree::display()
{
	inorder(root);  // here we are passing the address of root node
}
void btree :: inorder (node *sr)
{
	if(sr!=NULL)
	{
		inorder(sr->left);
		cout<<char(sr->data)<<" ";
		inorder(sr->right);
	}
}

btree :: ~btree() // deallocate memory
{
	delete arr;
	delete lc;
	delete rc;
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
	char a[]={'A','B','C','D','E','F','G','\0','\0','H'};
	int l[]={1,3,5,-1,9,-1,-1,-1,-1,-1};
	int r[]={2,4,6,-1,-1,-1,-1,-1,-1,-1};
	int sz=sizeof(a);
	btree bt(a,l,r,sz);
	bt.buildtree(0);
	cout<<"\nIn-order Traversal :"<<"\n";
	bt.display();
	return 0;
}
*/
//or by defining structure above the class

#include<iostream>
using namespace std;

struct node      //building a binary tree
{
	node *left;
	int data;
	node *right;
};

class  btree
{
   private :
	node *root;           //root of a binary tree
	char *arr;  //Because we are using array here
	int *lc;
	int *rc;
   public:
	btree(char *a,int *l ,int *r,int size);
	void buildtree(int index);
	node* insert(char *a,int *l ,int *r,int index);  //to avoid error like 'node is not define ' use structure globally
	void display();
	void inorder(node *sr);
	~btree();
	void del(node *sr);
};


btree::btree(char *a,int *l,int *r,int size)  //size = no. of nodes
{
	root=NULL;
	arr=new char[size];
	lc=new int[size];
	rc=new int[size];
	int i;
	for(i=0;i<size;i++)
	{
		*(arr+i)=*(a+i);
		*(lc+i)=*(l+i);
		*(rc+i)=*(r+i);
	}
}

void btree:: buildtree(int index)
{
	root=insert(arr,lc,rc,index);
}

node* btree::insert(char *a,int *l,int *r,int index)
{
	node *temp=NULL; //otherwise it takes garbage value
	if(index!=-1)    //-1 belongs to NULL i.e leaf node
	{
		temp=new node;
		temp->left=insert(a,l,r,*(l+index));
		temp->data=*(a+index);
		temp->right=insert(a,l,r,*(r+index));
	}
	return temp;
}
void btree::display()
{
	inorder(root);  // here we are passing the address of root node
}
void btree :: inorder (node *sr)
{
	if(sr!=NULL)
	{
		inorder(sr->left);
		cout<<char(sr->data)<<" ";
		inorder(sr->right);
	}
}

btree :: ~btree() // deallocate memory
{
	delete arr;
	delete lc;
	delete rc;
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
	char a[]={'A','B','C','D','E','F','G','\0','\0','H'};
	int l[]= {1,   3,  5, -1,  9, -1, -1,  -1,  -1, -1};
	int r[]= {2,   4,  6, -1, -1, -1, -1,  -1,  -1, -1};
	int sz=sizeof(a); // directly it find size of the char array which contains 1 byte per element
	//but in case of integer array you have to use counter or sz/n 'n' depends on compiler 2,4
	btree bt(a,l,r,sz);
	bt.buildtree(0);
	cout<<"\nIn-order Traversal :"<<"\n";
	bt.display();
	return 0;
}

 