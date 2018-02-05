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
	void add(int num);
	void append(node **p,int num);
	void show();
	void display(node *p);
	void fun(list &l);
	void copy(node *p,node **q);
	int length();
	int count(node *p);
	int operator == (list &l);
	int compare(node *p1,node *p2);
	
	~list();
};

list::list()
{
	p=NULL;
}

void list :: add(int num)
{
	append(&p,num);
}





	/*if ( q != NULL)
	{
		*s = new node
		
		( *s ) -> data = q -> data;
		( *s ) -> link = NULL;
		
		copy( q -> link , &( ( *s ) -> link));
	}*/
}

int list::length()
{
	return count(p);
}


void list :: show()
{
	display(p);
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
	list o,a,b;
	o.add(2);
	o.add(3);
	o.add(4);
	o.add(5);
	o.show();
	cout<<"\nLength of ll : "<<o.length();
	cout<<"\n";
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(4);
	a.show();
	cout<<"\nLength of l2 : "<<a.length();
	if(a==o)
		cout<<"\nSame";
	else
		cout<<"\nNot";
	cout<<"\n";
	o.fun(b);
	b.show();
	
}