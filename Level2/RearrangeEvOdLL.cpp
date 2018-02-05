/*
Rearrange a linked list

Given a singly linked list, rearrange it in a way that all odd position nodes are together and
 all even positions node are together,
Example:
Input:
2
4
1 2 3 4
5
1 2 3 4 5

Output:
1 3 2 4
1 3 5 2 4

my algo:
make even ll 
make odd ll
even->next=odd;
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

node *rearr(node *head)
{
	node *p,*q,*s;
	p=head;
	q=p->next;
	s=q;
	while(q!=NULL && q->next!=NULL)
	{
		p->next=q->next;
		p=p->next;//eg 1 2 3 4 5 so here now p points to 3
		q->next=p->next;
		q=q->next;
	}
	p->next=s;
	return head;
}

int main()
{
    node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
	head1->next->next->next->next = newNode(5);
	printlist(head1);
    node *head = rearr(head1);
	printlist(head);
	return 0;
}
