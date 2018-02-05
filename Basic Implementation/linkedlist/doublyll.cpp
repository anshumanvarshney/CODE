/*

For doubly linked lint think for double link because you need to take care of both the link (i.e backward (<-) as 
well as(->) forward with the previous and next stored data

Insert Node in a doubly sorted linked list  After each insertion, the list should be sorted
Insertion at end
Insertion at beg
Insertion at a loc
Insertion after a node
Insertion before a node
Deletion a node
Deletion after a node
Deletion before a node
Reverse
Display
Count
Deallocate

*/

/*
WE CAN USE EVERY SINGLY LL FN TO DOUBLY LL 
*/
/*
Note:

    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }

Node* SortedInsert(Node *head,int data)
{
    Node *temp,*r ;
    temp= new Node;
    temp->data = data;
    if (head == NULL)
    {
        return temp;
    }
    else if (data <= head->data)
    {
        temp->next = head;
        head->prev = temp;
        return temp;
    }
	/*
	or MY logic
		temp=head'
	    while(temp->data <e)
		{
			old= temp;
			temp=temp->link;
		}
		r=new node;
		r->data=e;
		then as usual
		
	*/
    else {
        r= SortedInsert(head->next, data);
        head->next = r;
        r->prev = head;
        return head;
    }
}

Add after a node 
void linklist ::addf(int num)
{
	node *temp,*old,*r;
	int n;
	cout<<"\nEnter the node_after :  ";
	cin>>n;
		temp=p;
		while(temp->data!=n)
		{
			old=temp;
			temp=temp->next;
		}
		r=new node;
		r->prev=temp;
		r->data=num;
		r->next=temp->next;
		r->next->prev=r;
		temp->next=r;
}

ADD before a node

void linklist ::addb(int num)
{
	node *temp,*old,*r;
	int n;
	cout<<"\nEnter the node_after :  ";
	cin>>n;
		temp=p;
		while(temp->data!=n)
		{
			old=temp;
			temp=temp->next;
		}
		r=new node;
		r->prev=old;
		r->data=num;
		r->next=old->next;
		r->next->prev=r;  // or temp->prev=r;
		old->next=r;
}

Delete before a node

void linklist ::delb()
{
	node *temp,*old;
	int n;
	cout<<"\nEnter the node_after :  ";
	cin>>n;
		temp=p;
		while(temp->data!=n)
		{
			old=temp;
			temp=temp->next;
		}
		old->next->prev=old->prev;
		old->prev->next=old->next;
		delete old;
}

Delete after a node

void linklist ::delf()
{
	node *temp,*old;
	int n;
	cout<<"\nEnter the node_after :  ";
	cin>>n;
		temp=p;
		while(temp->data!=n)
		{
			old=temp;
			temp=temp->next;
		}
		
		/*
		or 
		old = temp->next->next;
	    temp->next=old->next;
		
		*/
		temp=temp->next; //because its after a node
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		delete temp;
}
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class linklist
{
private:

struct node
{
  node *prev;
  int data;
  node *next;
}*p;

public:

 linklist();
 void addend(int);
 void addatbeg(int);
 void addafter(int,int);
 void display();
 int count();
 void reverse();
 void del(int);
 ~linklist();

};

linklist::linklist()
{
 p=NULL;
}

void linklist::addend(int num)
{
		node *temp,*r;
         
		 if(p==NULL)
		 {
		      p=new node;
			  p->prev=NULL;  //take care 
		      p->data=num;
		      p->next=NULL;
		  }
		else
		 {
			 temp=p;
		      while(temp->next!=NULL)
			     temp=temp->next;
		      r=new node;
		      r->data=num;
		      r->next=NULL;
			  r->prev=temp;  //
		      temp->next=r;
		   }
}

void linklist::addatbeg(int num)
{
 node *temp;
 temp=new node;
 temp->prev=NULL;
 temp->data=num;
 temp->next=p;
 p->prev=temp;
 p=temp;
}

void linklist::addafter(int num,int loc)
{
 node *temp,*r;
 temp=p;
 for(int i=0;i<loc;i++)
 {
  temp=temp->next;
  if(temp==NULL)
  {
   cout<<"\nThere is less than"<<loc<<"element in the list\n";
   return;
  }
 }
 temp=temp->prev;    //use to get back because addition takes place from previous element (Important)
 r=new node;
 r->data=num;
 r->prev=temp;
 r->next=temp->next; //element that are in temp->next should be in r->next
 r->next->prev=r; //previous part of new node points the new node
 temp->next=r;
} 
/*
void linklist::addafter(int num,int loc)
{
 node *temp,*r,*old;
 temp=p;
 for(int i=0;i<loc;i++)
 {
	old=temp; 
  temp=temp->next;
  if(temp==NULL)
  {
   cout<<"\nThere is less than"<<loc<<"element in the list\n";
   return;
  }
 }
 r=new node;
 r->data=num;
 r->prev=old;
 r->next=old->next//temp; //element that are in temp->next should be in r->next
 old->next=r; //previous part of new node points the new node
 temp->prev=r;
}


*/
//think as a doubly link 

void linklist::display()
{
 node *temp;
 temp=p;
 cout<<endl;
 while(temp!=NULL)
 {
  cout<<temp->data<<" ";
  temp=temp->next;
 }
}

int linklist::count()
{
 node *temp;
 temp=p;
 int c=0;
 while(temp!=NULL)
 {
  temp=temp->next;
  c++;
 }
 return c;
}

void linklist::del(int num)
{
 node *temp;
 temp=p;
 while(temp!=NULL)
 {
	if(temp->data==num)
	{
		if(temp==p)  //if node is to be deleted is first node
		{
			p=temp->next;
			p->prev=NULL;  //note
		}
		else
		{
			if(temp->next==NULL) //if node is to be deleted is last
			{
				temp->prev->next=NULL; //then NULL is stored in next part of the second last node i.e (temp ke previous ke next part mein NULL)
			}
			else                        // if node is to be deleted intermediate
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
			}
			delete temp;
		}
		return;
	}
   temp=temp->next;
 }
 cout<<"\n\nElement "<<num<<"not found";
}


/*
My logic

void linklist::del(int num)
{
 node *temp,*old;
 temp=p;
 while(temp!=NULL)
 {
	if(temp->data==num)
	{
		if(temp==p)  //if node is to be deleted is first node
		{
			p=temp->next;
			p->prev=NULL;  //note
		}
		else
		{
			if(temp->next==NULL)//last node
			{
				old->next=NULL;
			}
			else
			{
				old->next=temp->next;
				temp->next->prev=old;
			}
		}
		delete temp;
		return;
	}
	old=temp;
   temp=temp->next;
 }
 cout<<"\n\nElement "<<num<<"not found";
}

*/
void linklist::reverse()
{
	cout<<"\nReverse order\n";
	 node *last,*temp;
		last= NULL;  
        temp= p;
     while (temp !=  NULL)
     {
		 
     /* swap next and prev for all nodes of 
       doubly linked list */
	   
       last        =  temp->prev;
       temp->prev  =  temp->next;
       temp->next  =  last; 
	   
       temp = temp->prev; //temp=temp->prev;  increment of swapping
     }      
   
     if(last != NULL )//optional to check
        p = last->prev;//p=last->prev;
}

linklist::~linklist()
{
 node *temp;
 temp=p;
 while(temp!=NULL)
 {
  temp=temp->next;
  delete p;
  p=temp;
 }
}

int  main()
{
 linklist o;
	int n,x,l;
	cout<<"\n\n----------DOUBLY LINKED LIST----------\n\n";
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
		o.addend(x);
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
		o.addafter(x,l);
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
