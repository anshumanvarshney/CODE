#include <iostream>
#include<stdlib.h>
using namespace std;
int const MAX=10;
class stack
{
	private:
	int top;
	int a[MAX];
	public:
	void push(int);
	void pop();
	void topele();
	void min();
	stack();
};

stack::stack()
{
	top=-1;
}
void stack::push(int num)
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
void stack::pop()
{
	if(top==-1)
	{
		cout<<"\nStack is Empty";
	    return;
	}
	else
		int data =a[top];
	    cout<<"\n"<<a[top]<<"  is deleted";
		top--;
}
void stack::topele()
{
	if(top==-1)
	{
		cout<<"\nStack is Empty ";
	}
	else cout<<"\n"<<a[top]<<"is top element";
}

void stack::min()
{
	if(top==-1)
	{
		cout<<"\nStack is empty";
	}
	else
	{
		int i,mn = a[top];
		/*for(i=0;top>-1;i++)//for max top<MAX-1; and top++
		{
		 if(mn>a[i])
		 {
			 mn=a[i];
		 }
		 top--;
		}*/
		//or
		
		for(i=top;top>-1;top--)//or i>-1 ; i--
			if(mn>a[i])
		 {
			 mn=a[i];
		 }
		cout<<"\nMinimum Element :"<<mn;
	}
}

int main()
{
	stack s;
	int n,num;
	while(true)
	{
	cout<<"\n\n-----------STACK using Array----------------\n\nOperations :\n1-Push\n2-Pop\n3-Top\n4-Minimum Element\n5-Exit";
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
			s.min();
			break;
		}
		case 5:
		{
			exit(0);
		}
	}
	}	
}






















