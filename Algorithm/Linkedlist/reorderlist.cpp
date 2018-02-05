/*
Rearrange a given linked list in-place.
Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list 
so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …

You are required do this in-place without altering the nodes’ values.

Examples:
Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3 

Simple Solution

1) Initialize current node as head.
2) While next of current node is not null, do following
    a) Find the last node, remove it from end and insert it as next
       of current node.
    b) Move current to next to next of current
Time complexity of the above simple solution is O(n2) where n is number of nodes in linked list.

Efficient Solution:

1) Find the middle point using tortoise and hare method.
2) Split the linked list in two halves using found middle point in step 1.
3) Reverse the second half.
4) Do alternate merge of first and second halves. 
Time Complexity of this solution is O(n).
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


node* reverse(node* head)
{
	node *curr,*prev,*next;
	curr=head;
	prev=NULL;
	
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
	
}


node* reorder(node* head1)
{
	node *fast,*slow;
	slow=fast=head1;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	node *temp=slow;
	slow=slow->next;
	temp->next=NULL;
	node *head2=reverse(slow);
	
	//now merge alternate
	node *p1,*q1,*p,*q;
	p=head1;
	q=head2;
	while(q!=NULL)
	{
		p1=p->next;
		q1=q->next;
		p->next=q;
		q->next=p1;
		p=p1;
		q=q1;
	}
	return head1;
	
	
}



int main()
{
    node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
   // head1->next->next->next->next = newNode(5);
  //  head1->next->next->next->next->next = newNode(6);
	//head1->next->next->next->next->next->next = newNode(7);
    cout << "Given linked list\n";
    printlist(head1);
	
    head1=reorder(head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}
