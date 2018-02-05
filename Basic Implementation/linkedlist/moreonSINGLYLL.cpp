



#include <iostream>
using namespace std;

struct node
{
	int data;
	node*link;
};

class list
{
	private:
	node *p;//p==head//no need in this question
	public:
	list();
	void insert(node **p,int);
	int stcmp(node *a,node *b);
	int compare(node *a,node *b);
	node *MergeLists(node *a,node *b);//returning structure variable
	void alter(node *a,node **b);
	void copy(node *a,node **b);
	void concat(node *a,node **b);
	void merge(node *a,node *b,node **temp);
	void merg(node *a,node *b,node **temp);
	void disp(node *p);
	~list();
};

list::list()
{
	p=NULL;
}

void list ::insert(node **p,int data)
{  
    node *temp,*r;
	if((*p)==NULL)
	{
		(*p)=new node;
		(*p)->data=data;
		(*p)->link=NULL;
	}
	else
	{
		temp=(*p);
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
	r=new node;
	r->data  = data;
	r->link = NULL;
	temp->link=r;
	}	
}

/*
void list::append(node **p , int num)
{
	if(*p==NULL)
	{
		(*p)=new node;
		(*p)->data=num;
		(*p)->link=NULL;
	}
	else 
		append(&((*p)->link),num);
}
*/

//reverse using two pointer
void reverse(node** head)
{
    node *prev   = NULL;
    node *current = *head;
    node *next;
    while (current != NULL)
    {
        next  = current->link;  
        current->link = prev;   
        prev = current;
        current = next;
    }
    *head = prev;
}

//reverse using stack
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
//another way
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

//merge of two list into third list
/*void list::merge(node *a,node *b,node **temp)
{
	while(a!=NULL && b!=NULL)
	{
		if(a->data > b->data)
		{
			insert(temp,b->data);
			b=b->link;
		}
		else if(a->data < b->data)
		{
			insert(temp,a->data);
			a=a->link;
		}
		else if(a->data == b->data)
		{
			insert(temp,a->data);
			insert(temp,b->data);
			a=a->link;
			b=b->link;
		}
	}
		while(a!=NULL)
		{
			insert(temp,a->data);
			a=a->link;
		}
		while(b!=NULL)
		{
			insert(temp,b->data);
			b=b->link;
		}
}*/

//similar to concat -->merge only for concept
void list::merg(node *a,node *b,node **temp)
{
	while(a!=NULL) 
	{
		insert(temp,a->data);
		a=a->link;
	}
	while(b!=NULL)
	{
		insert(temp,b->data);
		b=b->link;
	}
}


//compare (same or not same)using recursion
int list::compare(node *headA, node* headB)
{
   
    if(headA==NULL && headB==NULL)
        return 1;
    else
        {
        if(headA==NULL || headB==NULL)
                    return 0;
         if(headA->data != headB->data)
                     return 0;
        else
            return compare(headA->link,headB->link);//recursion means while loop
    }
    return 0;
}

//compare without using recursion
int compare(node *a,node *b)
{
	while(a!=NULL && b!=NULL && a->data == b->data)
	{
		a=a->next;
		b=b->next;
	}
	if (a!=NULL && b==NULL) return 0;
	if(a==NULL && b!=NULL) return 0;
	
	return 1;
}


/* headA contain concat of ll and headB contain nothing(because of last statement *b=NULL becasue of *b is passed by address)
void list :: concat(node *a,node **b)
{
	node *temp;
	if(a==NULL) //if first ll is empty
	{
		a=*b;//a conatins b ll
	}
	else
	{//if both ll are non-empty
		if(*b!=NULL)
		{
			temp=a;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			//concatenate second string after first
			temp->link=*b;
		}
	}
	*b=NULL;	//it cause ll b is set to NULL
}
*/
//headA contain concat and headB as it is
void concat(node *a,node *b)
{
	node *temp;
	temp=a;
	if(temp==NULL)
		a=b;		
	while( temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=b;
}
/*
void list :: fun(list &l)
{
	copy(p,&l.p);
}
/*if object is passing for copying to another object
eg:
in main program
node *a;
a=NULL;
l.append(&a,4);
a=NULL;
m.append(&b,4);
l.fn(&n);
so n having same member as l 
*/

/*no need 
Node * MergeLists(Node *list1, Node *list2) {
  if (!list1) return list2;
  if (!list2) return list1;
  
  Node *head;
  if (list1->data < list2->data) {
    head = list1;
  } else {
    head = list2;
    list2 = list1;
    list1 = head;
  }
  while(list1->next && list2) {
    if (list1->next->data > list2->data) {
      Node *tmp = list1->next;
      list1->next = list2;
      list2 = tmp;
    }
    list1 = list1->next;
  } 
  if (!list1->next) list1->next = list2;
  return head;
}
*/

void copy(node *head,node **temp)
{
	*temp=NULL;	
	if( head!=NULL)
	{	
        (*temp)=new node;
		(*temp)->data=head->data;
		copy(head->next,&(*temp)->next);//recursion means it returns back
	}
}

/*
node* copy(node *head)
{
	node *temp=NULL;	
	if( head!=NULL)
	{	
        temp=new node;
		temp->data=head->data;
		temp->next=copy(head->next);//head as it is in temp only list moving
	}
	return temp;
}
int main()
node *a=copy(head);
disp(a);
*/

//merge at alternate position

//it only merge into one of the ll a or b it does not create any ll
node* list:: MergeLists(node *headA, node* headB)
{
    node *temp;
    temp=NULL;
    if (headA == NULL) {
        return headB;
    } else if (headB== NULL) {
        return headA;
    }

    if (headA->data < headB->data) {
        temp=headA;//every time head of ll assigned
        temp->link = MergeLists(headA->link, headB);
        
    } else {// don't put here condition like if(headA->data > headB->data) because if 2 element are equal then there should be problem
        temp=headB;
        temp->link = MergeLists(headA, headB->link);
        
    }
    return temp ;   
}


void list::disp(node *p)
{
	node *temp;
	temp=p;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<"\n";
	
}

/*
int list ::count(node *p)
{
    if (p== NULL)
        return 0;
    return 1 + count(p->link);
}


*/

/*
void list::display(node *p)
{
		cout<<p->data<<" ";
		if(p->link==NULL)
		{
			return;
		}
		display(p->link);
}
*/

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

int main()
{
	list l;
	node *a,*b,*c,*d;//structure pointer variable 
	a=b=c=d=NULL;
	l.insert(&a,5);
	l.insert(&a,1);
	l.disp(a);
	l.insert(&b,5);
	l.insert(&b,4);
	l.disp(b);
	l.merg(a,b,&c);
	l.disp(c);
	/*cout<<"\nBefore Concat :";
	l.disp(a);
	l.concat(a,&b);
	cout<<"\nAfter copy :";
	l.disp(a);*/
	/*cout<<l.stcmp(a,b)<<"\n";
	l.alter(a,&b);
	l.disp(a);
	cout<<"\nBefore copy :";
	l.disp(a);
	l.copy(a,&c);
	cout<<"\nAfter copy :";
	l.disp(c);
	cout<<"\nBefore Merging :";
	l.disp(d);
	d=l.MergeLists(a,b);
	cout<<"\nAfter Merging :";
	l.disp(d);	*/
    return 0;
}
//through class concept
/*
#include<iostream>

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
	void display();
	void count();
	void concat(list &l);
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


void list::display()
{
	node *temp;
	temp=p;
	cout<<"\n";
	while(temp!=NULL)   // here we can't use temp->link!=NULL because we have to display last value also;
	{
		cout<<temp->data<<" "; 
		temp=temp->link;
	}
}

void list :: concat(list &l)
{
	node *temp;
	if(p==NULL) //if first ll is empty
	{
		p=l.p;//l.p conatins b ll
	}
	else
	{//if both ll are non-empty
		if(l.p!=NULL)
		{
			temp=p;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			//concatenate second string after first
			temp->link=l.p;
		}
	}
	l.p=NULL;	//(all time neccessary)
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
	list a,b;
	a.append(2);
	a.append(3);
	a.append(4);
	a.append(5);
	a.display();
	b.append(6);
	b.append(7);
	b.append(8);
	b.append(9);
	b.display();
    a.concat(b);
	a.display();

}	
*/


//without appended directly append through function concept
/*
concept (no need) be clear on one concept only

// C++ program to compare two strings represented as linked 
// lists
#include<bits/stdc++.h>
using namespace std;
  
// Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
};
  
// Function to create newNode in a linkedlist
Node* newNode(char c)
{
    Node *temp = new Node;
    temp->c = c;
    temp->next = NULL;
    return temp;
};
 
int compare(Node *list1, Node *list2) 
{    
    // Traverse both lists. Stop when either end of a linked 
    // list is reached or current characters don't match
    while (list1 && list2 && list1->c == list2->c) 
    {         
        list1 = list1->next;
        list2 = list2->next;
    }
     
    //  If both lists are not empty, compare mismatching
    //  characters
    if (list1 && list2) 
        return (list1->c > list2->c)? 1: -1;
 
    // If either of the two lists has reached end
    if (list1 && !list2) return 1;
    if (list2 && !list1) return -1;
     
    // If none of the above conditions is true, both 
    // lists have reached end 
    return 0;
}
 
// Driver program
int main()
{
    Node *list1 = newNode('g');
    list1->next = newNode('e');
    list1->next->next = newNode('e');
    list1->next->next->next = newNode('k');
    list1->next->next->next->next = newNode('s');
    list1->next->next->next->next->next = newNode('b');
 
    Node *list2 = newNode('g');
    list2->next = newNode('e');
    list2->next->next = newNode('e');
    list2->next->next->next = newNode('k');
    list2->next->next->next->next = newNode('s');
    list2->next->next->next->next->next = newNode('a');
 
    cout << compare(list1, list2);
  
    return 0;
}
*/