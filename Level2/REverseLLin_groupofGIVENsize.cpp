/*
Reverse a Linked List in groups of given size
Given a linked list, write a function to reverse every k nodes (where k is an input to the function).

Example:
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
Output:  3->2->1->6->5->4->8->7->NULL. 

Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
Output:  5->4->3->2->1->8->7->6->NULL. 
*/

#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	node *link;
};


node *reverse (node *head, int k)
{
    node* current = head;
    node* next;//or node *next=NULL is a good practice
    node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->link;
        current->link = prev;
        prev = current;
        current = next;//at that point current and next points to same node
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->link = reverse(next, k); 
 
    /* prev is new head of the input list */
    return prev;
}

void disp(node *p)
{
	node *temp;
	temp=p;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<"\n";
	
}

node *newnode(int data)
{
	node *temp;
	temp=new node;
	temp->data=data;
	temp->link=NULL;
	return temp;
}

int main()
{
	node *head=NULL;
	head=newnode(2);
	head->link=newnode(3);
	head->link->link=newnode(4);
	head->link->link->link=newnode(5);
	head->link->link->link->link=newnode(6);
	head->link->link->link->link->link=newnode(7);
	head->link->link->link->link->link->link=newnode(8);
	head->link->link->link->link->link->link->link=newnode(9);
	
	disp(head);
	head=reverse(head,3);
	disp(head);
}