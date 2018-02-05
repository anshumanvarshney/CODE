#include<iostream>
#include<math.h>
using namespace std;

struct node
{
	int data;
	node *link;
};
class list
{
	private:
	node *p;
	public:
	list();
	void push(node** p, int data);
	//void sum(node *a,node *b);
	void sum(node *a,node **b);
	void display(node *p);
	void show();
	~list();
};

list::list()
{
	p=NULL;
}

void list :: push(node** p, int data)
{
   /*
   node *temp;
   temp=new node;
   temp->data=data;
   temp->link = (*p);
   (*p) = temp;*/
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
merging into third ll 

void list :: sum(node *a,node *b)
{
	node *temp;
	temp=NULL;
	
	while(a!=NULL && b!=NULL)
	{
		if(p==NULL)
		{
			p=new node;
			temp=p;
		}
		else
		{
			temp->link=new node;
			temp=temp->link;
		}	
		temp->data=a->data;
		temp->link=b;
		a=a->link;
		temp->link=new node;
		temp=temp->link;
		temp->data=b->data;
		temp->link=a;
		b=b->link;
	}
	temp->link=NULL;	
}
*/



void list :: display(node *p)
{

	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->link;
	}
	cout<<"\n";
}
void list :: show()
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
	node* a = NULL;
    node* b = NULL;
	node *su=NULL;
    l.push(&a, 5);
    l.push(&a, 6);
    l.push(&a, 3);
	cout<<"\nLL a before : ";
    l.display(a);
	l.push(&b, 8);
    l.push(&b, 4);
    l.push(&b, 2);
	cout<<"\nLL b before : ";
	l.display(b);
	/*l.sum(a,b);
	l.display();*/
	l.sum(a,&b);
	cout<<"\nLL a after : ";
	l.display(a);
	cout<<"\nLL b after : ";
	l.display(b);
}