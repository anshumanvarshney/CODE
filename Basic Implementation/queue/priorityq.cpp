#include<iostream>
#include<string.h>
using namespace std;
int const MAX=5;
int i ,j;
class pque
{
	public:
	struct data
	{
		char job[MAX];
		int pr;                   //priority and order
		int od;
	}d[MAX]; //object of structure
	int front,rear;
	
	pque();
	void add(data);
	data remove(); //because we need to pop out everything that's why we are using here structure name as data type
};

pque::pque()
{
	front=rear=-1;
	for(i=0;i<MAX;i++)
	{
	 strcpy(d[i].job,'\0');
	 d[i].pr=0;
	 d[i].od=0;
	}
}
void pque :: add(data dt)//passing entire structure as object
{
	if(rear==MAX-1)
	{
		cout<<"\nQueue is Full";
	}
	else
	{
		rear++;
		d[rear]=dt;
	}
	if(front==-1)
	{
		front=0;
	}
	
	//starts form here
	data temp;
	for(i=front;i<=rear;i++)
	{
		for(j=i+1;j<=rear;j++)
		{
			if(d[i].pr>d[j].pr) //checking priority wise
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
			else if(d[i].pr==d[j].pr)//if priorities are equal
			{
				if(d[i].od>d[j].od) //then checking order wise
				{
					temp=d[i];
					d[i]=d[j];
					d[j]=temp;
				}
			}
		}
	}
}
pque::data pque:: remove()
{
	data t;
    strcpy(t.job,"");
    t.pr=0;
    t.od=0;
    if(front==-1)
	{
		cout<<"\nQueue is Empty";
		return t;
	}
	t=d[front];
	//d[front]=t;
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front++;
	}
	return t;
}

int main()
{

	pque q;
	pque::data dt;//important concept to call structure object inside class or we can put structure at the top of class
    j=0;
	cout<<"Enter Job description and its priority\n";
	cout<<"Lower the priority number , Higher the priority\n\n";
	cout<<"JOB Priority\n";
	for(i=0;i<MAX;i++)
	{
		cin>>dt.job>>dt.pr;
		dt.od=j++;
		q.add(dt);  //object pass
	}
	cout<<"\n";
	cout<<"Process Jobs Prioritywise\n";
	cout<<"Job          Priority\n";
	for(i=0;i<MAX-1;i++)
	{
		pque::data temp=q.remove();//important concept
		cout<<temp.job<<"          "<<temp.pr<<"\n";
	}
	cout<<"\n";
	return 0;
}