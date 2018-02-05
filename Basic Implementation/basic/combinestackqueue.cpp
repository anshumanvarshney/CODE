#include <iostream>
#include<stdlib.h>
using namespace std;
int const MAX=10;
class deq
{
	private:
	int top,front,rear;
	int a[MAX];
	public:
	void push(int);
	void pop();
	void addq(int);
	void delq();
	void display();
	deq();
};

deq::deq()
{
	int i;
	top=-1;
	front=rear=MAX;
	for(i=0;i<MAX;i++)
	{
		a[i]=0;
	}
}
void deq :: addq(int num)
{
	if(rear==-1)
	{
		cout<<"\nQueue is full";
	}
	else
	{
		rear--;
		a[rear]=num;
		if(front==MAX)
		{
			front=MAX-1;
		}
		cout<<"\n"<<a[rear]<<" is added";
	}	
}
int data;
void deq::delq()
{
	if(front==rear&&front==MAX-1)
	{
		cout<<"\nQueue is empty";
	}
	else
	{	
		data=a[front];
		cout<<"\n"<<a[front]<<" is deleted";
		a[front]=0;
		front--;
	}
	
}
void deq::push(int num)
{
	if(top==MAX-1)
	{
		cout<<"\nStack is Full";
	}
	else
		top++;
	    a[top]=num;
		cout<<"\n"<<a[top]<<"  is added";
}
void deq::pop()
{
	if(top==-1)
	{
		cout<<"\nStack is Empty";
	    return;
	}
	else
		int ele =a[top];
	    cout<<"\n"<<a[top]<<"  is deleted";
	    a[top]=0;
	    top--;
}

void deq :: display()
{
	int i;
	cout<<"\n";
	for(i=0;i<MAX;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	deq s;
	int n,num;
	while(true)
	{
	cout<<"\n\n-----------Dequeue using Array----------------\n\nOperations :\n1-Add at Beg\n2-Delete at beg\n3-Add at end\n4-Delete at end\n5-Display\n6-Exit";
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
			cout<<"\n\nEnter element : ";
			cin>>num;
			s.addq(num);
			break;
		}
		case 4:
		{
			s.delq();
			break;
		}
		case 5:
		{
			s.display();
			break;
		}
		case 6:
		{
			exit(0);
		}
	}
	}	
}
