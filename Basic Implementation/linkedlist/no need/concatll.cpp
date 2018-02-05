#include<iostream>

using namespace std;

class list
{
	private:
	struct node
	{
		int data;
		node *link;
	}*p;          //p always points to first element;
	public:
	list();
	void append(int);
	void display();
	void count();
	void concat(list &l);
	~list();
};
list::list()
{
	p=NULL;
}
void list::append(int num)
{
	node *temp,*r;
	if(p==NULL)
	{
		p=new node;
		p->data = num;
		p->link=NULL;
	}
	else
	{
		temp=p;
		while(temp->link!=NULL) // we can't use temp!=NULL because here we have to append through its address;
			temp=temp->link;
		
		r=new node;
		r->data=num;
		r->link=NULL;
		temp->link=r;
        
	}
}


void list::display()
{
	node *temp;
	temp=p;
	cout<<"\n";
	while(temp!=NULL)   // here we can't use temp->link!=NULL because we have to display last value also;
	{
		cout<<temp->data<<" "; 
		temp=temp->link;
	}
}

void list :: concat(list &l)
{
	node *temp;
	if(p==NULL) //if first ll is empty
	{
		p=l.p;//l.p conatins b ll
	}
	else
	{//if both ll are non-empty
		if(l.p!=NULL)
		{
			temp=p;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			//concatenate second string after first
			temp->link=l.p;
		}
	}
	l.p=NULL;	//(all time neccessary)
}

list::~list()
{
	node *temp;
	temp=p;
	while(temp!=NULL)
	{
		temp=temp->link;
		delete p;
		p=temp;
	}
}


int main()
{
	list a,b;
	a.append(2);
	a.append(3);
	a.append(4);
	a.append(5);
	a.display();
	b.append(6);
	b.append(7);
	b.append(8);
	b.append(9);
	b.display();
    a.concat(b);
	a.display();

}	