#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
};

node *newnode(int data)
{
	node *temp;
	temp=new node;
	temp->data=data;
	temp->link=NULL;
	return temp;
}

void disp(node *head)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}

void detect(node *p)
{
	node *slow,*fast;
	slow=fast=p;
	int flag=0;
	
	while(fast!=NULL && fast->link!=NULL)
	{
		slow=slow->link;
		fast=fast->link->link;
		if(slow==fast)
		{
		    flag= 1;
			break;
		}
	}
	//loop exists so remove the loop
	if(slow ==fast)
	{
		slow=p;
		
		while(fast!=NULL)
		{
			slow =slow->link;
			if(fast->link==slow)
			{
				fast->link=NULL;
			}
			fast=fast->link;
		}
	}
	if(flag==0)
		cout<<"\nThere is not haveing any loop";
	else cout<<"\nLoop exist";
}
//or second method
void removeTheLoop(Node *head)
{
    Node *slow,*fast;
    slow=fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    if(slow==fast)
    {
        slow=head;
        while(fast->next!=slow->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
     //Your code here
}
/*
	to check where the loop is getting started
	if(slow ==fast)
	{
		slow=p;
        while(fast!=NULL)
		{
			slow=slow->link;
			fast=fast->link;
			if(slow==fast)
			{
				cout<<"\nLoop start at "<<slow->data;
				break;
			}
		}		
	}	
	*/
	
/*
Good approach
	or inside cycle checkingb also i,e if the cycle exist return where the cycle start else return NULL
	node* detect(node *p)
	{
		node *slow,*fast;
		slow=fast=p;
		int flag=0;
	
		while(fast!=NULL && fast->link!=NULL)
		{
			slow=slow->link;
			fast=fast->link->link;
			if(slow==fast)
			{
				slow=head;
				while(slow!=fast)
				{
					slow=slow->link;
					fast=fast->link;
				}
				return slow;
			}
		}
		return NULL;
	}
*/	
	
}

int main()
{
	node *head;
	head=newnode(2);
	head->link=newnode(3);
	head->link->link=newnode(4);
	head->link->link->link=newnode(5);
	head->link->link->link->link=newnode(6);
	disp(head);
	/* Create a loop for testing */
    head->link->link->link->link->link = head->link->link;
	detect(head);
	detect(head);
}

