/*
Check if Linked List is Palindrome
Given a singly linked list of integers, Your task is to complete a function that returns true if the given
 list is palindrome, else returns false
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


int main()
{
    node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(2);
    head1->next->next->next = newNode(1);
	head1->next->next->next->next = newNode(2);
	head1->next->next->next->next->next = newNode(0);
	head1->next->next->next->next->next->next = newNode(0);
	head1->next->next->next->next->next->next->next = newNode(0);
    printlist(head1);
	return 0;
}
