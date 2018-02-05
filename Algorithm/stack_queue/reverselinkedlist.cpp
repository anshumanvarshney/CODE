#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

class list
{
	private:
   struct node
   {
	  int data;
	  node *next;
   } *head;
    public:
	list();
	void add(int data);
   void reverse();
   void disp();
};

list::list()
{
	head=NULL;
}

void list::add(int data)
{
	node *temp,*r;
   if(head==NULL)
   {
	   head = new node;
	   head->data=data;
	   head->next=NULL;
   }	   
   else 
   {
	   temp=head;
	   while(temp->next!=NULL)
	   {
		   temp=temp->next;
	   }
	   r=new node;
	   r->data=data;
	   r->next=temp->next;
	   temp->next=r;
   }
}

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
	temp=s.top();
	head=temp;
	s.pop();
	while(!s.empty())
	{
		temp->next=s.top();
		s.pop();
		temp=temp->next;
	}
	temp->next=NULL;  //don't forget to make last node NULL
}

void list::disp()
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
		
}
int main()
{
	list l;
	l.add(5);
	l.add(4);
	l.add(3);
	l.add(2);
	l.disp();
	l.reverse();
	cout<<"\n";
	l.disp();
}