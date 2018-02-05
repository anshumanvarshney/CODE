#include<iostream>
#include<stdlib.h>
using namespace std;

int const MAX=10;
class queue
{
	private:
    int a[MAX];
    int front,rear; 	
	public:
	queue();
    void addq(int);
	void delq();
	void fronte();
	void reare();
	void minele();
	void disp();
};



queue::queue()
{
	front=rear=-1;
}
void queue :: addq(int num)
{
	if(rear==MAX-1)
	{
		cout<<"\nQueue is full ";
	}
	else
	{
		rear++;
		a[rear]=num;
		if(front==-1)
			front=0;
	}
}

int data;
void queue::delq()
{
	if(front==-1)
	{
		cout<<"\nQueue is Empty";
	}
	else
	{
		data=a[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
			front++;
	}
	cout<<"\n"<<data<<" is deleted";
}


void queue :: fronte()
{
	if(front==-1)
	{
		cout<<"\nQueue is empty";
	}
	else
	cout<<"\nFront element is "<<a[front];
}
void queue :: reare()
{
	if(front==-1)
	{
		cout<<"\nQueue is empty";
	}
	else
	cout<<"\nRear element is "<<a[rear];
}

void queue :: minele()
{
	int min,i;
	if(front==-1)
	{
		cout<<"\nQueue is Empty";
	}
	else
	{
		min = a[front];
		for(i=front ; i<=rear ; i++)
		{
			if(min > a[i])
			{
				min = a[i];
			}
			i++;
		}
		
	cout<<"\nMinimum Element :"<<min;
	}	
}

void queue :: disp()
{
	int i;
	for(i=front ; i<=rear ;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	queue s;
    int n,num;
	while(true)
	{
	cout<<"\n\n-----------Queue using Array----------------\n\nOperations :\n1-Add Queue\n2-Delete Queue\n3-Front Element\n4-Rear Element\n5-Minimum Element\n6-Display\n7-Exit";
	cout<<"\n\nEnter your choice :";
	cin>>n;
	switch(n)
	{
		case 1:
		{
			cout<<"\n\nEnter element : ";
			cin>>num;
			s.addq(num);
			break;
		}
		case 2:
		{
			s.delq();
			break;
		}
		case 3:
		{
			s.fronte();
			break;
		}
		case 4:
		{
			s.reare();
			break;
		}
		case 5:
		{
			s.minele();
			break;
		}
		case 6:
		{
			s.disp();
			break;
		}
		case 7 :
		{
			exit(0);
		}
	}
	}	
}
