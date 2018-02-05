/*
Find the middle of a given linked list 
Given a singly linked list, find middle of the linked list. For example, 
if given linked list is 1->2->3->4->5 then output should be 3.

If there are even nodes, then there would be two middle nodes, we need to print second middle element.
For example, if given linked list is 1->2->3->4->5->6 then output should be 4.
Method 1:
Traverse the whole linked list and count the no. of nodes. Now traverse the list again till count/2 and 
return the node at count/2.

Method 2:
Traverse linked list using two pointers. Move one pointer by one and other pointer by two.
When the fast pointer reaches end slow pointer will reach middle of the linked list.

Method 3:
Initialize mid element as head and initialize a counter as 0. Traverse the list from head, while traversing increment 
the counter and change mid to mid->next whenever the counter is odd. 
So the mid will move only half of the total length of the list.
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

int mid(node *p)
{
	node *slow,*fast;
	slow=fast=p;
	while(fast!=NULL  && fast->link!=NULL)//do not use -->  while(fast->link!=NULL  && fast->link->link!=NULL) because it returns only first middle in case of two 
	{
		slow=slow->link;
		fast=fast->link->link;
	}
	return slow->data;
}

int mid1(node *p)
{
	node *temp,*mid;
	mid=temp=p;
	int i=1;
	while(temp!=NULL)
	{
		if(i%2==0)
			mid=mid->link;
		temp=temp->link;
		i++;
	}
	return mid->data;
}

int main()
{
	
  node *p;
  p=NULL;
  p=newnode(2);
  p->link=newnode(3);
  p->link->link=newnode(4);
  p->link->link->link=newnode(5);
  p->link->link->link->link=newnode(6);
  //p->link->link->link->link->link=newnode(7);
  disp(p);
  cout<<"\nMiddle element :"<<mid(p);
  cout<<"\nMiddle element :"<<mid1(p);
    return 0;
}