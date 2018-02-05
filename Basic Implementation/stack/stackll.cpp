#include <iostream>
#include<stdlib.h>
using namespace std;

class stack
{
	private:
	struct node
	{
	 int data;
	 node *link;
	}*top;
	public:
	stack();
	void push(int);
	void pop();
	void topele();
	~stack();
};
stack::stack()
{
	top=NULL;
}
void stack :: push(int num)
{
	node *temp;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"\nStack is empty";
	}
	else
	{
		temp->data=num;
		temp->link=top;
		top=temp;
		cout<<"\n"<<top->data<<" is added";
    }
}
int t;
void stack ::pop()
{
	if(top==NULL)
	{
		cout<<"\nStack is empty";
	}
	else
	{
		node *temp;
		temp=top;
		t=top->data;
		top=top->link;
		delete temp;
     	cout<<"\n"<<t<<" is deleted";
	}
}
void stack::topele()
{
	if(top==NULL)
	{
		cout<<"\nStack is empty";
	}
	else
	{
		cout<<"\nTop element is "<<top->data;
	}
	
}
stack::~stack()
{
	node *temp;
	temp=top;
   while(top!=NULL)
   {
	   top=top->link;
	   delete temp;
	   temp=top;
   }
}


int main()
{
	stack s;
	int n,num;
	while(true)
	{
	cout<<"\n\n-----------STACK using Linked List----------------\n\nOperations :\n1-Push\n2-Pop\n3-Top\n4-Exit";
	cout<<"\n\nEnter your choice :";
	cin>>n;
	switch(n)
	{
		case 1:
		{
			cout<<"\n\nEnter element : ";
			cin>>num;
			s.push(num);
			break;
		}
		case 2:
		{
			s.pop();
			break;
		}
		case 3:
		{
			s.topele();
			break;
		}
		case 4:
		{
			exit(0);
		}
	}
	}	
}

