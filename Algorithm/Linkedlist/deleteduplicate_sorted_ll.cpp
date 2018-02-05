/*
Two concept
1-Delete duplicate ll only for sorted ll

For example,
Given 1->2->3->3->4->4->5, return 1->2->3->4->5.
Given 1->1->1->2->3, return 1->2->3.


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
	void rem();
	void display();
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

void list :: rem()
{
	{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    node *temp,*old,*r;
    temp=p;
    r=temp->link;
    while(r!=NULL)
    {
        if(temp->data == r->data)
        {
            old=r;
            r=r->link;
            temp->link=old->link;//temp->link =r;
            delete old;
        }
		else
		{
			r=r->link;
			temp=temp->link;
		}
    }
}
}

/*
second one


*/

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
    o.append(1);
	 o.append(1);
	  o.append(2);
	  o.append(3);
	  o.append(3);
	   o.append(4);
	   o.append(5);
	   o.append(6);
	   o.display();
	   o.rem();
	   cout<<"\n";
	   o.display();
}