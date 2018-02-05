//list should be in ascending order

/*
Using recursion

  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }

Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node *temp;
    temp=NULL;
    if (headA == NULL) {
        return headB;
    } else if (headB== NULL) {
        return headA;
    }

    if (headA->data < headB->data) {
        temp=headA;
        temp->next = MergeLists(headA->next, headB);
        
    } else {
        temp=headB;
        temp->next = MergeLists(headA, headB->next);
        
    }
    return temp;
    
}  
*/

#include<iostream>
using namespace std;

class list
{
	private:
	struct node
	{
		int data;
		node *link;
	}*p;
	public:
	list();
	//void get();
	void add(int);
	void show();
	int count();
	void merge(list &,list &);
	//void compare(list &,list &);
	~list();
};

list :: list()
{
	p=NULL;
}
void list::add(int num)
{
	node *temp,*r;
	if(p==NULL)
	{
		p=new node;
		p->data=num;
		p->link=NULL;
	}
	else
	{
		temp=p;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		r=new node;
		r->data=num;
		r->link=NULL; //r->link=temp->link because temp->link points to nULL before it
		temp->link=r;
	}
}

void list::show()
{
	node *temp;
	temp=p;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}

int list:: count()
{
	node *temp;
	temp=p;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	return c;
}

void list::get()
{
	int n;
	char ch;
	do
	{
    	cout<<"\n Enter value :";
		cin>>n;
		add(n);
		cout<<"\nDo you want to add more node :";
		cin>>ch;
    }while(ch=='y'||ch=='Y');
}

list :: ~list()
{
	node *temp;
	temp=p;
	while(temp!=NULL)
	{
		temp=temp->link;
		delete p;
		p=temp;
	}
}

void list ::merge(list &l1,list &l2)
{
	node *z;
	z=NULL;  //we have to do that because node should be empty before insertion
	if(l1.p==NULL && l2.p==NULL)
		return;
	while(l1.p!=NULL && l2.p!=NULL)
	{
		if(p==NULL)
		{
			p=new node;
			z=p;          //to make z is first node 
		}
		else
		{
			z->link=new node; // node are formed
			z=z->link;
		}
		if(l1.p->data<l2.p->data)
	    {
		 z->data=l1.p->data;
		 l1.p=l1.p->link;
	    }
        else
        {
			if(l1.p->data>l2.p->data)
		    {
		     z->data=l2.p->data;
		     l2.p =l2.p->link;
	        }
			else
			{
				if(l1.p->data==l2.p->data)
				{
					z->data=l2.p->data;
					l1.p=l1.p->link;
					l2.p=l2.p->link;
				}
			}
	    }		
    }
	while(l1.p!=NULL)
	{
		z->link=new node;
		z=z->link;    
		z->data=l1.p->data;
		l1.p=l1.p->link;
	}
	while(l2.p!=NULL)
	{
		z->link=new node;
		z=z->link;
		z->data=l2.p->data;
		l2.p=l2.p->link;
	}
	z->link=NULL; //last element (don't forget)
}


int main()
{
	list l1,l2,l3;
	//cout<<"\nEnter node in list 1 :";
	//l1.get();
	//cout<<"\nElements are :";
	l1.add(5);
	l1.add(3);
	l1.add(2);
	l1.show();
	cout<<"\nNo. of element in list 1 :";
	int n;
	n=l1.count();
	cout<<n<<"\n";
	//cout<<"\nEnter node in list 2 :";
	//l2.get();
	//cout<<"\nElements are :";
	l2.add(2);
	l2.add(1);
	l2.add(5);
	l2.show();
	cout<<"\nNo. of element in list 2 :";
	int m;
	m=l1.count();
	cout<<m<<"\n";
	cout<<"\nAfter Merging of two list  :";
	l3.merge(l1,l2);
	l3.show();
	//l3.compare(l1,l2);
	cout<<"\nNo of element after merging :"<<l3.count();
}