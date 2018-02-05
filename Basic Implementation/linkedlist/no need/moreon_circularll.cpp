#include<iostream>
#include<stdlib.h>
using namespace std;

class list
{
	private:
	struct node
	{
		int data;
		node *link;
	}*front,*rear;

	public:

	list();
	void addend(int);
	void addbeg(int data);
	void delf();
	void delr();
	void delan(int);
	void delaf(int);
	void display();
	~list();
};

list::list()
{
	front=rear=NULL;
}

void list::addend(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
	if(front==NULL)
	{
		front=temp;
	}
	else
	{		
		rear->link=temp;
	}
	rear=temp;
	rear->link=front; //always to make it circular
}

void list :: addbeg(int data)
{
	node *temp;
	temp=new node;
	temp->data=data;
	temp->link=front;
	rear->link=temp;
	front=temp;
}

void list::display()
{
	node *temp,*p;
	temp=front;
	p=NULL;
	while(temp!=p)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
		p=front;
	}
}

void list::delf()//delete front element
{
	node *temp;
	int item;
	if(front==NULL)
	{
		cout<<"\nQueue is Empty";
	}
	else
	{
		if(front==rear) //only one element
		{
			item=front->data;
			delete front;
			front=NULL;
			rear=NULL;
		}
		else
		{
			temp=front;
			item=temp->data;
			front=front->link;
			rear->link=front;
			delete temp;
		}
		cout<<"\n"<<item<<" is deleted";
	}
}

void list :: delr() //delete rear element
{
	node *temp,*old;
	temp=front;
	while(temp!=rear)
	{
		old=temp;
		temp=temp->link;
	}
	old->link=front;
	delete rear;
    rear=old;	
}

void list :: delan(int data) //delete a given node
{
	node *temp,*old;
	temp=front;
	while(temp->data!=data)
	{
		old=temp;
		temp=temp->link;
	}
	old->link=temp->link;
	delete temp;
}

void list :: delaf(int data) //delete after a given node
{
	node *temp,*old;
	temp=front;
	while(temp->data!=data)
	{
		temp=temp->link;
	}
	old =temp;
	temp=temp->link;      //or old->link = temp->link->link
	old->link=temp->link;
	delete temp;
}

list::~list()
{
 node *temp;
 temp=front;
 while(temp!=rear)
 {
  temp=temp->link;
  delete temp;
  front=temp;
 }
 delete rear; //note it is important here don't forget this one
}

int  main()
{
	list o;
	o.addend(1);
	o.addend(2);
	o.addend(4);
	o.addend(6);
	o.addend(7);
	o.display();
	o.delf();
	cout<<"\n";
	o.display();
	o.addbeg(0);
	o.addbeg(5);
	o.addbeg(8);
	cout<<"\n";
	o.display();
	o.delr();
	cout<<"\n";
	o.display();
	o.delan(5);
	cout<<"\n";
	o.display();
	o.delaf(2);
	cout<<"\n";
	o.display();
}