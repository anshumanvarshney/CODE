/*

Pairwise swap elements of a given linked list

Given a singly linked list, write a function to swap elements pairwise. For example,
 if the linked list is 1->2->3->4->5 then the function should change it to 2->1->4->3->5, and 
 if the linked list is 1->2->3->4->5->6 then the function should change it to 2->1->4->3->6->5.


*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
    node *link;
};
 
node* newnode(int data)
{
	node *temp;
	temp=new node;
	temp->data=data;
	temp->link=NULL;
	return temp;
} 

void disp(node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->link;
	}
}

void swapping(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void swap(node *p)
{
	node *temp,*r;
	r=temp=p;
	r=r->link;
	int flag=1;
	while(temp!=NULL&&r!=NULL)
	{
		if(flag==1)
		{
			swapping(&temp->data,&r->data);//note
			temp=temp->link;
			r=r->link;
		}
		else
		{
			temp=temp->link;
			r=r->link;
		}
		flag=!flag;//flipflops
		
	}
}
/*
or
with same complexity

void swap(node *p)
{
	node *temp;
	temp=p;
	int flag=1;
	while(temp->link!=NULL)
	{
		if(flag==1)
		{
			swapping(&temp->data,&temp->link->data);//note
			temp=temp->link;
		}
		else
		{
			temp=temp->link;
		}
		flag=!flag;//flipflops
		
	}
}

void pairWiseSwap(struct node *head)
{
    struct node *temp = head;
 
    // Traverse further only if there are at-least two nodes left 
    while (temp != NULL && temp->next != NULL)
    {
        // Swap data of node with its next node's data 
        swap(&temp->data, &temp->next->data);
 
        // Move temp by 2 for the next pair 
        temp = temp->next->next;
    }
}
*/


int main()
{
	
  node *p;
  p=NULL;
  p=newnode(1);
  p->link=newnode(2);
  p->link->link=newnode(3);
  p->link->link->link=newnode(4);
  p->link->link->link->link=newnode(5);
  p->link->link->link->link->link=newnode(7);
  disp(p);
  swap(p);
 cout<<"\n";
  disp(p);
    return 0;
}