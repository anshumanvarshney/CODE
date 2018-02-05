/*
Check if Linked List is Palindrome
Given a singly linked list of integers, Your task is to complete a function that returns true if the given
 list is palindrome, else returns false
 
 AlgoL
 1) using general method convert into number then check
 2)reverse the ll and then compare
 3)by reversing second half of ll and check
 4)using stack
*/
//best solution
bool isPalindrome(LinkedListNode* head)
{
    if(head==NULL)
        return true;
    LinkedListNode *temp,*slow,*fast;
    temp=slow=fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=slow->next;
    fast=reverse(fast);
    while(fast!=NULL)
    {
        if(temp->val!=fast->val)
            return false;
        fast=fast->next;
        temp=temp->next;
    }
    return true;

}


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
/*
node *reverse(node *head)
{
    node *cur,*pre,*next;
	cur=head;
    pre=NULL;
    while(cur!=NULL)
    {
        
		next=cur->next;
		cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}
bool isPalindrome(node *head)
{
    node *head2=reverse(head);
	printlist(head2);
    node* a = head;
    node* b = head2;
 
     while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
            return false;
 
        a = a->next;
        b = b->next;
    }
 
    // If linked lists are identical, then 'a' and 'b' must
    // be NULL at this point.
    return (a == NULL && b == NULL);
}
*/
//second method using stack
bool isPalindrome(node *head)
{
	stack<node *>s;
	node *temp=head;
	while(temp!=NULL)
	{
		s.push(temp);
		temp=temp->next;
	}
	temp=head;
	while(!s.empty())
	{
		if(temp->data!=s.top()->data)
		{
			return false;
		}
	    s.pop();
		temp=temp->next;
	}
	return true;
}

int main()
{
    node *head1 = newNode(3);
    head1->next = newNode(3);
    head1->next->next = newNode(3);
    //head1->next->next->next = newNode(4);
	printlist(head1);
	cout<<isPalindrome(head1);
    return 0;
}
