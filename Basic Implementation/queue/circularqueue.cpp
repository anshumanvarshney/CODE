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
	void display();
};
int i;
queue::queue()
{
	front=rear=-1;
	for(i=0;i<MAX;i++)   // initially elements are 000000....
	{
		a[i]=0;
	}
}
void queue :: addq(int num)
{
	if((rear==MAX-1&&front==0)||(rear + 1 == front))  //second condition is for second round
	{
		cout<<"\nQueue is full";
	}
	else
	{
		if(rear == MAX-1)  //circular------------- MAX-1 to 0 pointing( extra )
		{
			rear=0;
		}
		else 
		{
			rear++;
		}
		a[rear]=num;
		cout<<"\n"<<a[rear]<<" is added";
	}
    if(front==-1)
	{
		front=0;
	}		
}
int data;
void queue::delq()
{
	if(front==-1)   //only this condition shows queue is empty
	{
		cout<<"\nQueue is empty";
	}
	else
	{	
		data=a[front];
		a[front]=0;
		cout<<"\n"<<data<<" is deleted";
		if(front==rear)   //no element in the queue
		{
			front=rear=-1;
		}
		else
		{
			if(front==MAX-1)//circular------------- MAX-1 to 0 pointing ( extra )
				front=0;
			else front++;
		}
	}
}

void queue:: fronte()
{
	if(front==-1)
	{
		cout<<"\nQueue is Empty";
	}
	else
	{
		cout<<"\nFront element :";
		cout<<a[front];
	}
}

void queue :: reare()
{
	if(front==-1)
	{
		cout<<"\nQueue is Empty";
	}
	else
	{
		cout<<"\nRear element :";
		cout<<a[rear];
	}
}

void queue :: display() // also be use for printing simple queue using array
{
	int j;
	for(j=0;j<MAX;j++)
	{
		cout<<a[j]<<" ";
	}
}

int main()
{
	queue s;
	int n,num;
	while(true)
	{
	cout<<"\n\n-----------Circuklar Queue using Array----------------\n\nOperations :\n1-Add Queue\n2-Delete Queue\n3-Front element\n4-Rear Element\n5-Display\n6-Exit";
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