/*
SINGLY LL

Insertion at last
Insertion at beginning
Insertion after a location
Insertion after given node 
Insertion before given node
Deletion of a node
Delete at a given position
Deletion of node by given position form tail
Reverse LL
Reverse using stack;
Display 
Count Iterative and Recursive
Deallocation of memory
Bubble Sort
Selection Sort
Merge using Iterator and Recursion
Compare two ll (i.e Same or Not) using iteration and recursion
*/

/*
Insertion before given node

void list:: addb(int n,int num)//n=node
{
	node *temp,*old,*r;
	temp=head;
	while(temp->data!=n)
	{
		old=temp;
		temp=temp->next;
	}
	r=new node;
	r->data=num;
	r->next=old->next;
	old->next=r;
}

Insertion after given node

void list:: addf(int n,int num)//n=node
{
	node *temp,*old,*r;
	temp=head;
	while(temp->data!=n)
	{
		old=temp;
		temp=temp->next;
	}
	r=new node;
	r->data=num;
	r->next=temp->next;
	temp->next=r;
}
*/

/*reverse using stack
void list::reverse()
{
	if(head==NULL)
		return;
	stack<struct node*> s ;
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		s.push(temp);  //pushing the references
		temp=temp->next;
	}
	temp=s.top();  //for first element
	head=temp;//for assigning head of ll
	s.pop();
	while(!s.empty())
	{
		temp->next=s.top();
		s.pop();
		temp=temp->next;
	}
	temp->next=NULL; // next node should be NULL
}
*/

/*Deletion at given position

void list:: Delete(int position)
{
 
    node *temp,*old;
    temp=p;
    for(int i=0;i<position;i++)
    {
		old=temp;
		temp=temp->link;
    }
	if(position==0)//loop will not run then 
	{
		p=temp->link;
	}
	else
	{
		old->link=temp->link;
	}
	
	delete temp;
	 
}
*/

/*
Deletion of node by given position form tail
	Sample Input

1 -> 3 -> 5 -> 6 -> NULL, positionFromTail = 0
1 -> 3 -> 5 -> 6 -> NULL, positionFromTail = 2
Sample Output

6
3

int GetNode(Node *head,int positionFromTail)
{

  
    Node *temp2;
	temp2=head;
	int c=0;
	while(temp2!=NULL)   // here we can't use temp->link!=NULL because we have to display last value also;
	{
		c++;
		temp2=temp2->next;
	}
     Node *temp;
    temp=head;
    int i=0;
   positionFromTail=c-positionFromTail;
   while(temp!=NULL)
    {
		i++;
       if(i==positionFromTail)
       {
           break;
       }
	   temp=temp->next;
    }
    return temp->data;
}



*/

#include<iostream>
#include<cstdlib>
using namespace std;

class list
{
	private:
	struct node
	{
		int data;
		node *link;
	}*p;          //p always points to first element;
	public:
	list();
	void append(int);
	void addatbeg(int);
	void addmid(int,int);
	void display();
	void count();
	void del(int);
	void reverse();
	~list();
};

list::list()
{
	p=NULL;
}
void list::append(int num)
{
	node *temp,*r;
	if(p==NULL)
	{
		p=new node;
		p->data = num;
		p->link=NULL;
	}
	else
	{
		temp=p;
		while(temp->link!=NULL) // we can't use temp!=NULL because here we have to append through its address;
			temp=temp->link;
		
		r=new node;
		r->data=num;
		r->link=NULL;
		temp->link=r;
        
	}
}

void list::addatbeg(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
	temp->link=p;
	p=temp;
}
void list::addmid(int loc,int num)
{
	node *temp,*r;
	temp=p;
	int i;
	for(i=0;i<loc-1;i++)
	{
		temp=temp->link;
		if(temp==NULL)
		{
			cout<<"/nThere is no element after "<<loc<<" this/n";
		}
	}
	r=new node;
	r->data=num;
	r->link=temp->link;
	temp->link=r;
}

void list::display()
{
	node *temp;
	temp=p;
	while(temp!=NULL)   // here we can't use temp->link!=NULL because we have to display last value also;
	{
		cout<<temp->data<<" "; 
		temp=temp->link;
	}
}

void list::count()
{
	node *temp;
	temp=p;
	int c=0;
	cout<<"\nTotal number of elements:";
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	cout<<c<<"\n";
}
/*
or recursive
also called length of linked list 
void list ::Count(p)
{
    if (p== NULL)
        return 0;
    return 1 + Count(p->link);
}
*/

void list::del(int num)
{
	node *temp,*old;
	temp=p;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==p)
			{
				p=temp->link;
			}
			else
			{
				old->link=temp->link;
			}
		 delete temp;
		 return;                       //otherwise element not found printed all the time
		}
        else
		{
			old=temp;
			temp=temp->link;
		}			
	}
	cout<<"\nElement "<<num<<" not found\n";
}

void list::reverse()
{
	cout<<"\nReverse order\n";
	node *temp,*last,*s;
	temp=p;
	last=NULL;
	while(temp!=NULL)
	{
		s=last;
		last=temp;
		temp=temp->link;
		last->link=s;       //while executing first time (firstelement->link=NULL) ,second time secondele->firtelement
	}
	p=last;//head of a ll is last element now 
	/*  for printing in reversing order
	 while(last!=NULL)
        {
        cout<<last->data<<"\n";
        last=last->link;
    }
	*/
	//recursive method http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/
}
list::~list()
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


int main()
{
	list o;
   int n,x,l;
	cout<<"\n\n----------SINGLY LINKED LIST----------\n\n";
while(true)
{
	cout<<"\n\nOPERATIONS : Press --\n\n1- Insertion from end\n2-Insertion from beginning\n3-Insertion at any location\n4-Display\n5-Delete any node\n6-Count the nodes\n7-Reverse the list\n8-Exit\n\nEnter :";
	cin>>n;
	switch(n)
	{
	case 1:
	{
		cout<<"\nEnter the element to be added:";
		cin>>x;
		o.append(x);
		break;
	}
	case 2:
	{
		cout<<"\nEnter the element to be added:";
		cin>>x;
		o.addatbeg(x);
		break;
	}case 3:
	{
		cout<<"\nEnter the element to be added:";
		cin>>x;
		cout<<"\nEnter location:";
		cin>>l;
		o.addmid(l,x);
		break;
	}
	case 4:
	{
		cout<<"\nElements are:";
		o.display();
		break;
	}
	case 5:
	{
		cout<<"\nEnter the element to be deleted:";
		cin>>x;
		o.del(x);
		break;
	}
	case 6:
	{
		o.count();
		break;
	}
	case 7:
	{
		o.reverse();
		break;
	}
	case 8:
	{
		exit(0);
	}
    }
}	
}