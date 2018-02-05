//to understand this you need to draw a tree first , then implement
http://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
#include<iostream>
using namespace std;
//#define TRUE 1
//#define FALSE 0
struct node      //building a binary search tree
	{
		node *left;
		int data;
		node *right;
	};
	
class  btree
{
   private :
	node *root;           //root of a binary tree
	
   public:
	btree();
	void buildtree(int num);
	void insert(node **sr, int num);
	void search(node **sr, int num, node **par, node **x, int *found);//for balanced O(logn) and for imbalance O(n)
	void remove(int num);
	void rem (node **sr, int num);
	void getheight();
	int height(node *sr);
	void smallest();
	node* sm(node *sr);
	void largest();
	node* lr(node *sr);
	void tnode();
	int tn(node *sr);
	void mirrorimage();
	node* mi(node *sr);
	void tinode();
	int tin(node *sr);
	void tenode();
	int ten(node *sr);
	void display();
	void inorder(node *sr);
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

/*
node *insert(node *sr,int num)
{
	
	if(sr==NULL)    
	{
		sr=new node;
		sr->left=NULL;
		sr->data=num;
		sr->right=NULL;
		return sr;
	}
			//in place of this you can also use newnode function 
			i.e
			if(sr==NULL)    
			{
				return newnode(sr);
			}
	else
	{
		if(num<sr->data)
			sr->left =insert(sr->left,num);
		else
		{ 
	        sr->right =insert(sr->right,num);
        }
	}
	return sr;
}

*/

void btree::insert(node **sr,int num)
{
	if(*sr==NULL)    
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

void btree :: getheight()
{
	cout<<height(root);
}

//do it by drawing tree
int btree :: height (node *sr)
{
	int l,r;
	if(sr==NULL)
	{
		return 0;
	}
	else 
	{
		l= height(sr->left);
		r= height(sr->right);
		return 1+(l > r)?l:r;//return to its calling function
	}
}

void btree :: smallest()
{
	cout<<sm(root)->data;
}

node* btree :: sm(node *sr)//data type is node because we return here root
{
	if(sr==NULL || sr->left ==NULL)
		return sr;
	else
		return sm(sr->left);
}

void btree :: largest()
{
	cout<<lr(root)->data;
}
node* btree :: lr(node *sr)
{
	if(sr==NULL || sr->right ==NULL)
		return sr;
	else
		return lr(sr->right);
}

void btree :: tnode()
{
	cout<<tn(root);
}

int btree :: tn(node *sr)
{
	if(sr==NULL)
		return 0;
	else return (tn(sr->left)+tn(sr->right)+1);
}

void btree :: mirrorimage()
{
	root =mi(root);
}

//for this take eg : 5 3 4 8
node* btree :: mi(node *sr)
{
	node *ptr;
	if(sr!=NULL)
	{
		mi(sr->left);//for every node left child become right child and vice versa
		mi(sr->right);
		ptr=sr->left;
		sr->left=sr->right;
		sr->right=ptr;
	}
}


void btree :: tinode() //11,9,8,13,14
{
	cout<<tin(root);
}

int btree :: tin(node *sr)
{
	if(sr==NULL || (sr->left == NULL && sr->right == NULL))
		return 0;
	else return (tin(sr->left)+tin(sr->right)+1);//1 for root node
}

void btree :: tenode()//7,10,12,15
{
	cout<<ten(root);
}

int btree :: ten(node *sr)
{
	if(sr==NULL ) 
		return 0;
	else 
		if(sr->left == NULL && sr->right == NULL)
			return 1; 
	else return (ten(sr->left)+ten(sr->right));
}

void btree :: remove(int num)
{
	rem(&root,num);
}

void btree::rem(node **sr, int num)
{
	int found;
	node *parent,*x,*xsucc;
	if(*sr==NULL)
	{
		cout<<"\nTree is empty ";
		return;
	}
	parent=x=NULL;
	
	search(sr, num, &parent, &x, &found); //call search fn address passing
	if(found==false)
	{
		cout<<"\nData to be deleted , not found";
		return;
	}	// or we can put condition in else
		//we are basically find min in right sub tree or second sol is max in left sub tree
	if(x->left!=NULL&&x->right!=NULL)  //node with two children case
	{
		parent=x;//address of node that is to be deleted stored in parent 
		xsucc=x->right; //the  node is to be deleted is replaced by successor element,
						//here the address of right child of the node is stored in xsucc
		while(xsucc->left!=NULL)
		{
			parent=xsucc;  // xsucc is stored in x
			xsucc=xsucc->left;  // left child of xsucc stored in xsucc
		}
		x->data=xsucc->data;  //after deletion   
		x=xsucc;
	}
 
	if(x->left==NULL&&x->right==NULL)//no children case 
	{
		if(parent->right==x)
		{
			parent->right=NULL;
		}
		else
		{
			parent->left=NULL;
		}
		delete x;
		return;
	}
	
    if(x->left==NULL&&x->right!=NULL)//only right child case
	{
		if(parent->left==x)
		{
			parent->left=x->right;
		}
		else
		{
			parent->right=x->right;
		}
		delete x;
		return;
	}
	
	if(x->right==NULL&&x->left!=NULL)//only left child case
	{
		if(parent->left==x)
		{
			parent->left=x->left;
		}
		else
		{
			parent->right=x->left;
		}
		delete x;
		return;
	}
	
}

void btree :: search(node **sr, int num, node **par, node **x,int *found) 
//par is pointer to the parent node where data is found
//par and x contains address of parent of the node where the data is found and the address of node itself.  
{
	node *temp;
	temp=*sr;  //sr have address of root
	*found=false;//found is integer pointer it is not a node
	*par=NULL;
	//binary search operation
	while(temp!=NULL) //q holds the address of root node
	{
		if(temp->data==num)           
		{
			*found=true;
			*x=temp;   //i.e address of current node stored in x
			return; // its is returning all the parameter thats why we are using double pointer concept here
		}
			*par=temp; //understand by drawing a tree//same as variable old in ll
		if(temp->data>num)   
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
}

void btree :: display()
{
	inorder(root);
}

void btree :: inorder (node *sr)
{
	if(sr!=NULL)
	{
		inorder(sr->left);
		cout<<(sr->data)<<" ";
		inorder(sr->right);
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

/*
int main()
{
	btree bt;
	int req,i=0,num,a[]={11,9,13,8,10,12,14,15,7};
	
	while(i<=8)
	{
		bt.buildtree(a[i]);
		i++;
	}
	cout<<"\nHeight of the binary tree :";
	bt.getheight();
	cout<<"\nSmallest element of the binary tree :";
	bt.smallest();
	cout<<"\nLargest element of the binary tree :";
	bt.largest();
	cout<<"\nTotal nodes of the binary tree :";
	bt.tnode();
	cout<<"\nTotal internal nodes of the binary tree :";
	bt.tinode();
	cout<<"\nTotal external nodes of the binary tree :";
	bt.tenode();
	cout<<"\nTree inorder :";
	bt.display();
	cout<<"\nBinary tree before deletion :";
	bt.display();
	bt.remove(10);
	cout<<"\nBinary tree after deletion no child case:";
	bt.display();
	bt.remove(14);
	cout<<"\nBinary tree after deletion right child case:";
	bt.display();
	bt.remove(8);
	cout<<"\nBinary tree after deletion left child case :";
	bt.display();
	bt.remove(13);
	cout<<"\nBinary tree after deletion both child case :";
	bt.display();
	cout<<"\nMirror image inorder :";
	bt.mirrorimage();
	bt.display();
	return 0;
}

*/
//for better understanding

int main()
{
	btree bt;
	int req,i=0,num,a[]={11,9,13,8,10,12,16,14,18,7,15};
	
	while(i<=10)
	{
		bt.buildtree(a[i]);
		i++;
	}
	cout<<"\nHeight of the binary tree :";
	bt.getheight();
	cout<<"\nSmallest element of the binary tree :";
	bt.smallest();
	cout<<"\nLargest element of the binary tree :";
	bt.largest();
	cout<<"\nTotal nodes of the binary tree :";
	bt.tnode();
	cout<<"\nTotal internal nodes of the binary tree :";
	bt.tinode();
	cout<<"\nTotal external nodes of the binary tree :";
	bt.tenode();
	cout<<"\nTree inorder :";
	bt.display();
	cout<<"\nBinary tree before deletion :";
	bt.display();
	bt.remove(10);
	cout<<"\nBinary tree after deletion no child case:";
	bt.display();
	bt.remove(14);
	cout<<"\nBinary tree after deletion right child case:";
	bt.display();
	bt.remove(8);
	cout<<"\nBinary tree after deletion left child case :";
	bt.display();
	bt.remove(13);
	cout<<"\nBinary tree after deletion both child case :";
	bt.display();
	cout<<"\nMirror image inorder :";
	bt.mirrorimage();
	bt.display();
	return 0;
}
