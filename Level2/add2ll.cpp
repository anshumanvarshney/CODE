/*
Add two numbers represented by linked lists | Set 1
Given two numbers represented by two lists, write a function that returns sum list. The sum list is list
 representation of addition of two input numbers.

Example 1

Input:
  First List: 5->6->3  // represents number 365
  Second List: 8->4->2 //  represents number 248
Output
  Resultant list: 3->1->6  // represents number 613
Example 2

Input:
  First List: 7->5->9->4->6  // represents number 64957
  Second List: 8->4 //  represents number 48
Output
  Resultant list: 5->0->0->5->6  // represents number 65005

Pseudocode:
Step 1. Traverse the linked lists and push the elements in two different stacks
Step 2. Pop the top elements from both the stacks 
Step 3. Add the elements (+ any carry from previous additions) and store the carry in a temp variable
Step 4. Create a node with the sum and insert it into beginning of the result list
*/



//without using stack

LinkedListNode* reverse(LinkedListNode* head)
{
    LinkedListNode *prev,*curr,*next;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;

}

void insert(LinkedListNode **head,int val)
{
   LinkedListNode *temp=*head;
	temp=(struct LinkedListNode *)malloc(sizeof(LinkedListNode));
	temp->val=val;
	temp->next=*head;
	*head=temp;
}
    

LinkedListNode* addLists(LinkedListNode* head1, LinkedListNode* head2)
{
    LinkedListNode *temp1,*temp2,*temp=NULL;
    temp1=reverse(head1);
    temp2=reverse(head2);
    int sum,c=0,t;
    while(temp1!=NULL && temp2!=NULL)
    {
        t=temp1->val+temp2->val+c;
        insert(&temp,t%10);
        //printf("%d ",t%10);
        c=t/10;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL)
    {
        t=temp1->val+c;
        insert(&temp,t%10);
        //printf("%d ",t%10);

        c=t/10;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        t=temp2->val+c;
        insert(&temp,t%10);
        //printf("%d ",t%10);
        c=t/10;
        temp2=temp2->next;
    }
    if(c!=0)
        insert(&temp,c);
    //temp=reverse(temp);
    return temp;
    
}


#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *newnode(int data)
{
	node *temp=new node;
	temp->data=data;
	temp->next=NULL;
	return temp;
}

void display(node *head)
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

int count(node *head)
{
	node *temp=head;
	int c=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	return c;
}

void push(node **head,int data)
{
	node *temp=*head;
	temp=new node;
	temp->data=data;
	temp->next=*head;
	*head=temp;
}

node *reverse(node *head)
{
	node *prev,*curr,*next;
	prev=NULL;
	curr=head;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

node *sum(node *head1,node *head2)
{
	stack<node *>s1,s2;
	node *temp1=reverse(head1);
	node *temp2=reverse(head2);
	while(temp1!=NULL)
	{
		s1.push(temp1);
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		s2.push(temp2);
		temp2=temp2->next;
	}
	node *temp=NULL;
	int carry=0,t;
	
	while(!s1.empty()&&!s2.empty())
	{
		t=s1.top()->data+s2.top()->data+carry;
		push(&temp,t%10);
		///cout<<t%10<<" ";
		carry=t/10;
		s1.pop();
		s2.pop();
	}
	while(!s1.empty())
	{
		t=s1.top()->data+carry;
		push(&temp,t%10);
		///cout<<t%10<<" ";
		carry=t/10;
		s1.pop();
	}
	while(!s2.empty())
	{
		t=s2.top()->data+carry;
		push(&temp,t%10);
		///cout<<t%10<<" ";
		carry=t/10;
		s2.pop();
	}
	if(carry!=0)
		push(&temp,carry);
	node *tempp=reverse(temp);
	return tempp;
}
int main()
{
	node *h1=NULL;
	node *h2=NULL;
	h1=newnode(5);
	h1->next=newnode(6);
	h1->next->next=newnode(3);
	h2=newnode(8);
	h2->next=newnode(4);
	h2->next->next=newnode(2);
	display(h1);
	display(h2);
	node *res=sum(h1,h2);
	display(res);
	return 0;
}
//without using stack
/*	
   ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
   ListNode *currentA=A;
   ListNode *currentB=B;
   int sum=0,carry=0;
   if(!A)
    return B;
   if(!B)
    return A;
   while(currentA->next && currentB->next){
       sum=currentA->val+currentB->val+carry;
       carry=sum/10;
       currentA->val=sum%10;
       currentA=currentA->next;
       currentB=currentB->next;
   }
   sum=currentA->val+currentB->val+carry;
   carry=sum/10;
   currentA->val=sum%10;
   if(!(currentA->next))
       currentA->next=currentB->next;
    while(currentA->next){
        currentA=currentA->next;
        sum=currentA->val+carry;
       carry=sum/10;
       currentA->val=sum%10;
    }
    if(carry>0){
        ListNode *l=new ListNode(carry);
        currentA->next=l;
        l->next=NULL;
    }
    return A;
}
*/