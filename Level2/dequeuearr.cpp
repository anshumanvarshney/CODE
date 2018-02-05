/*
-------full-------
empty--------------empty
*/

#include <iostream>
#include<stdlib.h>
using namespace std;
int const MAX=10;
class deq
{
	private:
	int f1,f2;
	int a[MAX];
	public:
	void add1(int);
	void del1();
	void add2(int);
	void del2();
	void display();
	deq();
};

deq::deq()
{
	int i;
	f1=-1;
	f2=MAX;
	for(i=0;i<MAX;i++)
	{
		a[i]=0;
	}
}
void deq :: add1(int num)
{
	if(f1+1==f2)
	{
		cout<<"\nQueue is full";
	}
	else
	{
		f1++;
		a[f1]=num;
	    cout<<"\n"<<a[f1]<<" is added";
	}	
}
int data;
void deq::del1()
{
	if(f1==-1&&f2==MAX)
	{
		cout<<"\nQueue is empty";
	}
	else
	{	
		data=a[f1];
		cout<<"\n"<<a[f1]<<" is deleted";
		a[f1]=0;  // this can also be done in simple queue
		f1--;
	}
	
}
void deq :: add2(int num)
{
	if(f2-1==f1)
	{
		cout<<"\nQueue is full";
	}
	else
	{
		f2--;
		a[f2]=num;
		cout<<"\n"<<a[f2]<<" is added";
	}	
}

void deq::del2()
{
	if(f2==MAX&&f1==-1)
	{
		cout<<"\nQueue is empty";
	}
	else
	{	
		data=a[f2];
		cout<<"\n"<<a[f2]<<" is deleted";
		a[f2]=0;
		f2++;
	}
	
}
void deq :: display()
{
	int i;
	cout<<"\n";
	int d=0,c=0;
	for(i=0;i<MAX;i++)
	{
		cout<<a[i]<<" ";
		if(a[i]==0)
		{
			c++;
		}
		else
			d++;
	}
	cout<<"\nNo. of element :"<<d;
	cout<<"\nNo. of empty space :"<<c;
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
			s.add1(num);
			break;
		}
		case 2:
		{
			s.del1();
			break;
		}
		case 3:
		{
			cout<<"\n\nEnter element : ";
			cin>>num;
			s.add2(num);
			break;
		}
		case 4:
		{
			s.del2();
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
