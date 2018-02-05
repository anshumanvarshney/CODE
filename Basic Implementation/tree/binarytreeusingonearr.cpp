#include<iostream>
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
   public:
	btree(char *a,int size);
	void buildtree(int index);
	btree::node* insert(char *a,int index);//because structure inside class
	void display();
	void inorder(node *sr);
	~btree();
	void del(node *sr);
};

btree::btree(char *a,int size)  //size = no. of nodes
{
	root=NULL;
	arr=new char[size];
	int i;
	for(i=0;i<size;i++)
	{
		*(arr+i)=*(a+i);
	}
}

void btree:: buildtree(int index)
{
	root=insert(arr,index);
}

btree::node* btree::insert(char *a,int index)
{
	node *temp=NULL;
	if(*(a+index)!='\0')    //value at particular index
	{
		temp=new node;
		temp->left=insert(a,2*index+1);//it is not like this *(2*insex +1) because it does not have data in left and right array
		temp->data=*(a+index);
		temp->right=insert(a,2*index+2);
	}
	return temp;
}
void btree::display()
{
	inorder(root);
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
	char a[]={'A','B','C','D','E','F','G','\0','\0','H','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	int sz=sizeof(a);
	btree bt(a,sz);
	bt.buildtree(0);
	cout<<"\nIn-order Traversal :"<<"\n";
	bt.display();
	return 0;
}
