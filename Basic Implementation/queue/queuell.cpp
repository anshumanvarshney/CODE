#include<iostream>
#include<stdlib.h>
using namespace std;
/*
to display :

void queue::disp()
{
	while(front!=rear)
	{
		cout<<front->data<<" ";
		front=front->link;
	}
		cout<<front->data;//or cout<<rear->data;
}
*/
int const MAX=10;
class queue
{
	private:
    struct node
	{
		int data;
		node *link;
	}*front,*rear;	
	public:
	queue();
    void addq(int);
	void delq();
	void fronte();
	void reare();
	void minele();
	~queue();
};



queue::queue()
{
	front=rear=NULL;
}
void queue :: addq(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
    if(front==NULL)
	{
		front=temp;
	}
	else
	{
		rear->link=temp;
		rear=rear->link;
	}
		rear=temp;
}

int data;
void queue::delq()
{
	node *temp;
	if(front==NULL)
	{
		cout<<"\nQueue is Empty";
	}
	else
	{
		//this condition should be included
		if(front==rear)
		{
			int data=front->data;
			front=rear=NULL;
			return data;
		}
		else
		{
			temp=front;
			data=temp->data;
			cout<<"\n"<<front->data<<" is deleted";
			front=front->link; //take care of this statement ... don't place it after  displaying otherwise next element is to be printed	
			delete temp;
		} 	
	}
}
queue :: ~queue()
{
	node *temp;
	temp=front;
	while(temp!=rear)
	{
		temp=temp->link;
		delete temp;
		front=temp;
	}
	delete rear;
}

void queue :: fronte()
{
	if(front==NULL)
	{
		cout<<"\nQueue is empty";
	}
	else
	cout<<"\nfront element is "<<front->data;
}
void queue :: reare()
{
	if(front==NULL)
	{
		cout<<"\nQueue is empty";
	}
	else
	cout<<"\nRear element is "<<rear->data;
}

void queue :: minele()
{
	int min,i;
	if(front==NULL)
	{
		cout<<"\nQueue is Empty";
	}
	node *temp;
	temp=front;
	min=temp->data;
	while(temp!=rear)
	{
		if(min>(temp->data))
		{
			min=temp->data;
		}
		temp=temp->link;
	}
	if(min>(rear->data))//for rear also
	{
		min=rear->data;
	}
	cout<<"\nMinimum Element :"<<min;
	
}
int main()
{
	queue s;
    int n,num;
	while(true)
	{
	cout<<"\n\n-----------Queue using Array----------------\n\nOperations :\n1-Add Queue\n2-Delete Queue\n3-Front Element\n4-Rear Element\n5-Minimum Element\n6-Exit";
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
			exit(0);
		}
	}
	}	
}
