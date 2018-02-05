#include<iostream>
using namespace std;

struct node                      // define above to avoid error name 'node does not name a type'
{
	int data;
	int bf;
	node *left;
	node *right;
};

class atree
{
	private:
	 node *root;
	public:
	 atree();
	 node* insert(int data,int *h);
	 node* buildtree(node *root,int data,int *h);
	 void display(node *root);
	 node* deldata(node *root,int data,int *h);
	 node* del(node *n,node *root, int *h);
	 node* balright(node *root,int *h);
	 node* balleft(node *root,int *h);
	 void setroot(node *avl);
	 ~atree();
	 void deltree(node *root);
};

atree::atree()
{
	root=NULL;
}

node* atree::insert(int data,int *h)
{
	root=buildtree(root,data,h);
	return root;
}

/*h is the address of a variable that is used as a flag to check 
whether there is a need of balancing the tree after addition of new node */

node* atree::buildtree(node *root,int data,int *h)
{
	node *node1,*node2;
	if(root==NULL)
	{
		root=new node;
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		root->bf=0;
		*h=true;// i.e no need to balancing the tree
		return(root);
	}
	if(data<root->data)
	{
		root->left=buildtree(root->left,data,h);
		
		if(*h) // check whether there is a need of balancing
		{
			switch(root->bf)
			{
				case 1: // if the bf = 1 i.e height of (left sub tree > right sub tree)
				 node1=root->left;
				 if(node1->bf==1)
				 {
					cout<<"\nRight Rotation";
					root->left=node1->right;
					node1->right=root;
					root->bf=0;
					root=node1;
				 }
				 else
				 {
					cout<<"\nDouble rotation, left then right";
					node2=node1->right;
					node1->right=node2->left;
					node2->left=node1;
					root->left=node2->right;
					node2->right=root;
					if(node2->bf==1)
					{
						root->bf=-1;
					}
					else
					{
						root->bf=0;
					}
					if(node2->bf==-1)
					{
						node1->bf=1;
					}
					else
					{
						node1->bf=0;
					}
					root=node2;
				 }
				 root->bf=0; // after addition 
				 *h=false;
				 break;
				case 0:
				 root->bf=1; //left addition 
				 break;
				case -1:
				 root->bf=0;//-1 + 1 = 0 // left addition
				 *h=false;
			}
		}
	}
	if(data>root->data)
    {
    	root->right=buildtree(root->right,data,h);
     	if(*h)
	    {
		 switch(root->bf)
		 {
			case 1:
			 root->bf=0;
			 *h=false;
			 break;
			case 0:
			 root->bf=-1;
			 break;
			case -1:
			 node1=root->right;
			 if(node1->bf==-1)
				{
					cout<<"\nLeft Rotation";
					root->right=node1->left;
					node1->left=root;
					root->bf=0;
					root=node1;
				 }
				 else
				 {
					cout<<"\nDouble rotation, right then left";
					node2=node1->left;
					node1->left=node2->right;
					node2->right=node1;
					root->right=node2->left;
					node2->left=root;
					if(node2->bf==-1)
					{
						root->bf=1;
					}
					else
					{
						root->bf=0;
					}
					if(node2->bf==1)
					{
						node1->bf=-1;
					}
					else
					{
						node1->bf=0;
					}
					root=node2;
		          }
		        root->bf=0;
				*h=false;
		 }
	   }
	}
	return (root);
}
//in order traversal
void atree:: display(node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<root->data<<" ";
		display(root->right);
	}
}	

node* atree::deldata(node *root,int data,int *h)
{
	node *n;
	if(root==NULL)
	{
		cout<<"\nNo such data";
		return(root);
	}
	else
	{
		if(data<root->data)
	    {
			root->left=deldata(root->left,data,h);
			if(*h)
			{
				root=balright(root,h);
			}
		}
		else
		{
			if(data>root->data)
			{
				root->right=deldata(root->right,data,h);
				if(*h)
				{
					root=balleft(root,h);
				}
			}
			else
			{
				n=root;
				if(n->right==NULL)
				{
					root=n->left;
					*h=true;
					delete(n);
				}
				else
				{
					if(n->left==NULL)
					{
						root=n->right;
						*h=true;
						delete(n);
					}
					else
					{
						n->right=del(n->right,n,h);
						if(*h)
						{
							root=balleft(root,h);
						}
					}
				}
			}
		}
	}
	return(root);
}

node* atree::del(node *succ,node *n,int *h)
{
	node *temp=succ;
	if(succ->left!=NULL)
	{
		succ->left=del(succ->left, n, h);
		if(*h)
		{
			succ=balright(succ,h);
		}
	}
	else
	{
		temp=succ;
		n->data=succ->data;
		succ=succ->right;
		delete(temp);
		*h=true;
	}
	return(succ);
}

node* atree::balright(node *root,int *h)
{
	node *temp1,*temp2;
	switch(root->bf)
			{
				case 1:
				 root->bf=1;
				 break;
				case 0:
				 root->bf=-1;
				 *h=false;
				 break;
				case -1:
				 temp1=root->right;
				 if(temp1->bf<=0)
				 {
					cout<<"\nLeft Rotation";
					root->right=temp1->left;
					temp1->left=root;
					if(temp1->bf==0)
					{
						root->bf=-1;
						temp1->bf=1;
						*h=false;
					}
				    else
					{
						root->bf=temp1->bf=0;
					}
					root=temp1;
				 }
				 else
				 {
					cout<<"\nDouble rotation, right then left";
					temp2=temp1->left;
					temp1->left=temp2->right;
					temp2->right=temp1;
					root->right=temp2->left;
					temp2->left=root;
					if(temp2->bf==-1)
					{
						root->bf=1;
					}
					else
					{
						root->bf=0;
					}
					if(temp2->bf==1)
					{
						temp1->bf=-1;
					}
					else
					{
						temp1->bf=0;
					}
					root=temp2;
					temp2->bf=0;
		          }
	}
	return (root);
}
			     
node* atree::balleft(node *root,int *h)
{
	node *temp1,*temp2;
	switch(root->bf)
			{
				case -1:
				 root->bf=0;
				 break;
				case 0:
				 root->bf=1;
				 *h=false;
				 break;
				case 1:
				 temp1=root->left;
				 if(temp1->bf>=0)
				 {
					cout<<"\nRight Rotation";
					root->left=temp1->right;
					temp1->right=root;
					if(temp1->bf==0)
					{
						root->bf=1;
						temp1->bf=-1;
						*h=false;
					}
				    else
					{
						root->bf=temp1->bf=0;
					}
					root=temp1;
				 }
				 else
				 {
					cout<<"\nDouble rotation, left then right";
					temp2=temp1->right;
					temp1->right=temp2->left;
					temp2->left=temp1;
					root->left=temp2->right;
					temp2->right=root;
					if(temp2->bf==1)
					{
						root->bf=-1;
					}
					else
					{
						root->bf=0;
					}
					if(temp2->bf==-1)
					{
						temp1->bf=1;
					}
					else
					{
						temp1->bf=0;
					}
					root=temp2;
				    temp2->bf=0;
				}
			}
	return (root);
}
	
void atree::setroot(node *avl)
{
	root = avl;
}

atree::~atree()
{
	deltree(root);
}

void atree::deltree(node *root)
{
	if(root!=NULL)
	{
		deltree(root->left);
		deltree(root->right);
	}
	delete(root);
}

int main()
{
	atree at;
	node *avl=NULL;
	int h;
	avl=at.insert(20,&h);
	at.setroot(avl);
	avl=at.insert(6,&h);
	at.setroot(avl);
	avl=at.insert(29,&h);
	at.setroot(avl);
	avl=at.insert(5,&h);
	at.setroot(avl);
	avl=at.insert(12,&h);
	at.setroot(avl);
	avl=at.insert(25,&h);
	at.setroot(avl);
	avl=at.insert(32,&h);
	at.setroot(avl);
	avl=at.insert(10,&h);
	at.setroot(avl);
	avl=at.insert(15,&h);
	at.setroot(avl);
	avl=at.insert(27,&h);
	at.setroot(avl);
	avl=at.insert(13,&h);
	at.setroot(avl);
	cout<<"\n"<<"AVL tree:\n";
	at.display(avl);
	avl=at.deldata(avl,20,&h);
	at.setroot(avl);
	avl=at.deldata(avl,12,&h);
	at.setroot(avl);
	cout<<"\n"<<"AVL tree after deletion of a node:\n";
	at.display(avl);
	return 0;
}