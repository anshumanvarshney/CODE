#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

class B
{
	private:
	struct node
	{
		int data;
		node *link;
	}*p;
	public:
	B();
	void add(int n);
	void disp(int);
};

B::B()
{
	p=NULL;
}
void B::add(int n)
{
	node *temp,*r;
	if(p==NULL)
	{
		p=new node;
		p->data=n;
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
     r->data=n;
     r->link=temp->link;
     temp->link=r;	 
	}
}

void B::disp(int n)
{
	node *temp;
	temp=p;
	int c=0;
	while(temp!=NULL)
	{
		c+=(pow(2,n-1)*temp->data);
		temp=temp->link;
		n--;
	}
	cout<<c;
}

int main()
{
	B o;
	int i,n,p;
	cout<<"Enter the length of number:";
	cin>>p;
	for(i=0;i<p;i++)
	{
		cout<<"Enter digit :";
		cin>>n;
		o.add(n);
	}
	o.disp(p);
	
}