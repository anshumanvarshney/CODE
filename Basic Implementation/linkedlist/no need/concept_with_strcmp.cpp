/*

Note this is also a concept of passing different ll by using one object 

and this is also a concept

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
    else {
        r= SortedInsert(head->next, data);
        head->next = r;
        r->prev = head;
        return head;
    }
}
*/
#include<iostream>
#include<math.h>
using namespace std;

struct node
{
	char data;
	node *link;
};
class list
{
	private:
	node *p;
	public:
	list();
	void push(node** p, int data);
	int comp(node *a,node *b);
	void display(node *p);
	~list();
};

list::list()
{
	p=NULL;
}

void list :: push(node** p, int data)
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

int list :: comp(node *a,node *b)
{
	while(a!=NULL && b!=NULL && a->data == b->data)
	{
		a=a->link;
		b=b->link;
	}
	if (a!=NULL && b!=NULL) //if not equal
        return (a->data > b->data)? 1: -1;
    if (a!=NULL && b==NULL) return 1;
    if (b!=NULL && a==NULL) return -1;
     
    return 0;
}

/*

OR

int list :: comp(node *a,node *b)
{
	while(a && b && a->data == b->data)
	{
		a=a->link;
		b=b->link;
	}
	if (a && b) 
        return (a->data > b->data)? 1: -1;
    if (a && !b) return 1;
    if (b && !a) return -1;
     
    return 0;
}
*/


void list :: display(node *p)
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
	//delete p;
}
int main()
{
	list l;
	//note
	node* a = NULL;
    node* b = NULL;
    l.push(&a, 'g');
    l.push(&a, 'e');
    l.push(&a, 'e');
	l.push(&a, 'k');
    l.push(&a, 's');
	l.push(&a, 'a');
    l.display(a);
	l.push(&b, 'g');
    l.push(&b, 'e');
    l.push(&b, 'e');
	l.push(&b, 'k');
    l.push(&b, 's');
	l.push(&b, 'b');
	l.display(b);
	cout<<l.comp(a,b);
}