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
	void add(int num);
	void disp();
	void get();
	int count();
	void ssort(int);
	void bsort(int);
	~list();
};

list::list()
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
		r->link=temp->link;
		temp->link=r;
	}
}

void list::disp()
{
	node *temp;
	temp=p;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}

int list::count()
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

void list::get()
{
	int val;
	char ch;
	do
	{
	 cout<<"\nEnter a value:";
	 cin>>val;
	 add(val);
	 cout<<"\nPress 'y' to add node or any other key to further operations :";
	 cin>>ch;
	}
	 while(ch=='y'||ch=='Y');
}

void list ::ssort(int n)
{
	node *temp,*r;
	temp=p; 
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		r=temp->link;
		for(j=i+1;j<n;j++)
		{
			if(r->data>temp->data)
			{
				t=r->data;
				r->data=temp->data;
				temp->data=t;
	        }	
			r=r->link;				
		}
		temp=temp->link;// i should be incremented
	}
}

void list:: bsort(int n)
{
	node *temp,*r;
	
	int i,j,t;
	for(i=0;i<n;i++)
	{ 
        temp=p;
        r=temp->link;
		for(j=0;j<n-1-i;j++)
		{
			if(r->data>temp->data)
			{
				t=r->data;
				r->data=temp->data;
				temp->data=t;
			}
			temp=temp->link;
			r=r->link;
		}
	}
}

/*
above one is my logic


*/
int main()
{
	list l;
	cout<<"\nEnter element in the list :";
	l.get();
	cout<<"\nElement in the list :";
	l.disp();
	int n;
	n=l.count();
	cout<<"\nElement after sorted in the list using Selection sort :";
    l.ssort(n);
	l.disp();
	cout<<"\nElement after sorted in the list using bubble sort :";
	l.bsort(n);
	l.disp();
}