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
	void add(int);
	void disp();
	void del(int);
	void get();
	void kth(int,int);
	int count();
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
	r->link=NULL;
	temp->link=r;
   }
}

void list :: disp()
{
	node *temp;
	temp=p;
	cout<<"\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}
int list :: count()
{
	node *temp;
	temp=p;
	int c=0;
	cout<<"\n";
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	return c;
}

void list :: del(int num)
{
	node *temp,*old;
	temp=p;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==p)
			{
				p=temp->link;
			}
			else
			{
				old->link=temp->link;
			}
		 delete temp;
		 return;
		}
		old=temp;
		temp=temp->link;	
	}
	cout<<"\nElement "<<num<<" not found\n";
}
char ch;
void list :: get()
{
	do 
	{
		int n,m,i;
		cout<<"\nHow many element do you to enter :";
		cin>>n;
		for(i=0;i<n;i++)
		{
		 cout<<"\nEnter Element :";
		 cin>>m;
		 add(m);
		}
		
		cout<<"\nDo you want to enter more (y/n) :";
		cin>>ch;
	}
	while(ch=='y'||ch=='Y');
}

void list :: kth(int e,int a)
{
	node *temp;
	int i;
	temp=p;
	for(i=1;i<=a;i++)
    {
		if(i%2==0)    //first check the condition then increment
	    {
		   cout<<"\n"<<temp->data<<" should be deleted ";
		   del(temp->data);
		}
		temp=temp->link;
	}
	 disp();
}
list :: ~list()
{
	node *temp;
	temp=p;
	while(temp!=NULL)
	{
		temp=temp->link;
		delete temp;
		p=temp;
	}
}

int main()
{
	list l;
	int e,a;
	l.get();
	cout<<"\nElements in the list are :";
	l.disp();
	cout<<"\n";
	a=l.count();
	cout<<"\nNo.of element :"<<a;
	cout<<"\nEnter Kth element :";
	cin>>e;
	l.kth(e,a);
}