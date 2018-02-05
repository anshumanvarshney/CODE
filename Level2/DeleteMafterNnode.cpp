/*
Delete N nodes after M nodes of a linked list

Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.
Example:
M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
After 2 nodes 2 nodes will be deleted.Deleted Nodes 3->4 and 7->8
Output: Linked List: 1->2->5->6
*/
/*
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }

*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printlist(node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int count(node *head)
{
	int c=0;
    while(head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}


node* del(node *head,int m,int n)
{
	int len=count(head);
	node *temp=head;
	int c=0,d;
	while(temp!=NULL)
	{
		c++;
		if(c%m!=0)
		{
			temp=temp->next;
		}
		else
		{
			d=0;
			node *r,*t,*old;
			r=t=temp;
			r=r->next;
			while(d<n&&r!=NULL)
			{
				d++;
				old=r;
				r=r->next;
				t->next=r;
				delete old;
			}
			temp=temp->next;
		}	
	}
	return head;
}


int main()
{
    node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
	head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
	printlist(head1);
	node *temp=del(head1,2,2);
	printlist(temp);
    return 0;
}
